#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//从右往左查找最后一个小于nums[0]的元素
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        if(nums[left]<nums[right]){
                return nums[left];
        }
        int res=right;
        int tar=nums[left];
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>=tar){
                left=mid+1;
            }else if(nums[mid]<tar){
                res=mid;
                right=mid-1;
            }
        }
        return nums[res];
    }
};