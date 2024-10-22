#include <iostream>

using namespace std;

/*
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]
*/


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //递归终止条件：剩下的节点少于k个，返回剩下的节点
        if (head == NULL) return NULL;
        if (k == 1) return head;

        //保存当前的头节点，也是翻转后的尾节点
        ListNode* tail = head;

        for (int i = 0; i < k - 1; i++) {
            head = head->next;
            if (head == NULL) return tail;
        }

        //head遍历到这里的节点就是翻转后的头节点，保存头节点
        ListNode* newHead = head;
        //保存需要翻转的头节点
        ListNode* swapHead = tail->next;

        //递归
        tail->next = reverseKGroup(newHead->next, k);

        //将需要翻转的k-1个节点进行翻转
        swap(swapHead, k);
        //将翻转函数头节点，也就是翻转函数返回的尾节（最终翻转的倒数第二节点）接到最开始的头节点（也是最终翻转的尾节点）
        swapHead->next = tail;

        return newHead;
    }
private:
    //链表翻转
    void swap(ListNode* head, int k) {
        if (k == 2) {
        }
        else if (k == 3) {
            head->next->next = head;
        }
        else {
            ListNode* prev = head, * cur = head->next, * next = head->next->next;
            int n = 4;
            while (n <= k) {
                cur->next = prev;

                prev = cur;
                cur = next;
                next = next->next;

                n++;
            }
            cur->next = prev;
        }
        return;
    }
};