#include <iostream>

using namespace std;


 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 class Solution {
 public:
     ListNode* removeNthFromEnd(ListNode* head, int n) {
         int pos = 0;
         //定义左右节点，让左右两个节点的间隔值等于n
         struct ListNode* L = head;
         struct ListNode* R = head;
         while (R->next != NULL) {
             //让左右两个节点的间隔值等于n
             if (pos < n) {
                 pos++;
                 R = R->next;
                 if (R == NULL) return NULL;
             }
             else {
                 //两节点的间隔值相等后，节点平移到链表的末尾
                 L = L->next;
                 R = R->next;
             }
         }
         //如果有pos小于n的情况，其实表示我们要删除的节点就是最左边的节点，我们直接删除返回就行
         if (pos < n) {
             //这一步的意思是，如果右节点移到的最后，但是长度还是不够，
             //我们就在左节点前增加节点来让接下来L->next = L->next->next 可以正常运行
             // for(int i = 0; i < n - pos; i++){
             //     struct ListNode *temp = new ListNode(0);
             //     temp->next = L;
             //     L = temp;
             //     head = head->next;
             // }
             L = L->next;
             return L;
         }
         L->next = L->next->next;
         return head;
     }
 };