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
//用队列处理，不空就一直循环,进队时判断是否为空
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> line;
        vector<vector<int>> res;
        if(root==NULL){
            return res;
        }
        line.push(root);
        while(!line.empty()){
            int len=line.size();
            vector<int> nums;
            for(int i=0;i<len;i++){
                TreeNode* cur=line.front();
                if(cur==NULL){
                    line.pop();
                    continue;
                }
                line.pop();
                nums.push_back(cur->val);
                line.push(cur->left);
                line.push(cur->right);
            }
            if(!nums.empty()){
                res.push_back(nums);
            }
            

        }
        return res;

    }
};