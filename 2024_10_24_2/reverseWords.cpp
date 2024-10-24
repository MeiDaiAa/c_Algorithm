#include <iostream>
#include <vector>

using namespace std;

/*
给你一个字符数组 s ，反转其中 单词 的顺序。

单词 的定义为：单词是一个由非空格字符组成的序列。s 中的单词将会由单个空格分隔。

必须设计并实现 原地 解法来解决此问题，即不分配额外的空间。

示例 1：

输入：s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
输出：["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
*/

class Solution {
public:
    void reverseWords(vector<char>& s) {
        int len = s.size();
        //先将字符串翻转， 这样字符串的单词就倒过来了，然后在将每一个单词翻转过来
        int left = 0, right = len - 1;
        //字符串翻转
        while(left < right) swap(s[left++], s[right--]);

        left = 0;
        for(int cur = 0; cur < len; ++cur){
            if(s[cur] == ' '){
                //单词翻转
                right = cur - 1;
                while(left < right) swap(s[left++], s[right--]);
                //重置left的位置为下一个单词的首位
                left = cur + 1;
            }
        }
        //处理最后一个单词
        right = len - 1;
        while(left < right) swap(s[left++], s[right--]);
    }
};