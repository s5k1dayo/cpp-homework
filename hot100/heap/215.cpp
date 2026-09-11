#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int target;
    int partition(vector<int>& nums,int l,int r){
        if(l>=r){
            return l;
        }
        int random=l+rand()% (r-l+1);
        int pivot=nums[random];
        swap(nums[r],nums[random]);
        int i=l-1;
        int j=r+1;
        while(i<j){
            do i++ ;while(nums[i]>pivot);
            do j-- ;while(nums[j]<pivot);
            if(i<j) swap(nums[i],nums[j]);
        }
        if(j<target){
            return partition(nums,j+1,r);
        }else{
            return partition(nums,l,j);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        target=k-1;
        return nums[partition(nums,0,nums.size()-1)];
    }
};