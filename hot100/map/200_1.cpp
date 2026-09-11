#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//类中定义引用类型成员变量，引用必须初始化，编译器无法生成默认无参构造函数
    
    void dfs(pair<int,int> cur,vector<vector<char>>& grids){
        int x=cur.first;
        int y=cur.second;
        grids[x][y]='0';
        if(x+1<grids.size() && grids[x+1][y]=='1') dfs({x+1,y},grids);
        if(x-1>=0 && grids[x-1][y]=='1') dfs({x-1,y},grids);
        if(y+1<grids[0].size() && grids[x][y+1]=='1') dfs({x,y+1},grids);
        if(y-1>=0 && grids[x][y-1]=='1') dfs({x,y-1},grids);

    }
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs({i,j},grid);
                    res++;
                }
            }
        }
        return res;
    }
};