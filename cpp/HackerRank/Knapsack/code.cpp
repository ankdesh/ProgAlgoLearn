#include <iostream>
#include <vector>

int main(){

  int T,n,k;
  std::cin >> T;
  for (int i = 0; i < T; i++){

    std::cin >> n >> k;
    std::vector<uint32_t> a(n);
    for (int j = 0; j < n; j++){
      std::cin >> a[j];
    }


    std::vector<uint32_t> O(k+1);
    
    for (int i = 0; i < k+1; i++){
      int max = 0;
      for (int j = 0; j < n; j++){
        if(a[j] <= i){
          int temp = O[i - a[j]] + a[j];
          if (temp > max){
            max = temp;
          }
        }
        O[i] = max;
      }   
    }

    std::cout << O[k] << std::endl;
  }

}
