#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> wordmp;
        vector<vector<string>> result;
        for(int i=0;i<strs.size();i++){
            string word=strs[i];
            string upword=word;
            sort(upword.begin(),upword.end());
            if(wordmp.count(upword)){
                wordmp[upword].push_back(i);
            }else{ 
                wordmp[upword]=vector<int>(1,i);
            }
        }
        for(auto it=wordmp.begin();it!=wordmp.end();it++){
            vector<string> group;
            for(int j=0;j<it->second.size();j++){
                group.push_back(strs[it->second[j]]);
            }
            result.push_back(group);
        }
        return result;
    }
};