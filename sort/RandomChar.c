#include <stdio.h>

void SortChar(char data[], int length)
{
    const int size = 52;
    char table[size];
    for(int i=0; i<size; ++i)
    {
        table[i] = 0;
    }
    for(int i=0; i<length; ++i)
    {
        int index = data[i]>'Z'? 2*(data[i]-'a'): 2*(data[i]-'A')+1;
        table[index]++;
    }
    int index = 0;
    for(int i=0; i<size; ++i)
    {
        for(int j=0; j<table[i]; ++j)
        {
            data[index++] = (i&0x1)? ((i-1)/2+'A'): (i/2+'a');
        }
    }
}

int main(void)
{
    char data[] = {'R', 'B', 'B', 'b', 'W', 'W', 'R', 'B', 'w'};
    SortChar(data, 9);
    for(int i=0; i<9; ++i)
    {
        printf("%c ", data[i]);
    }
    printf("\n");
    return 0;
}
