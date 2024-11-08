#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
给定一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间 intervals[i] = [starti, endi] ，请你判断一个人是否能够参加这里面的全部会议。

示例 1：

输入：intervals = [[0,30],[5,10],[15,20]]
输出：false
示例 2：

输入：intervals = [[7,10],[2,4]]
输出：true
*/

class Solution {
public:
//数组表示
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int maxTime = 0;
        for(int i = 0; i < intervals.size(); ++i){
            if(intervals[i].back() > maxTime) maxTime = intervals[i].back();
        }
        vector<int>time(maxTime);

        for(auto& v : intervals){
            for(int i = v[0]; i < v[1]; ++i){
                if(++time[i] == 2) return false;
            }
        }
        return true;
    }
    //排序后检查
    bool canAttendMeetings2(vector<vector<int>>& intervals) {
        if(intervals.empty()) return true;

        sort(intervals.begin(), intervals.end(), [&](vector<int>& x, vector<int>& y){
                return x[0] < y[0];
            });

        for(int i = 0; i < intervals.size() - 1; ++i){
            if(intervals[i][1] > intervals[i+1][0]) return false;
        }
        return true;
    }
};