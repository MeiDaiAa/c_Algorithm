#include "reverseKGroup.cpp"

int main() {
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);
	ListNode* l5 = new ListNode(5);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = NULL;

	Solution solution;
	ListNode* ret = solution.reverseKGroup(l1, 2);
	while (ret != NULL) {
		cout << ret->val << " ";
		ret = ret->next;
	}
	cout << endl;
	
	return EXIT_SUCCESS;
}