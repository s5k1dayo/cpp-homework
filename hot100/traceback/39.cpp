#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> now;
    void traceback(vector<int>& candidates,int target,int sum,int cur){
        if(sum==target){
            res.push_back(now);
            return;
        }
        if(sum>target || cur>=candidates.size()){
            return;
        }
        int num=candidates[cur];
        now.push_back(num);
        traceback(candidates,target,sum+num,cur);
        now.pop_back();
        traceback(candidates,target,sum,cur+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        traceback(candidates,target,0,0);
        return res;
    }
};