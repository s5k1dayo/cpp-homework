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
    vector<int> list;
    void middled(TreeNode* root ){
        if(root==NULL){
            return ;
        }    
        middled(root->left);
        list.push_back(root->val);
        middled(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        middled(root);
        return list[k-1];
    }
};