#include <stdio.h>

void Bubble_Sort_Down(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;++i)
    {
        for(j=i;j<n;++j)
        {
            if(a[j]<a[j-1])
            {
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
}

void Bubble_Sort_Up(int a[],int n)
{
    int i,j,temp;
    for(i=n-1;i>0;--i)
    {
        for(j=n-1;j>n-i-1;--j)
        {
            if(a[j]<a[j-1])
            {
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
}

int main(void)
{
    int a[10]={2,1,5,4,3,6,7,10,9,8};
    Bubble_Sort_Down(a,10);
    int i=0;
    for(;i<10;++i)
    {
        printf("%d\n",a[i]);
    }
}
