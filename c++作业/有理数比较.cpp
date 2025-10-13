#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	float a1, b1, a2, b2, c1, c2;
	char d[2];
	cin >> a1 >> d[0] >> b1 >> a2 >> d[1] >> b2;
	c1 = a1 / b1;
	c2 = a2 / b2;
	if (c1 > c2)
	{
		cout << a1 << "/" << b1 << " > " << a2 << "/" << b2;
	}
	else if (c1 < c2)
	{
		cout << a1 << "/" << b1 << " < " << a2 << "/" << b2;
	}
	else if (c1 == c2)
	{
		cout << a1 << "/" << b1 << " = " << a2 << "/" << b2;
	}
	return 0;
}
