#include <iostream>
using namespace std;
int main()
{
	int m, n;
	cin >> m >> n;
	int a[m][n], max[m], min[m], sum[m] = {0}, b[m];
	float ave[m];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			max[i] = a[i][0];
			min[i] = a[i][0];
			sum[i] += a[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (max[i] < a[i][j])
			{
				max[i] = a[i][j];
			}
			else if (min[i] > a[i][j])
			{
				min[i] = a[i][j];
			}
		}
		ave[i] = (sum[i] - max[i] - min[i]) * 1.0 / (n - 2);
	}
	for (int l = 0; l < m; l++)
	{
		b[l] = {l + 1};
	}

	for (int j = m; j > 0; j--)
	{
		for (int k = 0; k < m; k++)
		{
			if (ave[k] < ave[k + 1])
			{
				float c, d;
				c = b[k];
				b[k] = b[k + 1];
				b[k + 1] = c;
				d = ave[k];
				ave[k] = ave[k + 1];
				ave[k + 1] = d;
			}
		}
	}
	for (int h = 0; h < m; h++)
	{
		cout << "  " << b[h];
	}
	return 0;
}
