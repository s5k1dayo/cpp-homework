#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a[4][4], x1, x2, x3, y1, y2, y3, kan1, kan2, kan3, b, Sum, Jin, Count[10] = {'0'}, n;
	int Money[20] = {10000, 36, 720, 360, 80, 252, 108, 72, 54, 180, 72, 180, 119, 36, 306, 1080, 144, 1800, 3600};
	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			cin >> a[i][j];
			n = a[i][j];
			Count[n] = 1;
		}
	}
	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			for (int h = 0; h <= 9; h++)
			{
				if (Count[h] == 0 && a[i][j] == 0)
				{
					a[i][j] = h;
				}
			}
		}
	}
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> b;
	kan1 = a[x1][y1];
	kan2 = a[x2][y2];
	kan3 = a[x3][y3];
	if (b >= 1 && b <= 3)
	{
		Sum = a[b][1] + a[b][2] + a[b][3];
	}
	else if (b >= 4 && b <= 6)
	{
		Sum = a[1][b - 3] + a[2][b - 3] + a[3][b - 3];
	}
	else if (b == 7)
	{
		Sum = a[1][1] + a[2][2] + a[3][3];
	}
	else if (b == 8)
	{
		Sum = a[1][3] + a[2][2] + a[3][1];
	}
	for (int k = 0; k <= 19; k++)
	{
		if (Sum - 6 == k)
		{
			Jin = Money[k];
		}
	}
	cout << kan1 << endl
		 << kan2 << endl
		 << kan3 << endl
		 << Jin << endl;
	return 0;
}
