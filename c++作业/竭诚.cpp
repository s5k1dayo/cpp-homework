#include<iostream>
using namespace std;
void amns(int a ,int b){
	cin>>a;
	for(int i=1;i<=a;i++){
		b=b*i;
	}
		cout<<b;
}
int main (){
	int N,b=1;
	amns(N,b);
}

