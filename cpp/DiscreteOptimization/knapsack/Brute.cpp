#include <iostream>
#include <vector>
#include <numeric>
#include <string>

// Calculate the weight for given configuration (1 for selected item) and weights 
uint32_t calcW(std::vector<uint8_t>& conf, std::vector<uint32_t>& w){
  return std::inner_product(conf.begin(), conf.end(), w.begin(), 0);
}

// Returns the vector of boolean representing if the item was selected in knapsack.
// Takes Num of items (n), knapsack size (k), weights(w) and values (v) of each item
std::vector<uint8_t> bruteForce(int n, int k, std::vector<uint32_t>& w, std::vector<uint32_t>& v){
  
  int maxValue = 0;

  std::vector<uint8_t> a{0,1};
  std::vector<uint32_t> b{12,10};
  std::string str = std::to_string(calcW(a,b));
  std::cout << str;

  return a;
}
