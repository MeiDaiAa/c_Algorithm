#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/*
给你一个字符串 s 和一个整数 k ，请你找出 至多 包含 k 个 不同 字符的最长
子串
，并返回该子串的长度。

示例 1：

输入：s = "eceba", k = 2
输出：3
解释：满足题目要求的子串是 "ece" ，长度为 3 。
示例 2：

输入：s = "aa", k = 1
输出：2
解释：满足题目要求的子串是 "aa" ，长度为 2 。
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int len = s.size();
        if(k > len) return len;
        if(k == 0) return 0;

        unordered_map<char, int>alph;
        int left = 0, right = 0, ret = 1;
        int alphNum = 0;

        while(right < len){
            if(++alph[s[right]] == 1) ++alphNum;

            while(alphNum > k) if(--alph[s[left++]] == 0) --alphNum;

            ret = max(ret, right++ - left + 1);
        }
        return ret;
    }
};