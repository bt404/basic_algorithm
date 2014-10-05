#include <stdio.h>

void PrintRotate2DimMatrix(int data[][3], int length)
{
    for(int j=length-1; j>=0; --j)
    {
        int i = 0;
        int temp = j;
        while(i<length && temp<length)
        {
            printf("%d ", data[i++][temp++]);
        }
        printf("\n");
    }
    for(int i=1; i<length; ++i)
    {
        int j = 0;
        int temp = i;
        while(temp<length && j<length)
        {
            printf("%d ", data[temp++][j++]);
        }
        printf("\n");
    }
}

void PrintRotateMatrix(int data[], int length)
{
    for(int j=length-1; j>=0; --j)
    {
        int i = 0;
        int temp = j;
        while(i<length && temp<length)
        {
            printf("%d ", data[i*length+temp]);
            ++i;
            ++temp;
        }
        printf("\n");
    }
    for(int i=1; i<length; ++i)
    {
        int j = 0;
        int temp = i;
        while(temp<length && j<length)
        {
            printf("%d ", data[temp*length+j]);
            ++j;
            ++temp;
        }
        printf("\n");
    }
}

int main(void)
{
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    PrintRotateMatrix(data, 3);
    return 0;
}
