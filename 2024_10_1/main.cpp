#include "strStr.cpp"

int main() {
	string haystack = "sadbutsad", needle = "sad";
	Solution solution;
	cout << "at:" << solution.strStr(haystack, needle);
	return EXIT_SUCCESS;
}