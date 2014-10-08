#include <stdio.h>

int FindFirstBitOne(int num)
{
    int index = 0;
    while((num&0x1)==0 && index<sizeof(int)*8)
    {
        num >>= 1;
        ++index;
    }
    return index;
}

int IsSet(int num, int index)
{
    num >>= index;
    return num & 0x1;
}

void FindMissing(int data[], int length, int *num1, int *num2)
{
    if(data==NULL || length<=0)
        return;
    int xor = 0;
    for(int i=0; i<length; ++i)
    {
        xor ^= data[i];
    }
    for(int i=1; i<=length+2; ++i)
    {
        xor ^= i;
    }
    int index = FindFirstBitOne(xor);
    *num1 = 0;
    *num2 = 0;
    for(int i=1; i<=length+2; ++i)
    {
        if(IsSet(i, index))
            *num1 ^= i;
        else
            *num2 ^= i;
    }
    for(int i=0; i<length; ++i)
    {
        if(IsSet(data[i], index))
            *num1 ^= data[i];
        else
            *num2 ^= data[i];
    }
}

int main(void)
{
    int data[] = {1, 4, 3, 6, 7, 9, 10, 5};
    int num1, num2;
    FindMissing(data, 8, &num1, &num2);
    printf("missing number: %d, %d\n", num1, num2);
    return 0;
}
