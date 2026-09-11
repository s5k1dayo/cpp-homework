#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back(vector<int> (1,1));
        for(int i=2;i<=numRows;i++){
            vector<int> cur(i,0);
            for(int j=0;j<i;j++){
                if(j==0||j==i-1){
                    cur[j]=1;
                }else{
                    cur[j]=res[i-1-1][j-1]+res[i-1-1][j];
                }

            }
            res.push_back(cur);
        }
        return res;
    }
};