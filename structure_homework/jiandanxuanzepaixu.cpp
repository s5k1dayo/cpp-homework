#include <iostream>
using namespace std;
void pai(int a[], int n, int k)
{
    int max = 0;
    int ci = n - k - 1;
    for (int i = 0; i < ci; i++)
    {
        if (a[i] > a[max])
        {
            max = i;
        }
    }
    int b = a[ci];
    a[ci] = a[max];
    a[max] = b;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < 3; j++)
    {
        pai(a, n, j);
        for (int k = 0; k < n; k++)
        {
            cout << a[k] << " ";
        }
        cout << endl;
    }
}