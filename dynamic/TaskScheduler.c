#include <stdio.h>

/* 仅有两台机器的情况 */
int SchedulerWith2Machine(int time[], int n)
{
    int table[n];
    table[0] = time[0]>time[1]? 1: 0;
    for(int i=1; i<n; ++i)
    {
        if((table[i-1]+1)*time[0]<(n-table[i-1]+1)*time[1])
        {
            table[i] = table[i-1]+1;
        }
        else
        {
            table[i] = table[i-1];
        }
    }
    return table[n-1];
}

int main(void)
{
    int time[2] = {2, 5};
    int n = 7;
    int ret = SchedulerWith2Machine(time, n);
    printf("第一台执行 %d 个任务\n第二台执行 %d 个任务\n", ret, n-ret);
    return 0;
}
