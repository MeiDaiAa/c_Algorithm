#include <vector>
#include <iostream>
using namespace std;

/*
给定一个长度为 n 的整数数组 nums 和一个二维数组 queries，其中 queries[i] = [li, ri]。

对于每个查询 queries[i]：

在 nums 的下标范围 [li, ri] 内选择一个下标子集。
将选中的每个下标对应的元素值减 1。
零数组 是指所有元素都等于 0 的数组。

如果在按顺序处理所有查询后，可以将 nums 转换为 零数组 ，则返回 true，否则返回 false。

数组的 子集 是对数组元素的选择（可能为空）。
*/

class Solution {
public:
    //方法：差分数组
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1);
        for(auto& v : queries){
            diff[v[0]]++;
            diff[v[1] + 1]--;
        }
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += diff[i];
            if(sum < nums[i]) return false;
        }
        return true;
    }
};