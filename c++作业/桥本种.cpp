#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	string str[20];
	int N;
	string s="qiao ben zhong.";
	string t="Skipped";
	cin>>N;
	getchar();
	for(int i=0;i<N;i++){
		getline(cin,str[i]);
		if(str[i].find("ong,")!=string::npos){
			if(str[i].find("ong.")!=string::npos){
				int k=0,f=0;
				unsigned int j=str[i].size();
				for(;j>0;j--){
					if(k==3){
						break;
					}
					else{
						if(str[i][j]==' '){
							k++;
						}
						f++;
					}
				}
				str[i].replace(j+2,f,s);
			}
			else{
				str[i].replace(0,str[i].length(),t);
			}
		}
		else{
			str[i].replace(0,str[i].length(),t);
		}
	}
	for(int i=0;i<N;i++){
		cout<<str[i]<<endl;
	}
	return 0;
}
