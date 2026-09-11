#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //自己装填链表返回时需要用不动的哨兵节点记录开头，要装入节点实体，不能只用指针；
        ListNode* cur1=l1;
        ListNode* cur2=l2;
        ListNode dummy(0);
        ListNode* head=&dummy;
        ListNode* res=head;
        int add=0;
        while(cur1!=NULL || cur2!=NULL ||add !=0){
            int sum=0;
            if(cur1==NULL && cur2!=NULL){
                int num2=cur2->val;
                sum=(num2+add)%10;
                add=(num2+add)/10;
                ListNode* newnode=new ListNode(sum);
                head->next=newnode;
                head=head->next;
                cur2=cur2->next;
                continue;
            }
            if(cur2==NULL && cur1!=NULL){
                int num1=cur1->val;
                sum=(num1+add)%10;
                add=(num1+add)/10;
                ListNode* newnode=new ListNode(sum);
                head->next=newnode;
                head=head->next;
                cur1=cur1->next;
                continue;
            }
            if(cur1==NULL&& cur2==NULL){
                ListNode* newnode=new ListNode(1);
                head->next=newnode;
                head=head->next;
                break;
            }
            int num1=cur1->val;
            int num2=cur2->val;
            
            sum=(num1+num2+add)%10;
            add=(num1+num2+add)/10;
            ListNode* newnode=new ListNode(sum);
            head->next=newnode;
            head=head->next;
            cur1=cur1->next;
            cur2=cur2->next;
        }
        return res->next;
    }
};
/*
开头指针没赋值，是随机乱地址，访问直接报错；
节点建在临时空间里，用完就销毁，指针指向失效内存；
循环条件不对，没法算完两条链表所有数字，加法进位计算顺序写错，最后多出的进位也没补上。
*/