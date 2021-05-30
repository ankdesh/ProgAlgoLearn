#include <iostream>
#include <vector>

int main(){
  int N,M;
  std::cin >> N >> M;

  std::vector<uint64_t> coins(M);

  for (int i = 0; i < M; i++){
    std::cin >> coins[i];
  }

  std::vector<std::vector<uint64_t>> C(M, std::vector<uint64_t>(N+1,0));

  for (int i = 0; i < M; i++){
    C[i][0] = 1;
  }


  // We iterate for each coin to calculate C(i,j)
  // C(i,j) = num of ways to find denominations of value j using 
  // denomications of coins[0...i] coins
  for (int i = 0; i < M; i++){
    for (int j = 1; j < N+1; j++){
      if ( j >= coins[i] ){ // Value from same row (j-coins[j]) column
        C[i][j] += C[i][j-coins[i]]; 
      }
      C[i][j] += ((i-1) >= 0 ? C[i-1][j]:0); // Value from last row same column (row zero should get value 0)
    }
  }

  //for (int i = 0; i < M; i++){
  //  for (int j = 0; j < N+1; j++){
  //    std::cout << " " << C[i][j];
  //  }
  //  std::cout << std::endl;
  //}

  std::cout << C[M-1][N];  
}
