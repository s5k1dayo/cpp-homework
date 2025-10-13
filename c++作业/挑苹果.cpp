#include <iostream>
#include <string>
#include <vector>
using namespace std;
class apple
{
public:
	int iBusket;
	string sNum;
	int iWeight;
	int iDiam;
	void Busket(int a)
	{
		iBusket = a;
	}
	void Num(string a)
	{
		sNum = a;
	}
	void Weight(int a)
	{
		iWeight = a;
	}
	void Diam(int a)
	{
		iDiam = a;
	}
};

int main()
{
	int n, count = 1;
	cin >> n;
	vector<int> Aa;
	vector<int> ji;
	apple a[n];
	for (int i = 0; i < n; i++)
	{
		int lan, zhong, zhi;
		string hao;
		cin >> lan;
		if (i == 0)
		{
			Aa.push_back(lan);
			ji.push_back(1);
		}
		else
		{
			int huh = 0;
			for (unsigned long long k = 0; k < Aa.size(); k++)
			{
				if (Aa[k] == lan)
				{
					ji[k]++;
					huh = 1;
					break;
				}
			}
			if (huh == 0)
			{
				Aa.push_back(lan);
				ji.push_back(1);
				count++;
			}
		}
		for (int j = 0; j < 8; j++)
		{
			hao.push_back(getchar());
		}
		cin >> zhong >> zhi;
		a[i].Busket(lan);
		a[i].Diam(zhi);
		a[i].Weight(zhong);
		a[i].Num(hao);
	}
	for (int j = 0; j < count; j++)
	{
		int N = ji[j];
		apple lan[N];
		int m = 0;
		for (int k = 0; k < n; k++)
		{
			if (a[k].iBusket == Aa[j])
			{
				lan[m] = a[k];
				m++;
			}
		}
		for (int l = 0; l < N; l++)
		{
			for (int o = l; o < N; o++)
			{
				if (lan[l].iWeight < lan[o].iWeight)
				{
					apple t = lan[l];
					lan[l] = lan[o];
					lan[o] = t;
				}
			}
		}
		cout << lan[0].iBusket << lan[0].sNum << " " << lan[0].iWeight << " " << lan[0].iDiam;

		if (j < count - 1)
		{
			cout << endl;
		}
	}
	return 0;
}
