#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//每到一个下标先处理栈中没有找到更大值的元素，最后再把当前下标入栈
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size(),0);
        for(int i=1;i<temperatures.size();i++){
            while(!stk.empty()){
                int topt=stk.top();
                if(temperatures[topt]<temperatures[i]){
                    stk.pop();
                    res[topt]=i-topt;
                }else{
                    break;
                }
            }
            stk.push(i);
        }
        return res;
    }
};