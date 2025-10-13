#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int main(){
	string a[10000];
	int c=0,o=0,d=0,e=0;
	for(int i=0;i<10000;i++){
		a[i]=getchar();
	    if(a[i]=="c" || a[i]=="C"){
			c++;	
		}
		if(a[i]=="o" || a[i]=="O"){
			o++;	
		}
		if(a[i]=="d" || a[i]=="D"){
			d++;	
		}
		if(a[i]=="e" || a[i]=="E"){
			e++;	
		}
		if(a[i]=="\n"){
			break;
		}
	}
	for(int i=0;;i++){
		if(c>0){
			cout<<"C";
			c--;
		}
		if(o>0){
			cout<<"O";
			o--;
		}
		if(d>0){
			cout<<"D";
			d--;
		}
		if(e>0){
			cout<<"E";
			e--;
		}
		if(c<=0 && o<=0 && d<=0 && e<=0){
			break;
		}
	}
	return 0;
}
