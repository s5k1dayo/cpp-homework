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

    //递归判断，停止条件：left/right中有NULL相等条件：当前left=right且left的左等于right的右，left右等于right左。
    bool check(TreeNode* left,TreeNode* right){
        if(!left && !right){
            return true;
        }
        if(!left || !right){
            return false;
        }
        return left->val==right->val && check(left->right,right->left) && check(right->right,left->left);
    }
    bool isSymmetric(TreeNode* root) {
       bool res=check(root->left,root->right);
       return res;
    }
};