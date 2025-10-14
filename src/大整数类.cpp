#include <iostream>
#include <string>
using namespace std;

class HugeInteger{
public:
	long long a;
	string A;
	int flag=0;
	HugeInteger(long long x){
		a=x;
	}
	HugeInteger(string x){
		A=x;
		flag=1;
	}
	HugeInteger(){
		a=0;
	}
	HugeInteger operator +(HugeInteger x){
		long long X;
		if(x.flag){
			string qian=this->A;
			string hou=x.A;
			if(qian.length()<hou.length()){
				string t=qian;
				qian=hou;
				hou=t;
			}
			int lqian=qian.length();
			int lhou=hou.length();
			int shu[lqian]={0};
			int jinwei=0;
			for( int i=1;i<=lhou;i++){
				shu[lqian-i]=qian[lqian-i]-'0'+hou[lhou-i]-'0';
				if(shu[lqian-i]>=10 && i!=lqian){
					shu[lqian-i]-=10;
					shu[lqian-i-1]++;
				}
			}
			for(int j=lhou+1;j<=lqian;j++){
				shu[lqian-j]+=qian[lqian-j]-'0';
				if(shu[lqian-j]>=10 && j!=lqian){
					shu[lqian-j]-=10;
					shu[lqian-j-1]++;
				}
				if(shu[lqian-j]>=10 && j==lqian){
					shu[lqian-j]-=10;
					jinwei=1;
				}
				
			}
			if(jinwei){
				string shu1;
				for(int i=0;i<=lqian;i++){
					if(i==0){
						shu1.push_back('1');
						continue;
					}
					shu1.push_back((char)shu[i-1]+'0');
				}
				HugeInteger deshu(shu1);
				return deshu;
			}
			string shu2;
			for(int i=0;i<lqian;i++){
				shu2[i]=shu[i];
			}
			HugeInteger deshu(shu2);
			return deshu;
		}
		X=this->a+x.a;
		HugeInteger deshu(X);
		return deshu;
	}
	HugeInteger operator +(string x){
		long long qian=this->a;
		string hou=x;
		long long shi=1,sum=0;
		for( int i=hou.length()-1;i>=0;i--)	{
			sum+=(hou[i]-'0')*shi;
			shi*=10;
		}
		HugeInteger deshu(qian+sum);
		return deshu;
	}
};
ostream& operator<<(ostream& cout,const HugeInteger &x){
	if(x.flag){
		cout<<x.A;
		return cout; 
	}
	cout<<x.a;
	return cout;
}
/* 请在这里写出HugeInteger类的定义和实现 */


int main()
{
	HugeInteger n1( 7654321 );
	HugeInteger n2( 7891234 );
	HugeInteger n3( "99999999999999999999999999999" );
	HugeInteger n4( "1" );
	HugeInteger n5;
	cout << "n1 is " << n1 << "\nn2 is " << n2
	<< "\nn3 is " << n3 << "\nn4 is " << n4
	<< "\nn5 is " << n5 << "\n\n";
	n5 = n1 + n2;
	cout << n1 << " + " << n2 << " = " << n5 << "\n\n";
	cout << n3 << " + " << n4 << "\n= " << ( n3 + n4 ) << "\n\n";
	n5 = n1 + 9;
	cout << n1 << " + " << 9 << " = " << n5 << "\n\n";
	n5 = n2 + "10000";
	cout << n2 << " + " << "10000" << " = " << n5 << endl;
	
	return 0;
}

