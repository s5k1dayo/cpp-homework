#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //前缀和+哈希表
        int len=nums.size();
        int res=0;
        for(int i=0;i<len;i++){
            int sum=0;
            for(int j=i;j<len;j++){
                sum+=nums[j];
                if(sum==k){
                    res++;
                }
            }
        }
        return res;
    }
};