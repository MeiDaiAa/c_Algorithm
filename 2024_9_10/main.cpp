#include <iostream>
#include "Solution.cpp"
using namespace std;

////////////////题目描述/////////////////
/* 
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案。
*/

int main()
{
	vector<int>nums = { 2, 7, 11, 5 };
    int traget = 9;

    Solution solution;
    vector<int>ret = solution.twoSum(nums, traget);
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret.at(i) << " ";
    }
}