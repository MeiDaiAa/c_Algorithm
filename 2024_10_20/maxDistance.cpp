#include <iostream>
#include <vector>

using namespace std;

/*
给定 m 个数组，每个数组都已经按照升序排好序了。

现在你需要从两个不同的数组中选择两个整数（每个数组选一个）并且计算它们的距离。两个整数 a 和 b 之间的距离定义为它们差的绝对值 |a-b| 。

返回最大距离。

示例 1：

输入：[[1,2,3],[4,5],[1,2,3]]
输出：4
解释：
一种得到答案 4 的方法是从第一个数组或者第三个数组中选择 1，同时从第二个数组中选择 5 。
*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        //计算的是数组最大值或最小值减去当前的的最大值或最小值，所以不用担心会取到同一个数组的最大值减去最小值的情况
        int min = arrays[0].front();
        int max = arrays[0].back();
        for (int i = 1; i < arrays.size(); i++) {
            ans = std::max(ans, std::max(arrays[i].back() - min, max - arrays[i].front()));
            //更新最大值和最小值
            min = std::min(arrays[i].front(), min);
            max = std::max(arrays[i].back(), max);
        }
        return ans;
    }
};