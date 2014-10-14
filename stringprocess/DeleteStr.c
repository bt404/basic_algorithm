#include <stdio.h>
#include <string.h>
#include "kmp.c"


void StrMoveBehind(char *str, int count, int offset)
{
    if(str==NULL || count<=0 || offset<=0)
        return;
    while(count>0)
    {
        *(str-offset) = *str;
        ++str;
        --count;
    }
}

/* 删除pSrc中的所有pDel，每次删除一个，count记录当前删除次数，从而保证每个字符只移动1次。 */
void DeleteStr(char *pSrc, char *pDel)
{
    if(pSrc==NULL || pDel==NULL)
        return;
    int count = 0;
    int lenDel = strlen(pDel);
    int lenSrc = strlen(pSrc);
    int index[2] = {0, 0};
    int flag = 0;
    char *p = pSrc;
    index[flag] = KMP(p, pDel, lenSrc, lenDel);
    if(index[flag] == -1)
        return;
    while(index[flag]!=-1 && count<5)
    {
        ++count;
        p += index[flag]+lenDel;
        index[1-flag] = KMP(p, pDel, strlen(p), lenDel);
        if(index[1-flag]!=-1)
            StrMoveBehind(p, index[1-flag], count*lenDel);
        else
            StrMoveBehind(p, strlen(p), count*lenDel);
        flag = 1-flag;
    }
    pSrc[lenSrc-count*lenDel] = '\0';
}

int main(void)
{
    char pSrc[] = {"tell hello elle"};
    char pDel[] = {"el"};
    DeleteStr(pSrc, pDel);
    printf("%s\n", pSrc);
    return 0;
}
