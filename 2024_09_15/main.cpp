#include "longestCommonPrefix.cpp"
/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
*/
int main() {
	vector<string>str = {
		{"abc"},
		{"abc"},
		{"abb"}
	};

	Solution solution;
	string ret = solution.longestCommonPrefix(str);
	for (int i = 0; i < ret.size(); i++) {
		cout << ret.at(i);
	}
	cout << endl;
	return EXIT_SUCCESS;
}
