#include <iostream>
#include "Header.h"
using namespace std;

int n = 4;
int input(int a[20][20])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

int change(int a[20][20])
{
    bool d = true;
    for (int i = 0; i < n; i++)
    {
        int g = a[i][i];
        bool flag = false;
        while (g > 0)
        {
            if (((g % 10) == 3) || ((g % 10) == 5))
            {
                flag = true;
            }
            g /= 10;
        }
        if ((!(a[i][i] > 0)) || (!(flag == true)))
        {
            d = false;
        }
    }
    if (d == true)
    {
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            int min = 100000000;
            for (int j = 0; j < n; j++)
            {
                sum += a[j][i] * a[j][i];
                if (a[j][i] < min)
                {
                    min = a[j][i];
                }
            }
            for (int j = 0; j < n; j++)
            {
                if (a[j][i] == min)
                {
                    a[j][i] = sum;
                }
            }
        }
    }
    return 0;
}

int out(int a[20][20])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}