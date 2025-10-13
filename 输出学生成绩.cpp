#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
int main (){
	int N;
	cin>>N;
	float n[N],max,min,sum=0,ave;
	for(int i=0;i<N;i++){
		cin>>n[i];
		sum+=n[i];
	}
	max=n[0];
	min=n[0];
	ave=sum/N;
	for(int j=0;j<N;j++){
		if(n[j]>max){
			max=n[j];
		}
		else if(n[j]<min){
			min=n[j];
		}
	}
	cout<<"average = "<<fixed<<setprecision(2)<<ave<<endl;
	printf("max = %.2f\nmin = %.2f\n",max,min);
	return 0;
}
