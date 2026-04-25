#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a,b,c;
    vector<int> v;
    cin>>a;
    for(int i=0;i<a;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    cin>>b>>c;
    int sum=0;
    for( int j : v){
        if(j>=b && j<=c){
            sum+=j;
        }
    }
    cout<<sum<<endl;
}

