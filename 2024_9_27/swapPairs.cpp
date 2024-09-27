#include <iostream>
#include <string>

using namespace std;

/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
输入：head = [1,2,3,4]
输出：[2,1,4,3]
*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 class Solution {
 public:
     ListNode* swapPairs(ListNode* head) {
         if (head == NULL) return NULL;
         if (head->next == NULL) return head;

         //ListNode* phead = head->next, *cur = head->next, *prev = phead;
         ListNode* prev = head;
         ListNode* cur = prev->next;
         ListNode* phead = prev->next;
         ListNode* before = NULL;

         while (cur != NULL) {
             ListNode* temp = cur;
             cur = cur->next;

             temp->next = prev;
             prev->next = cur;

             if (before != NULL) {
                 before->next = temp;
             }
             before = prev;

             if (cur == NULL) break;
             cur = cur->next;

             prev = prev->next;

         }
         return phead;
     }
 };

 /*
 class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //终止条件：传入的head小于2
        if(head == NULL) return NULL;
        if(head->next == NULL)return head;

        //回调
        ListNode *newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        
        return newHead;
    }
};
 */