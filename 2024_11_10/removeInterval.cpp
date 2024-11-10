#include <iostream>
#include <vector>
using namespace std;

/*
实数集合可以表示为若干不相交区间的并集，其中每个区间的形式为 [a, b)（左闭右开），表示满足 a <= x < b 的所有实数  x 的集合。如果某个区间 [a, b) 中包含实数 x ，则称实数 x 在集合中。

给你一个 有序的 不相交区间列表 intervals 。intervals 表示一个实数集合，其中每一项 intervals[i] = [ai, bi] 都表示一个区间 [ai, bi) 。再给你一个要删除的区间 toBeRemoved 。

返回 一组实数，该实数表示intervals 中 删除 了 toBeRemoved 的部分 。换句话说，返回实数集合，并满足集合中的每个实数 x 都在 intervals 中，但不在 toBeRemoved 中。你的答案应该是一个如上所述的 有序的 不相连的间隔列表 。


示例 1：


输入：intervals = [[0,2],[3,4],[5,7]], toBeRemoved = [1,6]
输出：[[0,1],[6,7]]
示例 2：


输入：intervals = [[0,5]], toBeRemoved = [2,3]
输出：[[0,2],[3,5]]
示例 3：

输入：intervals = [[-5,-4],[-3,-2],[1,2],[3,5],[8,9]], toBeRemoved = [-1,4]
输出：[[-5,-4],[-3,-2],[4,5],[8,9]]
*/

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>>res;

        int l = toBeRemoved[0], r = toBeRemoved[1];
        for(const auto& v : intervals){
            if(v[0] < l) res.push_back({v[0], min(l, v[1])});
            if(v[1] > r) res.push_back({max(v[0], r), v[1]});
            
        }
        return res;
    }
    vector<vector<int>> removeInterval2(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>>res;

        for(auto& v : intervals){
            if(v[0] >= toBeRemoved[0] && v[1] <= toBeRemoved[1]) continue;
            else if(v[1] <= toBeRemoved[0] || v[0] >= toBeRemoved[1]) res.push_back(v);
            else if(v[0] <= toBeRemoved[0] && v[1] <= toBeRemoved[1]) res.push_back({v[0], toBeRemoved[0]});
            else if(v[0] >= toBeRemoved[0] && v[1] >= toBeRemoved[1]) res.push_back({toBeRemoved[1], v[1]});
            else {
                res.push_back({v[0], toBeRemoved[0]});
                res.push_back({toBeRemoved[1], v[1]});
            }
        }
        return res;
    }
    vector<vector<int>> removeInterval3(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>>res;

        for(auto& v : intervals){
            if(v[1] <= toBeRemoved[0] || v[0] >= toBeRemoved[1]) res.push_back(v);
            else{
                if(v[0] < toBeRemoved[0]) res.push_back({v[0], toBeRemoved[0]});
                if(v[1] > toBeRemoved[1]) res.push_back({toBeRemoved[1], v[1]});
            }
        }
        return res;
    }
};