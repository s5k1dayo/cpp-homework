/*
6-1 二叉树中值为奇数的结点数*
分数 10
作者 李祥
单位 湖北经济学院
已知二叉树的结点结构定义如下：

typedef struct _NODE_
{
    int data;
    struct _NODE_ *lch, *rch;
} NODE;
说明：data 为数据域。lch 和 rch 为指示左、右孩子的指针域。

请编写函数，求二叉树的值为奇数的结点个数。

函数原型
int NumOdd(const NODE *root);
说明：root 为二叉树的根指针，函数值为二叉树中的奇数结点数。

裁判程序
int main()
{
    NODE *root;
    Create(&root);
    Input(&root);
    printf("%d\n", NumOdd(root));
    Destroy(&root);
    return 0;
}
说明：Create 函数创建空二叉树，Destroy 函数销毁二叉树。Input 函数按先根遍历顺序输入二叉树，结点值均为正整数，遇到空树时，输入零。

输入样例
85 37 94 53 0 0 21 0 0 0 18 46 0 60 32 0 87 0 0 0 95 0 72 0 0

输出样例
6

提示：多次调用 NumOdd 函数都应得到正确的结果。
*/