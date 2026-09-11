#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        int real=k%len;
        vector<int> num=nums;
        for(int i=0;i<len;i++){
            nums[i]=num[(i+len-real)%len];
        }
    }
};