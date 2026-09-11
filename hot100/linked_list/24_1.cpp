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
//递归：先处理当前，然后将下一个处理的往后递，然后返回处理后的前面值，往前归时候连接；
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL ||head->next==NULL ){
            return head;
        }
        ListNode* cur=head->next->next;
        ListNode* res=head->next;
        ListNode* nex=swapPairs(cur);
        res->next=head;
        head->next=nex;
        return res;
    }
};