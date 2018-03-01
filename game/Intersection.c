#include <stdio.h>

void Intersection(int data1[], int size1, int data2[], int size2)
{
    if(data1==NULL || data2==NULL || size1<=0 || size2<=0)
        return;
    int i = 0;
    int j = 0;
    int size = size1>size2? size2: size1;
    int data[size];
    int k=0;
    while(i<size1 && j<size2)
    {
        if(data1[i] == data2[j])
        {
            data[k] = data1[i];
            ++k;
            ++i;
            ++j;
        }
        else if(data1[i] < data2[j])
        {
            ++i;
        }
        else
        {
            ++j;
        }
    }
    for(i=0; i<k; ++i)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main(void)
{
    // 如果是一般数组可以先对两个数组进行排序
    int data1[] = {1, 2, 4, 6, 8, 12, 24};
    int data2[] = {1, 2, 5, 7, 8, 12, 24, 30};
    Intersection(data1, 7, data2, 8);
    return 0;
}
