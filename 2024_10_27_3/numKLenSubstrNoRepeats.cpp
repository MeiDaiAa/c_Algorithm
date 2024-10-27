#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
给你一个字符串 S，找出所有长度为 K 且不含重复字符的子串，请你返回全部满足要求的子串的 数目。

示例 1：

输入：S = "havefunonleetcode", K = 5
输出：6
解释：
这里有 6 个满足题意的子串，分别是：'havef','avefu','vefun','efuno','etcod','tcode'。
示例 2：

输入：S = "home", K = 5
输出：0
解释：
注意：K 可能会大于 S 的长度。在这种情况下，就无法找到任何长度为 K 的子串。
*/

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int len = s.size();
        if(len < k) return 0;

        int left = 0, right = 0, alphNum = 1, ret = 0;
        unordered_map<char, int>alph;

        while(right < len){
            if(++alph[s[right]] != 1){
                while(s[left] != s[right]) --alph[s[left]], ++left, --alphNum;
                --alph[s[left]], ++left, --alphNum;
            }
            if(alphNum == k){
                ++ret;
                --alph[s[left]], ++left;
                --alphNum;
            } 
            ++right;
            ++alphNum;
        }
        return ret;
    }
};


