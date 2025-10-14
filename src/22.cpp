#include<iostream>
using namespace std;
int main(){
	int a[5]={4,6,2,9,8};
	for(int i=5;i>0;i--){
		for(int j=0;j<i-1;j++){
			if(a[j]<a[j+1]){
				int b;
				b=a[j];
				a[j]=a[j+1];
				a[j+1]=b;
			}
		}
	}
	for(int k=0;k<5;k++){
		cout<<a[k];
	}
	return 0;
}
