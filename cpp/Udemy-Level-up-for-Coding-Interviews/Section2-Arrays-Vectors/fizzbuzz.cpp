#include<vector>
#include<string>
#include<iostream>
using namespace std;

//Complete this method, don't write main
vector<string> fizzbuzz(int n){
    std::vector <std::string> result;
    for (int i=1; i<n+1; i++){
        if ( i >= 5 && i % 3 == 0 && i % 5 == 0){
            result.push_back("FizzBuzz");
        }
        else if (i >= 3 && i % 3 == 0){
            result.push_back("Fizz");
        }
        else if (i >= 5 && i % 5 == 0){
            result.push_back("Buzz");
        }
        else {
            result.push_back(std::to_string(i));
        }
    }
   return result;
}

int main(){
    for (auto &elm: fizzbuzz(15)){
        std::cout << elm << ",";
    }
    return 0;
}