#include "longestPalindrome.cpp"

/*
给你一个字符串 s，找到 s 中最长的回文子串。
*/
int main() {
	string str = "cbcbc";
	Solution solution;
	string ret = solution.longestPalindrome(str);
	for (int i = 0; i < ret.size(); i++) {
		cout << ret.at(i);
	}
	cout << endl;
	return EXIT_SUCCESS;
}