#include "isOneEditDistance.cpp"

int main(){
    Solution Solution;
    string s = "ab", t = "acb";

    if(Solution.isOneEditDistance(s, t)) cout << "true";
    else cout << "false";
    cout << endl;
    return EXIT_SUCCESS;
}