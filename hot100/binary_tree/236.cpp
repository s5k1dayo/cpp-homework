#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
//一个递归函数,直接返回满足的左/右,只有一边时继续传递,两边都有时返回根
    TreeNode* res=NULL;
    TreeNode* P;
    TreeNode* Q;
    vector<bool> find(TreeNode* root ){
        if(root==NULL){
            return {false,false};
        }
        if(res!=NULL){
            return {true,true};
        }
        vector<bool> findpq1(2,false),findpq2(2,false);
        findpq1=find(root->left);
        findpq2=find(root->right);
        bool findp=findpq1[0] || findpq2[0] || root==P;
        bool findq=findpq1[1] || findpq1[1] || root==Q;
        if(findp && findq && res==NULL){
            res=root;
        }
        return {findp,findq};

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        P=p;
        Q=q;
        find(root);
        return res;
    }
};