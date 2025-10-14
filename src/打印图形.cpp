#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<n+1;i++){
		for(int j=0;j<i;j++){
			cout<<"*";
		}
		for(int k=0;k<(n-i)*2;k++){
			cout<<" ";
		}
		for(int h=0;h<i;h++){
			cout<<"*";
		}
		cout<<endl;
	}
}
