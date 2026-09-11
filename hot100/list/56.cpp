#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //排序然后判断
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            return a[0]<b[0];
        });
        vector<vector<int>> res;
        int left=intervals[0][0],right=intervals[0][1];
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>right){
                vector<int> last({left,right});
                res.push_back(last);
                left=intervals[i][0];
                right=intervals[i][1];
            }else if(intervals[i][0]<=right&&intervals[i][1]>right){
                right=intervals[i][1];
            }
        }
        res.push_back(vector<int> ({left,right}));
        return res;
    }
};