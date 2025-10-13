#include <iostream>
#include <string>
using namespace std;
int main()
{
	unsigned long long account;
	string name[10];
	string ID;
	char password[6];
	int money;
	cout << "请输入姓名：";
	for (int i = 0; i < 10; i++)
	{
		char x = getchar();
		if (x == '\n')
		{
			break;
		}
		name[i] = x;
	}
	cout << "请输入身份证号码：";
	getline(cin, ID);
	int set = 0;
	while (set == 0)
	{
		cout << "请设置密码：";
		for (int i = 0; i < 6; i++)
		{
			password[i] = getchar();
		}
		cout << "确认密码：";
		char x[6];
		for (int i = 0; i < 6; i++)
		{
			x[i] = getchar();
		}
		int flag = 0;
		for (int i = 0; i < 6; i++)
		{
			if (x[i] != password[i])
			{
				cout << "密码不一致，请重新输入！";
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			cout << "设置成功！" << endl;
			set = 1;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << name[i];
	}
	cout << ID << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << password[i];
	}
	return 0;
}
