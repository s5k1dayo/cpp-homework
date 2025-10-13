#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	unsigned int a;
	unsigned int *A=&a;
	cin>>a;
	unsigned char* c=(unsigned char*)A;
	printf("%x\n",a);
	printf("%x ",*c);
	for(int i=0;i<3;i++){
		c++;
		printf("%x ",*c);
		if(i<2){
			cout<<" ";
		}
else{
	break;
}
	}
	return 0;
}
