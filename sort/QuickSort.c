#include <stdio.h>

int Partition(int a[], int p, int r)
{
    int i = p;
    int j, temp;
    for(j=p; j<r; ++j)
    {
        if(a[j]<a[r])
        {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            ++i;
        }
    }
    temp = a[i];
    a[i] = a[r];
    a[r] = temp;
    return i;
}

void QuickSort(int a[], int p, int r)
{
    int q;
    if(p<r)
    {
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
