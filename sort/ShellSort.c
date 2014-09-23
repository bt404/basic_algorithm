#include <stdio.h>

void ShellSort(int data[], int length)
{
    if (data == NULL || length <= 0)
        return;
    int i, j, tmp, gap;
    gap = length/2;
    while (gap>0)
    {
        for (i=gap; i<length; ++i)
        {
            tmp = data[i];
            j = i-gap;
            while (j>=0 && tmp<data[j])
            {
                data[j+gap] = data[j];
                j -= gap;
            }
            data[j+gap] = tmp;
            j -= gap;
        }
        gap /= 2;
    }
}

int main(void)
{
    int data[] = {2, 4, 3, 9, 25, 12, 7, 34, 1};
    ShellSort(data, sizeof(data)/4);
    for (int i=0; i<sizeof(data)/4; ++i)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}
