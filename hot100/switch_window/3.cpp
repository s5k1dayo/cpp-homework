#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
            unordered_set<char> have;
            for(int j=i;j<s.size();j++){
                char cur=s[j];
                if(have.count(cur)){
                    break;
                }else{
                    have.insert(cur);
                }
            }
            int cur=have.size();
            res=max(cur,res);
        }
        return res;
    }
};