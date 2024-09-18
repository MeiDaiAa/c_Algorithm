#include <iostream>
#include <string>

using namespace std;

class Solution {

public:
    string convert(string s, int numRows) {
        //记录一行中每一个字母到下一个字母有多远
        int pain = numRows + (numRows - 1) - 1;
        int len = s.size();
        string ret;
        if (numRows == 1 || numRows >= s.size()) return s;
        else if (numRows == 0 || s.size() == 0) return "";

        //有多少行就循环几次
        int time = 0;
        int idx;
        int mult = 0;
        while (time < numRows) {
            //定位到下标
            idx = time + (pain * mult);
            //算出在中间几行需要往前移动的距离
            int need = time * 2;
            //检查往前移动的距离是否越界
            //判断下标有没有越界
            if (idx - need >= len) {
                //如果越界了，那么idx也肯定越界了，直接跳到下一行
                time++;
                //重置距离
                mult = 0;
                continue;
            }
            //如果是中间的几行就要进行其他操作
            if (time != 0 && time != (numRows - 1) && idx >= numRows) {
                //先把前面的字母推入ret中
                ret.push_back(s.at(idx - need));
            }
            //判断下标有没有越界
            if (idx >= len) {
                time++;
                mult = 0;
                continue;
            }
            //如果下标没有越界，就把当前字母推到ret中
            ret.push_back(s.at(idx));
            mult++;
        }
        return ret;
    }
};