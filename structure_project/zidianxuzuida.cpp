/*
7-4 字典序最大出栈序列
分数 15
作者 李佳
单位 重庆大学
给定一组正整数序列<a1,a2,...,an>，其中所有数值互不相同。将a1到an依次入栈，而栈顶元素可以随时出栈。求所有合法出栈序列中，字典序最大的出栈序列。
输入格式:
输入在第一行中给出整数n (1≤n≤106)，接下来一行包含n个整数，数值间用空格分开。所有数值都在区间[1,109]以内。

输出格式:
在一行中输出字典序最大的出栈序列，数值间用空格分开。简单起见，末尾数值后面也留有一个空格。

输入样例:
5
2 1 5 3 4
输出样例:
5 4 3 1 2 
*/
#include<iostream>
#include<stack>
using namespace std;
void paixu(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=n-1-i;j>0;j--){
            if(a[j]>=a[j-1]){
                int b=a[j-1];
                a[j-1]=a[j];
                a[j]=b;
            }
        }
    }
}

int main(){
    int n,max=0;
    cin>>n;
    int a[n],pai[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        pai[i]=a[i];
    }
    paixu(pai,n);
    stack<int> ru;
    for(int j=0;j<n;j++){
        if(a[j]==pai[max]){
            cout<<a[j]<<" ";
            max++;
        }
        else{
            ru.push(a[j]);
        }
    }
    while(!ru.empty()){
        cout<<ru.top()<<" ";
        ru.pop();
    }

    
}