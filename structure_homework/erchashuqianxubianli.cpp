#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};
void getTree(string tree,TreeNode root){
    for(int i=0;i<tree.length();i++){
        if(tree[i]!='#'){
            int val=tree[i]-'0';
            TreeNode cur=TreeNode(val);
            
        }
    }
        

}