#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main (){
	int L,K;
	cin>>L>>K;
	int a[L],n,m=0;
	int b[L-K+1]={0},c[L-K+1][K],d[L-K+1];
	for(int i=0;i<=L;i++){
		a[i-1]=getchar();
	}
	for(int i=0;i<=L-K;i++){
		n=0;
		for(int j=0;j<K;j++){
			c[i][j]=(a[i+j]-48)*pow(10,K-j-1);
			b[i]=b[i]+c[i][j];
		}
		d[i]=b[i]/2;
	for(int k=2;k<d[i];k++){
		if(b[i]%k!=0){
			n++;
		}	
	}
	if(n==d[i]-2 && b[i]!=4){
			cout<<b[i]<<endl;
			m++;
			break;
	}
	else if(b[i]==2 || b[i]==3){
		cout<<b[i]<<endl;
		m++;
		break;
	}
	}
	if(m==0){
		cout<<"404";
	}
	return 0;
}
