#include "wiggleSort.cpp"

int main(){
    vector<int> nums = {3, 5, 2, 1, 6, 4};

    Solution solution;
    solution.wiggleSort(nums);

    cout << "[ ";
    for(auto i : nums){
        cout << i << " ";
    }
    cout << "]" << endl;

        solution.wiggleSort2(nums);
    
    cout << "[ ";
    for(auto i : nums){
        cout << i << " ";
    }
    cout << "]" << endl;

        solution.wiggleSort3(nums);
    
    cout << "[ ";
    for(auto i : nums){
        cout << i << " ";
    }
    cout << "]" << endl;

        solution.wiggleSort4(nums);
    
    cout << "[ ";
    for(auto i : nums){
        cout << i << " ";
    }
    cout << "]" << endl;

    return EXIT_SUCCESS;
}