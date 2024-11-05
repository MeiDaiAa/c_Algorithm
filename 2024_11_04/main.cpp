#include "multiply.cpp"

int main(){
    vector<vector<int>>mat1 = {
        {1,0,0},
        {-1,0,3}
    };
    vector<vector<int>>mat2 = {
    {7,0,0},
    {0,0,0},
    {0,0,1}
    };

    Solution sol;

    vector<vector<int>>ret = sol.multiply(mat1, mat2);
    for(auto& v : ret){
        for(auto& i : v){
            cout << i << ' ';
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}