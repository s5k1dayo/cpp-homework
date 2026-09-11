#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //小数组用bool列表比哈希快
        int height=matrix.size();
        int weight=matrix[0].size();
        vector<bool> zerox(height,false),zeroy(weight,false);
        for(int i=0;i<height;i++){
            for(int j=0;j<weight;j++){
                if(matrix[i][j]==0){
                   zerox[i]=true;
                   zeroy[j]=true;
                }
            }
        }
        for(int i=0;i<height;i++){
            for(int j=0;j<weight;j++){
                if(zerox[i]||zeroy[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
//当前开了m+n的列表，空间复杂度m+n，空间复杂度更小做法：用矩阵第0行，0列记录需要置零的行列，空间复杂度1；