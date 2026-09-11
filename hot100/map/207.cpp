#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //bfs拓扑判环法:依次删除0入度的点，删除时将后续点入度-1，如果有剩余则有环
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,int> incount;
        vector<vector<int>> save(numCourses,vector<int>());
        queue<int> zero;
        int cnt=0;
        for(int i=0;i<numCourses;i++){
            incount[i]=0;
        }
        for(int i=0;i<prerequisites.size();i++){
            int outnum=prerequisites[i][1];
            int innum=prerequisites[i][0];
            save[outnum].push_back(innum);
            incount[innum]++;
        }
        for(auto &item : incount){
            int k=item.first;
            int v=item.second;
            if(v==0){
                zero.push(k);
                cnt++;
            }
        }
        while(!zero.empty()){
            int cur=zero.front();
            zero.pop();
            for(int i=0;i<save[cur].size();i++){
                int next=save[cur][i];
                incount[next]--;
                if(incount[next]==0){
                    zero.push(next);
                    cnt++;
                }
            }
        }
        if(cnt<numCourses){
            return false;
        }
        return true;
    }
};