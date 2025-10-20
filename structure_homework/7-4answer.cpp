#include<iostream>
#include<string>
using namespace std;
int main(){
    string a,b,da,xiao,sum,he;
    int Da,Xi;
    while(cin>>a>>b){
        int jw=0;
        sum="";
        if(a.size()>=b.size()){
            da=a;
            xiao=b;
        }
        else{
            da=b;
            xiao=a;
        }
        for(int i=1;i<=xiao.size();i++){
            Da=da[da.size()-i]-'0';
            Xi=xiao[xiao.size()-i]-'0';
            he=(Da+Xi+jw)%10+'0';
            sum=he+sum;
            jw=(Da+Xi+jw)/10;
        }
        for(int i=da.size()-xiao.size()-1;i>=0;i--){
            Da=da[i]-'0';
            he=(Da+jw)%10+'0';
            sum=he+sum;
            jw=(Da+jw)/10;
        }
        if(jw==1){
            sum="1"+sum;
        }
        cout<<sum<<endl;
    }
}