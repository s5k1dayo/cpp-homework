#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int n,t;
    cin>>n>>t;
    vector<long long> a(n);
    unordered_map<long long,int> cnt;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=0;i<n;i++){
        long long x=a[i];
        long long px=t-x;
        if(cnt.find(px)==cnt.end()){
            cout<<x<<" ";
        }
        else if(px==x && cnt[x]<2){
            cout<<x<<" ";
        }
    }
    return 0;
}