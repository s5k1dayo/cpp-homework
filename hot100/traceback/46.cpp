#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    //可以通过交换前后位置直接完成，不必新建这么多变量储存，每次循环交换当前调整位置的数字和循环到的数字
    
    vector<int> Nums;
    void collect(int cur,vector<int>& visited,vector<int>& now){
        if(cur==Nums.size()){
            res.push_back(now);
            return;
        }
        for(int i=0;i<Nums.size();i++){
            auto it=find(visited.begin(),visited.end(),Nums[i]);
            if(it==visited.end()){
                now.push_back(Nums[i]);
                visited.push_back(Nums[i]);
                collect(cur+1,visited,now);
                now.pop_back();
                visited.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        Nums=nums;
        vector<int> visit;
        vector<int> now;
        collect(0,visit,now);
        return res;
    }
};