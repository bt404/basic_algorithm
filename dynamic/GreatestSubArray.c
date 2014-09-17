#include <stdio.h>

int g_valid_input = 0;

int FindGreatestSubArray(int data[], int length)
{
    if (data == NULL)
    {
        g_valid_input = 1;
        return 0;
    }
    
    int f[length];
    for (int i = 0; i < length; ++i)
    {
        f[i] = data[i];
    }

    int ret = data[0];

    for (int i = 1; i < length; ++i)
    {
        if(f[i-1] > 0)
            f[i] = f[i-1]+data[i];      // 如果以 i-1 为结尾的子数组最大和为正
        else
            f[i] = data[i];
        if(ret < f[i])
        {
            ret = f[i];
        }
    }

    return ret;
}

int main(void)
{
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    int ret = FindGreatestSubArray(data, 8);
    printf("%d\n", ret);
    printf("%lu\n", sizeof(data));
    return 0;
}
