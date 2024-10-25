#include "shortestWay.cpp"

int main(){
    string source = "abc";
    string target = "abcbc";

    Solution solution;

    cout << '[' << solution.shortestWay(source, target) << ']' << endl;

    string target2 = "abdbc";

    cout << '[' << solution.shortestWay(source, target2) << ']' << endl;


    return EXIT_SUCCESS;
}