#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0];
        int res=0;
        for(int price:prices){
            if(price<min){
                min=price;
            }else{
                int cur=price-min;
                res= cur>res? cur:res;
            }
        }
        return res;
    }
};