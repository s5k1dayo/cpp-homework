/*
7-2 是不是堆
分数 10
作者 陈越
单位 浙江大学
给定一个完全二叉树的层序遍历序列，请判断该二叉树是否是二叉堆。

输入格式：
每组测试第 1 行包含 2 个正整数：m (≤100) 是二叉树的个数；n（1<n≤1000）是每个二叉树中结点的个数。随后 m 行，每行给出 n 个不重复的整数键值（均在 32 位整型 int 范围内），是一个完全二叉树的层序遍历序列。

输出格式：
对每个输入中给定的二叉树，如果其对应了一个最大堆，则在一行中输出 Max Heap；如果对应最小堆，则输出 Min Heap；否则输出 Not Heap。随后在下一行输出这棵树的后序遍历序列。一行中的数字间以 1 个空格分隔，行首尾不得有多余空格。

输入样例：
3 8
98 72 86 60 65 12 23 50
8 38 25 58 52 82 70 60
10 28 15 12 34 9 8 56
输出样例：
Max Heap
50 60 65 72 12 23 86 98
Min Heap
60 58 52 38 82 70 25 8
Not Heap
56 12 34 28 9 8 15 10
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
bool dadui(int a[], int len)
{
    for (int i = 0; i < len / 2; i++)
    { // 遍历有叶子的结点
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        if (r >= len)
        { // 只有左子节点的情况
            if (a[l] > a[i])
            {
                return 0;
            }
        }
        else if (a[l] > a[i] || a[r] > a[i])
        { // 出现子比父大直接返回0
            return 0;
        }
    }
    return 1;
}
bool xiaodui(int a[], int len)
{
    for (int i = 0; i < len / 2; i++)
    { // 遍历有叶子的结点
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        if (r >= len)
        {
            if (a[l] < a[i])
            {
                return 0;
            }
        }
        else if (a[l] < a[i] || a[r] < a[i])
        {
            return 0;
        }
    }
    return 1;
}
vector<int> houxu(int a[], int len)
{
    vector<int> result;
    int flag[len * 2 + 2] = {0};
    stack<int> cun;
    cun.push(0);
    for (int i = len; i < len * 2 + 2; i++)
    {
        flag[i] = 1;
    }
    flag[0] = 1;
    while (!cun.empty())
    {
        int cur = cun.top();
        if (flag[cur * 2 + 1] == 1 && flag[cur * 2 + 2] == 1)
        { // Flag初始为0；表示子结点没入栈，入栈时变1，没有子节点的位置全部为1；
            result.push_back(a[cur]);
            cun.pop();
        }
        if (cur * 2 + 2 < len && flag[cur * 2 + 2] == 0)
        { // 判断是否有右子节点
            cun.push(cur * 2 + 2);
            flag[cur * 2 + 2] = 1; // 若有将右子节点放入栈
        }
        if (cur * 2 + 1 < len && flag[cur * 2 + 1] == 0)
        {
            cun.push(cur * 2 + 1);
            flag[cur * 2 + 1] = 1;
        }
    }
    return result;
}
int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        int num[n];
        for (int j = 0; j < n; j++)
        {
            cin >> num[j];
        }
        if (dadui(num, n))
        {
            cout << "Max Heap" << endl;
        }
        else if (xiaodui(num, n))
        {
            cout << "Min Heap" << endl;
        }
        else
        {
            cout << "Not Heap" << endl;
        }
        vector<int> result = houxu(num, n);
        for (int k = 0; k < n; k++)
        {
            cout << result[k];
            if (k < n - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}