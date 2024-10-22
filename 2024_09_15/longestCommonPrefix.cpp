#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) { return ""; }
        if (strs.size() == 1 ) { return strs.at(0); }

        string ret = "";

        //算出字符串数组中最短的字符串的长度
        int l = strs.at(0).size();
        for (vector<string>::iterator it = strs.begin() + 1; it < strs.end(); it++) {
            l = l < (*it).size() ? l : (*it).size();
        }//如果最短长度为0，直接返回
        if (l == 0) { return ""; }

        //创建指向字符串的下标
        int idx = 0;
        //创建第几个字符串的下标
        while (idx < l) {
            //将c等于第一个字符串数组的下标
            char c = strs.at(0).at(idx);
            //遍历其他几个字符串的同一个下标，查看是否相等
            for (int i = 1; i < strs.size(); i++) {
                //如果不相等，就直接返回
                if (c != strs.at(i).at(idx)) { return ret; }
            }
            //如果相等， 就将这个一个字符存入到ret中
            ret.push_back(c);
            //idx++ 继续执行下一个判断
            idx++;
        }
        return ret;
    }
};