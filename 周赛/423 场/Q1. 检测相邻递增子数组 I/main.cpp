#include "hasIncreasingSubarrays.cpp"

int main(){
    vector<int> nums = {2,5,7,8,9,2,3,4,3,1};

    Solution sol;

    cout << '[' << sol.hasIncreasingSubarrays(nums, 3) << ']' << endl;

    return EXIT_SUCCESS;
}