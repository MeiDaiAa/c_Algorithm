#include <iostream>
#include <vector>

using namespace std;

/*
给定一个数字 N，当它满足以下条件的时候返回 true：

原数字旋转 180° 以后可以得到新的数字。

如 0, 1, 6, 8, 9 旋转 180° 以后，得到了新的数字 0, 1, 9, 8, 6 。

2, 3, 4, 5, 7 旋转 180° 后，得到的不是数字。

易混淆数 (confusing number) 在旋转180°以后，可以得到和原来不同的数，且新数字的每一位都是有效的。

 

示例 1：
输入：6
输出：true
解释： 
把 6 旋转 180° 以后得到 9，9 是有效数字且 9!=6 。
*/

class Solution {
public:
    bool confusingNumber(int n) {
        vector<int>can = {0, 1, 6, 8, 9};
        vector<int>cant = {2, 3, 4, 5, 7};
        vector<int>ret;
        int after = 0, root = 1;
        int before = n;

        while(n > 0){
            int temp = n % 10;
            for(auto i : cant) if(temp == i) return false;
            for(auto i : can) if(temp == i) {
                switch(i){
                    case 6:
                        ret.push_back(9);
                        break;
                    case 9:
                        ret.push_back(6);
                        break;
                    default:
                        ret.push_back(i);
                }
                root *= 10;
            }
            n /= 10;
        }

        for(auto i : ret) after += i * (root /= 10);
        if(after == before) return false;
        return true;
    }


    //////////代码优化
    bool confusingNumber2(int n) {
        vector<int>can = {0, 1, 6, 8, 9};
        vector<int>cant = {2, 3, 4, 5, 7};

        int before = n, after = 0;

        while(n > 0){
            int temp = n % 10;
            for(auto i : cant) if(temp == i) return false;
            for(auto i : can) if(temp == i) {
                switch(i){
                    case 6:
                        after = after * 10 + 9;
                        break;
                    case 9:
                        after = after * 10 + 6;
                        break;
                    default:
                        after = after * 10 + i;
                }
            }
            n /= 10;
        }
        return after != before;
    }
};