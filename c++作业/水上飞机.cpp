#include <iostream>
using namespace std;
 class CRAFT{
 protected:
	double speed;
 public:
	CRAFT(double x){
		speed=x;
		cout<<"创建航行器(速度: "<<x<<")"<<endl;
	}
	virtual ~CRAFT(){
		cout<<"销毁航行器(速度: "<<speed<<")"<<endl;
	}
	virtual void Show(){
		cout<<"航行(速度: "<<speed<<")"<<endl;
	}
 };
class PLANE:virtual public CRAFT{
protected:
	double width;
public:
	PLANE(double x,double y):CRAFT(x){
		width=y;
		cout<<"创建飞机(翼展: "<<y<<")"<<endl;
	}
	~PLANE(){
		cout<<"销毁飞机(翼展: "<<width<<")"<<endl;
	}
 void Show(){
		cout<<"航行(速度: "<<speed<<", 翼展: "<<width<<")"<<endl;
	}
};
class SHIP:virtual public CRAFT{
	protected:
	double depth;
public:
	SHIP(double x,double y):CRAFT(x){
		depth=y;
		cout<<"创建船(吃水: "<<y<<")"<<endl;
	}
	~SHIP(){
		cout<<"销毁船(吃水: "<<depth<<")"<<endl;
	}
 void Show(){
		cout<<"航行(速度: "<<speed<<", 吃水: "<<depth<<")"<<endl;
	}
};
class SEAPLANE:public PLANE, public SHIP{
public:
	SEAPLANE(double x,double y,double z):CRAFT(x),PLANE(x,y),SHIP(x,z){
		cout<<"创建水上飞机"<<endl;
	}
	~SEAPLANE(){
		cout<<"销毁水上飞机"<<endl;
		
	}
	void Show(){
		cout<<"航行(速度: "<<speed<<", 翼展: "<<width<<", 吃水: "<<depth<<")"<<endl;
	}
};
/* 你提交的代码将被嵌在这里 */

int main()
{
	double s, w, d;
	CRAFT *p;
	cin >> s >> w >> d;
	p = new SEAPLANE(s, w, d);
	p->Show();
	delete p;
	return 0;
}
