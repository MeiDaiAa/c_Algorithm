#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

/*
给你一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间 intervals[i] = [starti, endi] ，返回 所需会议室的最小数量 。

示例 1：

输入：intervals = [[0,30],[5,10],[15,20]]
输出：2
示例 2：

输入：intervals = [[7,10],[2,4]]
输出：1
*/

class Solution {
public:
    //上下车
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;

        vector<vector<int>>vec;
        for(auto& v : intervals){
            vec.push_back({v[0], 1});
            vec.push_back({v[1], -1});
        }
        int maxRoom = 0, ret = 0;
        sort(vec.begin(), vec.end());
        for(auto& v : vec){
            maxRoom += v[1];
            ret = max(maxRoom, ret);
        }
        return ret;
    }
    //使用最小堆优先队列
    int minMeetingRooms2(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        int ret = 0;

        pq.emplace(intervals[0][1]);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= pq.top()) pq.pop();

            pq.emplace(intervals[i][1]);
        }
        return pq.size();
    }
};