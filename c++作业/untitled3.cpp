#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b[11],c[11],Largest,Smallest;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b[i];
		c[i]=b[i];
		if(i==1){
			Smallest=c[1];
			Largest=c[1];
		}
		if(b[i]>Largest){
			Largest=c[i];
		}
		if(b[i]<Smallest){
			Smallest=c[i];
		}
		
	}
	for(int k=1;k<=a;k++){
		if(b[k]==Smallest){
			b[k]=c[1];
			b[1]=Smallest;
		}
	}
	for(int k=1;k<=a;k++){
		if(b[k]==Largest){
			b[k]=c[a];
			b[a]=Largest;
		}
	}
	for(int j=1;j<=a;j++){
		cout<<b[j]<<" ";
	}
	return 0;
}
