#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        //非回溯的退出条件，等于 0 直接返回//因为题目要求传入 "" 时返回 空 而非 ""
        //如果一开始传入的字符就等于空的话，就返回空
        if (digits.size() == 0) return {};

        //先创建一个字符串数组存储每个数字代表的字符串
        vector<string>itos = {
            {""},
            {""},
            {"abc"},
            {"def"},
            {"ghi"},
            {"jkl"},
            {"mno"},
            {"pqrs"},
            {"tuv"},
            {"wxyz"}
        };

        vector<string>res;
        string temp;
        //退出条件：传入字符长度为1,返回当前数字所表示的所有字符
        if (digits.size() == 1) {
            for (int i = 0; i < itos[digits.at(0) - '0'].size(); i++) {
                temp = itos[digits.at(0) - '0'].at(i);
                res.push_back(temp);
            }
            return res;
        }
        //回溯
        for (auto& s : letterCombinations(digits.substr(1, digits.size()))) {
            //第一次到这里的时候是len = 2 的时候， 相当于这里传入了最后一个数字表示的几种字符
            //我们需要把这一个数字显示的字符分别拼接到传入字符的前面
            //digits.at(0) - '0'表示当前第一个数字也就是当前需要操作的数字

            //进行每种情况的字符串拼接
            for (int i = 0; i < itos[digits.at(0) - '0'].size(); i++) {
                temp = itos[digits.at(0) - '0'].at(i) + s;

                res.push_back(temp);
            }
        }
        return res;
    }
};