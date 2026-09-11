#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left=0,right=matrix.size()-1;
        int row;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(matrix[mid][0]<=target){
                row=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        left=0,right=matrix[0].size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(matrix[row][mid]<target){
                left=mid+1;
            }else if(matrix[row][mid]>target){
                right=mid-1;
            }else if(matrix[row][mid]==target){
                return true;
            }
        }
        return false;
    }
};