#include "anagramMappings.cpp"

int main(){
    vector<int> nums1 = {12,28,46,32,50};
    vector<int> nums2 = {50,12,32,46,28};

    Solution sol;

    vector<int> ret = sol.anagramMappings(nums1, nums2);


    cout << "[ ";
    for(auto i : ret) cout << i << ' ';
    cout << ']';

    return EXIT_SUCCESS;
}