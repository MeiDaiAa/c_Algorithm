#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int fmax = 0, fmin = 0;
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i){
            fmax = max(fmax, 0) + nums[i];
            fmin = min(fmin, 0) + nums[i];
            ret = max(ret, max(fmax, -fmin));
        }
        return ret;
    }
};
class Solution {
public:
    int maxAbsoluteSum2(vector<int>& nums) {
        int fmax = 0, fmin = 0;
        int sum = 0;
        for(auto i : nums){
            sum += i;
            fmax = max(fmax, sum);
            fmin = min(fmin, sum);
        }
        return fmax - fmin;
    }
};