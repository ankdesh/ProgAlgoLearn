#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::copy(nums.begin(),nums.end(), ostream_iterator<int>(cout, " "));
        return {};
    }


int main(){
    auto asd = std::vector<int>({1,-1, 4});
    threeSum(asd);
}