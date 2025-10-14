#include<iostream>
#include<string>
using namespace std;
class Teacher{
private:
	string name;
	int age;
public:
	Teacher(string name,int age);
	string getName() const;
	int getAge() const ;
	void setName(string name);
	void setAge(int age);
};
Teacher::Teacher(string name,int age){
	Teacher::name=name;
	Teacher::age=age;
}
string Teacher::getName() const{
	return Teacher::name;
}
int Teacher::getAge() const{
	return Teacher::age;
}
void Teacher::setName(string name)
{
	Teacher::name=name;
}
void Teacher::setAge(int age)
{
	Teacher::age=age;
}
/* 请在这里填写答案 */

int main(){
	Teacher a("Wang",20);
	cout<<"name:"<<a.getName()<<endl;
	cout<<"age:"<<a.getAge()<<endl;
	a.setName("Zhang");
	a.setAge(30);
	cout<<"name:"<<a.getName()<<endl;
	cout<<"age:"<<a.getAge()<<endl;
	return 0;
}
