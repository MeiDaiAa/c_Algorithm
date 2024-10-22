#include "reverse.cpp"

/*
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。
*/
int main() {
	Solution solution;
	int x = -123;
		
	cout << solution.reverse(x) << endl;

	return EXIT_SUCCESS;
}