#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> Jilu;
int ji=0;
int ge=0;
int sum(int a){
	int shi=10,wei=1,b[4],ping=0;
	for(int i=0;i<4;i++){
		if(a/shi>0){
			wei++;
			shi*=10;
		}
	}
	for(int j=0;j<wei;j++){
		b[j]=a%10;
		a=a/10;
		ping=ping+b[j]*b[j];
	}
	return ping ;
}


bool su(int a){
	for(int i=2;i<a/2;i++){
		if(a%i==0){
			return 0;
			break;
		}
	}
		return 1;
}

void shi(int a){
	vector<int> A;
	for(int i=0;i<20;i++){
		A.push_back(a);
		if(a==1){
			Jilu.push_back(A);
			ji++;
			A.clear();
			break;
		}
		a=sum(a);
	}
}
void cha(int a,int b,int n){
	int N,xu,f=0;
	for(int i=0;i<ji;i++){
		for(unsigned int j=1;j<Jilu[i].size();j++){
			if(Jilu[i][j]==n){
				f++;
				break;
			}
		}
	}
	if(f==0){
	for(int k=0;k<b-a;k++){
		if(n==Jilu[k][0]){
			xu=k;
			break;
		}
	}
	N=Jilu[xu].size()-1;
	if(su(n)==1){
		N=N*2;
	}
	cout<<n<<" "<<N<<endl;
		ge++;
	}
}

int main(){	
	int a,b;
	cin>>a>>b;
	for(int i=a+1;i<b;i++){
		shi(i);
	}
	for(int j=0;j<ji;j++){
		cha(a,b,Jilu[j][0]);
	}
	if(ge==0){
		cout<<"SAD";
	}
	return 0;
}
