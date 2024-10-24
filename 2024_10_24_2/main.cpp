#include "reverseWords.cpp"

int main(){
    vector<char> s = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};

    cout << '[' << ' ';
    for(auto i : s) cout << i << ' ';
    cout << ']' << endl;
    
    Solution solution;
    solution.reverseWords(s);

    cout << '[' << ' ';
    for(auto i : s) cout << i << ' ';
    cout << ']' << endl;
    
    return EXIT_SUCCESS;
}