#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int data[], int start, int end)
{
    if (!data) return -1;
    int small = start;
    int i = start+rand()%(end-start+1);
    Swap(&data[i], &data[end]);
    for(i=start; i<end; ++i)
    {
        if(data[i] < data[end])
        {
            if(small != i)
                Swap(&data[small], &data[i]);
            ++small;
        }
    }
    Swap(&data[small], &data[end]);
    return small;
}

void QuickSort(int a[], int p, int r)
{
    if(p<r)
    {
        int q;
        q = Partition(a, p, r);
        QuickSort(a, p, q-1);
        QuickSort(a, q+1, r);
    }
}

int main(void)
{
   int a[10] = {4, 5, 3, 7, 1, 2, 10, 8, 9, 6};
   QuickSort(a, 0, 9);
   int i = 0;
   for(; i<10; ++i)
   {
       printf("%d\n", a[i]);
   }
}
