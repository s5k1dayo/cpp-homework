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
//链表用归并排序，之后合并有序链表：呀节点后面直接连接，无需断开原链表的后续节点
//链表中点正确模板：slow=fast=head，while（fast->next!=null && fast->next->next!=NULL）
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* cur1=head1;
        ListNode* cur2=head2;
        ListNode* head=new ListNode();
        ListNode* cur=head;
        while(cur1!=NULL && cur2!=NULL){
            if(cur1->val < cur2->val){
                cur->next=cur1;
                cur1=cur1->next;
                cur=cur->next;
            }else{
                cur->next=cur2;
                cur2=cur2->next;
                cur=cur->next;
            }
        }
        cur->next = cur1==NULL ? cur2:cur1;
        return head->next;
    }
    ListNode* spread(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while( fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next;
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* res=slow->next;
        slow->next=NULL;
        return res;
    }
    ListNode* sortList(ListNode* head) {    
        if(head==NULL ||head->next==NULL){
            return head;
        }
        ListNode* head2=spread(head);
        ListNode* head1=sortList(head);
        head2=sortList(head2);
        ListNode* res=merge(head1,head2);
        return res;
        
    }
};