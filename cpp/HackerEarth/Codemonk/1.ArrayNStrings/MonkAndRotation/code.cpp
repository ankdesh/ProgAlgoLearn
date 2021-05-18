// Sample code to perform I/O:
#include <iostream>
int main() {
  int T, N, K;
  std::cin >> T;

  for (int t=0; t<T; t++){
    std::cin >> N >> K;
    int *inp = new int [N];
    int *temp = new int [K];

    for (int n = 0; n < N; n++){
      std::cin >> inp[n];
    }

    //Save last K items
    for (int k = N-K, i=0 ; k < N; k++,i++){
      temp[i] = inp[k];
    }
    
    // Shift
    for (int k = N-K-1, i=N-1 ; k >= 0; k--,i--){
      inp[i] = inp[k];
    }

    // Copy back
    for (int i=0; i<K; i++){
      inp[i] = temp[i];
    }
    
    // Write
    for (int i=0; i<N; i++){
      std::cout << inp[i] << " ";
    }
    std::cout << std::endl;
  
  }
  
}
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail


// Write your code here
