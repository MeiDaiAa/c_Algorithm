#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


/*
给你一个字符串 s ，如果该字符串的某个排列是 
回文串
 ，则返回 true ；否则，返回 false 。
示例 1：

输入：s = "code"
输出：false
示例 2：

输入：s = "aab"
输出：true
示例 3：

输入：s = "carerac"
输出：true
*/
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int len = s.size();
        if(len == 1) return true;
        else if(len == 2) return s[0] == s[1];

        vector<int> alph(26);

        for(int i = 0; i < len; ++i) ++alph[s[i] - 'a'];

        int num = 0;
        for(int i = 0; i < 26; ++i){
            if(alph[i] % 2 == 1) ++num;
            if(num > 1) return false;
        }

        return true;
    }
    /////优化
        bool canPermutePalindrome2(string s) {
        vector<int> alph(26);

        for(auto c : s) ++alph[c - 'a'];

        return count_if(alph.begin(), alph.end(), [](int i){return i & 1;}) < 2;
    }
};