#include<iostream>
using namespace std;
int main(){
	int N,M,X,Y,flag[200]={0};
	cin>>N>>M>>X>>Y;
	int x[N],y[M];
	for(int i=0;i<N;i++){
		cin>>x[i];
	}
	for(int i=0;i<M;i++){
		cin>>y[i];
	}
	for(int i=0;i<N;i++){
		int a=X,b=x[i];
		if(a<b){
			for(int j=a;j<=b;j++){
				flag[j+100]=1;
			}
		}
		else{
			for(int j=b;j<=a;j++){
				flag[j+100]=1;
			}
		}
	}
	for(int i=0;i<M;i++){
		int a=Y,b=y[i];
		if(a<b){
			for(int j=a;j<=b;j++){
				if(flag[j+100]==1){
					cout<<X<<" and "<<Y<<": possible";
					return 0;
				}
			}
		}
		else{
			for(int j=b;j<=a;j++){
			if(flag[j+100]==1){
				cout<<X<<" and "<<Y<<": possible";
				return 0;
				}
			}
		}
	}
	cout<<X<<" and "<<Y<<": impossible";
	return 0;
}
