#include "removeNthFromEnd.cpp"

int main() {
	struct ListNode* L1 = new ListNode(1);
	struct ListNode* L2 = new ListNode(2);
	struct ListNode* L3 = new ListNode(3);
	struct ListNode* L4 = new ListNode(4);
	struct ListNode *L5 = new ListNode(5);
	L1->next = L2;
	L2->next = L3;
	L3->next = L4;
	L4->next = L5;
	L5->next = NULL;

	Solution solution;
	struct ListNode* ret = solution.removeNthFromEnd(L1, 3);
	while (ret != NULL) {
		cout << ret->val << " ";
		ret = ret->next;
	}
	cout << endl;
	
	return EXIT_SUCCESS;
}