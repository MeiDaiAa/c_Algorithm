#include <iostream>
using namespace std;



struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //取出 l1 与 l2 节点中间的数字
    ListNode* L1 = l1;
    ListNode* L2 = l2;

    //设置两个节点相加的变量 add
    int add = 0;
    //设置进位数 nextAdd
    int nextAdd = 0;
    //创造返回的链表
    ListNode* rHead = new ListNode;
    //创建链表上的指针来追加返回链表上面的数值
    ListNode* ret = rHead;


    //当两个链表有不为空情况的时候（两个链表中还有数字没有加完）
    while (L1 || L2) {

        //不能够判断链表中有数字的时候让 add 与 链表中保存的数值相加
        //因为如果链表为空的情况下 使用-> 引用了空
        //因该直接判断链表是否存在然后直接使用内部的val来相加
        if (L1) {
            add += L1->val;
            //指针后移
            L1 = L1->next;
        }
        if (L2) {
            add += L2->val;
            //指针后移
            L2 = L2->next;
        }
        //两链表中的数相加后，看是否有进位，有进位的话就与进位相加
        add += nextAdd;

        //相加后创建节点，保存在返回链表中
        ListNode* addNode = new ListNode(add % 10);
        //将创建的节点接入返回链表
        ret->next = addNode;
        //移动标
        ret = addNode;
        //查看是否有进位，如果有保存进位到 nextAdd中
        nextAdd = add / 10;
        //重置两链表相加的结果，让下一轮重新开始相加
        add = 0;
    }

    //检查两数加完后是否有进位
    if (nextAdd != 0)
    {
        //相加后创建节点，保存在返回链表中
        ListNode* addNode = new ListNode(nextAdd);
        //将创建的节点接入返回链表
        ret->next = addNode;
        //移动标
        ret = addNode;
    }

    ret->next = NULL;
    return rHead->next;
}
};