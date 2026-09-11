//迭代，递归，用哈希保存链表
//迭代穿插，在每个旧的后面依次插入新的，省下哈希空间
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur=head;
        Node* newhead=new Node(0);
        Node* newcur=newhead;
        unordered_map<Node*,Node*> save,ran;
        while(cur!=NULL){
            newcur->next=new Node(cur->val);
            newcur=newcur->next;
            save[cur]=newcur;
            ran[cur]=cur->random;
            cur=cur->next;
        }
        cur=head;
        while(cur!=NULL){
            newcur=save[cur];
            Node* newran=save[ran[cur]];
            newcur->random=newran;
            cur=cur->next;
        }
        return newhead->next;
    }
};