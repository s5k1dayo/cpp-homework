#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>m>>n;
	float A,B,a;
	B=(8*m-6*n)/(m-n);              //8*m=A+mB
	A=6*n-n*B;                  //6*n=A+nB
	a=A/(10-B);            //10*a=A+aB
	cout<<A<<endl<<B<<endl<<a;
	return 0;
}
