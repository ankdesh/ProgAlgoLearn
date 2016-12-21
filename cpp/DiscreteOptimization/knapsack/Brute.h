#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <memory>
#include <Helper.h>

namespace BruteForce{

int N;
int K;
std::shared_ptr<std::vector<uint32_t>> pW;
std::shared_ptr<std::vector<uint32_t>> pV;
uint32_t maxV;
std::vector<uint8_t> conf;
std::vector<uint8_t> bestConf;

void bruteForce(int level){
  if (level > N){
    return;
  }

  auto newV = calcLinearComb(conf, *pV);
  auto newW = calcLinearComb(conf, *pW);
  if(newV > maxV && newW <= K){
    maxV = newV;
    std::copy(conf.begin(), conf.end(), bestConf.begin());
  }

  conf[level] = 1;
  bruteForce(level+1);
  conf[level] = 0;
  bruteForce(level+1);

}

// Returns the vector of boolean representing if the item was selected in knapsack.
// Takes Num of items (n), knapsack size (k), weights(w) and values (v) of each item
std::vector<uint8_t> bruteForce(int n, int k, std::vector<uint32_t>& w, std::vector<uint32_t>& v){
  // Initialize
  maxV = 0;
  N = n;
  K = k;
  pW = std::make_shared<std::vector<uint32_t>>(w);
  pV = std::make_shared<std::vector<uint32_t>>(v);
  conf.resize(n);
  bestConf.resize(n);
  std::fill(conf.begin(), conf.end(), 0);

  // Call recursive bruteforce
  bruteForce(0);

  return bestConf;
}

};
