#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

namespace DFBB{

int N; // Num of Items
int K; // Max capacity of knapsack 
std::shared_ptr<std::vector<uint32_t>> pW;
std::shared_ptr<std::vector<uint32_t>> pV;

uint32_t maxV;
std::vector<uint8_t> bestConf;

std::vector<uint8_t> currConf;
  
typedef std::pair<int,float>  IndexValPair;
  
// vec of <index, v/w values
std::vector<IndexValPair>     fracVbyW; 

// Calulates upper bound using constraints for current conf 
// with prefix upto 'level' and select all further
// using linear relaxation
float getLinearRelaxedConstraint(int level){
  float bestEstimate = 0;
 
  float accW = 0;
  for (auto it:fracVbyW){
    // Use currConf till the level we have explored and
    // select all items futher on
    int i = std::get<0>(it);
    if (((i < level) && (currConf[i] == 1)) || (i >= level) ){
      //std::cout << "At level: " << std::to_string(level) << "Accept: " << std::to_string(i) << std::endl; 
      auto currW = (*pW)[i];
      auto currV = (*pV)[i];
      if( accW + currW <= K){
        accW += currW;
        bestEstimate += currV;
        //std::cout << "--> " << std::to_string(currW)
        //          << ","    << std::to_string(currV) 
        //          << " ==> "<< std::to_string(bestEstimate) <<std::endl;
      }
      else { // Fill remaining space by partial value
        float remainW = K - accW;
        //std::cout << "-- " << std::to_string(remainW)
        //          << "/"   << std::to_string(currW) <<std::endl;
        float fracWUsed = remainW/currW;
        bestEstimate += currV * fracWUsed;
        // Break loop
        break;
      }
    }
    else {
      //std::cout << "At level: " << std::to_string(level)<< "Reject: " << std::to_string(i)<< std::endl; 
    }
  }

  return bestEstimate;
}


// Do a depth first traversal and do branch n bound using linear relaxation.
void branchNBound(uint32_t currV, uint32_t availW, int level){

  float currEstimate = getLinearRelaxedConstraint(level);

  //std::cout << ">>" << std::to_string(currV) << " " 
  //                  << std::to_string(availW) << " "
  //                  << std::to_string(currEstimate) << " " 
  //                  << std::to_string(level) << std::endl;

  if (level == N && currV > maxV){
    maxV = currV;
    std::copy(currConf.begin(), currConf.end(), bestConf.begin());
  }

  if (level >= N) {
    return;
  }

  //std::cout <<" Current Est : " << std::to_string(currEstimate)
  //          <<" Max V: " << maxV << std::endl; 
  if (currEstimate < maxV){
    return;
  }

  // Choosing next element
  if (availW >= (*pW)[level]){ // Possible to choose levelth element
    currConf[level] = 1;
    branchNBound(currV + (*pV)[level], availW - (*pW)[level], level + 1);
  }
  
  // Dropping next element
  if (currEstimate >= (*pV)[level]){
    currConf[level] = 0;
    branchNBound(currV, availW, level + 1);  }
}

// Returns the vector of boolean representing if the item was selected in knapsack.
// Takes Num of items (n), knapsack size (k), weights(w) and values (v) of each item
std::vector<uint8_t> branchBound(int n, int k, std::vector<uint32_t>& w, std::vector<uint32_t>& v){
  // Initialize
  maxV = 0;
  N = n;
  K = k;
  pW = std::make_shared<std::vector<uint32_t>>(w);
  pV = std::make_shared<std::vector<uint32_t>>(v);
  currConf.resize(n);
  bestConf.resize(n);
  std::fill(currConf.begin(), currConf.end(), 0);
  fracVbyW.resize(N);

  for (int i = 0; i < N; i++){
    fracVbyW[i] = std::make_pair(i, ((float)(*pV)[i] / (*pW)[i]));
  }
  
  // Sort the vec by v/w values 
  std::sort(fracVbyW.begin(), fracVbyW.end(), 
             [](IndexValPair a, IndexValPair b){
                return std::get<1>(a) > std::get<1>(b);});  
  

  //std::cout << ">> " << std::to_string(int(bestEstimate)) << std::endl;

  // Call recursive bb
  branchNBound(0, K, 0);

  return bestConf;
}

};
