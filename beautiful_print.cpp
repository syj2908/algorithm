#include<iostream>
using namespace std;

int getlen(int m, int n, int i, int j, int array[])
{
    int len = 0;
    for (int k = i-1; k <= j-1; k++)
    {
        len += array[k];
    }
    int space = m - j + i - len;
    if (space < 0)
    {
        return 99999999;
    }
    else if (j == n)
    {
        return 0;
    }
    else
    {
        return space * space * space;
    }
}

void beautiful_print(int n, int m, int array[])
{
    int c[n] = {0};//从1~i个单词所用的最少空格
    int p[n] = {0};//断开位置
    c[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        c[i] = 99999999;
        for (int j = 1; j <= i; j++)
        {
            if (c[i] > c[j - 1] + getlen(m, n, j, i, array))
            {
                c[i] = c[j - 1] + getlen(m, n, j, i, array);
                p[i] = j;
            }
        }
    }
    cout << c[n] << endl;
}

int main()
{
    int n = 5, m = 6;
    int array[n] = {1, 3, 3, 2, 3};
    beautiful_print(n, m, array);
    return 0;
}