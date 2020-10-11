#include<iostream>
using namespace std;

int ackerman(int m, int n)
{
    int ind[m + 1] = {0};
    int val[m + 1] = {0};
    for (int i = 0; i < m; i++)
    {
        ind[i + 1] = -1;
        val[i + 1] = -1;
    }
    ind[0] = 0;
    val[0] = 1;

    while (ind[m] < n)
    {
        ind[0]++;
        val[0]++;
        for (int i = 1; i <= m; i++)
        {
            if(ind[i-1]==1)
            {
                val[i] = val[i - 1];
                ind[i] = 0;
            }
            if (val[i] == ind[i - 1])
            {
                ind[i]++;
                val[i] = val[i - 1];
            }
        }
    }
    return val[m];
}

int main()
{
    int m = 3;
    int n = 3;
    int ack = ackerman(m, n);
    cout << ack << endl;
    return 0;
}
