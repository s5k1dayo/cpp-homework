/*
7-1 堆的建立
分数 10
作者 张志梅
单位 青岛大学
所谓“堆的建立”，是指将已经存在的N个元素调整成最大堆或最小堆。

输入格式:
第一行是一个整数N，表示元素的个数，N<=10000。第二行N个元素的值。

输出格式:
输出2行，第一行是输入序列调整为最大堆后的元素序列，元素之间用空格分开。
第二行是输入序列调整为最小堆后的元素序列，元素之间用空格分开。

输入样例:
在这里给出一组输入。例如：

8
7 5 8 4 2 3 6 1

输出样例:
在这里给出相应的输出。例如：

8 5 7 4 2 3 6 1
1 2 3 4 7 8 6 5
*/
#include <iostream>
#include <queue>
using namespace std;

int *xiaodui(int Num[], int len)
{
    int *num = Num;
    int cur = len / 2 - 1;
    queue<int> huan;
    while (cur >= 0)
    {
        int l = cur * 2 + 1;
        int r = cur * 2 + 2;
        if (r >= len)
        {
            if (num[l] < num[cur])
            {
                int b = num[cur];
                num[cur] = num[l];
                num[l] = b;
                huan.push(l);
            }
        }
        else if (num[l] < num[cur] || num[r] < num[cur])
        {
            if (num[l] <= num[r])
            {
                int b = num[cur];
                num[cur] = num[l];
                num[l] = b;
                huan.push(l);
            }
            else
            {
                int b = num[cur];
                num[cur] = num[r];
                num[r] = b;
                huan.push(r);
            }
        }
        else if (num[l] < num[cur] && num[r] < num[cur])
        {
            if (num[l] <= num[r])
            {
                int b = num[cur];
                num[cur] = num[l];
                num[l] = b;
                huan.push(l);
            }
            else
            {
                int b = num[cur];
                num[cur] = num[r];
                num[r] = b;
                huan.push(r);
            }
        }
        cur--;
    }
    while (!huan.empty())
    {
        cur = huan.front();
        int l = cur * 2 + 1;
        int r = cur * 2 + 2;
        if (l >= len)
        {
            huan.pop();
            continue;
        }
        else if (r >= len)
        {
            if (num[l] < num[cur])
            {
                int b = num[cur];
                num[cur] = num[l];
                num[l] = b;
                huan.push(l);
            }
        }
        else if (num[l] < num[cur] || num[r] < num[cur])
        {
            if (num[l] <= num[r])
            {
                int b = num[cur];
                num[cur] = num[l];
                num[l] = b;
                huan.push(l);
            }
            else
            {
                int b = num[cur];
                num[cur] = num[r];
                num[r] = b;
                huan.push(r);
            }
        }
        else if (num[l] < num[cur] && num[r] < num[cur])
        {
            if (num[l] <= num[r])
            {
                int b = num[cur];
                num[cur] = num[l];
                num[l] = b;
                huan.push(l);
            }
            else
            {
                int b = num[cur];
                num[cur] = num[r];
                num[r] = b;
                huan.push(r);
            }
        }
        huan.pop();
    }
    return num;
}
int *dadui(int Num[], int len)
{
    int *num = Num;
    int cur = len / 2 - 1;
    queue<int> huan;
    while (cur >= 0)
    {
        int l = cur * 2 + 1;
        int r = cur * 2 + 2;
        if (r >= len)
        {
            if (num[l] > num[cur])
            {
                int b = num[cur];
                num[cur] = num[l];
                num[l] = b;
                huan.push(l);
            }
        }
        else if (num[l] > num[cur] || num[r] > num[cur])
        {
            if (num[l] >= num[r])
            {
                int b = num[cur];
                num[cur] = num[l];
                num[l] = b;
                huan.push(l);
            }
            else
            {
                int b = num[cur];
                num[cur] = num[r];
                num[r] = b;
                huan.push(r);
            }
        }
        else if (num[l] > num[cur] && num[r] > num[cur])
        {
            if (num[l] >= num[r])
            {
                int b = num[cur];
                num[cur] = num[l];
                num[l] = b;
                huan.push(l);
            }
            else
            {
                int b = num[cur];
                num[cur] = num[r];
                num[r] = b;
                huan.push(r);
            }
        }
        cur--;
    }
    while (!huan.empty())
    {
        cur = huan.front();
        int l = cur * 2 + 1;
        int r = cur * 2 + 2;
        if (l >= len)
        {
            huan.pop();
            continue;
        }
        else if (r >= len)
        {
            if (num[l] > num[cur])
            {
                int b = num[cur];
                num[cur] = num[l];
                num[l] = b;
                huan.push(l);
            }
        }
        else if (num[l] > num[cur] || num[r] > num[cur])
        {
            if (num[l] >= num[r])
            {
                int b = num[cur];
                num[cur] = num[l];
                num[l] = b;
                huan.push(l);
            }
            else
            {
                int b = num[cur];
                num[cur] = num[r];
                num[r] = b;
                huan.push(r);
            }
        }
        else if (num[l] > num[cur] && num[r] > num[cur])
        {
            if (num[l] >= num[r])
            {
                int b = num[cur];
                num[cur] = num[l];
                num[l] = b;
                huan.push(l);
            }
            else
            {
                int b = num[cur];
                num[cur] = num[r];
                num[r] = b;
                huan.push(r);
            }
        }
        huan.pop();
    }
    return num;
}
int main()
{
    int n;
    cin >> n;
    int num[n], a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        a[i] = num[i];
    }
    int *big = dadui(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << big[i];
        if (i < n - 1)
            cout << " ";
    }
    cout << endl;
    int *small = xiaodui(num, n);
    for (int i = 0; i < n; i++)
    {
        cout << small[i];
        if (i < n - 1)
            cout << " ";
    }
    return 0;
}