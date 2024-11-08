#include "minMeetingRooms.cpp"

int main(){
    vector<vector<int>>intervals = {
        {0,30},
        {5,10},
        {5,20}
    };
    vector<vector<int>>intervals2 = {
        {7,10},
        {2,4}
    };
    Solution sol;

    cout << '[' << sol.minMeetingRooms2(intervals) << ']';
    cout << '[' << sol.minMeetingRooms(intervals) << ']' << endl;

    cout << '[' << sol.minMeetingRooms2(intervals2) << ']';
    cout << '[' << sol.minMeetingRooms(intervals2) << ']' << endl;

    return EXIT_SUCCESS;
}