#include <iostream>

using namespace std;

/*
给你两个整数，被除数 dividend 和除数 divisor。将两数相除，要求 不使用 乘法、除法和取余运算。

整数除法应该向零截断，也就是截去（truncate）其小数部分。例如，8.345 将被截断为 8 ，-2.7335 将被截断至 -2 。

返回被除数 dividend 除以除数 divisor 得到的 商 。

注意：假设我们的环境只能存储 32 位 有符号整数，其数值范围是 [−231,  231 − 1] 。本题中，如果商 严格大于 231 − 1 ，则返回 231 − 1 ；如果商 严格小于 -231 ，则返回 -231 。



示例 1:

输入: dividend = 10, divisor = 3
输出: 3
解释: 10/3 = 3.33333.. ，向零截断后得到 3 。
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == -2147483648 && divisor == -1) return 2147483647;
        if (divisor == 1 || divisor == -1) return divisor == 1 ? dividend : -dividend;

        long sor = divisor, dend = dividend, ret = 1;

        bool temp1 = true, temp2 = true;
        if (dividend < 0) {
            temp1 = false;
            dend = -dend;
        }
        if (divisor < 0) {
            temp2 = false;
            sor = -sor;
        }

        if (dend < sor) return 0;
        if (dend == sor) {
            if (temp1 == temp2) return 1;
            else return -1;
        }

        sor *= 2;
        while (sor < dend) {
            sor *= 2;
            ret *= 2;
        }

        if (temp1 == temp2) {
            if (temp2 == true) return ret + divide(dend - (sor >> 1), divisor);
            else return ret + divide(dend - (sor >> 1), -divisor);
        }
        else {
            if (temp2 == true) return -ret + divide(dend - (sor >> 1), -divisor);
            else return -ret + divide(dend - (sor >> 1), divisor);
        }
    }
};

////////////////更新的新的代码//////////////
//解决了不能使用long类型的变量的问题//

class Solution {
public:
    int divide(int dividend, int divisor) {
        //特殊情况处理
        if(dividend == INT_MIN){
            if(divisor == 1) return INT_MIN;
            if(divisor == -1) return INT_MAX;
        }
        if(divisor == INT_MIN) return dividend == INT_MIN ? 1 : 0;
        if(dividend == 0) return 0;

        bool flag = false;

        if((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)) flag = true;  
        /*
        如果我们将被除数和除数都变为正数，那么可能会导致溢出。
        我们可以考虑将被除数和除数都变为负数，这样就不会有溢出的问题，在编码时只需要考虑 1 种情况了。
        */      
        dividend = dividend < 0 ? dividend : -dividend;
        divisor = divisor < 0 ? divisor : -divisor;

        int sor = divisor, num = -1, ans = 0;

        while(divisor >= dividend){
            sor = divisor, num = -1;

            while(sor >= dividend - sor){
                sor <<= 1;
                num <<= 1;
            }
            
            dividend -= sor;
            ans += num;
        }
        return flag ? -ans : ans;
    }
};	