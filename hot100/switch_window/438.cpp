#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> letter(26,0);
        vector<int> cur(26,0);
        vector<int> res;
        int len=p.size();
        //考虑p长度大于s情况
        if(len>s.size()){
            return vector<int>();
        }
        for(int i=0;i<len;i++){
            int num=p[i]-'a';
            letter[num]++;
        }
        for(int i=0;i<len;i++){
            int num=s[i]-'a';
            cur[num]++;
        }
        if(cur==letter){
                res.push_back(0);
            }
        int a=1;
        while(a<=s.size()-len){
            cur[s[a-1]-'a']--;
            cur[s[a+len-1]-'a']++;
            if(cur==letter){
                res.push_back(a);
            }
            a++;
        }
        return res;
    }
};