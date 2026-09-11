#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//bfs，用一个数组记录所有苹果距离，cnt记录好苹果个数，bfs后cnt不为0判负，res记录当前最大距离
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>> bad;
        queue<pair<int,int>> spread;
        vector<vector<int>> distance(10,vector<int>(10,-1));
        int cnt=0,res=0;
        int movex[]={0,1,0,-1};
        int movey[]={1,0,-1,0};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    bad.push_back({i,j});
                    distance[i][j]=0;
                }
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        for(int i=0;i<bad.size();i++){
            spread.push(bad[i]);
        }
        while(!spread.empty()){
            auto [x,y]=spread.front();
            spread.pop();
            int dist=distance[x][y];
            for(int i=0;i<4;i++){
                int newx=x+movex[i];
                int newy=y+movey[i];
                if(newx<0 || newy<0 || newx>=grid.size() || newy>=grid[0].size() || distance[newx][newy]!=-1 || grid[newx][newy]!=1){
                    continue;
                }
                cnt--;
                spread.push({newx,newy});
                distance[newx][newy]=dist+1;
                res=dist+1;
            }
            if(cnt==0){
                break;
            }
        }
        return cnt ? -1:res;
    }
};