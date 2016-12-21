#include <iostream>
#include <vector>

// Returns the vector of boolean representing if the item was selected in knapsack.
// Takes Num of items (n), knapsack size (k), weights(w) and values (v) of each item
std::vector<uint8_t> dp(int n, int k, std::vector<uint32_t>& w, std::vector<uint32_t>& v){

  std::vector<std::vector<uint32_t>> dpTable(n+1, std::vector<uint32_t>(k+1,0));

  for (int i = 1; i < n + 1; i++){ // Skip first Row (=0)
    for (int j = 0; j < k + 1; j++){ // j represents current capacity 
      int obj_i = i - 1; //  Object index starts from 1
      if (w[obj_i] <= j){ // Cannot choose ith item till the capacity becomes atleast w[i]
        uint32_t valueDropItem = dpTable[i-1][j];
        uint32_t valueChooseItem = dpTable[i-1][j-w[obj_i]] + v[obj_i];         dpTable[i][j] = std::max(valueDropItem, valueChooseItem);
      }
      else {
        dpTable[i][j] = dpTable[i-1][j];
      }
    }
  }
  
  std::vector<uint8_t> returnConf (n,0);
  int currJ = k; // 
  for (int i = n; i > 0; i--) { // 0th row is phony item
    int item_i = i - 1;
    if ( dpTable[i][currJ] == dpTable[i-1][currJ] ){// Item was not chosen
      returnConf[item_i] = 0;
    }
    else{ // item was chosen
      returnConf[item_i] = 1;
      currJ = currJ - w[item_i];
    }

  }

  //for (int i = 0; i < n + 1; i++){
  //  for (int j = 0; j < k + 1; j++){
  //    std::cout << " " << std::to_string(dpTable[i][j]);
  //  }
  //  std::cout << std::endl;
  //}
  return returnConf;
}
