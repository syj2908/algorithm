#include<iostream>
using namespace std;

int bin_search(int array[], int key, int len)
{
    //找到array中比key大的最小的那个数并替换
    int head = 0, tail = len - 1;
    while (head <= tail)
    {
        int mid = (head + tail) / 2;
        if(key==array[mid])
        {
            return mid;
        }
        else if (key < array[mid])
        {
            tail = mid - 1;
        }
        else
        {
            head = mid + 1;
        }
    }
    return head; 
}

int lis(int array[], int len)
{
    int tail[len] = {0};
    tail[0] = array[0];
    int pos = 0;//proper posotion for array[i]
    int max = 1;//max len of lis

    for (int i = 1; i < len; i++)
    {
        if(array[i]>tail[max-1])
        {
            //array[i] is bigger than any number in tail[]
            //len of lis++
            tail[max] = array[i];
            max++;
        }
        else
        {
            //use binsearch to find a proper set for 
            //array[i]
            pos = bin_search(tail, array[i], len);
            tail[pos] = array[i];
        }  
    }
    return max;
}

int main()
{
    int array[] = {2, 1, 5, 3, 6, 4, 8, 9, 7};
    //int array[] = {3, 4, 7, 2, 5};
    int len = sizeof(array) / sizeof(int);
    int max = lis(array, len);
    cout << max << endl;
    return 0;
}