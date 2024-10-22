#include <iostream>
#include <vector>
using namespace std;

/*
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。

输入：[1,8,6,2,5,4,8,3,7]
输出：49
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        //定义两个指针分别指向数组的两端
        int L = 0, R = n - 1;

        int len = R - L, max = 0, area = 0;
        //指针向中间移动
        while (L < R) {
            //计算出两个指针能够储存到的水
            area = len * min(height.at(L), height.at(R));

            //如果存到的水大于最大能存到的水，就更新
            max = area > max ? area : max;

            //指针指向的墙高度更小的跟新下标
            if (height.at(L) < height.at(R)) {
                L++;
                len--;
                continue;
            }
            else {
                R--;
                len--;
                continue;
            }
        }
        return max;
    }
};