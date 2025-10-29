#include<iostream>
using namespace std;
void pai(int a[],int len){
    for(int i=len-1;i>0;i--){
        if(a[i]<a[i-1]){
            int b=a[i];
            a[i]=a[i-1];
            a[i-1]=b;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<3;i++){
        pai(a,n);
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}