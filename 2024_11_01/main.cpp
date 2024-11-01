#include "smallestCommonElement.cpp"

int main(){
    vector<vector<int>>map = {
        {1,2,3,4,5},
        {2,4,5,8,10},
        {3,5,7,9,11},
        {1,3,5,7,9}
    };

    Solution sol;

    cout << '[' << sol.smallestCommonElement(map) << ']' << endl;
    cout << '[' << sol.smallestCommonElement2(map) << ']' << endl;
    cout << '[' << sol.smallestCommonElement3(map) << ']' << endl;
    cout << '[' << sol.smallestCommonElement4(map) << ']' << endl;

    return EXIT_SUCCESS;
}