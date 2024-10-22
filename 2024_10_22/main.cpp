#include "confusingNumber.cpp"

int main(){
    Solution solution;
    if(solution.confusingNumber(66)) cout << "is confusingNumber" << endl;
    else cout << "is not confusingNumber" << endl; 

    if(solution.confusingNumber2(99)) cout << "is confusingNumber" << endl;
    else cout << "is not confusingNumber" << endl; 

    return EXIT_SUCCESS;
}