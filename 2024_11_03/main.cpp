#include "findLonelyPixel.cpp"

int main(){
    Solution sol;

    vector<vector<char>> picture = {
        {'W','W','B'},
        {'W','B','W'},
        {'B','W','W'}
    };
    vector<vector<char>> picture2 = {
        {'B','B','B'},
        {'B','B','W'},
        {'B','B','B'}
    };

    cout << '[' << sol.findLonelyPixel(picture) << ']' << endl;
    cout << '[' << sol.findLonelyPixel(picture2) << ']' << endl;

    return EXIT_SUCCESS;
}