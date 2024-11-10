#include "maxIncreasingSubarrays.cpp"

int main(){
    vector<int> nums = {2,5,7,8,9,2,3,4,3,1};

    Solution sol;

    cout << '[' << sol.maxIncreasingSubarrays(nums) << ']' << endl;

    return EXIT_SUCCESS;
}