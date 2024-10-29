#include "calculateTime.cpp"

int main(){
    Solution sol;

    cout << '[' << sol.calculateTime("abcdefghijklmnopqrstuvwxyz", "cba") << ']' << endl;
    cout << '[' << sol.calculateTime("pqrstuvwxyzabcdefghijklmno", "leetcode") << ']' << endl;

    return EXIT_SUCCESS;
}