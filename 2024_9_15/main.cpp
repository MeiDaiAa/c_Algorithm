#include "longestCommonPrefix.cpp"
int main() {
	vector<string>str = {
		{"abc"},
		{"abc"},
		{""}
	};

	Solution solution;
	string ret = solution.longestCommonPrefix(str);
	for (int i = 0; i < ret.size(); i++) {
		cout << ret.at(i);
	}
	cout << endl;
	return EXIT_SUCCESS;
}