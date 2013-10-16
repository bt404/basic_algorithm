#include <stdio.h>

#define FINITE 65525

int matrix_chain_order(int *p,int m[][6],int s[][6],int n)
{
    int i=0,j;
    for(;i<n;++i)
    {
        m[i][i]=0;
    }

    int l;
    for(l=2;l<=n;++l)
    {
        for(i=0;i<n-l+1;++i)
        {
            j=i+l-1;
            m[i][j]=FINITE;
            int k;

            for(k=i;k<j;++k)
            {
                int q=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    return 0;
}

void print_parens(int s[][6],int i,int j)
{
    if(i==j)
    {
        printf("A%d",i);
    }
    else
    {
        printf("(");
        print_parens(s,i,s[i][j]);
        print_parens(s,s[i][j]+1,j);
        printf(")");
    }
}

int main(void)
{
    int m[6][6];
    int s[6][6];
    int p[7]={30,35,15,5,10,20,25};

    int ret=matrix_chain_order(p,m,s,6);
    printf("%d\n",s[0][5]);
    print_parens(s,0,5);
    printf("\n");

    int i,j;
    for(i=0;i<6;++i)
    {
        for(j=i;j<6;++j)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    return 0;
}

