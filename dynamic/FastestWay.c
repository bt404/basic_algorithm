/*

  该解决方法的关键在于使用f表记录了问题规模从0到6的每一步的最优代价（两个子问题分别记录\
 ），而l表记录了每个最优结果的前一个加工站的信息，方便了最后构造最优解的追溯。 

*/

#include <stdio.h>


int fastest_way(int *e,int *x,int a[][6],int l[][6],int t[][5],int n)
{
    int result;
    int i,l_final;
    int f[2][6];
    f[0][0]=e[0]+a[0][0];
    f[1][0]=e[1]+a[1][0];
    
    for(i=1;i<n;++i)
    {
        if(f[0][i-1]+a[0][i]<=f[1][i-1]+a[0][i]+t[1][i-1])
        {
            f[0][i]=f[0][i-1]+a[0][i];
            l[0][i]=0;
        }
        else
        {
            f[0][i]=f[1][i-1]+a[0][i]+t[1][i-1];
            l[0][i]=1;
        }
        if(f[1][i-1]+a[1][i]<=f[0][i-1]+a[1][i]+t[0][i-1])
        {
            f[1][i]=f[1][i-1]+a[1][i];
            l[1][i]=1;
        }
        else
        {
            f[1][i]=f[0][i-1]+a[1][i]+t[0][i-1];
            l[1][i]=0;
        }
    }

    if((f[0][n-1]+x[0])<(f[1][n-1]+x[1]))
    {
        result=f[0][n-1]+x[0];
        l_final=0;
    }
    else
    {
        result=f[1][n-1]+x[1];
        l_final=1;
    }

    return l_final;
}

void print_result(int l_final,int l[][6],int n)
{
    int i=l_final,j=n-1;
    if(j>0)
    {
        print_result(l[i][j],l,j);
    }
    printf("line %d  station %d\n",i,j);

}

int main(void)
{
    int l[2][6];
    int a[2][6]={7,9,3,4,8,4,8,5,6,4,5,7};
    int e[2]={2,4};
    int x[2]={3,2};
    int t[2][5]={2,3,1,3,4,2,1,2,2,1};
    int l_final;
    
    l_final=fastest_way(e,x,a,l,t,6);
    print_result(l_final,l,6);
    
    return 0;

}
