#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char a;
	for(int i=1;i<=8;i++){
		scanf("%c",&a);
		if(a>=48 && a<=57){
			printf("%c",a);
		}
		else{
			break;
		}
		printf("   ");
	}
	return 0;
}
