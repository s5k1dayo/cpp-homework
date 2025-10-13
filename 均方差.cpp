#include<iostream>
#include<cstdio>
#include<math.h>
#include<iomanip>
using namespace std;
int main()		{
	double n,Avg,Sum=0,a[10001],b[10001],c[10001],d=0,Ave;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Sum=Sum+a[i];
	}
	Avg=Sum/n;
	for(int j=1;j<=n;j++){
		b[j]=a[j]-Avg;
		c[j]=b[j]*b[j];
		d=d+c[j];
	}
	Ave=d/n;
	float e =pow(Ave,0.5); 
	cout<<fixed<<setprecision(5)<<e;
	return 0;
}
