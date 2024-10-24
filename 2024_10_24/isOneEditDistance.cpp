#include <iostream>
#include <vector>

using namespace std;

/*
给定两个字符串 s 和 t ，如果它们的编辑距离为 1 ，则返回 true ，否则返回 false 。

字符串 s 和字符串 t 之间满足编辑距离等于 1 有三种可能的情形：

往 s 中插入 恰好一个 字符得到 t
从 s 中删除 恰好一个 字符得到 t
在 s 中用 一个不同的字符 替换 恰好一个 字符得到 t
 

示例 1：

输入: s = "ab", t = "acb"
输出: true
解释: 可以将 'c' 插入字符串 s 来得到 t。
示例 2:

输入: s = "cab", t = "ad"
输出: false
解释: 无法通过 1 步操作使 s 变为 t。
*/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int slen = s.size(), tlen = t.size();
        int cur = 0, ocur = 0;//一个指向长的字符串，另一个指向短的字符串
        int diff = 0;//两个字符串中不相同字符的个数

        //两字符串相同，只需要遍历两个字符串，判断相同位置上 字符不同的个数
        if(slen == tlen) {
            while(cur < slen) if(s[cur] != t[cur++]) ++diff;
        }
        //差位1情况，将长的设为cur 短的设为ocur 长的一直往右遍历，短的只有字符相同的时候往右遍历
        else if(slen == tlen + 1){
            for(cur = 0; cur < slen; ++cur){
                if(s[cur] != t[ocur]) diff++;
                else ocur++;
            }
        }
        else if(slen + 1 == tlen){
            for(cur = 0; cur < tlen; ++cur){
                if(s[ocur] != t[cur]) diff++;
                else ocur++;
            }
        }
        //长度差大于1直接返回
        else return false;

        //最后判断是不是只有一个不同
        if(diff == 1) return true;
        else return false;
    }
};