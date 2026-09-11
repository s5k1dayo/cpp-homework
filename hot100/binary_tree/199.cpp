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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL){
            return res;
        }
        queue<TreeNode*> list;
        list.push(root);
        while(!list.empty()){
            int len=list.size();
            for(int i=0;i<len;i++){
                TreeNode* cur=list.front();
                if(i==len-1){
                    res.push_back(cur->val);
                }
                if(cur->left) list.push(cur->left);
                if(cur->right)list.push(cur->right);
                list.pop();
                
            }
        }
        return res;
    }
};