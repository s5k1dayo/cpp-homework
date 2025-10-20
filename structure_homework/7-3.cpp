#include <iostream>
using namespace std;
int x(int a)
{
    if (a == 1 || a == 0)
    {
        return 1;
    }
    else
    {
        return a * x(a - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    int sum = x(n);
    cout << sum;
}