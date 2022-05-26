#include <vector>
#include <iostream>

class Solution {
public:
    int longestMountain(std::vector<int>& arr) {
         
        int currMax = 0;
        for (int i = 1; i < arr.size()-1; i++){
            if (arr[i] > arr[i-1] && arr[i] > arr[i+1]){
                //std::cout << "i:" << i << std::endl;
                int size = 1;
                //Backward trail
                int j = i-1;
                while (j >= 0 && arr[j] < arr[j+1]){
                    //std::cout << "j1:" << j << std::endl;
                    j--;
                    size++;
                }
                j = i + 1;
                while(j < arr.size() && arr[j-1] > arr[j]){
                    //std::cout << "j2:" << j << std::endl;
                    j++;
                    size++;
                }
                if (size > currMax){
                    currMax = size;
                }
            }
        }
        return currMax;
    }
};

int main(){
    auto asd = new Solution();
    auto ins = std::vector<int>{0,1,2,3,4,5,4,3,2,1,0};
    //auto ins = std::vector<int>{1,2,3,2,1};
    //auto ins = std::vector<int>{2,2,2};
    auto outs = asd->longestMountain(ins);
    std::cout << outs;
    return 0;
} 
