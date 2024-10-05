#include <iostream>
#include <vector>
using namespace std;
/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。



示例 1:

输入: nums = [1,3,5,6], target = 5
输出: 2
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1, mid = 0;
        while (L <= R) {
            mid = (L + R) >> 1;
            if (nums[mid] < target) L = mid + 1;
            else R = mid - 1;
        }
        return L;
    }
};