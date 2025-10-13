#include <iostream>
#include <string>
using namespace std;
int main(){
	
string qian="99999999999999999999999999";
string hou="1";
if(qian.length()<hou.length()){
	string t=qian;
	qian=hou;
	hou=t;
}
int lqian=qian.length();
int lhou=hou.length();
int shu[lqian]={0};
int jinwei=0;
for( int i=1;i<=lhou;i++){
	shu[lqian-i]=qian[lqian-i]-'0'+hou[lhou-i]-'0';
	if(shu[lqian-i]>=10 && i!=lqian){
		shu[lqian-i]-=10;
		shu[lqian-i-1]++;
	}
}
for(int j=lhou+1;j<=lqian;j++){
	shu[lqian-j]+=qian[lqian-j]-'0';
	if(shu[lqian-j]>=10 && j!=lqian){
		shu[lqian-j]-=10;
		shu[lqian-j-1]++;
	}
	if(shu[lqian-j]>=10 && j==lqian){
		shu[lqian-j]-=10;
		jinwei=1;
	}
	
}
if(jinwei){
	string shu1;
	for(int i=0;i<=lqian;i++){
		if(i==0){
			shu1.push_back('1');
			continue;
		}
		shu1.push_back((char)shu[i-1]+'0');
	}
	cout<< shu1;
}
string shu2;
for(int i=0;i<lqian;i++){
	shu2[i]=shu[i];
}
cout<<shu2;
	return 0;
}
