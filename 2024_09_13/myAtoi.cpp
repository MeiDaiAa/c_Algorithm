#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if (!s.size()) { return 0; }
        int idx = 0;
        long long ret = 0;
        bool flag;
        //先过滤掉前导空格
        while (s.at(idx) == ' '&& idx < s.size()) {
            idx++;
            if (idx == s.size()) { return 0; }
        }

        flag = true;//默认为正
        //然后看是否有正负号 , 并且只需要也只能判断一次
        if (s.at(idx) == '+') {
            idx++;
            if (idx == s.size()) { return 0; }
        }
        else if (s.at(idx) == '-') {
            flag = false;
            idx++;
            if (idx == s.size()) { return 0; }
        }

        //去掉数字前面的零
        while (s.at(idx) == '0') {
            idx++;
            if (idx == s.size()) { return 0; }
        }


        //最后判断是否为数字，是就继续，不是就返回
        while (idx < s.size()) {
            if (s.at(idx) >= '0' && s.at(idx) <= '9') {
                ret = ret * 10 + (s.at(idx) - '0');
                if (ret > 2147483647 && flag == true) {
                    return 2147483647;
                }
                if (ret > 2147483648 && flag == false) {
                    return -2147483648;
                }
                idx++;
            }
            else {
                break;
            }
        }

        return flag == true ? ret : -ret;
    }
};



/////////////////////原来错误的提交代码//////////////////


//class Solution {
//public:
//    int myAtoi(string s) {
//        int idx = 0, isPlus = 1, ret = 0;
// 
//        //重第一位开始，判断字符串，直到idx代表数字退出循环
//        while (idx < s.size()) {
//            //查看字符串的这一位是否为空格
//            if (s.at(idx) == ' ') {
//                //如果是空格，就跳到下一位
//                idx++;
//            }
//            //如果这一位不是空格，看是不是负号
//            else if (s.at(idx) == '-') {
//                isPlus = 0;
//                idx++;
//            }
//            //查看这一位是不是数字或0，如果是数字，直接退出循环进入下一阶段
//            //else if (s.at(idx) - '0' >= 0 || s.at(idx) - '0' <= 9) {
//            else if (s.at(idx) >= '0' && s.at(idx) <= '9') {
//                break;
//            }
//            //如果这一位什么都不是，直接返回
//            else { return ret; }
//        }
//        
//        //从这里开始，idx就指向了字符串中的第一个数字
//        //开始往后读取数字，如果读到不是数字的字符，就直接退出
//
//        //将读取的字符拷贝到新的字符串中
//        string tempStr = "";
//        while (idx < s.size()) {
//            //if ((s.at(idx) - '0') >= '0' || (s.at(idx) - '0') <= '9') {
//            if ((s.at(idx) >= '0' && s.at(idx) <= '9')) {
//
//                tempStr.push_back(s.at(idx++));
//            }
//            else {
//                break;
//            }
//        }
//
//        //判断字符串中的数字大小
//        if (tempStr.size() > 10) {
//            if (isPlus) {
//                return 2147483647;
//            }
//            else {
//                return -2147483648;
//            }
//        }
//
//        //将读取到的字符串转换为数字
//        int multRet = 1;
//        for (int i = tempStr.size() - 1; i >= 0; i--) {
//            ret += (tempStr.at(i) - '0') * multRet;
//            multRet *= 10;
//        }
//
//        return isPlus ? ret : -ret;
//    }
//};