#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main(){
	int d,n;
for(int i=0;i<1000;i++){
	n=0;
	d=i/2;
for(int k=2;k<d;k++){
	if(i%k!=0){
		n++;
	}	
}
if(n==d-2){
	cout<<i<<endl;
}
}
	return 0;
}
