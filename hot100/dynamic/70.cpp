#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> ways;
        ways.push_back(1);
        ways.push_back(1);
        for(int i=2;i<=n;i++){
            int way=ways[i-1]+ways[i-2];
            ways.push_back(way);
        }
        return ways[n];
    }
};