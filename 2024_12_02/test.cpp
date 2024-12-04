#include "80_removeDuplicates.cpp"
#include <algorithm>

int main(){
    vector<int>arr = {1,1,1,2,2,3};
    Solution sol;
    cout << "ret:" << sol.removeDuplicates(arr) << endl;;
    
    for_each(arr.begin(), arr.end(), [](int i){cout << i << ' ';});

    return EXIT_SUCCESS;
}
