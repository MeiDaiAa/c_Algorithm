#include "letterCombinations.cpp"

int main(void) {
	Solution solution;
	vector<string>res;
	string num = "23";

	res = solution.letterCombinations(num);

	for (auto& s : res) {
		cout << s << " ";
	}
	cout << endl;

	return EXIT_SUCCESS;
}