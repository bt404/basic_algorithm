#include <stdio.h>

void lcs(char *x,char *y,int m,int n,int c[][n],int s[][n])
{
    int i,j;
    for(j=0;j<n;++j)
    {
        c[0][j]=0;
    }
    for(i=0;i<m;++i)
    {
        c[i][0]=0;
    }

    for(i=1;i<m;++i)
    {
        for(j=1;j<n;++j)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                s[i][j]=1;
            }
            else
            {
                if(c[i-1][j]>c[i][j-1])
                {
                    c[i][j]=c[i-1][j];
                    s[i][j]=2;
                }
                else
                {
                    c[i][j]=c[i][j-1];
                    s[i][j]=3;
                }
            }
        }
    }
}


void print_lcs(char *x,int s[][7],int m,int n)
{
    if(m<0||n<0)
        return;
    if(s[m][n]==1)
    {
        print_lcs(x,s,m-1,n-1);
        printf("%c",x[m-1]);
    }
    else if(s[m][n]==2)
    {
        print_lcs(x,s,m-1,n);
    }
    else if(s[m][n]==3)
    {
        print_lcs(x,s,m,n-1);
    }
}

int main(void)
{
    char *x="hello echo";
    char *y="elyoco";
    int c[11][7];
    int s[11][7];
    lcs(x,y,11,7,c,s);
    print_lcs(x,s,10,6);
    printf("\n");
    return 0;
}


