#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {//动态规划，位置i的最大值分情况可能等于most[i-1]+nums[i],most[i-1]或most[i-2]+nums[i]
        vector<int> most;
        vector<bool> lastvisit;
        if(nums.size()==1){
            return nums[0];
        }
        most.push_back(nums[0]);
        lastvisit.push_back(true);
        if(nums[0]>nums[1]){
            most.push_back(nums[0]);
            lastvisit.push_back(false);
        }else{
            most.push_back(nums[1]);
            lastvisit.push_back(true);
        }
        for(int i=2;i<nums.size();i++){
            if(!lastvisit[i-1]){
                most.push_back(most[i-1]+nums[i]);
                lastvisit.push_back(true);
            }else if(most[i-1]>most[i-2]+nums[i]){
                most.push_back(most[i-1]);
                lastvisit.push_back(false);
            }else{
                most.push_back(most[i-2]+nums[i]);
                lastvisit.push_back(true);
            }
        }
        return most[nums.size()-1];
    }
};