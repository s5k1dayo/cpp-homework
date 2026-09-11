#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//将每个数字对应的字母存到顺序表中
    unordered_map<int,string> letter;
    string now;
    vector<string> res;
    void traceback(vector<int> nums,int cur){
        if(cur==nums.size()){
            res.push_back(now);
            return;
        }
        for(char a :letter[nums[cur]]){
            now.push_back(a);
            traceback(nums,cur+1);
            now.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<int> nums;
        char cura='a';
        for(int i=2;i<10;i++){
            string letters="";
            if(i==7 || i==9){
                for(int j=0;j<4;j++){   
                    letters.push_back(cura);
                    cura++;
                }
            }else{
                for(int j=0;j<3;j++){
                    letters.push_back(cura);
                    cura++;
                }
            }
            letter[i]=letters;
        }
        for(char a : digits){
            nums.push_back(a-'0');
        }
        traceback(nums,0);
        return res;
    }
};