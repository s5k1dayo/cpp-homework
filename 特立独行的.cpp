#include<iostream>
using namespace std;
int  Jilu[10001];
int m,n;
int sum(int a){
	int shi=10,wei=1,b[4],ping=0;
	for(int i=0;i<4;i++){
		if(a/shi>0){
			wei++;
			shi*=10;
		}
	}
	for(int j=0;j<wei;j++){
		b[j]=a%10;
		a=a/10;
		ping=ping+b[j]*b[j];
	}
	return ping ;
}


int su(int a){
	if(a==1) return 0;
	for(int i=2;i<a/2;i++){
		if(a%i==0){
			return 0;
		}
	}
	return 1;
}
int duli(int x){
	for(int i=n;i<=m;i++){
		if(Jilu[i]==x){
			return  0;
		}
	}
	return 1;
}
int xingfu(int x){
	int p[10001];
	int i,j;
	int  a=x;
	for(i=0;Jilu[a]!=1;i++){
		p[i]=Jilu[a];
		a=Jilu[a];
		for(j=0;j<i;j++){
			if(p[j]==p[i]){
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	int i,flag=0,count,x;
	cin>>n>>m;
	for(i=1;i<=10000;i++){
		Jilu[i]=sum(i);
	}
	for(i=n;i<=m;i++){
		if(duli(i)&&xingfu(i)){
			cout<<i;
			count=1;
			x=i;
			while(sum(x)!=1){
				count++;
				x=sum(x);
			}
			if(su(i)){
				count*=2;
			}
			cout<<" "<<count<<endl;
			flag=1;
		}
	}
	if(!flag){
		cout<<"SAD";
	}
	return 0;
}
