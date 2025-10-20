#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    if (m % n == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << A[i];
            if (i != n - 1)
            {
                cout << " ";
            }
        }
    }
    else if (n >= m)
    {
        for (int i = n - m; i < n; i++)
        {
            cout << A[i] << " ";
        }
        for (int i = 0; i < n - m; i++)
        {
            cout << A[i];
            if (i < n - m - 1)
            {
                cout << " ";
            }
        }
    }
    else if (n < m)
    {
        for (int i = n-m % n; i < n; i++)
        {
            cout << A[i] << " ";
        }
        for (int i = 0; i < n-m % n; i++)
        {
            cout << A[i];
            if (i != n-m % n - 1)
            {
                cout << " ";
            }
        }
    }
    cout << endl;
}
