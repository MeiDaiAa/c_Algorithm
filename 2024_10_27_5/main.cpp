#include "canPermutePalindrome.cpp"

int main(){
    Solution sol;

    cout << "code : ";
    if (sol.canPermutePalindrome("code")) cout << "true ";
    else cout << "false "; 
    if (sol.canPermutePalindrome2("code")) cout << "true" << endl;
    else cout << "false" << endl; 

    cout << "aab : ";
    if (sol.canPermutePalindrome("aab")) cout << "true ";
    else cout << "false "; 
    if (sol.canPermutePalindrome2("aab")) cout << "true" << endl;
    else cout << "false" << endl; 

    cout << "carerac : ";
    if (sol.canPermutePalindrome("carerac")) cout << "true ";
    else cout << "false "; 
    if (sol.canPermutePalindrome2("carerac")) cout << "true" << endl;
    else cout << "false" << endl; 

    return EXIT_SUCCESS;
}