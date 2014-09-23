#include <stdio.h>
#include <string.h>

int lcs(char *str1, char *str2)
{
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    if (size1 == 0 || size2 == 0) return 0;

    /*int start1 = -1;
    int start2 = -1;*/
    int table[size1][size2];
    /* 初始化放在 table 的构造过程中实现 */
    /*for (int i = 0; i < size1; ++i)
    {
        for (int j = 0; j < size2; ++j)
        {
            table[i][j] = 0;
        }
    }*/

    int longest = 0;

    for (int j = 0; j < size2; ++j)
    {
        table[0][j] = (str1[0] == str2[j] ? 1 :0);
    }

    for (int i = 1; i < size1; ++i)
    {
        table[i][0] = (str1[i] == str2[0] ? 1 :0);

        for (int j = 1; j < size2; ++j)
        {
            if(str1[i] == str2[j])
            {
                table[i][j] = table[i-1][j-1]+1;
            }
            else
            {
                table[i][j] = 0;
            }
            if (longest < table[i][j])
                longest = table[i][j];
        }
    }

    /*for (int i = 0; i < size1; ++i)
    {
        for (int j = 0; j < size2; ++j)
        {
            if(longest < table[i][j])
            {
                longest = table[i][j];
                start1 = i-longest+1;
                start2 = j-longest+1;
            }
        }
    }*/

    return longest;
}


int main(int argc, char **argv)
{
    char *str1 = "hello world";
    char *str2 = "ye word";
    int longest = lcs(str1, str2);
    printf("%d\n", longest);
    return 0;
}
