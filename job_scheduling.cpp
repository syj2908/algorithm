#include<iostream>
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
    int job_tab[100][100]={0};
    int wait_time[m] = {0};
    bool flag[n];
    bool all_done = false;

    for (int i = 0; i < n;i++)
        flag[i] = false;//all job is NOT scheduled
    
        while (!all_done)
        {
            shortest = get_shortest(n, flag, t);
            for (int i = 0; i < m; i++)
            {
                //calculate wait time of each meachine
                int time = 0;
                for (int j = 0; j < n; j++)
                {
                    time += job_tab[j][i];
                }
                wait_time[i] = time;
            }

            int min_time = INF;
            int p = 0;
            for (int i = 0; i < m; i++)
            {
                if (wait_time[i] < min_time)
                {
                    p = i;
                    min_time = wait_time[i];
                }
            }
            job_tab[shortest][p] = t[shortest];
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
        for (int j = 0; j < m;j++)
        {
            cout << job_tab[i][j] << " ";
        }
        cout << endl;
    } */
    cout << sum_wait << endl;
}

int main()
{
    int n=0, m=0;
    int t[100000] = {0};
    cin >> n >> m;
    for (int i = 0; i < n;i++)
    {
        cin >> t[i];
    }
    job_scheduling(n,m,t);
    return 0;
}