/*
7-3 用两个栈实现队列
分数 15
作者 陈越
单位 浙江大学
一个队列（先进先出结构）可以用两个堆栈（后进先出结构）来实现，方法如下：

从两个空堆栈 s 
1
​
  和 s 
2
​
  开始。
当元素 e 入队时，它实际上是被推入到 s 
1
​
 。
当我们需要出队时，首先检查 s 
2
​
 。如果 s 
2
​
  是空的，则把 s 
1
​
  中的元素全部导入 s 
2
​
 ，即将每个元素从 s 
1
​
  弹出后马上推入 s 
2
​
 。然后从 s 
2
​
  中弹出元素 —— s 
2
​
  顶端元素一定是第一个进入 s 
1
​
  的，所以是应该出列的第一个元素。
假设每个堆栈的推入和弹出操作都用 1 个单位时间，请你给出每个出队操作所花的时间。

输入格式：
输入首先在一行中给出一个正整数 N（≤10 
3
 ），是操作数量。随后 N 行，每行按以下格式给出一个操作：

操作 元素
其中 操作 或者是 I 表示入队，或者是 O 表示出队。每个 I 后面跟的 元素 是一个不超过 10 
6
  的正整数。O 操作后面不跟任何元素。
题目保证至少有一个 O 操作。

输出格式：
对每个出队操作，在一行中输出出队的那个元素和这出队操作所花费的单位时间数量，其间以 1 个空格分隔，行首尾不得有多余空格。
若出队操作被调用时队列是空的，则在对应行中输出 ERROR。

输入样例：
10
I 20
I 32
O
I 11
O
O
O
I 100
I 66
O
输出样例：
20 5
32 1
11 3
ERROR
100 5

*/
#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> a,b;
    int n,shu,ru=0;
    char io;
    cin>>n;

    for(int i=0;i<n;i++){
        int count=0;
        cin>>io;
        if(io=='I'){
            cin>>shu;
            a.push(shu);
            ru+=1;
        }
        if(io=='O'){
            if(b.empty() && a.empty()){
                cout<<"ERROR"<<endl;
                continue;
            }
            else if(b.empty()){
            for(int j=0;j<ru;j++){
                b.push(a.top());
                a.pop();
                count+=2;
            }
            ru=0;
        }   

            cout<<b.top()<<" ";
            b.pop();
            count++;
            cout<<count<<endl;
        }
    }
}