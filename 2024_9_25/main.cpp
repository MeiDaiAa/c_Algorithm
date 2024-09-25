#include "fourSum.cpp"

int main() {
	vector<int> nums = { -3,-1,0,2,4,5 };
	Solution solution;

	vector<vector<int>>ret = solution.fourSum(nums, 2);
	
	for (auto& s : ret) {
		for (auto& ss : s) {
			cout << ss << " ";
		}
		cout << endl;
	}

	return EXIT_SUCCESS;
}