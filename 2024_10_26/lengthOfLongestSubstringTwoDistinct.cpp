#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/*
给你一个字符串 s ，请你找出 至多 包含 两个不同字符 的最长
子串
，并返回该子串的长度。

示例 1：

输入：s = "eceba"
输出：3
解释：满足题目要求的子串是 "ece" ，长度为 3 。
示例 2：

输入：s = "ccaabbb"
输出：5
解释：满足题目要求的子串是 "aabbb" ，长度为 5 。
*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int len = s.size();
        int left = 0, right = 0;
        unordered_map<char, int>alph;
        int num = 0, ret = 1;//num表示有几个不同的单词， ret表示一共有几个单词

        while(right < len){     
            if(++alph[s[right]] == 1) ++num;

            while(num > 2) if(--alph[s[left++]] == 0) --num;
            
            ret = max(ret, right++ - left + 1);
        }
        return ret;
    }
};