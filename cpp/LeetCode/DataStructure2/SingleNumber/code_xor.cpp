#include <cstdint>
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int32_t res = 0;
        for (int val:nums){
            res ^= val;
        }
        return res;
    }
};