#include <iostream>
using namespace std;

void paixu(int a[], int b[], int qian, int hou, bool flag)
{
    if (flag == 0)
    {
        for (int j = 0; j < hou - qian; j++)
        {
            for (int i = hou - 1; i > qian; i--)
            {
                if (a[i] > a[i - 1])
                {
                    int d = a[i];
                    int c = b[i];
                    a[i] = a[i - 1];
                    b[i] = b[i - 1];
                    a[i - 1] = d;
                    b[i - 1] = c;
                }
            }
        }
    }
    else if (flag == 1)
    {
        for (int j = 0; j < hou - qian; j++)
        {
            for (int i = hou - 1; i > qian; i--)
            {
                if (a[i] < a[i - 1])
                {
                    int d = a[i];
                    int c = b[i];
                    a[i] = a[i - 1];
                    b[i] = b[i - 1];
                    a[i - 1] = d;
                    b[i - 1] = c;
                }
            }
        }
    }
}
int main()
{
    int n, m, count = 0;
    cin >> n >> m;
    int shu = m * 1.5 / 1;
    int hao[n], fen[n],chuhao[n],chufen[n];
    for (int i = 0; i < n; i++)
    {
        cin >> hao[i] >> fen[i];
    }
    paixu(fen, hao, 0, n, 0);
    int j = 0;
    while (count < shu)
    {
        if (fen[j] != fen[j + 1])
        {
            chuhao[count]=hao[j];
            chufen[count]=fen[j];
            j++;
            count++;
        }
        else
        {
            int tong = 1;
            while (fen[j] == fen[j + 1])
            {
                j++;
                tong++;
            }
            j++;
            paixu(hao, fen, count, count + tong, 1);
            for (int k = 0; k < tong; k++)
            {
                chuhao[count+k]=hao[count+k];
                chufen[count+k]=fen[count+k];
            }
            count += tong;
        }
    }
    cout<<chufen[count-1]<<" "<<count<<endl;
    for(int h=0;h<count;h++){
        cout<<chuhao[h]<<" "<<chufen[h]<<endl;
    }
}