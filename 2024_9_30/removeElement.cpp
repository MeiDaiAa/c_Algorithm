#include <iostream>
#include <vector>

using namespace std;

/*
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。

假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：

更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
返回 k。
输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2,_,_]
解释：你的函数函数应该返回 k = 2, 并且 nums 中的前两个元素均为 2。
你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 1) return nums[0] == val ? 0 : 1;
        int L = 0, R = 0, temp;
        while (R < nums.size()) {
            if (nums[R] == val) R++;
            else if (nums[L] == val && nums[R] != val) {
                temp = nums[L];
                nums[L++] = nums[R];
                nums[R] = temp;
            }
            else {
                L++;
                R++;
            }
        }
        return L;
    }
};