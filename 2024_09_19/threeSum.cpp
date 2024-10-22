#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*////解题思路

排序之后 枚举一个数之后，在进行双指针查找算法

*/



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int len = nums.size();
        //对目标数组进行排序
        sort(nums.begin(), nums.end());
        //定义左指针下标和右指针下标
        int L, R;
        //定义一个指针记录枚举数字之前的下标
        int perid = -1;
        for (int i = 0; i < len; ++i) {
            //如果当前枚举下标的值与记录的之前的下标的值相同， 
                //此时有可能会输出相同的数组，并且这种情况已经考虑过了，应该跳过
            if (perid != -1 && (nums[i] == nums[perid]))
                continue;
            L = i + 1;
            R = len - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0) {
                    ret.push_back({ nums[i], nums[L], nums[R] });
                    //找到一个目标后，左指针右移切换数据， 如果切换后左指针指向的值与切换之前相同的话，
                      //会输出相同的数组，所以应该移到只想与之前不同的值的位置上
                    //记录当前的左指针
                    int temp = L;
                    //如果左指针与记录前指向的值相同，就L++
                    while (L < R && (nums[L] == nums[temp]))
                        L++;
                }
                else if (sum < 0) {
                    L++;
                }
                else if (sum > 0) {
                    R--;
                }
            }
            //记录这一循环的i，如果下一循环指向的值与当前相同，就直接再进行下一次循环
            perid = i;
        }

        return ret;
    }
};