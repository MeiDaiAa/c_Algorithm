#include "groupStrings.cpp"

int main(){
    vector<string>strings = {"abc","bcd","acef","xyz","az","ba","a","z"};
    Solution solution;
    vector<vector<string>>emp=solution.groupStrings2(strings);

    for(auto& v : emp){
        for(auto& s : v){
            cout << s << ' ';
        }
        cout << endl;
    }


    return EXIT_SUCCESS;
}