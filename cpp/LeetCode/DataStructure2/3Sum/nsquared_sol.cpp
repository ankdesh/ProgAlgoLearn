#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::set<std::vector<int>> result;
        for (int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i-1] == nums[i]){
                continue;
            }
            int target = -nums[i];
            int start = i+1;
            int end = nums.size()-1;
            while (start < end){
                int candidate = nums[start] + nums[end];
                if (target == candidate){
                    std::cout <<"S"  << i << " " << start << " " << end <<endl ;
                    result.insert(std::initializer_list<int>({nums[i], nums[start], nums[end]}));
                    start++;
                }
                else if (candidate > target){
                    
                    std::cout <<"G"  << i << " " << start << " " << end << endl ;
                    end--;
                }
                else {
                    
                    std::cout <<"L"  << i << " " << start << " " << end << endl ;
                    start++;
                }
                
            }
        }

        std::vector<std::vector<int>> real_result;
        for (auto elm: result){
            real_result.push_back(elm);
        }
        return real_result;
    }
};


int main(){
    auto asd = new Solution();
    auto ins = std::vector<int>{-1,0,1,2,-1,-4};
    auto outs = asd->threeSum(ins);
    for (auto &vals: outs){
        std::cout <<"[";
        std::copy (vals.begin(), vals.end(), std::ostream_iterator<int> (std::cout, " "));
        std::cout <<"]";
    }

    ins = std::vector<int>{0,0,0,0};
    outs = asd->threeSum(ins);
    for (auto &vals: outs){
        std::cout <<"[";
        std::copy (vals.begin(), vals.end(), std::ostream_iterator<int> (std::cout, " "));
        std::cout <<"]";
    }

} 

