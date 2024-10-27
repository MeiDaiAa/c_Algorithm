#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
给定一个二进制数组 nums ，如果最多可以翻转一个 0 ，则返回数组中连续 1 的最大个数。

示例 1：

输入：nums = [1,0,1,1,0]
输出：4
解释：翻转第一个 0 可以得到最长的连续 1。
     当翻转以后，最大连续 1 的个数为 4。
示例 2:

输入：nums = [1,0,1,1,0,1]
输出：4
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = 0, sumNum = 0, ret = 0;

        while(right < len){
            if(nums[right] == 0) ++sumNum;

            while(sumNum > 1) if(nums[left++] == 0) --sumNum;

            ret = max(ret, right++ - left + 1);
        }
        return ret;
    }
};