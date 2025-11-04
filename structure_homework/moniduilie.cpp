#include <iostream>
#include <string>
using namespace std;

class queue
{
private:
    int a[100000];
    int front, rear, length;

public:
    queue()
    {
        front = 0;
        rear = 0;
        length = 0;
    }
    ~queue()
    {
        front = 0;
        rear = 0;
        length = 0;
    }
    void push(int A)
    {
        a[rear] = A;
        rear++;
    }
    void pop()
    {
        front++;
    }
    bool empty()
    {
        return rear == front;
    }
    int query()
    {
        return a[front];
    }
};
int main()
{
    int n, pu;
    cin >> n;
    string m;
    queue dui;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        if (m == "push")
        {
            cin >> pu;
            dui.push(pu);
        }
        else if (m == "pop")
        {
            dui.pop();
        }
        else if (m == "empty")
        {
            if (dui.empty())
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else if (m == "query")
        {
            int qu = dui.query();
            cout << qu << endl;
        }
    }
}