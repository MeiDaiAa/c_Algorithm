#include "removeDuplicates.cpp"

int main() {
	vector<int>nums = { 1,1,2,2,3,3,4,4,5,5,6 };

	Solution solution;
	int ret = solution.removeDuplicates(nums);
	cout << "ret=" << ret << endl;
	for (int i = 0; i < ret; i++) {
		cout << nums.at(i) << " ";
	}
	cout << endl;
	return EXIT_SUCCESS;
}