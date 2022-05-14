#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //std::sort(nums.begin(), nums.end());
        std::set<std::vector<int>> outs;
        for (auto i=0; i < nums.size(); i ++){
            for (auto j=0; j < nums.size(); j ++){
                auto val_i = nums[i];
                auto val_j = nums[j];
                auto k_loc = std::lower_bound(nums.begin(), nums.end(), -1 * (val_i + val_j)) ;
                if (k_loc == nums.end()){
                    continue;
                }
                int k = k_loc - nums.begin();
                //std::cout << k <<" ";
                if (i == j || j == k || k == i){
                    continue;
                }
                if (nums[k] != -1*(val_i+val_j)){
                    continue;
                }

                auto temp_val = std::vector<int> ({val_i, val_j, -1 * (val_i + val_j)});
                std::sort(temp_val.begin(), temp_val.end());
                outs.insert(temp_val);
            }
        }
        vector<vector<int>> outVec;
        for (auto vals:outs){
            outVec.push_back(vals);
        }
        return outVec;
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


} 

