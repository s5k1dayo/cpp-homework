#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        //取n值下标为0以免遇到一列情况越界
        int n=matrix[0].size();
        int type=0,cnt=0,x=0,y=0;
        vector<vector<bool>> flag (m,vector<bool> (n,false));
        vector<int> res;
        while(cnt<m*n){
            flag[x][y]=true;
            res.push_back(matrix[x][y]);
            cnt++;
            //switch每个情况结尾必须break;
            switch (type%4){
                case 0:
                if(y+1==n ){
                    type++;
                    x++;
                    break;
                }else if(flag[x][y+1]){
                    type++;
                    x++;
                }
                else{
                    y++;
                }
                break;
                case 1:
                if(x+1==m){
                    type++;
                    y--;
                    break;
                }else if(flag[x+1][y]){
                    type++;
                    y--;
                }
                else{
                    x++;
                }
                break;
                case 2:
                if(y==0){
                    type++;
                    x--;
                    break;
                }else if(flag[x][y-1]){
                    type++;
                    x--;
                }
                else{
                    y--;
                }
                break;
                case 3:
                if(flag[x-1][y]){
                    type++;
                    y++;
                }else{
                    x--;
                }
                break;
            }
            
        }
        return res;
    }
};
//还有一种解法是按照从外到内的层逐层输出;