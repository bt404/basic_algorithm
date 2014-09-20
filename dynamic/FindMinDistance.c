#include <stdio.h>
#include <string.h>

int MinNum(int n1, int n2, int n3)
{
    int temp = (n1 < n2) ? n1 : n2;
    return  (temp < n3) ? temp : n3;
}

int FindMinDistance(char * str1, char * str2)
{
    if (str1 == NULL || str2 == NULL)
        return -1;
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    int table[size1+1][size2+1];
    for (int j = 0; j <= size2; ++j)
        table[0][j] = j;
    for (int i = 1; i <= size1; ++i)
    {
        table[i][0] = i;
        for (int j = 1; j <= size2; ++j)
        {
            if (str1[i] == str2[j])
                table[i][j] = table[i-1][j-1];
            else
                table[i][j] = MinNum(table[i-1][j-1]+1, table[i][j-1]+1, table[i-1][j]+1);
        }
    }
    int distance = table[size1][size2];
    return distance;
}

int main(void)
{
    char *str1 = "hello world";
    char *str2 = "ello nor";
    int distance = FindMinDistance(str1, str2);
    printf("%d\n", distance);
    return 0;
}
