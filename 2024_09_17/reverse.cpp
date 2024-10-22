#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == -2147483648)return 0;
        int num = x;
        //记录整数的正负情况
        bool isPlus = true;
        //如果为负数，转为正数//特殊情况：-2147483648 不能转换成 2147483648
        if (x < 0) {
            num = -num;
            isPlus = false;
        }
        //设计一个数组存入10位数
        int nums[10] = { 0 };
        //记录下标
        int idx = 0;
        //记录整数的长度//ret即可表示
        //int sum = 1;
        //将传入的数存入数组中
        while (num / 10 != 0) {
            nums[idx++] = num % 10;
            num /= 10;
            //sum++;
        }
        nums[idx] = num;

        long ret = 0;
        long mult = 1;
        //逆向遍历字符串到ret中
        for (int i = idx; i >= 0; i--) {
            ret += nums[i] * mult;
            mult *= 10;
            if (ret > 2147483647) {
                return 0;
            }
        }
        return isPlus == true ? ret : -ret;
    }
};