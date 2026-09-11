#include <bits/stdc++.h>
using namespace std;
//使用双向链表存储数据,同时哈希表存储数据节点方便查询,删除和增加节点时注意哈希表同步改动;


struct LRUNode{
    int key;
    int val;
    LRUNode* next;
    LRUNode* previous;
    LRUNode(int key,int value): key(key),val(value),next(NULL),previous(NULL) {}
};
class LRUCache {
public:
    int cap;
    int size=0;
    LRUNode* head;
    LRUNode* tail;
    unordered_map<int,LRUNode*> nums;
    LRUCache(int capacity) {
        cap=capacity;
        LRUNode* heads=new LRUNode(0,0);
        LRUNode* tails=new LRUNode(0,0);
        head=heads;
        tail=tails;
        head->next=tail;
        tail->previous=head;
    }
    
    int get(int key) {
        auto it=nums.find(key);
        if(it!=nums.end()){
            LRUNode* cur=nums[key];
            LRUNode* curpre=cur->previous;
            LRUNode* curnext=cur->next;
            curpre->next=curnext;
            curnext->previous=curpre;
            LRUNode* first=head->next;
            head->next=cur;
            cur->previous=head;
            cur->next=first;
            first->previous=cur;
            return nums[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it =nums.find(key);
        if(it!=nums.end()){
            nums[key]->val=value;
            LRUNode* cur=nums[key];
            LRUNode* curpre=cur->previous;
            LRUNode* curnext=cur->next;
            curpre->next=curnext;
            curnext->previous=curpre;
            LRUNode* first=head->next;
            head->next=cur;
            cur->previous=head;
            cur->next=first;
            first->previous=cur;
            return;
        }
        LRUNode* newnode=new LRUNode(key,value);
        LRUNode* second=head->next;
        head->next=newnode;
        newnode->previous=head;
        newnode->next=second;
        second->previous=newnode;
        nums[key]=newnode;
        size++;
        if(size>cap){
            int lastkey=tail->previous->key;
            LRUNode* newlast=tail->previous->previous;
            newlast->next=tail;
            tail->previous=newlast;
            nums.erase(lastkey);
            size--;
        }
    }
};