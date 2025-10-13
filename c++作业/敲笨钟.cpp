#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int N;
	cin>>N;
	char a[N][100]={0};
	char* A[N];
	char *B[N],*C[N];
	for(int k=0;k<N;k++){
	int n=0;
	A[k]=a[k];
	cin.getline(a[k],100,'.');

	for(int i=0;i<100;i++){
		if(a[k][i]==','){
			C[k]=a[k]+i-1;
		}
		if(a[k][i]==0){
			A[k]=A[k]+i-1;
			break;
		}
	}
	for(char* j=A[k];;j--){
		if(*j==32){
			n++;
		}
		if(n==3){
			B[k]=j;
			break;
		}
	}
	}
	for(int k=0;k<N;k++){
	if(*A[k]=='g' && *(A[k]-1)=='n' && *(A[k]-2)=='o' && *C[k]=='g' && *(C[k]-1)=='n' && *(C[k]-2)=='o'){
		for(int i=0;i<B[k]-a[k];i++){
			cout<<a[k][i];
		}
		cout<<" qiao ben zhong."<<endl;
	}
	else{
		cout<<"Skipped"<<endl;
	}
	}
	return 0;
}
