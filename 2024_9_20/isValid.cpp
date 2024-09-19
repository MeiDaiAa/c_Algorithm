#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        stack<char>stack;
        for (int i = 0; i < len; i++) {
            //如果栈为空，就直接入栈
            if (stack.size() == 0) {
                stack.push(s.at(i));
            }
            //如果栈不为空，产看栈顶元素，是否与当前元素相同，
            //如果相同，栈顶元素出栈执行下一次循环，如果不同，就入栈
            else {
                char c = stack.top();
                if (c == '{' || c == '[') {
                    if (c == s.at(i) - 2) {
                        stack.pop();
                    }
                    else {
                        stack.push(s.at(i));
                    }
                }
                else {
                    if (c == s.at(i) - 1) {
                        stack.pop();
                    }
                    else {
                        stack.push(s.at(i));
                    }
                }
            }
        }
        if (stack.size() == 0) return true;
        else return false;
    }
};