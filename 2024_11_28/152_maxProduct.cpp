#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() <= 1) return nums[0];
        int minus = 0, plus = 0;
        int ret = INT_MIN;
        for(auto i : nums){
            int temp = max({plus * i, minus * i, i});
            minus = min({minus * i, plus * i, i});
            plus = temp;
            ret = max(plus, ret); 
        }
        return ret;
    }
};