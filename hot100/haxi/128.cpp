#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int max=0;
        //哈希表自动去重，第二次遍历表即可，继续遍历顺序表会超时
        for(auto it=st.begin();it!=st.end();it++){
            int cur=*it;
            int sum=0;
            //若有比当前元素小1的值则当前不是开头，跳过
            if(st.count(cur-1)){
                continue;
            }
            //没有则当前元素是开头，从当前元素开始查询连续序列
            else{
                while(st.count(cur)){
                    sum++;
                    cur++;
                }
                if(sum>max){
                    max=sum;
                }
            }
        }
        return max;
    }
};