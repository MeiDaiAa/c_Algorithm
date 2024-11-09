#include <string>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/*
给定字符串 s 和字符串数组 words。

对于 s 内部的子字符串，若其存在于 words 数组中， 则通过添加闭合的粗体标签 <b> 和 </b> 进行加粗标记。

如果两个这样的子字符串重叠，你应该仅使用一对闭合的粗体标签将它们包围起来。
如果被粗体标签包围的两个子字符串是连续的，你应该将它们合并。
返回添加加粗标签后的字符串 s 。

示例 1：

输入： s = "abcxyz123", words = ["abc","123"]
输出："<b>abc</b>xyz<b>123</b>"
解释：两个单词字符串是 s 的子字符串，如下所示: "abcxyz123"。
我们在每个子字符串之前添加<b>，在每个子字符串之后添加</b>。
示例 2：

输入：s = "aaabbb", words = ["aa","b"]
输出："<b>aaabbb</b>"
解释：
"aa"作为子字符串出现了两次: "aaabbb" 和 "aaabbb"。
"b"作为子字符串出现了三次: "aaabbb"、"aaabbb" 和 "aaabbb"。
我们在每个子字符串之前添加<b>，在每个子字符串之后添加</b>: "<b>a<b>a</b>a</b><b>b</b><b>b</b><b>b</b>"。
由于前两个<b>重叠，把它们合并得到: "<b>aaa</b><b>b</b><b>b</b><b>b</b>"。
由于现在这四个<b>是连续的，把它们合并得到: "<b>aaabbb</b>"。
*/

class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        bool mask[s.size()];
        memset(mask, false, sizeof(mask));

        for(auto& str : words){
            int cur = 0;
            while((cur = s.find(str, cur) ) != string::npos){
                for(int j = 0; j < str.size(); ++j) mask[cur + j] = true;
                ++cur;
            }
        }
        string ret;
        for(int i = 0; i < s.size(); ++i){
            if(mask[i]){
                ret += "<b>";
                while(i < s.size() && mask[i]){
                    ret += s[i];
                    ++i;
                }
                --i;
                ret += "</b>";
            }
            else ret += s[i];
        }
        return ret;
    }
};