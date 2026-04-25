/*
7-2 二分查找
分数 15
作者 HBU训练营
单位 河北大学
给定一个长度为n的非负数组，该数组为单调不减，然后进行 m 次询问。对于每次询问，给出一个整数 q，要求输出这个数字在序列中第一次出现的编号，如果没有找到的话输出 −1。

输入格式:
第一行 2 个整数 n 和 m，表示数字个数和询问次数，n,m<=10 
5
 。
第二行 n个整数，表示数组元素，a[i]<=10 
9
 ，1<=i<=n。
第三行 m 个整数，表示要询问的数字q，q<=10 
9
 。

输出格式:
输出一行，m 个整数，以空格隔开，表示答案。

输入样例:
在这里给出一组输入。例如：

5 2
1 4 6 6 7
2 6
输出样例:
在这里给出相应的输出。例如：

-1 3 

*/ 

#include<iostream>
#include<vector>
using namespace std;
int cha(const vector<int> &a,int b){
    int qian=0,hou=a.size()-1;
    int res=-1;
    while(qian<=hou){
        int mid=(qian+hou)/2;
        if(a[mid]==b){
            res=mid+1;
            hou=mid-1;
        }
        else if(a[mid]>b){
            hou=mid-1;
        }
        else if(a[mid]<b){
            qian=mid+1;
        }
    }
    return res;
}
int main(){
    int n,m,num;
    cin>>n>>m;
    vector<int> a,b;
    for(int i=0;i<n;i++){
        cin>>num;
        a.push_back(num);
    }
    for(int j=0;j<m;j++){
        cin>>num;
        b.push_back(num);
    }
    for(int k:b){
        cout<<cha(a,k)<<" ";
    }
    cout<<endl;
    return 0;
}