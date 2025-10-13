#include <iostream>
#include <string>
using namespace std;
class apple
{
public:
	int num;
	string id;
	int weight;
	int diameter;
};
int main()
{
	int n;
	cin >> n;
	apple app[n];
	for (int i = 0; i < n; i++)
	{
		cin >> app[i].num >> app[i].id >> app[i].weight >> app[i].diameter;
	}
	int basket[999999 + 1] = {0};
	for (int i = 0; i < n; i++)
	{
		basket[app[i].num]++;
	}
	int max[999999 + 1] = {0};
	for (int i = 0; i < 999999; i++)
	{
		if (basket[i + 1] != 0)
		{
			for (int j = 0; j < n; j++)
			{
				if (max[i + 1] <= app[j].weight && i + 1 == app[j].num)
				{
					max[i + 1] = app[j].weight;
				}
			}
		}
	}
	for (int i = 0; i < 999999; i++)
	{
		if (basket[i + 1] != 0)
		{
			for (int j = 0; j < n; j++)
			{
				if (max[i + 1] == app[j].weight && i + 1 == app[j].num)
					cout << i + 1 << " " << app[j].id << " " << app[j].weight << " " << app[j].diameter << endl;
			}
		}
	}
	return 0;
}
