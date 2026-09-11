#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        map<char,char> dic={
            {'(',')'},
            {'{','}'},
            {'[',']'}
        };
        for(char a :s){
            if(a=='(' || a=='{' || a=='['){
                stk.push(a);
            }else{
                if(stk.empty()){
                    return false;
                }
                char topa=stk.top();
                if(dic[topa]!=a){
                    return false;
                }
                stk.pop();
            }
        }
        if(stk.empty()){
            return true;
        }
        return false;
    }
};