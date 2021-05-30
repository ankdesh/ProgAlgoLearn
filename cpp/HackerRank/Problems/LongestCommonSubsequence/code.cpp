#include <iostream>
#include <vector>
#include <cassert>
#include <stack>

int main(){
  
  uint32_t N,M;
  std::cin >> N >> M;

  std::vector<uint32_t> A(N+1);
  std::vector<uint32_t> B(M+1);

  for (int i = 1; i < N+1; i++){
    std::cin >> A[i];
  }

  for (int i = 1; i < M+1; i++){
    std::cin >> B[i];
  }

  std::vector<std::vector<uint32_t>> C (N+1, std::vector<uint32_t>(M+1,0)); // Subsequence length
  // Direction for retracing result (u for up, l for left, q for up,left
  std::vector<std::vector<char>> Dir (N+1, std::vector<char>(M+1,0)); 

  for (int i = 1; i < N + 1; i++){
    for (int j = 1; j < M + 1; j++){
      if (A[i] == B[j]){
        C[i][j] = C[i-1][j-1] + 1;
        Dir[i][j] = 'q'; 
      }
      else {
        if (C[i-1][j] > C[i][j-1]){
          C[i][j] = C[i-1][j];
          Dir[i][j] = 'u'; 
        }

        else {
          C[i][j] = C[i][j-1];
          Dir[i][j] = 'l'; 
        }

      }
    }
  }
   
  
   //for (int i = 1; i < N + 1; i++){
   //  for (int j = 1; j < M + 1; j++){
   //    std::cout << " " << Dir[i][j];
   //  }
   //  std::cout << std::endl;
   //}

  // Print Max Subsequence 
  int i = N; 
  int j = M; 

  std::stack<uint32_t> longestSub;
   
  while (i > 0 && j > 0){
    if (Dir[i][j] == 'q'){
      longestSub.push(A[i]);
      i = i - 1;
      j = j - 1;
      //std::cout <<"(" << i << "," << j <<")>" << A[i];
    }
    else if (Dir[i][j] == 'u'){
      i = i - 1;
    }
    else if (Dir[i][j] == 'l'){
      j = j - 1;
    }
    else {
      assert( 0 && "Should not have reached");
    }
  }

  while (!longestSub.empty()){
    std::cout << longestSub.top() << " ";
    longestSub.pop();
  } 
}

