#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int Year,n,y[4]={0},a,b,c,d[10]={0},Y=0;
	cin>>Year;
	cin>>n;
	while(1){
		c=0;
		for(int i=0;i<10;i++){
			d[i]=0;
		}
		for(int i=0;i<4;i++){
			a=pow(10,i);
			b=Year/a;
			y[i]=b%10;
		}
		for(int i=0;i<10;i++){
			for(int j=0;j<4;j++){
				if(y[j]==i){
					d[i]++;	
				}
			}
		}
		for(int i=0;i<10;i++){
			if(d[i]!=0){
				c++;
			}
		}
		if(c==n){
			break;
		}
		Year++;
		Y++;
	}
	cout<<Y<<" ";
	for(int i=3;i>=0;i--){
		cout<<y[i];
	}
	return 0;
}
