#include<iostream>
using namespace std;
int main(){
    int a,shou,wei,sum=0;
    cin>>a;
    int A[a];
    for (int i=0;i<a;i++){
        cin>>A[i];
    }
    cin>>shou>>wei;
    for (int i=0;i<a;i++){
        if(A[i]>=shou && A[i]<=wei){
            sum+=A[i];
        }
    }
    cout<<sum;
}