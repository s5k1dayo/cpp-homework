#include<iostream>
#include<vector>
using namespace std;
bool isbig(vector<int>& a){
    for(int i=0;i<a.size()/2;i++){
        int left=2*i+1;
        int right=2*i+2;
        if(a[i]<a[left] ){
            return false;
        }
        if(right<a.size() && a[i]<a[right] ){
            return false;
        }
    }
    return true;

}
bool issmall(vector<int>& a){
    for(int i=0;i<a.size()/2;i++){
        int left=2*i+1;
        int right=2*i+2;
        if(a[i]>a[left] ){
            return false;
        }
        if(right<a.size() && a[i]>a[right] ){
            return false;
        }
    }
    return true;

}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(!isbig(a)&&!issmall(a)){
        cout<<"这不是堆"<<endl;
    }
    else if(isbig(a)){
        cout<<"这是大根堆"<<endl;
    }
    else if(issmall(a)){
        cout<<"这是小根堆"<<endl;
    }
    return 0;
}