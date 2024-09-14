#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) { return false; }
        //将数字存入到字符串中
        string str;
        //创建副本变量，用于后续修改
        int num = x;

        //当 num 不为 0 的时候一直执行循环
        while (num != 0) {
            //将 num 的最后一位数存入到字符串中
            str.push_back(num % 10 + '0');
            //num = num - num % 10;
            //直接 /10 可以变相删除 num 的最后一位
            num /= 10;
        }
        
        //创建两个变量，指向字符串的左右两个端点
        int L = 0, R = str.size() - 1;
        while (L <= R) {
            //如果左端点的数不等于右端点的数，就直接返回 false
            if (str.at(L) != str.at(R)) { return false; }

            //两个端点向内靠
            L++;
            R--;
        }
        //如果都相等，就返回 true
        return true;
    }
};