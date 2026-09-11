#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool res=false;
    string now;
    string tarword;
    vector<vector<bool>> passed;
    void traceback(vector<vector<char>>& board,pair<int,int> pos,int cur){
        if(cur==tarword.size()){
            res=true;
            return ;
        }
        int nextx[]={0,1,0,-1};
        int nexty[]={1,0,-1,0};
        for(int i=0;i<4;i++){
            int curx=pos.first+nextx[i];
            int cury=pos.second+nexty[i];
            if(curx>=0 && curx<board.size() && cury>=0 && cury<board[0].size() && !passed[curx][cury]){
                if(board[curx][cury]==tarword[cur]){
                    passed[curx][cury]=true;
                    traceback(board,{curx,cury},cur+1);
                    passed[curx][cury]=false;
                }
            }
        }
        return;
    }
    bool exist(vector<vector<char>>& board, string word) {
        tarword=word;
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> pass(m,vector<bool>(n,false));
        passed=pass;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    passed[i][j]=true;
                    traceback(board,{i,j},1);
                    passed[i][j]=false;
                }
            }
        }
        return res;
    }
};