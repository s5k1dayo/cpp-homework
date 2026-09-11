#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int yesx=0,yesy=0;
        for(int i=0;i<m;i++){
            int first=matrix[i][0];
            int last=matrix[i][n-1];
            if(first==target || last==target){
                return true;
            }
            if(first<target  &&  last>target){
                yesx=i;
            }else if(first>target){
                break;
            }
        }
        for(int i=0;i<n;i++){
            int first=matrix[0][i];
            int last=matrix[m-1][i];
            if(first==target || last==target){
                return true;
            }
            if(first<target  &&  last>target){
                yesy=i;
            }else if(first>target){
                break;
            }
        }
        for(int i=0;i<=yesx;i++){
            for(int j=0;j<=yesy;j++){
                if(matrix[i][j]==target){
                    return true;
                }
                if(matrix[i][j]>target){
                    break;
                }
            }
        }
        return false;
    }
};
//z字寻找,从[0,n-1]开始,如果当前位置比目标大,往左移,若比目标小,往右移;
