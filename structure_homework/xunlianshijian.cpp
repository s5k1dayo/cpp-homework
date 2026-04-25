/*
7-3 训练时间
分数 10
作者 mjye
单位 北京师范大学珠海校区
在深度学习任务中，我们有 n 个模型需要训练，每个模型的训练时间已知，记作数组 a[i]（表示第 i 个模型的训练时间）。 现在，我们有 m 张 GPU 可供并行训练。
为了减少训练总时长，我们需要合理地将 n 个模型顺序地分配给 m 张 GPU，使得所有 GPU 训练完成的最长时间尽可能小。
注意：

任务必须从左到右连续分配，即某个 GPU 负责的模型必须是数组 a 中的一段连续子序列。
每个模型必须且只能被分配给一个 GPU 进行训练。
GPU 之间可以并行训练，但我们关心的是最晚完成任务的 GPU，即所有 GPU 训练完成的最短可能时间。
输入格式:
第一行：两个整数 n 和 m（1≤m≤n≤10 
5
 ），分别表示模型数和GPU数。
第二行：n 个整数 a[i](1≤a[i]≤10 
9
 )，表示每个模型的训练时间，每个数之间用一个空格分隔。

输出格式:
一个整数，表示最优任务分配方案下，所有 GPU 训练完成的最短可能时间。

输入样例:
4 2
3 1 4 7
输出样例:
8

样例解释
可能的任务分配方式如下：

方案 1：【3】，【1，4，7】，最长时间12。
方案 2：【3，1】，【4，7】，最长时间11。
方案 3：【3，1，4】，【7】，最长时间8。
最终，最优方案的完成时间为 8。
*/
#include<iostream>
#include<vector>
using namespace std;
bool ke(const vector<long long> &a,long long  mid,long long ge){
    long long yong=0,cur=0;
    for(long long i:a){
        long long he=cur+i;
        if(he>mid){
            cur=i;
            yong+=1;
        }
        else{
            cur+=i;
        }
    }
    if(cur!=0)yong+=1;
    if(yong<=ge){
        return 1;
    }
    return 0;
}
//传入项目数组，显卡个数，max,sum输出最短完成时间
long long xun(const vector<long long> &a,long long m,long long max,long long sum){
    //二分查找，顺序从max到sum
    long long  qian=max,hou=sum;
    long long  res;
    while(qian<=hou){
        long long mid=qian+(hou-qian)/2;
        //有一个函数，输入项目数组，时间，显卡数，输出是否
        if(ke(a,mid,m)){
            hou=mid-1;
            res=mid;
        }
        else{
            qian=mid+1;
        }
    }
    return res;
}
int main(){
    long long n,m,num,sum=0,max=0;
    cin>>n>>m;
    vector<long long> a;
    for(int i=0;i<n;i++){
        cin>>num;
        sum+=num;
        if(num>max)max=num;
        a.push_back(num);
    }
    cout<<xun(a,m,max,sum);
    return 0;
}