#include <vector>
#include <iostream>
using namespace std;

//方法1：模拟
class Solution {
public:
    vector<int> differ;
    int res = 0;
    int countValidSelections(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; ++i) differ.push_back(0);
        int curr = 0;
        vector<int> orig = nums;
        
        for(; curr < len; ++curr){
            nums = orig;
            if(nums[curr] == 0) {
                bfs(curr, nums, true);
                nums = orig;
                bfs(curr, nums, false);
            }
        }

        return res;
    }
    void bfs(int i, vector<int>&nums, bool flag){
        if(i < 0 || i >= nums.size()) {
            if(nums == differ) res++;
            return;
        }

        if(nums[i] == 0) {
            if(flag) bfs(i - 1, nums, flag);
            else bfs(i + 1, nums, flag);
        }
        else if(nums[i] > 0) {
            --nums[i];
            if(flag) bfs(i + 1, nums, !flag);
            else bfs(i - 1, nums, !flag);
        }
    }
    //方法2：小球弹砖块：判断小球左边与右边的砖块数量，如果相差为0 则+2 如果相差为1 则+1， 其余不相加 
};