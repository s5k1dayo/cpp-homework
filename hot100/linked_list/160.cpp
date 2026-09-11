//方法一：哈希集合，将a中所有节点加入哈希表，之后遍历b每个元素，出现的第一个在哈希表中存在的就是交点，没有则返回null
//方法二：双指针m，n分别从a，b从前往后遍历，到头之后跳到另一支上继续，两指针相等时则是结果（交点或null）
#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* m=headA;
        ListNode* n=headB;
        while(m!=n){
            if(m->next==NULL&& n->next!=NULL){
                m=headB;
                n=n->next;
                continue;
            }
            else if(n->next==NULL && m->next!=NULL){
                n=headA;
                m=m->next;
                continue;
            }
            m=m->next;
            n=n->next;
        }
        return m;
    }
};