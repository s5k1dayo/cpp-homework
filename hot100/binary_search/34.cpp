#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//两次二分分别找出左边界和右边界,一次当作大于等于,一次当作小于等于处理,只有等于时才记录
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1,last=-1;
        bool found=false;
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]<target){
                left=mid+1;
            }else if(nums[mid]==target){
                found=true;
                right=mid-1;
                first=mid;
            }
            else {   
                right=mid-1;
            }
        }
        if(!found){
            return vector<int> ({-1,-1});
        }
        left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>target){
                right=mid-1;
            }else if(nums[mid]==target){
                left=mid+1;
                last=mid;
            }else{
                left=mid+1;
            }
        }
        return vector<int> ({first,last});
    }
};