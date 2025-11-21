/*
6-2 二叉树叶节点打印并计数
分数 10
作者 周强
单位 青岛大学
本题要求实现一个函数，对于给定的二叉树，按从右到左的顺序打印所有叶结点，并返回叶结点的数量。

函数接口定义：
int leaves(struct BTree *bt)； //bt为二叉树根指针
其中二叉树定义如下：

struct BTree{
    char data;  //结点名称(字母表示)
    struct BTree *left;  //左子树指针
    struct BTree *right;  //右子树指针
};
二叉树的结点用英文字母（区分大小写）表示，因此显然二叉树中的结点总数不超过52个。

提示：

要求函数在一行中按照从右到左的顺序打印所有叶节点，行末无需打印换行符，可参考裁判程序和输出样例；
函数须返回叶节点的数量；
程序根据输入的前序和中序序列创建二叉树，该部分内容由裁判程序实现（即：createTree( )函数），你无需编写。
裁判测试程序样例：
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct BTree{
    char data;
    struct BTree *left;
    struct BTree *right;
};
char pre[53], mid[53];
int leaves(struct BTree *bt);  //函数原型
struct BTree *createTree(int n, char *pre, char *mid){
    // 根据输入前序和中序序列创建二叉树，实现细节省略。
};
int main(){
    scanf("%s%s", pre, mid);
    struct BTree *bt;
    bt = createTree(strlen(pre), pre, mid);
    printf(",%d\n", leaves(bt));  
    return 0;
}

输入样例：
ABDFGHIEC
FDHGIBEAC

输出样例：
CEIHF,5
*/