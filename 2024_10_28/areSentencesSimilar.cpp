#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

/*
我们可以将一个句子表示为一个单词数组，例如，句子 "I am happy with leetcode" 可以表示为 arr = ["I","am",happy","with","leetcode"]

给定两个句子 sentence1 和 sentence2 分别表示为一个字符串数组，并给定一个字符串对 similarPairs ，其中 similarPairs[i] = [xi, yi] 表示两个单词 xi and yi 是相似的。

如果 sentence1 和 sentence2 相似则返回 true ，如果不相似则返回 false 。

两个句子是相似的，如果:

它们具有 相同的长度 (即相同的字数)
sentence1[i] 和 sentence2[i] 是相似的
请注意，一个词总是与它自己相似，也请注意，相似关系是不可传递的。例如，如果单词 a 和 b 是相似的，单词 b 和 c 也是相似的，那么 a 和 c  不一定相似 。

示例 1:

输入: sentence1 = ["great","acting","skills"], sentence2 = ["fine","drama","talent"], similarPairs = [["great","fine"],["drama","acting"],["skills","talent"]]
输出: true
解释: 这两个句子长度相同，每个单词都相似。
*/
class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int len1 = sentence1.size(), len2 = sentence2.size();
        if(len1 != len2) return false;

        unordered_set<string> hash;

        for(auto& v : similarPairs) hash.emplace(v[0] + "+" + v[1]);

        for(int i = 0; i < len1; ++i){
            if(sentence1[i] != sentence2[i] &&
                !hash.count(sentence1[i] + "+" + sentence2[i]) &&
                !hash.count(sentence2[i] + "+" + sentence1[i])) return false;
        }
        return true;
    }
};