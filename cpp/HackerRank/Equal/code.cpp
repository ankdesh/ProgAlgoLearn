#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main(){
  
  // Inputs 
  int T;
  std::cin >> T;
  for (int i = 0; i < T; i++){
    int N;
    std::cin >>N;

    std::vector<int32_t> choc(N);
    for (int i = 0; i < N; i++){
      std::cin >> choc[i];
    }

    // Sort
    std::sort(choc.begin(), choc.end());

    auto minVal = choc[0];
   
    uint32_t minNumOps = std::numeric_limits<uint32_t>::max(); 
    uint32_t numOps = 0;
   
    int j = 0; 
    for (int j = 0; j < 3; j++){
      for (int i = 1; i < N; i++){
        if (minVal >= j){
          uint32_t numFives = (choc[i] - (minVal + j))/5;
          uint32_t numTwos = ((choc[i] - (minVal + j))%5) / 2;
          uint32_t numOnes = (choc[i] - (minVal + j)) - (numFives * 5 + numTwos * 2);
          numOps += numFives + numTwos + numOnes;
        }
      }
      if (numOps < minNumOps){
        minNumOps = numOps;
      }
    }

    std::cout << minNumOps << std::endl;
  }
}
