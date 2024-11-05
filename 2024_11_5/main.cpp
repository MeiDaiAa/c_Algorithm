#include "findMissingRanges.cpp"

int main(){
    vector<int> nums = {0, 1, 3, 50, 75};
    Solution sol;

    vector<vector<int>> ret = sol.findMissingRanges(nums, 0, 99);
    for(auto& v : ret){
        for(auto& i : v){
            cout << i << ' ';
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}