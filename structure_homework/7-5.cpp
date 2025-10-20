#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> n, m, zhan;

    int a, curn = 0, curm = 0, lzhan;
    while (cin >> a)
    {
        n.push_back(a);
    }
    while (cin >> a)
    {
        m.push_back(a);
    }
    while (curm < m.size() - 1)
    {
        while (n[curn] != m[curm])
        {
            zhan.push_back(n[curn]);
            curn += 1;
            cout<<"P";
        }
        if (n[curn] == m[curm])
        {
            lzhan = zhan.size();
            if (zhan[lzhan - 1] == n[curn])
            {
                cout << "O";
                curn -= 1;
                curm += 1;
            }
            else
            {
                cout<<"wrong"<<endl;
                for(int i=0;i<n.size();i++){
                    cout<<n[i];
                }
                break;
            }
        }
    }
}