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
    ListNode* reverseList(ListNode* head) {
    //迭代：从前向后依次处理，记录下一个的下一个、
    //递归：当前没有或下一个没有返回当前，否则对当前下一个调用本身函数，之后需要将后面的head接到当前的前面，当前的后面换为null,利用递归栈保存节点信息实现逆序遍历，同时传递最终的头节点信息；
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* cur=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return cur;
    }
};