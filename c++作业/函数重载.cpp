#include <iostream>
using namespace std;
int add(int a, int b, int c)
{
	int d = a + b + c;
	return d;
}
int add(int a, int b)
{
	int d = a + b + 30;
	return d;
}
int add(int a)
{
	int d = 30 + 20 + a;
	return d;
}
int main()
{
	int a, b, c;

	cin >> a >> b >> c;

	cout << add(a) << endl;
	cout << add(a, b) << endl;
	cout << add(a, b, c) << endl;

	return 0;
}
