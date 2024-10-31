#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
给你一个整数数组 arr， 对于元素 x ，只有当 x + 1 也在数组 arr 里时，才能记为 1 个数。

如果数组 arr 里有重复的数，每个重复的数单独计算。

示例 1：

输入：arr = [1,2,3]
输出：2
解释：1 和 2 被计算次数因为 2 和 3 在数组 arr 里。
示例 2：

输入：arr = [1,1,3,3,5,5,7,7]
输出：0
解释：所有的数都不算, 因为数组里没有 2、4、6、8。
*/

class Solution {
public:
    int countElements(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int>hash;
        int ret = 0;
        for(auto& i : arr){
            if(hash[i - 1] > hash[i]) ret += hash[i - 1] - hash[i], hash[i - 1] = 0;
            ++hash[i];
        }
        return ret;
    }
    //优化
    int countElements2(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int hash[1002] = {0};
        int ret = 0;
        for(int i = 0; i < arr.size(); ++i){
            int idx = arr[i] + 1;
            if(hash[idx - 1] > hash[idx]) {
                ret += hash[idx - 1] - hash[idx];
                hash[idx - 1] = 0;
            }
            ++hash[arr[i] + 1];
        }
        return ret;
    }
};