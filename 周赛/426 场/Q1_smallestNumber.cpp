#include <iostream>
class Solution {
public:
    int smallestNumber(int n) {
        int len = 0;
        while(n != 0){
            n /= 2;
            len++;
        }
        return (1 << len) - 1;
    }
};
//时间复杂度:O(logn)  判断了n有多少位
//空间复杂度:O(1)

class Solution {
public:
    int smallestNumber(int n) {
        return (1 << (int)(log2(n) + 1) ) - 1;
    }
};
//时间复杂度&空间复杂度:O(1)