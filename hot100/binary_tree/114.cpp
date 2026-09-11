#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0),left(NULL),right(NULL) {}
    TreeNode(int vals): val(vals),left(NULL),right(NULL) {}

};

class Solution {
public:
//遍历，有左子树则拆下来放右边，右子树入栈，遍历到叶子节点时接栈里的右子树；
    void flatten(TreeNode* root) {
        if(root==NULL ||(root->left==NULL && root->right==NULL)){
            return;
        }
        TreeNode* cur=root;
        stack<TreeNode*> stk;
        while(cur!=NULL|| !stk.empty()){
            if(cur->left==NULL && cur->right==NULL && !stk.empty()){
                cur->right=stk.top();
                stk.pop();
            }
            if(cur->left){
                if(cur->right) stk.push(cur->right);
                cur->right=cur->left;
                cur->left=NULL;
            }
            cur=cur->right;
        }
    }
};