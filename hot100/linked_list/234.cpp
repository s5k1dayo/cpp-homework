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
    ListNode *frontend;
public:
//递归函数：1.停止条件   2.递阶段   3.归阶段任务    4.设计返回值
    bool reverselycheck(ListNode* head){
        ListNode* cur;
        if(!head){
            return true;
        }
        bool next=reverselycheck(head->next);
        if(head->val != frontend->val || !next){
            return false;
        }
        frontend=frontend->next;
        return true;
    }
    bool isPalindrome(ListNode* head) {
        frontend=head;
        return reverselycheck(head);

    }
};