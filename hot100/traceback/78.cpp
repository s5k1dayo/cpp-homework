#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> now;
    void traceback(vector<int>& nums,int cur){
        if(cur==nums.size()){
            res.push_back(now);
            return;
        }
        now.push_back(nums[cur]);
        traceback(nums,cur+1);
        now.pop_back();
        traceback(nums,cur+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        traceback(nums,0);
        return res;
    }
};