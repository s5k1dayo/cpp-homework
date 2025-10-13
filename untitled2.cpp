#include<cstdio>
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	long long a,c=1;
	double e=1,b=1;
	cin>>a;
	for(int j=1;j<=a;j++){
		c*=10;
	}
	for(double i=1;i<=14;i++){
		b*=i;
		if(b>c){
			break;
		}
		e=e+1/b;
	}
	cout<<fixed<<setprecision(a+1)<<e;
	return 0;
}
