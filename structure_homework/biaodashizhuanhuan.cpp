#include<iostream>
#include<string>
#include<stack>
using namespace std;
void kuohao(int b,string n){
    while(n[b]!=')'){
        b++;
    }
}
int find(int typ,int b,int len,string n){
    if (typ==1){
        while(n[b]!='+' && n[b]!='-'){
            b++;
            if(n[b]=='('){

            }
        }
    }
}
int main(){
    stack<int> sta;
    string n,out;
    cin>>n;
    int len=n.length();
    int shu[len],count=0;
    for(int i=0;i<len;i++){
        if(0<=n[i]-'0'<=9){
            out[count]=n[i];
            count++;
        }
        else if (n[i]=='+'){
            
        }
        
    }
}