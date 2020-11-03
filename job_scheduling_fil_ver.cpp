#include<iostream>
#include<stdio.h>
#define INF 99999
using namespace std;

int get_shortest(int n, bool flag[],int t[])
{
    //get job which is shortest&&not scheduled
    int shortest = INF;
    int p = 0;
    for (int i = 0; i < n;i++)
    {
        if (flag[i] == false && t[i] < shortest)
        {
            shortest = t[i];
            p = i;
        }
    }
    return p;
}

void job_scheduling(int n,int m,int t[])
{
    int shortest = 0;
    int sum_wait = 0;
    int job_tab[n]={0};
    int wait_time[m+1] = {0};
    bool flag[n];
    bool all_done = false;

    for (int i = 0; i < n;i++)
        flag[i] = false;//all job is NOT scheduled
    
    while (!all_done)
    {
        shortest = get_shortest(n, flag, t);
        for (int i = 1; i <= m;i++)
        {
            wait_time[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            //calculate wait time of each meachine
            int temp = job_tab[i];
            wait_time[temp] += t[i];
        }

        int min_time = INF;
        int p = 0;
        for (int i = 1; i <= m; i++)
        {
            if (wait_time[i] < min_time)
            {
                p = i;
                min_time = wait_time[i];
            }
        }
        job_tab[shortest] = p;
        sum_wait += min_time;
        flag[shortest] = true;
        all_done = true;
        for (int i = 0; i < n; i++)
        {
            if (!flag[i])
            {
                all_done = false;
                break;
            }
        }
    }
/*     for (int i = 0; i < n;i++)
    {
            cout << job_tab[i] << " ";
    } */
    cout << sum_wait << endl;
}

int main()
{
    freopen("D:\\Algorithm\\algorithm\\exp3_in.txt", "r", stdin);
    int n=0, m=0;
    int t[100000] = {0};
    while(cin >> n >> m)
    {
        for (int i = 0; i < n;i++)
        {
            cin >> t[i];
        }
        job_scheduling(n,m,t);
    }
    return 0;
}