#include "canAttendMeetings.cpp"

int main(){
    vector<vector<int>> intervals = {
        {0,30},
        {5,10},
        {15,20}
    };

    Solution sol;

    if(sol.canAttendMeetings2(intervals)) cout << "true ";
    else cout << "false "; 
    if(sol.canAttendMeetings(intervals)) cout << "true" << endl;
    else cout << "false" << endl;

    vector<vector<int>> intervals2 = {
        {7,10},
        {2,4}
    };
    if(sol.canAttendMeetings2(intervals2)) cout << "true ";
    else cout << "false ";
    if(sol.canAttendMeetings(intervals2)) cout << "true" << endl;
    else cout << "false" << endl;

    return EXIT_SUCCESS;
}