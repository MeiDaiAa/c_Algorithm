#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//class Solution {
//public:
//	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//		ListNode* ret = new ListNode();
//		ListNode* rHead = ret;
//		//创建两个对应两个链表的指针
//		//两个指针分别指向两个链表的相同位置
//		ListNode* cur1 = list1;
//		ListNode* cur2 = list2;
//		
//		//当两个链表还有内容的时候一直循环
//		while (cur1 != NULL && cur2 != NULL) {
//			//将两个指针指向的值拿出来对比，小的先推入后++进行下一次循环
//			if (cur1->val < cur2->val) {
//				ListNode* temp = new ListNode(cur1->val);
//				ret->next = temp;
//				ret = ret->next;
//				cur1 = cur1->next;
//			}
//			else {
//				ListNode* temp = new ListNode(cur2->val);
//				ret->next = temp;
//				ret = ret->next;
//				cur2 = cur2->next;
//			}
//		}
//		//跳出循环表示两个链表至少有一个链表已经空了，只需要将不为空的链表全部推入ret即可
//		if (cur1 != NULL) ret->next = cur1;
//		else if (cur2 != NULL) ret->next = cur2;
//
//		return rHead->next;
//	}
//};

/// <summary>
/// ///////////////////////可以先将list1全部推入到ret中，然后将lest2与ret中的每个元素对比
/// </summary>

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* ret = new ListNode();
		ListNode* rHead = ret;

		ListNode* cur1 = list1;
		ListNode* cur2 = list2;
		//将list1全部推入到ret中
		while (cur1 != NULL) {
			ListNode* temp = new ListNode(cur1->val);
			ret->next = temp;
			ret = ret->next;
			cur1 = cur1->next;
		}

		//推入可以直接修改在list1上
		//将list1全部推入到ret中
		//ret->next = cur1;

		//这样时间复杂度就可以从O(M + N)变成O(N)


		//将ret的指针改到头部
		cur1 = rHead->next;
		ListNode *pre = rHead;
		//将list2中较小的元素插入到ret对应位置的前面， 如果ret走到了最后，表示ret中已经没有比list2中更大的了，直接将list2往后拼接即可
		while (cur1 != NULL) {
			//如果cur2 == NULL，表示cur2
			if (cur2 == NULL) return rHead->next;
			//如果cur2小于cur1 就将cur2插入到cur1前面
			if (cur2->val < cur1->val) {
				ListNode* temp = new ListNode(cur2->val);
				pre->next = temp;
				pre = pre->next;
				temp->next = cur1;
				//cur2后移
				cur2 = cur2->next;
				continue;
			}
			//cur1的元素小，cur1后移
			pre = cur1;
			cur1 = cur1->next;
		}
		//将cur2直接拼接到后面
		pre->next = cur2;

		return rHead->next;
	}
};