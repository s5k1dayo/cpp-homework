#include<iostream>
#include<cmath>
using namespace std;
bool su(long long a){
	if(a==0 || a==1){
		return 0;
	}
	for(long long i=2;i<=sqrt(a);i++){
		if(a%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int L,K,flag=0;
	cin>>L>>K;
	char num[1001];
	for(int i=0;i<L;i++){
		cin>>num[i];
	}
	for(int i=0;i<=L-K;i++){
		int a=0;
		int p=i;
		for(int j=0;j<K;j++){
			a*=10;
			a+=num[p]-'0';
			p++;
		}
		if(su(a)){
			flag=1;
			cout<<a;
			break;
		}
	}
	if(flag==0){
		cout<<"404";
	}
	return 0;
}

