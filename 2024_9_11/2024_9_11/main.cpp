#include <iostream>
#include "addTwoNumbers.cpp"

using namespace std;

/*
 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

*/

//struct ListNode {
//	int val;
//	ListNode* next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode* next) : val(x), next(next) {}
//};


int main(void)
{
	ListNode* phead1 = new ListNode;
	ListNode* node1 = new ListNode(2);
	ListNode* node2 = new ListNode(4);
	ListNode* node3 = new ListNode(3);

	//创建链接
	phead1->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	//遍历一遍
	//ListNode* current = phead1->next;
	//while (current != NULL) {
	//	cout << current->val << " ";

	//	current = current->next;
	//}

	ListNode* phead2 = new ListNode;
	ListNode* node21 = new ListNode(5);
	ListNode* node22 = new ListNode(6);
	ListNode* node23 = new ListNode(4);

	//创建链接
	phead2->next = node21;
	node21->next = node22;
	node22->next = node23;
	node23->next = NULL;

	//ListNode* current = phead2->next;
	//while (current != NULL) {
	//	cout << current->val << " ";

	//	current = current->next;
	//}

	///////////////////测试//////////////////

	Solution solution;
	ListNode* test = solution.addTwoNumbers(phead1->next, phead2->next);

	while (test) {
		cout << test->val << " ";
		test = test->next;
	}
		


	return EXIT_SUCCESS;
}