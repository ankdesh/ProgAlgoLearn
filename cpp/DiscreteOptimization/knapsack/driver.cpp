#include <iostream>
#include <string>


int main(){
  int n,K;
  std::cin >> n >> K;

  std::string str;
  for(int i = 0; i < n; i++){
    int v,w;
    std::cin >> v >> w;
    str += std::to_string(v) + " ";
  }
  std::cout << str;
}
