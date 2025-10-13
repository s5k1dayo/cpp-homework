#include <iostream>
using namespace std;
int main()
{
	int T, n;
	cin >> T;
	int b[T] = {0};
	float Ave;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		int a[n], Sum = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> a[j];
			Sum += a[j];
		}
		Ave = Sum * 1.0 / n;
		for (int k = 0; k < n; k++)
		{
			if (a[k] > Ave)
			{
				b[i]++;
			}
		}
	}
	for (int l = 0; l < T; l++)
	{
		cout << b[l] << endl;
	}
	return 0;
}
