#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int N, Yang[11][11] = {'0'}, a;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		a = 6 - i;
		for (int k = 1; k <= a; k++)
		{
			cout << " ";
		}
		for (int j = 1; j <= i; j++)
		{
			if (j == 1 || j == i)
			{
				Yang[i][j] = 1;
			}
			else
			{
				Yang[i][j] = Yang[i - 1][j - 1] + Yang[i - 1][j];
			}
			if (Yang[i][j] < 10)
			{
				cout << "   " << Yang[i][j];
			}
			else if (Yang[i][j] >= 10 && Yang[i][j] < 100)
			{
				cout << "  " << Yang[i][j];
			}
			else if (Yang[i][j] > 100)
			{
				cout << " " << Yang[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}
