#include<bits/stdc++.h>
using namespace std;


class MinStack {
public:
    stack<int> stk;
    stack<int> minstk;

    MinStack() {
        
    }
    
    
    void push(int value) {
        stk.push(value);
        if(minstk.empty()){         //第一次入栈时，minstk是空栈不能直接访问获取最小值
            minstk.push(value);
            return;
        }
        int min=minstk.top();
        minstk.push(min<value ? min:value);
    }
    
    void pop() {
        stk.pop();
        minstk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
    }
};