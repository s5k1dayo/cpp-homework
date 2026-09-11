#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//通过比较mid和left判断左/右有序，通过有序区间判断tar在左区/右区
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(target==nums[mid]){
                return mid;
            }
            if(nums[mid]<nums[left]){
                if(target<=nums[right] && target>nums[mid]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }else if(nums[mid]>nums[left]){
                if(target<nums[mid] && target>=nums[left]){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }else{
                left++;
            }
        }
        return -1;
    }
};