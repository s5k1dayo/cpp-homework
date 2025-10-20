#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool bigger(string a,string b){
    if(a.length()>b.length()){
        return 1;
    }
    else{
        return 0;
    }
}

string summ(string a,string b){
    int al=a.length();
    int bl=b.length();
    string sum;
    int jinwei[al]={0};
    for(int i=1;i<=bl;i++){
        int he=a[al-i]+b[bl-i]+jinwei[al-i];
        if(he>=10){
            he=he%10;
            jinwei[al-i-1]=1;
        }
        sum[al-i]=he;
    }
    for(int i=al-bl;i>0;i++){
        int he=a[i]+jinwei[i];
        if(he>=10){
            he=he%10;
            jinwei[i-1]=1;
        }
        sum[i]=he;
    }
    if(jinwei[0]==1){
        for(int i=al;i>0;i--){
            sum[i]=sum[i-1];
        }
        sum[0]=1;
    }
    return sum;

}

int main (){
    vector <string> A,sum;
    string str;
    int leng=0;
    while(cin>>str){
        A.push_back(str);
        leng++;
    }
    for(int i=0;i<leng/2;i++){
        if(bigger(A[2*i],A[2*i+1])){
            sum[i]=summ(A[2*i],A[2*i+1]);
        }
        else{
            sum[i]=summ(A[2*i+1],A[2*i]);
        }
    }
    for(int i=0;i<leng;i++){
        cout<<A[i]<<endl;
    }
}