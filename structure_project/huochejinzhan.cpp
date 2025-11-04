/*
7-2 火车进站
分数 10
作者 苏国煜
单位 闽江学院
现在有n节火车车厢在进站口，每个车厢的编号为1∼n​（不存在重复的编号）中的数字。
现在他们按照给定的顺序排列在一条轨道上，且可以向两个方向（进站口和出站口方向）移动，问他们能否通过在进站口和出站口中间的一个车站，且每部火车至多进站一次，使得出站口的编号顺序变为升序？
如果可以输出一行Yes，并在下一行输出调整过程中不需要进车站的车厢的数量，如果不行输出No。

输入格式
第一行一个整数T(1≤T≤105)，代表测试用例的数量
对于每个测试用例：

第一行一个整数n。(1≤n≤105)
第二行n个整数，a1,a2,…,an，第i个整数ai表示在进站口第i个车厢的编号。(1≤ai≤n,ai=aj)
输出格式:
如果可以变成升序输出一行Yes，并在下一行输出调整过程中不需要进车站的车厢的数量，反之输出No。

输入样例:
2
3
2 1 3
4
3 4 1 2
输出样例:
Yes
2
No
*/
#include<iostream>
#include<stack>
using namespace std;
bool pan(int a[],int n){
    int chu=1,cur=0;
    stack<int> ku;
    while(cur<=n-1){
        if(!ku.empty() && ku.top()==chu){
            ku.pop();
            chu++;
        }
        else if(a[cur]>chu){
            ku.push(a[cur]);
            cur++;
        }
        else if(a[cur]==chu){
            cur++;
            chu++;
        }
    }
    return ku.empty();
}
int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        int a[n];
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        if(pan(a,n)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}



/*
#include<iostream>
#include<stack>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int a[n];
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        stack<int> zhan;
        int out=1,no=0;
        for(int j=0;j<n;j++){
            if(a[j]==out){
                no++;
                out++;
                while(!zhan.empty() && zhan.top()==out){
                    zhan.pop();
                    out++;
                }
            }
            else{
                zhan.push(a[j]);
            }
        }
        bool flag=1;
        while(!zhan.empty()){
            if(zhan.top()!=out){
                flag=0;
                break;
            }
            zhan.pop();
            out++;
        }
        if(flag){
            cout<<"Yes"<<endl<<no<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}
*/