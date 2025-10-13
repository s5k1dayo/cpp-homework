#include <iostream>
#include <string>
using namespace std;
int main(){
long long qian=7891234;
string hou="10000";
long long shi=1,sum=0;
for(int i=hou.length()-1;i>=0;i--)	{
	sum+=(hou[i]-'0')*shi;
	shi*=10;
}
cout<<sum+qian;
return 0;
}
