#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct treenode {
    char val;
    treenode* left;
    treenode* right;
    treenode(char x):val(x),left(NULL),right(NULL){}
};
int idx;
treenode* buildtree(string& s){
    if(idx>=s.size() || s[idx]=='*'){
        idx++;
        return NULL;
    }
    treenode* root =new treenode(s[idx]);
    idx++;
    root->left=buildtree(s);
    root->right=buildtree(s);
    return root;
}

int getdepth(treenode* root){
    if(root==NULL){
        return 0;
    }
    int leftdepth=getdepth(root->left);
    int rightdepth=getdepth(root->right);
    return max(leftdepth,rightdepth)+1;
}
int main(){
    string s;
    while(cin>>s){
        idx=0;
        treenode* root=buildtree(s);
        int depth=getdepth(root);
        cout<<depth<<endl;
    }
    return 0;
}