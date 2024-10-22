#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
// 
//class Solution {
//public:
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//
//        ListNode* cur = nullptr;
//        for (auto s : lists) {
//			cur = mergeTwoLists(cur, s);
//        }
//        return cur;
//    }
//
//	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//		ListNode* ret = new ListNode();
//		ListNode* rHead = ret;
//		ListNode* cur1 = list1;
//		ListNode* cur2 = list2;
//		while (cur1 != NULL) {
//			ListNode* temp = new ListNode(cur1->val);
//			ret->next = temp;
//			ret = ret->next;
//			cur1 = cur1->next;
//		}
//		cur1 = rHead->next;
//		ListNode* pre = rHead;
//		while (cur1 != NULL) {
//			if (cur2 == NULL) return rHead->next;
//			if (cur2->val < cur1->val) {
//				ListNode* temp = new ListNode(cur2->val);
//				pre->next = temp;
//				pre = pre->next;
//				temp->next = cur1;
//				cur2 = cur2->next;
//				continue;
//			}
//			pre = cur1;
//			cur1 = cur1->next;
//		}
//		pre->next = cur2;
//		return rHead->next;
//	}
//};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists.at(l);
        if (l > r) return nullptr;

        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if ((!list1) || (!list2)) return list1 ? list1 : list2;

        ListNode head, * tail = &head, * cur1 = list1, * cur2 = list2;

        while (cur1 && cur2) {
            if (cur1->val < cur2->val) {
                tail->next = cur1;
                cur1 = cur1->next;
            }
            else {
                tail->next = cur2;
                cur2 = cur2->next;
            }
            tail = tail->next;
        }
        tail->next = cur1 ? cur1 : cur2;

        return head.next;
    }
};