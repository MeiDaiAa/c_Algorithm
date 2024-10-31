#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>
#include<cstring>
using namespace std;

/*
对字符串进行 “移位” 的操作：

右移：将字符串中每个字母都变为其在字母表中 后续 的字母，其中用 'a' 替换 'z'。比如，"abc" 能够右移为 "bcd"，"xyz" 能够右移为 "yza"。
左移：将字符串中每个字母都变为其在字母表中 之前 的字母，其中用 'z' 替换 'a'。比如，"bcd" 能够左移为 "abc"，"yza" 能够左移为 "xyz"。
我们可以不断地向两个方向移动字符串，形成 无限的移位序列。

例如，移动 "abc" 来形成序列：... <-> "abc" <-> "bcd" <-> ... <-> "xyz" <-> "yza" <-> ... <-> "zab" <-> "abc" <-> ...
给定一个字符串数组 strings，将属于相同移位序列的所有 strings[i] 进行分组。你可以以 任意顺序 返回答案。
=
示例 1：

输入：strings = ["abc","bcd","acef","xyz","az","ba","a","z"]

输出：[["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
*/

class Solution {
public:
    //vector<vector<string>> groupStrings(vector<string>& strings) {
    //    vector<vector<string>>ret;
    //    int len = strings.size();
    //    bool flag[len];//用flag来存储当前位是否已经存入
    //    memset(flag, true, len);

    //    for (int i = 0; i < len; ++i) {
    //        if (flag[i]) {
    //            unordered_set<string>hash;
    //            string temp = strings[i];
    //            //将所有可能的数都列出插入到表中
    //            for (int j = 0; j < 26; ++j) {
    //                for (int k = 0; k < temp.size(); ++k) temp[k] = 'a' + (strings[i][k] - 'a' + j) % 26;
    //                hash.insert(temp);
    //            }
    //            //将所有与当前相似的字符串都存入
    //            vector<string>retSon;
    //            for (int x = i; x < len; ++x) {
    //                if (flag[x] && hash.count(strings[x]) != 0) {
    //                    retSon.push_back(strings[x]);
    //                    flag[x] = false;
    //                }
    //            }
    //            ret.push_back(retSon);
    //        }
    //    }
    //    return ret;
    //}

    //优化：字符串中将后一位减去前一位的差值存入到一个字符串中，这个字符串当作unordered_map 的key值，value值为差值字符串为当前差值的原字符串
    vector<vector<string>> groupStrings2(vector<string>& strings) {
         unordered_map<string, vector<string>>hash;
         vector<vector<string>>ret;
         int len = strings.size();

         for(auto& s : strings){
             string temp = "";
             for(int i = 0; i < s.size() - 1; ++i){
                 temp += 'a' + (s[i + 1] - s[i] + 26) % 26;
             }
             hash[temp].emplace_back(s);
         }
         for(auto& pair : hash) ret.emplace_back(pair.second);
         return ret;
     }
};
