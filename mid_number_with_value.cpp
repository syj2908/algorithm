#include<iostream>
using namespace std;

int array[] = {9, 7, 5, 6, 4, 3, 8, 1, 2, 10, 11, 12, 13, 20, 19, 67, 52, 75, 44, 97, 42,99};

int select(int, int, int);
void sort(int, int);
int partition(int, int, int);
void exchange(int, int);
int mid_number_with_value(int, int,int);

int main()
{
    int len = sizeof(array) / sizeof(int);
    int sum = 0;
    sort(0, len-1);
    for (int i = 0; i < len; i++)
    {
        sum += array[i];
        cout << array[i] << " ";
    }
    cout << endl;

    int mid = mid_number_with_value(0, len - 1, sum);
    cout << mid << endl;
    return 0;
}

int mid_number_with_value(int head,int tail,int sum)
{
    int len = tail - head + 1;
    int mid = select(head, tail, len / 2);
    int l_sum = 0, r_sum = 0;
    int pos = 0;
    for (int i = 0; i < len; i++)
    {
        if(array[i]==mid)
        {
            pos = i;
            break;
        }
        else
        {
            l_sum += array[i];
        }
    }
    r_sum = sum - l_sum - array[pos];
    if (l_sum <= sum / 2 &&  r_sum<= sum / 2)
    {
        return mid;
    }
    else if (l_sum > r_sum)
    {
        array[pos] += r_sum;
        return mid_number_with_value(head, pos, sum);
    }
    else
    {
        array[pos] += l_sum;
        return mid_number_with_value(pos, tail, sum);
    }
}

int select(int head, int tail, int key)
{
    //devide array into 5 numbers each piece, sort them
    //to find the third number, then move it to the array's
    //head
    if (tail - head + 1 <= 5)
    {
        sort(head, tail);
        return array[head + key - 1];
    }
    for (int i = 0; i <= (tail - head - 4) / 5; i++)
    {
        sort(head + 5 * i, head + 5 * i + 4);
        exchange(head + i, head + 5 * i + 2);
    }

    //find the middle-number of middle-numbers

    int middle = select(head, head + (tail - head - 4) / 5, ((tail - head - 4) / 5 + 1) / 2 + 1);
    int mid_id = partition(head, tail, middle);
    int mid_rank = mid_id - head + 1;

    if(key==mid_rank)
    {
        return array[mid_id];
    }
    else if (key < mid_rank)
    {
        return select(head, mid_id, key);
    }
    else
    {
        return select(mid_id + 1, tail, key - mid_rank);
    }

    if(key<=mid_rank)
    {
        return select(head, mid_id, key);
    }   
    else
    {
        return select(mid_id + 1, tail, key - mid_rank);
    }
}

void sort(int head, int tail)
{
    //bubblesort
    for (int i = head; i < tail; i++)
        for (int j = head; j < head+tail - i; j++)
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
}

int partition(int low, int high, int middle)
{
    //return the number that is in the right position,
    //which means left part is smaller than it and right
    //part is bigger than it

    //since v is the first number, i should be array[low+1]

    int i = low + 1, j = high, k;
    for (k = low; k < high - low + 1;k++)
        if(array[k]==middle)
            break;
    exchange(array[k], array[low]);
    int v = array[low];
    while(1)
    {
        while(array[i]<v)
        {
            i++;
            if(i==high)
                break;
        }
        while(array[j]>v)
        {
            j--;
            if(j==low)
                break;
        }
        
        //Now, array[i] is bigger than v and array[j] is 
        //smaller than v. And array[low+1..i-1] are all 
        //smaller than v, same situcation for array[j+1
        //..high].

        if(i>=j)
            break;
        exchange(i, j);
    }

    //move array[j] to the right position

    exchange(low, j);

    //return j to devide array

    return j;
}

void exchange(int i,int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}