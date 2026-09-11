#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {//先遍历一遍得到每个字母最后出现，再遍历维护当前切割必须最远位置，i=位置直接切
        unordered_map<char,int> lastappear;
        for(int i=0;i<s.size();i++){
            char letter=s[i];
            lastappear[letter]=i;
            //cout<<"lastappear "<<letter<<"="<<i<<endl;
        }
        int nxtcut=-1,cursize=0;
        vector<int> res;
        for(int i=0;i<s.size();i++){
            cursize++;
            char letter=s[i];
            nxtcut=lastappear[letter]>nxtcut ?lastappear[letter]:nxtcut;
            //cout<<"i="<<i<<endl;
            //cout<<"nextcut="<<nxtcut<<endl;
            if(i==nxtcut){
                res.push_back(cursize);
                cursize=0;
                continue;
            }
        }
        return res;
    }
};