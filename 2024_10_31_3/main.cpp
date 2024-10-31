#include "countElements.cpp"

int main(){
    Solution sol;
    vector<int>arr = {1,2,3};
    vector<int>arr2 = {1,1,3,3,5,5,7,7};

    cout << '[' << sol.countElements(arr) << ']';
    cout << '[' << sol.countElements2(arr) << ']' << endl;
    cout << '[' << sol.countElements(arr2) << ']';
    cout << '[' << sol.countElements2(arr2) << ']' << endl;
}