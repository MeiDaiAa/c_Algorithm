#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int traget) {
        vector<int>idxs;
        for (int i = 0; i < nums.size(); i++) idxs.push_back(i);

        sort(idxs.begin(), idxs.end(), [idxs, nums](int i, int j) {
            return nums[idxs[i]] < nums[idxs[j]];
            });

        int l = 0, r = nums.size() - 1;
        vector<int>ret;

        while (l < r) {
            if (nums[idxs[l]] + nums[idxs[r]] == traget) {
                ret.push_back(idxs[l]);
                ret.push_back(idxs[r]);
                break;
            }
            else if (nums[idxs[l]] + nums[idxs[r]] < traget) {
                l++;
            }
            else {
                r--;
            }
        }
        return ret;
    }
};