#include <stdio.h>
#define INFINITY 9999999

void Merge(int a[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int L[n1+1],R[n2+1];
    int i,j;
    for(i=0;i<n1;++i)
    {
        L[i]=a[p+i];
    }
    for(j=0;j<n2;++j)
    {
        R[j]=a[q+j+1];
    }
    L[n1]=INFINITY;
    R[n2]=INFINITY;

    i=0;
    j=0;
    int k;
    for(k=p;k<=r;++k)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            ++i;
        }    
        else
        {
            a[k]=R[j];
            ++j;
        }
    }
}

void Merge_Sort(int a[],int p,int q)
{
    if(p<q)
    {
        int r=(p+q)/2;
        Merge_Sort(a,p,r);
        Merge_Sort(a,r+1,q);
        Merge(a,p,r,q);
    }
}

int main(void)
{
    int a[20]={1,3,5,3,6,23,43,2,32,45,432,323,32,45,423,3423,23,43,432,43};
    Merge_Sort(a,0,19);
    int i=0;
    for(;i<20;++i)
    {
        printf("%d\n",a[i]);
    }
}
