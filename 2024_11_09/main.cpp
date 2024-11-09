#include "addBoldTag.cpp"

int main(){
    string s = "abcxyz123";
    string s2 = "aaabbb";
    vector<string>words = {
        "abc",
        "123"
    };
    vector<string>words2 = {
        "aa",
        "b"
    };
    Solution sol;

    cout << '[' << sol.addBoldTag(s, words) << ']' << endl;
    cout << '[' << sol.addBoldTag(s2, words2) << ']' << endl;

    return EXIT_SUCCESS;
}