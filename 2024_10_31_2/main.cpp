#include "largestUniqueNumber.cpp"

int main(){
    Solution sol;

    vector<int>nums = {5,7,3,9,4,9,8,3,1};
    cout << '[' << sol.largestUniqueNumber(nums) << ']' << endl;

    vector<int>nums2 = {9,9,8,8};
    cout << '[' << sol.largestUniqueNumber(nums2) << ']' << endl;

    return EXIT_SUCCESS;
}

