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
    ListNode* swapPairs(ListNode* head) {
        //靶节点pre，当前处理cur，下一个nex
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* cur=head;
        ListNode* nex=head->next;
        ListNode* res=nex;
        ListNode* pre=new ListNode(0);
        pre->next=head;
        while(cur!=NULL&& nex!=NULL){
            cur->next=nex->next;
            nex->next=cur;
            pre->next=nex;
            pre=cur;
            cur=cur->next;
            if(cur==NULL){
                break;
            }
            nex=cur->next;
        }
        return res;
    }
};
