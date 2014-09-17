#include <stdio.h>

int FindMissing(int data[], int length)
{
    if (data == NULL || length <= 0)
        return -1;
    int start = 0;
    int end = length-1;
    while (start <= end)
    {
        int mid = (start+end)/2;
        if (data[mid] > mid+1)
            end = mid-1;
        else if (data[mid] == mid+1)
            start = mid+1;
    }
    return start+1;
}

int main(void)
{
    int dataOdd[] = {1, 2, 3, 4, 6, 7};
    int dataEven[] = {1, 2, 3, 4, 5, 7, 8};
    int dataSingle[] = {2};
    int missing1 = FindMissing(dataOdd, 6);
    int missing2 = FindMissing(dataEven, 7);
    int missing3 = FindMissing(dataSingle, 1);
    printf("%d, %d, %d\n", missing1, missing2, missing3);
    return 0;
}
