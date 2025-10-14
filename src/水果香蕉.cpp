#include<iostream>
#include<string>
using namespace std;
class Fruit{
protected:
	int weight;
public:
	Fruit(){
		cout<<"Fruit Constructor"<<endl;
	}
	Fruit(int x){
		weight=x;
		cout<<"Fruit Constructor"<<endl;
	}
	virtual ~Fruit(){
		cout<<"Fruit Destructor"<<endl;
	}
	virtual void display(){
		cout<<"weight="<<weight<<endl;
	}
};
class Banana:virtual public Fruit{
protected:
	string origin;
public:
	Banana(string x,int y){
		origin=x;
		weight=y;
		cout<<"Banana Constructor"<<endl;
	}
	~Banana(){
		cout<<"Banana Destructor"<<endl;
	}
	void display(){
		cout<<"origin="<<origin<<",weight="<<weight<<endl;
	}
};
/* 请在这里填写答案 */
int main(){
	Fruit *pf=new Banana("Chongqing",10);;
	pf->display();
	delete pf;
	return 0;
}
