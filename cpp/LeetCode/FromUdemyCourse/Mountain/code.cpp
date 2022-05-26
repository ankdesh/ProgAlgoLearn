#include <vector>
#include <iostream>

class Solution {
public:
    int longestMountain(std::vector<int>& arr) {
         
        int currMax = 0;
        bool onMountain = true;
        int i = 0;
        while(i < arr.size() - 1 && arr[i] >= arr[i+1]){
            i++;
            //std::cout << "Throwing out" << i << std::endl;
        }
        
        //i = std::max(i,1);
        int lastValley = i;
        // std::cout << i << " " << lastValley << std::endl;
        for (; i<arr.size()-1; i++){
            
            if (i != 0 && arr[i-1] > arr[i] && arr[i] < arr[i+1]){
                //std::cout << i <<std::endl;
                //std::cout << "Curr i" << i << std::endl; 
                if ((i - lastValley) > currMax && onMountain){
                    currMax = i - lastValley + 1;
                    //std::cout << "CurrMax=" << currMax << std::endl;
                }   
                lastValley = i;
                onMountain = true;
            }
            if (i != 0 && arr[i-1] == arr[i]){
                //std::cout << "What" << i << std::endl;
                onMountain = false;
            }
        }
        if (arr[arr.size() - 1] < arr[arr.size() - 2]){
            //std::cout << "Last Valley" << lastValley << onMountain << std::endl;
            if (((arr.size() - 1) - lastValley) > currMax && onMountain){
                    currMax = (arr.size() - 1) - lastValley + 1;
                    //std::cout << "Last moutain" << currMax << std::endl;
                } 
        }
        return currMax;
    }
};

int main(){
    auto asd = new Solution();
    //auto ins = std::vector<int>{0,1,2,3,4,5,4,3,2,1,0};
    auto ins = std::vector<int>{2,2,2};
    auto outs = asd->longestMountain(ins);
    std::cout << outs;
    return 0;
} 
