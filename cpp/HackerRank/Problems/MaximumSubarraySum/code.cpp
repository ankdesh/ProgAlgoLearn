#include <iostream>

int main(){
  int T;
  
  std::cin >> T;

  for (int t = 0; t < T; t++){

    int N;
    std::cin >> N;

    int max = 0; 
    int runningMax = 0;
    int maxSubArray = 0;
    bool allNegative = true;
    int maxNeg = -1 * (1<<30);
 
    for (int n = 0; n < N; n++){
      int val;
      std::cin >> val;

      if (val > 0){
        maxSubArray += val;
        allNegative = false;
      }
      else { // Handling all neg value case
        if (val >= maxNeg){
          maxNeg = val;
        }
      }

      if (runningMax + val > 0){
        runningMax += val;
        //std::cout << ">>" << val << " " << runningMax << std::endl;
        if (runningMax > max){
          //std::cout << "||" << val << " " << runningMax << std::endl;
          max = runningMax;
        }
      }
      else {
        runningMax = 0;
      }
    }
    if (allNegative == true){
      max = maxNeg;
      maxSubArray = maxNeg;
    }
    std::cout << max << " " << maxSubArray << std::endl;
  }
}
