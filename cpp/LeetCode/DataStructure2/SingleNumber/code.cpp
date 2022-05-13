class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::set<int> sets;
        for (int val:nums){
            auto pos = sets.find(val);
            if ( pos == sets.end()){
                sets.insert(val);
            }
            else{
                sets.erase(pos);
            }   
        }
        int result ;
        for (auto &val: sets){
            result = val;
        }
        return result;
    }
};