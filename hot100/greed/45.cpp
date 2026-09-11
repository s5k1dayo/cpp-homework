#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {//对每一个位置能到的距离遍历,寻找能走的最远距离,距离达到终点停止
        int step=0,cur=0;
        int far=0,last=0;
        if(nums.size()==1){
            return 0;
        }
        while(cur<nums.size()-1){
            int len=nums[cur];
            step++;
            if(len+cur>=nums.size()-1){
                break;
            }
            for(int i=1;i<=len;i++){
                if(cur+i+nums[cur+i]>far){
                    far=cur+i+nums[cur+i];
                    last=cur+i;
                }
            }
            cur=last;
        }
        return step;
    }
};