#include <iostream>
using namespace std;
int main()
{
    int n, count = 0;
    while (cin >> n)
    {
        count++;
        int a[n] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int j = 1; j < n; j++)
        {
            for (int k = j; k > 0; k--)
            {
                if (a[k] <= a[k - 1])
                {
                    int swi = a[k];
                    a[k] = a[k - 1];
                    a[k - 1] = swi;
                }
            }
            for (int h = 0; h < n; h++)
            {
                cout << a[h];
                if (h != n - 1)
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
}