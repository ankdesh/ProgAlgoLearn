#include <unordered_map>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int,int> freq;
        int half_size = nums.size() / 2;
        for (int val: nums){
            auto curr = freq.find(val);
            if (curr == freq.end()){
                freq[val] = 1;
            }
            else{
                if (freq[val] >= half_size){
                    return val;
                }
                else{
                    freq[val] = freq[val] + 1;
                }
            }
        }
        for (auto &val: freq){
            if (val.second >= half_size){
                return val.first;
            }
        }
        return -1;
    }
};