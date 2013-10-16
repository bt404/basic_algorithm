#include <stdio.h>

void  sort(int a[],int n)
{
    int temp=0,i,j;
    for(i=1;i<n;++i)
    {
        temp=a[i];
        j=i-1;
        while(j>=0&&temp<a[j])
        {
            a[j+1]=a[j];
            --j;
        }
        a[j+1]=temp;
    }
}

int main(void)
{
    int a[10]={1,3,2,4,6,5,7,10,9,8};
    sort(a,10);
    int i=0;
    for(;i<10;++i)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
