#include "generateParenthesis.cpp"
/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
*/

int main() {
	int n = 3;
	Solution solution;
	vector <string> ret = solution.generateParenthesis(n);

	for (auto it = ret.begin(); it != ret.end(); it++) {
		cout << (*it) << endl;
	}
	//string str = "123";
	//string temp11 = str.substr(0, 3);
	//string temp12 = str.substr(3, 3);

	//string temp1 = str.substr(0, 1);
	//string temp2 = str.substr(1, 2);
	//string temp3 = str.substr(0, 2);
	//string temp4 = str.substr(2, 3);
	//cout << temp11 << endl;
	//cout << temp12 << endl;
	//cout << endl;
	//cout << temp1 << endl;
	//cout << temp2 << endl;
	//cout << temp3 << endl;
	//cout << temp4 << endl;
	return EXIT_SUCCESS;
}