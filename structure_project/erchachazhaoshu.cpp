/*
B 二叉查找树的构建及序列化
分数 10
作者 李佳
单位 重庆大学
二叉查找树是一种特殊的二叉树，要求树中任一结点，如果其左子结点非空，则左子结点的数据一定小于结点数据；同样，若右子结点非空，右子结点的数据一定大于结点数据。在C\C++语言中，二叉树结点可用以下的结构体或类来实现。

// C
typedef struct bSTNode{
    int val;   // 结点数据
    struct bSTNode* left;   //指向左子结点
    struct bSTNode* right;  //指向右子结点
} BSTNode;

// C++
class BSTNode{
public:
     int val;
    BSTNode* left;
     BSTNode* right;
};

给定一个正整数序列，将数值依次插入(insert)到初始为空的二叉树中，由此可构建一棵二叉查找树。插入单个数值需要执行二分查找：从根结点开始比较，如果新数值与当前结点存放的数据相同，说明已在树中不需要再添加；否则，若数值比当前结点小，则查找结点的左子树，若比当前结点大，则移到右子树进行查找。如果到达的结点是空结点(NULL)，则生成新的叶结点。

输入格式:
输入在第一行中给出1个正整数N，代表整数序列的长度（1≤N≤1000)。接下来一行有N个正整数，数值间用空格分开。所有数值都不超过10 
6
 。

输出格式:
在一行中输出构建的二叉查找树的前序序列，其中空结点用0表示。数值间用空格分开，简单起见，最后一个数值后面也有空格。

输入样例:
8
3 1 6 4 2 6 5 7
输出样例:
3 1 0 2 0 0 6 4 0 5 0 0 7 0 0 
由样例构建的二叉查找树如下图所示。
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class BSTNode{
public:
    int val;
    BSTNode* left;
    BSTNode* right;
};
void cha(BSTNode* a,int num){
    BSTNode* cur=a;
    BSTNode xin;
    while(1){
        if(cur->val<num){
            if(cur->right==NULL){
                cur->right=&xin;
                xin.val=num;
                break;
            }
            cur=cur->right;
        }
        else if(cur->val>num){
            if(cur->left==NULL){
                cur->left=&xin;
                xin.val=num;
                break;
            }
            cur=cur->left;
        }
        else return;
    }
}
vector<int> bianli(BSTNode* a){
    vector<int> num;
    if(a==NULL) num.push_back(0);
    else if(a->left==NULL && a->right==NULL){
        num.push_back(a->val);
    }
    else{
        bianli(a->left);
        bianli(a->right);
    }
    return num;
}
int main(){
    int n,num;
    cin>>n;
    cin>>num;
    BSTNode a;
    a.val=num;
    for(int i=1;i<n;i++){
        cin>>num;
        cha(&a,num);
    }
    vector<int> res=bianli(&a);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}