#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


/// <summary>
/// 回调函数直接字符串插入
/// </summary>
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 1)
            return { "()" };
        // 生成的字符串的长度一定是2n(n对左右括号）
        // 生成返回字符串数组
        vector<string> res;
        unordered_map<string, int> hash;

        // 接下来处理n>=2的情况
        // 当n = 2 的时候，其实就是将一对括号插入到（）的中间和两边的情况，
        // 所以当n = 3 的时候，就是将一对括号插入到n = 2的所有情况下找缝隙插入
        string tmp;
        for (auto& s : generateParenthesis(n - 1)) {
            // 如果n = 2 此时s = “()”
            // 我们就可以设计一个字符串将一对（）与原来的字符串进行拼接
            //2 * (n - 1) 为带拼接字符串的长度，即上一个返回字符串的长度
            for (int i = 0; i < 2 * (n - 1); i++) {
                tmp = s.substr(0, i) + "()" + s.substr(i, 2 * (n - 1));
                // 拼接完后，虽然拼接的位置不同但是我们得到的拼接字符串整体可能与之前的相同
                // 这时我们可一创建一个哈希表将之前没有出现过字符串存入到哈希表中
                if (!hash[tmp]) {
                    // 记录当前的字符串
                    hash[tmp]++;
                    // 因为没有出现过，所以将当前的字符串输出到res中
                    res.emplace_back(tmp);//res.emplace_back(tmp)会比res.push_back更快
                }
            }
        }
        return res;
    }
};

/// <summary>
/// 回溯算法
/// </summary>
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        back(str, n, n);
        return res;
    }
private:
    vector<string>res;
    //定义回溯函数, str保存拼接字符串， left，right 分别保存左括号和右括号还剩多少, len表示当前字符串有多长（进入多少层循环）
    void back(string& str, int left, int right) {
        //退出条件：右括号等于0(左右括号都匹配成功）
        if (right == 0) {
            res.emplace_back(str);
            return;
        }

        //优先往字符串内插入左括号
        if (left > 0) {
            str.push_back('(');
            back(str, left - 1, right);
            //第一种情况跑完后，函数将返回到这里，此时str中的值为“(((”
            str.pop_back();
        }
        if (right > left) {
            str.push_back(')');
            back(str, left, right - 1);
            //到这里表示上一个back已经退出，此时函数将返回到最后一个出现左括号的情况，然后将最后一个左括号改为右括号
            str.pop_back();
        }
    }
};