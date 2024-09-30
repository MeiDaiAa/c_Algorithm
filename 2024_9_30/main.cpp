#include "removeElement.cpp"

int main(){
		vector<int>nums = { 3,2,2,3 };

		Solution solution;
		int ret = solution.removeElement(nums, 3);
		cout << "ret=" << ret << endl;
		for (int i = 0; i < ret; i++) {
			cout << nums.at(i) << " ";
		}
		cout << endl;
		return EXIT_SUCCESS;
}