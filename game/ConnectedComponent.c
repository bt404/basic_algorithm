#include <stdio.h>

 
/* 无法使用DP，因为不能从table[i-1][j]和table[i][j-1]推出table[i][j]。
/*int ConnectedComponent(int data[][4], int rows, int cols)
{
    if(data==NULL || rows<=0 || cols<=0)
        return -1;
    int table[rows][cols];
    table[0][0] = data[0][0]? 1: 0;
    for(int j=1; j<rows; ++j)
    {
        if(data[0][j]==1 && data[0][j-1]==0)
            table[0][j] = table[0][j-1]+1;
        else
            table[0][j] = table[0][j-1];
    }
    for(int i=1; i<cols; ++i)
    {
        if(data[i][0]==1 && data[i-1][0]==0)
            table[i][0] = table[i-1][0]+1;
        else
            table[i][0] = table[i-1][0];
    }
    for(int i=1; i<rows; ++i)
    {
        for(int j=1; j<cols; ++j)
        {
            int max = (table[i-1][j]>table[i][j-1])? table[i-1][j]: table[i][j-1];
            if(data[i][j]==1 && data[i-1][j]==0 && data[i][j-1]==0)
                table[i][j] = max+1;
            else
                table[i][j] = max;
        }
    }
    return table[rows-1][cols-1];
}*/

/* 深度遍历的方法，每遇到一个1，统计加1，并且消除与其连通的所有1 */
void Erase(int data[][4], int i, int j, int rows, int cols)
{
    data[i][j] = 0;
    while(i-1>=0 && data[i-1][j]==1)
        Erase(data, i-1, j, rows, cols);
    while(i+1<rows && data[i+1][j]==1)
        Erase(data, i+1, j, rows, cols);
    while(j-1>=0 && data[i][j-1]==1)
        Erase(data, i, j-1, rows, cols);
    while(j+1<cols && data[i-1][j]==1)
        Erase(data, i, j+1, rows, cols);
}

int ConnectedComponent(int data[][4], int rows, int cols)
{
    if(data==NULL || rows<=0 || cols<=0)
        return -1;
    int num = 0;
    for(int i=0; i<rows; ++i)
    {
        for(int j=0; j<cols; ++j)
        {
            if(data[i][j]==1)
            {
                Erase(data, i, j, rows, cols);
                ++num;
            }
        }
    }
    return num;
}

int main(void)
{
    int data[][4] = {1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0};
    //int data[][4] = {1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1};
    //int data[][4] = {1, 0, 0, 0, 0, 1, 0, 1};
    //int data[][4] = {1, 0, 0, 0};
    int num = ConnectedComponent(data, 4, 4);
    printf("连通区域数量为： %d\n", num);
    return 0;
}
