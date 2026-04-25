/*
7-1 区间质数
分数 10
作者 杨军
单位 四川师范大学
输入两个整数a和b，a<=b，输出a到b（包含a和b）之间的所有质数，每个质数占一行。

输入格式:
a
b

输出格式:
满足条件的所有质数。

输入样例:
在这里给出一组输入。例如：

2
5
输出样例:
在这里给出相应的输出。例如：

2
3
5
*/
#include<iostream>
#include<cmath>
using namespace std;

void biao(int num[],int a,int len,int q){//传入头，len，判断数组，乘数
    int qian=a/q,hou=(a+len-1)/q;//头/乘数，得到开始倍率，尾同样int
    for(int i=qian;i<=hou;i++){
        int shu=q*i;
        if(shu>=a && shu<=a+len-1 && i>1){
            num[shu-a]=1;
        }
    }
//用倍率循环，将范围内的数标记为1；
}
int main(){
    int a,b;
    cin>>a>>b;
    int len=b-a+1;
    int flag[len]={0};
    double sqrtb=sqrt(b);
    for(int i=2;i<=sqrtb;i++){
        biao(flag,a,len,i);
    }
    for(int i=0;i<len;i++){
        if(flag[i]==0 && a+i>=2)cout<<i+a<<endl;
    }
    return 0;
}