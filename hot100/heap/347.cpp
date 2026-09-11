#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> Count;
        for(int num:nums){
            if(Count.count(num)){
                Count[num]++;
            }else{
                Count[num]=1;
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        for(auto it=Count.begin();it!=Count.end();it++){
            if(heap.size()==k){
               int TopNum=heap.top().first;
               if(it->second > TopNum){
                heap.pop();
                heap.push({it->second,it->first});
               }
            }else{
                heap.push({it->second,it->first});
            }
        }
        vector<int> res;
        while(!heap.empty()){
            int cur=heap.top().second;
            res.push_back(cur);
            heap.pop();
        }
        return res;
    }
};