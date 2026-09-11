#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void traceback(vector<int>& nums,int cur){
        if(cur==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=cur;i<nums.size();i++){
            swap(nums[cur],nums[i]);
            traceback(nums,cur+1);
            swap(nums[cur],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        traceback(nums,0);
        return res;
    }
};