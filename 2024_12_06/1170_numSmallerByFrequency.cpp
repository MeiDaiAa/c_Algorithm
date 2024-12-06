class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n1 = queries.size(), n2 = words.size();
        vector<int>que = findMinCnt(queries);
        vector<int>wor = findMinCnt(words);
        
        ranges::sort(wor);
        vector<int>ret(n1);

        for(int i = 0; i < n1; ++i){
            ret[i] = n2 - (lower_bound(wor.begin(), wor.end(), que[i] + 1) - wor.begin());
        }
        return ret;
    }
    vector<int> findMinCnt(vector<string>& strs){
        int n = strs.size();
        vector<int> sum(n);

        for(int i = 0; i < n; ++i){
            // map<char, int>memo;
            // for(auto c : strs[i]) memo[c]++;
            // sum[i] = memo.begin()->second;
            sum[i] = count(strs[i].begin(), strs[i].end(), *min_element(strs[i].begin(), strs[i].end()));//查询最小值的数量
        }
        return sum;
    }
};
//时间复杂度:O(nlong(n)) 将字符串数组转换成数组为O(n * m) ,查找值为O(nlong(n))
//空间复杂度:O(n)