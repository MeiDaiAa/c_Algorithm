#include "minTimeToReach.cpp"

int main(){
    vector<vector<int>> moveTime = {
        {0,4},
        {4,4}
    };
    vector<vector<int>> moveTime2 = {
        {0,0,0},
        {0,0,0}
    };

    Solution sol;

    cout << '[' << sol.minTimeToReach(moveTime) << ']' << endl;
    cout << '[' << sol.minTimeToReach(moveTime2) << ']' << endl;

    return EXIT_SUCCESS;
}