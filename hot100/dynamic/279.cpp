#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {//对于每个n都要从0开始维护前i的最小和
        vector<int> res;
        res.push_back(0);
        for(int i=1;i<=n;i++){
            int sq=sqrt(i);
            int less=i;
            for(int j=1;j<=sq;j++){
                int cur=res[i-j*j]+1;
                less=less>cur? cur:less;
            }
            res.push_back(less);
            //cout<<"res["<<i<<"]="<<less<<endl;
        }
        return res[n];
    }
};