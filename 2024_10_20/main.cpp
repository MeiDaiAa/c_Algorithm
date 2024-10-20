#include "maxDistance.cpp"

int main(){
    Solution solution;

    vector<vector<int>> arrays = {{1,5},{3, 4}};

    cout << "[" << solution.maxDistance(arrays) << "]" << endl;

    return EXIT_SUCCESS;
}