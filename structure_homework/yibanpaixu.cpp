#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        a[i]=num;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1]){
                int b=a[j+1];
                a[j+1]=a[j];
                a[j]=b;
            }
        }
    }
    for(int k=0;k<n;k++){
        cout<<a[k];
        if(k!=n-1){
            cout<<" ";
        }
    }
    cout<<endl;
}