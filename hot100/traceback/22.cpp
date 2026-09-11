#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> res;
    string now;
    void traceback(int left,int right){
        if(!left && !right){
            res.push_back(now);
            return;
        }
        if(left!=0){
            now.push_back('(');
            traceback(left-1,right);
            now.pop_back();
        }
        if(right!=0 && right>left){
            now.push_back(')');
            traceback(left,right-1);
            now.pop_back();
        }

        
    }
    vector<string> generateParenthesis(int n) {
        traceback(n,n);
        return res;
    }
};