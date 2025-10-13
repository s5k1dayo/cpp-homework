#include<iostream>
using namespace std;
class country{
public:
	int hao;
	int ci;
	int qian=0;
	void jihao(int x){
		hao=x+1;
	}
	void jici(int x){
		ci=x;
	}
};
country a[104];
void mai(int x){
	for(int i=0;i<a[x].ci;i++){
		int N,P;
		cin>>N>>P;
		a[x].qian+=P;
		a[N-1].qian-=P;
	}
}
int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int k;
		cin>>k;
		a[i].jici(k);
		a[i].jihao(i);
		mai(i);
	}
	for(int i=0;i<N;i++){
		for(int j=i;j<N;j++){
			if(a[i].qian<a[j].qian){
				country A=a[i];
				a[i]=a[j];
				a[j]=A;
			}
			else if(a[i].qian==a[j].qian){
				if(a[i].ci<a[j].ci){
					country A=a[i];
					a[i]=a[j];
					a[j]=A;
				}
				else if(a[i].ci==a[j].ci){
					if(a[i].hao>a[j].hao){
						country A=a[i];
						a[i]=a[j];
						a[j]=A;
					}
				}
			}
		}
	}
	for(int i=0;i<N;i++){
		cout<<a[i].hao<<" "<<a[i].qian<<endl;
	}
	return 0;
}
