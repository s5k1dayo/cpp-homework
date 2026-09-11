#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {//遍历每个元素,依次维护当前能到达的最远值
        int max=0;
        for(int i=0;i<nums.size();i++){
            if(i>max){
                return false;
            }
            int far=i+nums[i];
            max=max>far ? max:far ;
        }
        return true;
    }
};