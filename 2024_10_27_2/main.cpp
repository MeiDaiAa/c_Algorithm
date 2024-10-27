#include "findMaxConsecutiveOnes.cpp"

int main(){
    vector<int>nums = {1,0,1,1,0};
    vector<int>nums2 = {1,0,1,1,0,1};
    vector<int>nums3 = {0,0,0,0};

    Solution solution;

    cout << '[' <<solution.findMaxConsecutiveOnes(nums) << ']' << endl;
    cout << '[' <<solution.findMaxConsecutiveOnes(nums2) << ']' << endl;
    cout << '[' <<solution.findMaxConsecutiveOnes(nums3) << ']' << endl;

    return EXIT_SUCCESS;
}