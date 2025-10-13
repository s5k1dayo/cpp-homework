#include<iostream>
using namespace std;

int main(){
	int a,count=1;
	cin>>a;
	while (a!=1){
		cout<<a<<" ";	
		if(a%2==0){
			a=a/2;
		}
		else if(a%2!=0){
			a=a*3+1;
		}
		count++;
	}
	cout<<a<<" ";	
	cout<<endl<<"count = "<<count;
}


