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
//递归函数携带当前最大,最小范围,注意题目给的数据范围2^31,需要用longlong类型变量;
class Solution {
public:
    bool test(TreeNode* root ,long long lower,long long upper){
        if(root==NULL){
            return true;
        }
        int num=root->val;
        if(!(lower<root->val && root->val<upper)){
            return false;
        }
        if(root->left){
            if(!test(root->left,lower,root->val)){
                return false;
            }
        }
        if(root->right){
            if(!test(root->right,root->val,upper)){
                return false;
            }

        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
       return test(root,LONG_MIN,LONG_MAX);
    }
};