#include "stringShift.cpp"

int main(){
    Solution Solution;

    //case_1
    string s = "abc";
    vector<vector<int>> shift = {{0, 1}, {1, 2}};
    
    cout << '[' << s << ']' << endl;
    cout << '[' << Solution.stringShift(s, shift) << ']' << endl;
    //case_2
    s = "leetcode";
    shift = {{0, 10}};
    
    cout << '[' << s << ']' << endl;
    cout << '[' << Solution.stringShift(s, shift) << ']' << endl;


    return EXIT_SUCCESS;
}