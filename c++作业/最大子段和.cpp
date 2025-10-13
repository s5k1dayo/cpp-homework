#include<iostream>
using namespace std;
int main(){
	int n,max_sum=0,cur_sum=0;
	cin>>n;
	int num[n];
	for(int i=0;i<n;i++){
		cin>>num[i];
		cur_sum=cur_sum+num[i];
		if(cur_sum<num[i]){
			cur_sum=num[i];
		}
		if(cur_sum>max_sum){
			max_sum=cur_sum;
		}
		
	}
	cout<<max_sum;
	
}
