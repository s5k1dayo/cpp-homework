#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        if(coins.size()==1 && amount%coins[0]!=0){
            return -1;
        }
        vector<int> res(amount+1,-1);
        sort(coins.begin(),coins.end());
        int curmax=0;
        res[0]=0;
        for(int i=coins[0];i<=amount;i++){
            if(curmax<coins.size()-1 && i>=coins[curmax+1]){
                curmax++;
            }
            int less=amount+1;
            for(int j=0;j<=curmax;j++){
                if(res[i-coins[j]]==-1){
                    continue;
                }else{
                    int cur=res[i-coins[j]]+1;
                    less=less>cur? cur:less;
                }
            }
            if(less!=amount+1){  //提前设置了默认值-1，必须判断如果遍历硬币都不行不能直接用less覆盖，而是保持-1
                res[i]=less;
            }
            
        }
        return res[amount];
    }
};