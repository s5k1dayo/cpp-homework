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
//不复制数组，递归函数增加left，right标记左右边界，结束用left>right控制；
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){
            return NULL;
        }
        if(nums.size()==1){
            TreeNode* res=new TreeNode(nums[0]);
            return res;
        }      
        if(nums.size()==2){
            TreeNode* res=new TreeNode(nums[0]);
            res->right=new TreeNode(nums[1]);
            return res;
        }
        int len=nums.size();
        int mid=len/2;
        vector<int> lef,righ;
        for(int i=0;i<mid;i++){
            lef.push_back(nums[i]);
        }
        for(int i=mid+1;i<len;i++){
            righ.push_back(nums[i]);
        }
        TreeNode* cur=new TreeNode(nums[mid]);
        TreeNode* left=sortedArrayToBST(lef);
        TreeNode* right=sortedArrayToBST(righ);
        cur->left=left;
        cur->right=right;
        return cur;
    }
};