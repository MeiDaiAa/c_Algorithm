#include <iostream>
#include <string>

using namespace std;

/*
对于任何字符串，我们可以通过删除其中一些字符（也可能不删除）来构造该字符串的 子序列 。(例如，“ace” 是 “abcde” 的子序列，而 “aec” 不是)。

给定源字符串 source 和目标字符串 target，返回 源字符串 source 中能通过串联形成目标字符串 target 的 子序列 的最小数量 。如果无法通过串联源字符串中的子序列来构造目标字符串，则返回 -1。

示例 1：

输入：source = "abc", target = "abcbc"
输出：2
解释：目标字符串 "abcbc" 可以由 "abc" 和 "bc" 形成，它们都是源字符串 "abc" 的子序列。
*/

class Solution {
public:
    int shortestWay(string source, string target) {
        int slen = source.size(), tlen = target.size();
        int cur = 0, ocur = 0;//cur指向target ，ocur指向source
        int ret = 0;
        int temp = 0;//temp用来记录source遍历完一遍后cur在target中的位置

        while(cur < tlen){
            if(target[cur] != source[ocur]) ++ocur;
            else ++cur, ++ocur;
            if(ocur == slen){
                //如果ocur又遍历完一遍后，cur根本没有动过，表示source中没有target中cur指向的字母，返回-1
                if(temp == cur) return -1;
                temp = cur;//记录遍历一遍后cur在target中的位置
                //将ocur置为0，开始下一轮遍历
                ocur = 0;
                ++ret;//返回值+1
            }
        }
        //处理traget遍历完但是source没有遍历完的情况
        //ocur != 0 表示traget的最后一段是source的子集，但是source没有跑完，所以返回值要+1
        return ocur != 0 ? ret + 1 : ret;
    }
};