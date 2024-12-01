#include <vector>
#include <unordered_map>
#include <iostream>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int allSum = accumulate(nums.begin(), nums.end(), 0);

//逆序枚举异常值, 第一个符合的异常值就为最大的异常值
        for(int i = n - 1; i >= 0; --i){
            int temp = allSum - nums[i];
            if(temp % 2 != 0) continue;//总数-异常数 如果为奇数, 此异常数必定不合法

            //查看是否有 特殊数字和的 数
            int idx = lower_bound(nums.begin(), nums.end(), temp / 2) - nums.begin();

            if(nums[idx] == temp - nums[idx] && idx != i) return nums[i];
        }
        return -1;
    }
};
// 时间复杂度：O(nlogn) 一次排序 + 一次遍历 + n次查找
//空间复杂度:O(1) 仅用到临时变量



// class Solution {
// public:
//     int getLargestOutlier(vector<int>& nums) {
//         int n = nums.size();
//         int target = reduce(nums.begin(), nums.end());

//         unordered_map<int, int> memo;
//         for(int i = 0; i < n; ++i){
//             memo[nums[i]]++;
//         }

//         int ret = INT_MIN;
//         for(int i = 0; i < n; ++i){
//             memo[nums[i]]--;

//             if(memo[target - nums[i] * 2] > 0) ret = max(ret, target - nums[i] * 2);

//             memo[nums[i]]++;

//         }
//         return ret;
//     }
// };
//时间复杂度: O(n) 两次遍历
//空间复杂度O(n) 创建了哈希表保存了nums所有元素

//multset版本
// class Solution {
// public:
//     int getLargestOutlier(vector<int>& nums) {
//         int n = nums.size();
//         int target = 0;

//         multiset<int> memo;
//         for(int i = 0; i < n; ++i){
//             memo.insert(nums[i]);
//             target += nums[i];
//         }

//         int ret = INT_MIN;
//         for(int i = 0; i < n; ++i){
//             memo.erase(memo.find(nums[i]));

//             if(memo.find(target - nums[i] * 2) != memo.end()) ret = max(ret, target - nums[i] * 2);

//             memo.insert(nums[i]);

//         }

//         return ret;
//     }
// };