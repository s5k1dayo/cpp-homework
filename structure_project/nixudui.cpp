/*
A h0279. 逆序对
分数 10
作者 黄正鹏
单位 贵州工程应用技术学院
给定一个长度为n的整数数列，请你计算数列中的逆序对的数量。

逆序对的定义如下：对于数列的第 i 个和第 j 个元素，如果满足 i < j 且 a[i] > a[j]，则其为一个逆序对；否则不是。

输入格式:
第一行包含整数n，表示数列的长度；第二行包含 n 个整数，表示整个数列。（1≤n≤100000）

输出格式:
输出一个整数，表示逆序对的个数。

输入样例:
6
2 3 4 5 6 1
输出样例:
5
*/
#include<iostream>
using namespace std;
int main(){
    int n,count=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cur=0;
    while(cur<n){
        if(a[cur]<=a[cur+1]){
            cur++;
            continue;
        }
        else{
            for(int j=0;j<cur+1;j++){
                if(a[j]>a[cur+1]){
                    count++;
                }
            }
            cur++;
        }
    }
    cout<<count;
}