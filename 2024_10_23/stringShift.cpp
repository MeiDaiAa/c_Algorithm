#include <iostream>
#include <vector>

using namespace std;

/*
给定一个包含小写英文字母的字符串 s 以及一个矩阵 shift，其中 shift[i] = [direction, amount]：

direction 可以为 0 （表示左移）或 1 （表示右移）。
amount 表示 s 左右移的位数。
左移 1 位表示移除 s 的第一个字符，并将该字符插入到 s 的结尾。
类似地，右移 1 位表示移除 s 的最后一个字符，并将该字符插入到 s 的开头。
对这个字符串进行所有操作后，返回最终结果。

示例 1：

输入：s = "abc", shift = [[0,1],[1,2]]
输出："cab"
解释：
[0,1] 表示左移 1 位。 "abc" -> "bca"
[1,2] 表示右移 2 位。 "bca" -> "cab"
*/

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int len = s.size();
        //if(len <= 1) return s;

        for(auto i : shift){
            int cur;
            int sub = i[1];

            while(sub > len) sub -= len;

            if(i[0] == 0) cur = 0 + sub;
            else if(i[0] == 1) cur = len - sub;

            s = s.substr(cur, len) + s.substr(0, cur);
        }
        return s;
    }
    //优化
    string stringShift2(string s, vector<vector<int>>& shift) {
        int len = s.size();
        int cur;

        for(auto i : shift){
            if(i[0] == 0) cur = 0 + i[1] % len;
            else if(i[0] == 1) cur = len - i[1] % len;
            
            s = s.substr(cur, len) + s.substr(0, cur);
        }
        return s;
    }
};