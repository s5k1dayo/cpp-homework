#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   //这集神了：curstr保存当前获取字符串，curint保存当前读取倍数，遇到[入库pair的curstr和curint，同时继续收集curstr，遇到]出栈，用之前加上倍数乘当前
    string decodeString(string s) {
        stack<pair<int,string>> stk;
        int curint=0;
        string curstr;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                curint=curint*10+s[i]-'0';
            }else if(s[i]=='['){
                stk.push({curint,curstr});
                curstr="";
                curint=0;
            }else if(s[i]==']'){
                pair<int,string> stktop=stk.top();
                stk.pop();
                string combine=stktop.second;
                for(int j=0;j<stktop.first;j++){
                    combine.append(curstr);
                }
                curstr=combine;
            }else{
                curstr.push_back(s[i]);
            }
        }
        return curstr;
    }
};