#include<iostream>
using namespace std;
int main(){
	int n,c=0;
	cin>>n;
	int a[n][n],b[n][n]={0},max[n],min[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		max[i]=a[i][1];
		min[i]=a[1][i];
		for(int j=0;j<n;j++){
			if(max[i]<a[i][j]){
				max[i]=a[i][j];
			}
			if(min[i]>a[j][i]){
				min[i]=a[j][i];
			}
		}
	}
	if(n==1){
		cout<<"0 0";
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==max[i]){
				b[i][j]++;
			}
			if(a[i][j]==min[j]){
				b[i][j]++;
			}
			if(b[i][j]==2){
				cout<<i<<" "<<j;
				c++;
			}
		}
	}
	if(c==0 && n!=1){
		cout<<"NONE";
	}
	return 0;
}
