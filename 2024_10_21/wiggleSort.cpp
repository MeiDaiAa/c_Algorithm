#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个的整数数组 nums, 将该数组重新排序后使 nums[0] <= nums[1] >= nums[2] <= nums[3]... 

输入数组总是有一个有效的答案。

示例 1:

输入：nums = [3,5,2,1,6,4]
输出：[3,5,1,6,2,4]
解释：[1,6,2,5,3,4]也是有效的答案
示例 2:

输入：nums = [6,6,5,6,3,8]
输出：[6,6,5,6,3,8]
*/

class Solution {
public:
    //////暴力双指针法：排序后，两个指针指向两端， 左右分别插入到新数组中，然后将新数组赋值给nums
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return;

        sort(nums.begin(), nums.end());
        vector<int>ret;

        int left = 0, right = len - 1;

        while(left < right){
            ret.push_back(nums[left++]);
            ret.push_back(nums[right--]);
        }
        if(left == right) ret.push_back(nums[left]);

        nums = ret;
    }

    /*2 奇数交换法：
                    由题目可知，奇数位的数要大于两边的数，我么可以将三个数（偶<=奇=>偶）看作一组
                    我们将nums排序之后 左边的数一定小于右边的数, 所以左边的一组数 一定小于右边的一组数
                    一组数 包含 1 2 3 4 5 6
                    排序之后 1 < 2 < 3 < 4 < 5 < 6 此时,前三个数 1 < 2 < 3  我们只需要将 2 与 3 交换  1 < 3 > 2 
                    又因为我们排过序, 所以左边的一组数 必定小于右边的一组数 即 (1 < 3 > 2) < (4...)
                    所以说排序之后, 每一组数之间就可以不用关心了, 我们发现只需要将奇数位的数与下一位的数交换, 就可以完成
    */
    void wiggleSort2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size() - 1; i += 2){
            swap(nums[i], nums[i + 1]);
        }
    }

    /*3一组一组看待
                    上面一个方法中我们将三个数看作一组, 我们发现每组之间是有关系的 在 1 2 3 4 5 6 7中
                    第一组: 1 2 3  第二组: 3 4 5 其中有一位数相同
                    当我们只考虑奇数位的时候 第一组 改为 1 < 3 > 2  此时 第二组数变成了 2 4 5 
                    我们又将 2 4 5 改为了 2 < 5 > 4 ...
                    我们发现 整个数组变成了 1 < 3 > 2 < 5 > 4 < 7 > 6
                    这样整个数组就完成了
                    但是我们要考虑边界情况:最后一组有可能只有两个数
    */
    void wiggleSort3(vector<int>& nums) {
        if(nums.size() == 2 && nums[0] > nums[1]) swap(nums[0], nums[1]);
        for(int i = 1; i < nums.size(); i += 2){
            if(nums[i] < nums[i - 1]) swap(nums[i], nums[i - 1]);
            if(i == nums.size() - 1) return;
            if(nums[i] < nums[i + 1]) swap(nums[i], nums[i + 1]);
        }
    }

    
    /*4 贪心
        综上:如果我们不考虑一组,就没有边界情况
            我们发现,只需要让奇数位大于下一位, 偶数位小于下一位, 就可以让每一组完成排序
    */
    void wiggleSort4(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++){
            if((i % 2) == 0 && nums[i] > nums[i + 1] || 
            ((i % 2) == 1 && (nums[i] < nums[i + 1]))) swap(nums[i] , nums[i + 1]);
        }
    }
};