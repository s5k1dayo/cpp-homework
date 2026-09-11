#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //动态规划,求以i结尾的连续最大子序列
        vector<int> frontmax;
        int res=nums[0];
        frontmax.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            int diff=frontmax[i-1]+nums[i];
            int cur;
            if(diff<nums[i]){
                frontmax.push_back(nums[i]);
                cur=nums[i];
            }else{
                frontmax.push_back(diff);
                cur=diff;
            }
            res=max(cur,res);
        }
        return res;
    }
};