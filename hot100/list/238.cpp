#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //L和R保存左侧所有积和右侧所有积
        int len=nums.size();
        vector<int> L,R;
        vector<int> res;
        int cur=1;
        L.push_back(1);
        R.push_back(1);
        for(int i=0;i<len;i++){
            cur*=nums[i];
            L.push_back(cur);
        }
        cur=1;
        for(int i=len;i>=0;i--){
            cur*=nums[i];
            R.push_back(cur);
        }
        for(int i=0;i<len;i++){
            res.push_back(L[i]*R[len-i]);
        }
        return res;
    }
};