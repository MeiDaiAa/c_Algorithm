#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ret;
        int len = s.size();

        //创建一个二位的bool数组，来存储左节点到右节点这一段子字符串是否为回文串， 先初始化为false
        vector<vector<bool>>flag(len, vector<bool>(len, false));
        //测试
        //for (auto it = flag.begin(); it != flag.end(); it++) {
        //    for (auto ite = (*it).begin(); ite != (*it).end(); ite++) {
        //        cout << (*ite) << " ";
        //    }
        //    cout << endl;
        //}
        //创建字串的左节点和当前子字符串的长度
        int L = 0, sum = 1;
        //长度为1的子字符串字符串肯定为回文串，所以把该坐标的bool数组改为true
        for (int i = 0; i < len; i++) {
            flag[i][i] = true;
        }
        //开始枚举子字符串
        //外层循环因该是字符串的长度
        //内层循环应该是字符串的左下标
        //这样才能正确枚举

        //长度从2开始判断
        for (int n = 2; n <= len; n++) {
            //坐标从最左侧开始遍历到最右侧
            for (int left = 0; left < len; left++) {
                //先计算出右坐标
                int right = left + n - 1;
                //如果右节点超出，那么可以直接跳出当前循环，而不是将右节点变为末尾，因为这种情况已经判断过了
                if (right >= len) break;
                //如果改左节点不等于右节点， 那么必然不是回文串，直接跳过
                if (s.at(left) != s.at(right)) continue;
                //如果除去两节点的中间字符串不是回文串，那么也必定不是回文串 
                //flag[i + 1][j - 1]，如果i= 0j = 0 的时候取出flag会导致数据访问越界，所以要加判定条件
                if ((n > 2) && flag[left + 1][right - 1] == false) continue;

                //到这一步，表示字符串从下标i到j是一个回文串
                // 记录该回文串到bool数组中
                flag[left][right] = true;

                ////如果这一个回文串的长度大于记录的回文串， 那么就更新返回回文串
                //if (n > sum) {
                //    L = left;
                //    sum = n;
                //}

                //由于我们所判定的长度是越来越大的，所以我们现在判定的字符串一定是大于等于我么所记录的字符串的
                //所以我们可以直接更新返回的参数
                L = left;
                sum = n;
            }
        }
        return s.substr(L, sum);
    }
};