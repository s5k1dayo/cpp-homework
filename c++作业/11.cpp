#include <iostream>
using namespace std;
int main()
{
	int m;
	cin >> m;
	int b[m], ave[m];
	for (int i = 0; i < m; i++)
	{
		cin >> ave[i];
	}
	for (int l = 0; l < m; l++)
	{
		b[l] = {l + 1};
	}
	for (int j = m; j > 0; j--)
	{
		for (int k = 0; k < j - 1; k++)
		{
			if (ave[k] < ave[k + 1])
			{
				int c, d;
				c = ave[k];
				ave[k] = ave[k + 1];
				ave[k + 1] = c;
				d = b[k];
				b[k] = b[k + 1];
				b[k + 1] = d;
			}
		}
	}
	for (int h = 0; h < m; h++)
	{
		cout << " " << b[h];
	}
	return 0;
}
