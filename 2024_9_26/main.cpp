#include "mergeKLists.cpp"

int main() {
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(4);
	ListNode* l3 = new ListNode(5);
	ListNode* l4 = new ListNode(1);
	ListNode* l5 = new ListNode(3);
	ListNode* l6 = new ListNode(4);
	ListNode* l7 = new ListNode(2);
	ListNode* l8 = new ListNode(6);

	l1->next = l2;
	l2->next = l3;
	l3->next = NULL;
	l4->next = l5;
	l5->next = l6;
	l6->next = NULL;
	l7->next = l8;
	l8->next = NULL;

	vector<ListNode*>list = { {l1}, {l4}, {l7} };

	Solution solution;

	ListNode* ret = solution.mergeKLists(list);

	while (ret != NULL) {
		cout << ret->val;
		ret = ret->next;
	}
	cout << endl;

	return EXIT_SUCCESS;
}