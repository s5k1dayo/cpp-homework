/*吃不完！
刚从东风校区搬到科学校区，QT组ZL同学就立马跑到餐厅，一口气买了很多美味的小吃，不过，他后知后觉地发现，买的太多了，吃不完！！！

所以，他决定先选出最幸运的小吃吃掉。具体做法是把所有的小吃围成一个圈并编号为1，2，……，n，之后以1号为起点，从1开始顺时针数数，每次数到m，就把m对应的小吃拿走，然后从下一份小吃开始重新数，直到最后剩下唯一的一份小吃，便是最幸运的小吃，现在，请你帮他找出最幸运的小吃吧！

输入格式:
因为ZL同学到底买了多少份小吃，你不知道，所以你要考虑不同情况的n，也就是说这是一个多实例测试。 每行是用空格分开的两个整数，第一个是 n，表示小吃的数量, 第二个是 m，以0 0表示输入结束。

输出格式:
每一行输出一个最幸运小吃的编号（最后一行除外）

说明/提示:
0 < m,n <=1000

输入样例:
6 2
12 4
8 3
0 0
输出样例:
5
1
7
*/
#include <iostream>
using namespace std;
int zhuan(int n, int m)
{
    int a[n] = {0};
    int cur = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int count = 0;
        while (count < m)
        {
            cur++;
            if (a[cur % n] == 0)
            {
                count++;
            }
        }
        a[cur % n] = 1;
    }
    for (int j = 0; j < n; j++)
    {
        if (a[j] == 0)
        {
            return j;
        }
    }
    return 0;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
        {
            break;
        }
        int a = zhuan(n, m);
        cout << a << endl;
    }
}
/*
#include<iostream>
using namespace std;

int main(){
    int n,m,flag=1;
    while(cin>>n>>m){
        if(n==0 && m==0){
            break;
        }
        int a[1000]={0};
        for(int i=0;i<n;i++){
            a[i]=1;
        }
        int count=0,sheng=n,cur=0;
        while(sheng>1){
            if(a[cur]==1){
                count++;
                if(count==m){
                    a[cur]=0;
                    count=0;
                    sheng--;
                }
            }
            cur=(cur+1)%n;
        }
        for(int i=0;i<n;i++){
            if(a[i]==1){
                cout<<i+1<<endl;
                break;
            }
        }
    }
}

*/