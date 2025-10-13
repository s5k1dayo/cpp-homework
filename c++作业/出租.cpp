#include <iostream>
using namespace std;
int main()
{
	int a = 0;
	char num[11], arr[11];
	for (int i = 0; i < 11; i++)
	{
		cin >> num[i];
	}
	cout << "int[] arr = new int[]{";
	for (int i = 57; i >= 48; i--)
	{
		for (int j = 0; j < 11; j++)
		{
			if (num[j] == i)
			{
				arr[a] = i;
				a++;
				break;
			}
		}
	}
	for (int i = 0; i < a; i++)
	{
		cout << arr[i];
		if (i != a - 1)
		{
			cout << ",";
		}
	}
	cout << "};" << endl
		 << "int[] index = new int []{";

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (num[i] == arr[j])
			{
				cout << j;
				if (i != 10)
				{
					cout << ",";
				}
			}
		}
	}
	cout << "};";
	return 0;
}
