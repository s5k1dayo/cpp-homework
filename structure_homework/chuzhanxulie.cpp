#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
int main(){
    string in;
    string out;
    stack<char> st;
    vector<char> res;
    cin>>in>>out;
    int in_ptr=0;
    int out_ptr=0;
    int n=in.length();
    if(in.length()!=out.length()){
        cout<<"wrong"<<endl;
        cout<<endl;
        return 0;
    }
    while(in_ptr<n){
        st.push(in[in_ptr]);
        in_ptr++;
        res.push_back('P');
        while(!st.empty()&&out_ptr<n&&st.top()==out[out_ptr]){
            st.pop();
            res.push_back('O');
            out_ptr++;
        }
    }
    if(out_ptr==n && st.empty()){
        cout<<"right"<<endl;
        for(char i:res){
            cout<<i;
        }
    }
    else{
        cout<<"wrong"<<endl;
        vector<char> remain;
        while(!st.empty()){
            remain.push_back(st.top());
            st.pop();
        }
        for(int i=remain.size()-1;i>=0;i--){
            cout<<remain[i];
        }
    }
    return 0;
}