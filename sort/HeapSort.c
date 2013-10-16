#include <stdio.h>

void Max_Heapify(int a[],int i,int n)
{
    int l,r,temp,largest=i;
    l=2*i+1;
    r=2*i+2;
    if(l<n&&a[i]<a[l])
    {
        largest=l;
    }
    if(r<n&&a[r]>a[largest])
    {
        largest=r;
    }
    if(i!=largest)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        Max_Heapify(a,largest,n);
    }
}

void Build_Max_Heap(int a[],int n)
{
    int i=n/2-1;
    for(;i>=0;--i)
    {
        Max_Heapify(a,i,n);
    }
}

void Max_Heap_Sort(int a[],int n)
{
    Build_Max_Heap(a,n);
    int i=n-1,temp;
    for(;i>0;--i)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        Max_Heapify(a,0,i);
    }
}

int main(void)
{
    int a[11]={5,3,6,1,7,10,9,2,8,101,4};
    Max_Heap_Sort(a,11);
    int i;
    for(i=0;i<11;++i)
    {
        printf("%d\n",a[i]);
    }
}
