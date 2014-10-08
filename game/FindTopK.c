#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int data[], int start, int end)
{
    if(data==NULL || start>end || end<=0)
        return -1;
    int i = start+rand()%(end-start+1);
    int small = start;
    for(i=start; i<end; ++i)
    {
        if(data[i] < data[end])
        {
            if(i != small)
                Swap(&data[i], &data[small]);
            ++small;
        }
    }
    Swap(&data[small], &data[end]);
    return small;
}

void GetTopK(int data[], int start, int end, int k)
{
    printf("start: %d\n", start);
    printf("end: %d\n", end);
    if(k <= 0)
        return;
    int index = Partition(data, start, end);
    printf("count: %d\n", index+1);
    printf("\n");
    int count = index-start+1;
    if(index == -1)
        return;
    else if(count > k)    // k 是每次要找到的元素数
    {
        GetTopK(data, start, index-1, k);
    }
    else if(count < k)
    {
        GetTopK(data, index+1, end, k-count);
    }
}

int main(void)
{
    int data[] = {1, 32, 4, 2, 14, 9, 25, 7, 100, 54, 8};
    int top_k = 8;
    GetTopK(data, 0, sizeof(data)/sizeof(int)-1, top_k);
    for(int i=0; i<top_k; ++i)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}
