#include <vector>
#include <iostream>
using namespace std;


/*
给你一个整数数组 nums 。

开始时，选择一个满足 nums[curr] == 0 的起始位置 curr ，并选择一个移动 方向 ：向左或者向右。

此后，你需要重复下面的过程：

如果 curr 超过范围 [0, n - 1] ，过程结束。
如果 nums[curr] == 0 ，沿当前方向继续移动：如果向右移，则 递增 curr ；如果向左移，则 递减 curr 。
如果 nums[curr] > 0:
将 nums[curr] 减 1 。
反转 移动方向（向左变向右，反之亦然）。
沿新方向移动一步。
如果在结束整个过程后，nums 中的所有元素都变为 0 ，则认为选出的初始位置和移动方向 有效 。

返回可能的有效选择方案数目。
*/

class Solution {
public:
    //方法1：模拟
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