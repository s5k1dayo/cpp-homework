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
//递归遍历，每次拆分中序遍历数组，分为左子和右子树，根据前序遍历创建父节点，注意father指针不能在递归时自增，当前为null时停止
    vector<int> pre,ino;
    TreeNode* creat(int begin,int end,int &father){
        if(begin>end){
            return NULL;
        }
        TreeNode* root=new TreeNode(pre[father]);
        for(int i=begin;i<=end;i++){
            if(ino[i]==pre[father]){
                father++;
                TreeNode* leftree=creat(begin,i-1,father);
                TreeNode* rightree=creat(i+1,end,father);
                root->left=leftree;
                root->right=rightree;
                break;
            }
        }
        return root;
         
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre=preorder;
        ino=inorder;
        int father=0;
        TreeNode* res=creat(0,ino.size()-1,father);
        return res;
    }
};