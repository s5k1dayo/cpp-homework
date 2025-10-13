#include <iostream>
using namespace std;
class country
{
public:
	int _num;
	int _count = 0;
	int _sum = 0;
	int _sum2 = 0;
	int _profit = 0;

public:
	country() {};
	country(country &a);
	void set(int num, int count, int sum, int sum2);
	void show();
};
country::country(country &a)
{
	_num = a._num;
	_count = a._count;
	_sum = a._sum;
	_sum2 = a._sum2;
	_profit = a._profit;
}
void country::set(int num, int count, int sum, int sum2)
{
	_sum = sum;
	_count = count;
	_num = num;
	_sum2 = sum2;
	_profit = sum - sum2;
}
void country::show()
{
	cout << this->_num << " " << this->_profit << endl;
}
int main()
{
	int n;
	cin >> n;
	country a[n];
	int k[n];
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		int N[n], money[n];
		for (int t = 0; t < n; t++)
		{
			N[t] = 0;
			money[t] = 0;
		}
		cin >> k[i];
		for (int j = 0; j < k[i]; j++)
		{
			cin >> N[j] >> money[j];
			a[N[j] - 1]._count++;
			a[N[j] - 1]._sum2 += money[j];
			a[i]._count++;
			a[i]._sum += money[j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		a[i].set(i + 1, a[i]._count, a[i]._sum, a[i]._sum2);
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			country temp = a[j + 1];
			if (a[j]._profit < a[j + 1]._profit)
			{
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i]._profit == a[i + 1]._profit)
		{
			if (a[i]._count < a[i + 1]._count)
			{
				int temp2 = a[i + 1]._num;
				a[i + 1]._num = a[i]._num;
				a[i]._num = temp2;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
		{
			a[i].show();
		}
		else
		{
			cout << a[i]._num << " " << a[i]._profit;
		}
	}
	return 0;
}
