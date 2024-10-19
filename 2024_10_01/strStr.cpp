#include <iostream>
#include <string>
using namespace std;

/*
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int cur = 0, next = cur, i = 0;
        while (cur < haystack.size()) {
            if (haystack[cur] == needle[0]) {
                for (i = 0; i < needle.size(); i++) {
                    if ((cur + i) == haystack.size()) return -1;
                    if (haystack[cur + i] != needle[i]) break;
                }
                if (i == needle.size()) return cur;
            }
            cur++;
        }
        return -1;
    }
};