#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
//连续分割问题:固定一个起点,遍历后续所有点作为终点
    vector<vector<string>> res;
    vector<string> now;
    bool ispartition(string now){
        if(now==""){
            return false;
        }
        for(int i=0;i<now.size()/2;i++){
            int end=now.size()-1-i;
            if(now[i]!=now[end]){
                return false;
            }
        }
        return true;
    }

    void traceback(string s,int cur){
        if(cur==s.size()){
            res.push_back(now);
            return;
        }
        string part;
        for(int i=cur;i<s.size();i++){
            part.push_back(s[i]);
            if(ispartition(part)){
                now.push_back(part);
                traceback(s,i+1);
                now.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        traceback(s,0);
        return res;
    }
};