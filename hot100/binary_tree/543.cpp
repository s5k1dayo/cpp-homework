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
//递归，每次将左右子数大小相加，算可能的最长距离，并与res比较
    int res=0;
    int find(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=find(root->left);
        int right=find(root->right);
        int sum=left+right;
        if(sum>res){
            res=sum;
        }
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        find(root);
        return res;
    }
};