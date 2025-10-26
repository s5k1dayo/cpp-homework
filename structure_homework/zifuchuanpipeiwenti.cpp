#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==0){
        cout<<"YES";
    }
    stack<int> sta;
    int a=0,b=0,c=0,d=0;
    for(int i=0;i<n;i++){
        string shuru;
        cin>>shuru;
        int flag=1;
        for(int j=0;j<shuru.length();j++){
            if(shuru[j]=='<'){
                sta.push(10);
                a+=1;
            }
            else if(shuru[j]=='>'){
                if(sta.empty()){
                    cout<<"NO"<<endl;
                    flag=0;
                    break;
                }
                int cur=sta.top();
                if(cur==10){
                    sta.pop();
                }
                else{
                    cout<<"NO"<<endl;
                    flag=0;
                    break;
                }
            }
            
            
            else if(shuru[j]=='('){
                if(sta.empty()){
                    sta.push(20);
                    b+=1;
                }
                else{
                int cur=sta.top();
                if(cur<20){
                    cout<<"NO"<<endl;
                    flag=0;
                    break;
                }
                sta.push(20);
                b+=1;
                }
            }
            else if(shuru[j]==')'){
                if(sta.empty()){
                    cout<<"NO"<<endl;
                    flag=0;
                    break;
                }
                int cur=sta.top();
                if(cur==20){
                    sta.pop();
                }
                else{
                    cout<<"NO"<<endl;
                    flag=0;
                    break;
                }
            }
           
           
            else if(shuru[j]=='['){
                if(sta.empty()){
                    sta.push(30);
                    b+=1;
                }
                else{
                int cur=sta.top();
                if(cur<30){
                    cout<<"NO"<<endl;
                    flag=0;
                    break;
                }
                sta.push(30);
                c+=1;
                }
            }
            else if(shuru[j]==']'){
                if(sta.empty()){
                    cout<<"NO"<<endl;
                    flag=0;
                    break;
                }
                int cur=sta.top();
                if(cur==30){
                    sta.pop();
                }
                else{
                    cout<<"NO"<<endl;
                    flag=0;
                    break;
                }
            }

            else if(shuru[j]=='{'){
                if(sta.empty()){
                    sta.push(40);
                    d+=1;
                }
                else{
                int cur=sta.top();
                if(cur<40){
                    cout<<"NO"<<endl;
                    flag=0;
                    break;
                }
                sta.push(40);
                d+=1;
                }
            }
            else if(shuru[j]=='}'){
                if(sta.empty()){
                    cout<<"NO"<<endl;
                    flag=0;
                    break;
                }
                int cur=sta.top();
                if(cur==40){
                    sta.pop();
                }
                else{
                    cout<<"NO"<<endl;
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1){
        if(sta.empty()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    }
    

}
