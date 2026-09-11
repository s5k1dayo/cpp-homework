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
//一个函数递归,如果有符合路段,路线上前面的前缀和中必定出现curlength-target,递归遍历完当前路段需要回溯哈希表
    int target;
    int res=0;
    unordered_map<TreeNode*,long long> length;
    void calculate(TreeNode* root,long long sum){
        if(root==NULL){
            return ;
        }
        int num=root->val;
        sum+=num;
        length[root]=sum;
        calculate(root->left,sum);
        calculate(root->right,sum);
    }
    void find(TreeNode* start,TreeNode* cur){
        if(cur==NULL || start==NULL){
            return ;
        }
        if(length[cur]-length[start]==target){
            res++;
        }
        find(start,cur->left);
        find(start,cur->right);
    }
    void reach(TreeNode* root){
        if(root==NULL){
            return ;
        }
        find(root,root->left);
        find(root,root->right);
        reach(root->left);
        reach(root->right);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        target=targetSum;
        TreeNode* start=new TreeNode(0);
        length[start]=0;
        start->left=root;
        calculate(start,0);
        reach(start);
        return res;
    }
};