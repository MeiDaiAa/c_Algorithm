#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //如果字符串的长度小于2的话，直接返回当前长度
        if (s.length() < 2) { return s.length();}
        //创建左节点右节点， 返回目标数（最大数）和计算数（左节点到右节点的记录数）
        int L = 0, R = 1, ret = 1, cur = 1;

        //当右节点没有走到字符串末尾的时候
        while (R < s.length()) {
            //从左节点开始到右节点之前，判断是否有字符与右节点相同
            for (int i = L; i < R; i++) {
                //如果有节点与右节点相同那么就将左节点移到相同的节点之后，这样两个相同的字符就会变成一个即右节点的字符
                if (s.at(i) == s.at(R)) {
                    L = i + 1;
                    //更新计算数
                    cur = R - L;
                    cout << "当前的cur为:" << cur << endl;
                    break;
                }
            }

            //如果在右节点之前没有与右节点相同的字符串，那么就更新计算数的长度
            cur++;
            //如果计算数长度大于最大数那么就赋值
            if (cur > ret) { ret = cur ;}
            //右节点右移
            R++;
        }
        return ret;
    }
};