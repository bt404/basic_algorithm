#include <stdio.h>
#include <string.h>

void GetNext(char *pattern, int next[], int length)
{
    if (!pattern || !next) return;
    int j = 0;
    int k = -1;
    next[0] = -1;
    while (j < length-1)
    {
        if (k == -1 || pattern[j] == pattern[k])
        {
            if (pattern[++j] != pattern[++k])
            {
                next[j] = next[k];
            }
            else
            {
                next[j] = k;
            }
        }
        else
        {
            k = next[k];
        }
    } 
}

int KMP(char *text, char *pattern, int lenText, int lenPattern)
{
    if (!text || !pattern || lenText<=0 || lenPattern <=0) return -1;
    int next[lenPattern];
    GetNext(pattern, next, lenPattern);
    int i=0, j=0;
    int ret;
    while (i < lenText && j < lenPattern)
    {
        if (j == -1 || text[i] == pattern[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == lenPattern)
    {
        ret = i-j;
    }
    return ret;
}

int main()
{
    char *text = "abcabdef";
    char *patt = "abd";
    int ret = KMP(text, patt, strlen(text), strlen(patt));
    printf("%d\n", ret);

    return 0;
}
