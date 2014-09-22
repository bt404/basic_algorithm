#include <stdio.h>
#include <string.h>
#include <assert.h>

void DeleteChars(char *pStr, char *pDel)
{
    assert((pStr!=NULL) && (pDel!=NULL));
    const int tableSize = 256;
    int hashTable[tableSize];
    for (int i=0; i < tableSize; ++i)
    {
        hashTable[i] = 0;
    }
    char *p = pDel;
    while (*p != '\0')
        hashTable[*p++]++;
    char *pBehind = pStr;
    p = pStr;
    while (*p != '\0')
    {
        if(hashTable[*p] == 0)
            *pBehind++ = *p;
        ++p;
    }
    *pBehind = '\0';
}

int main(void)
{
    char pStr[] = "hello world";    // 必须是数组而不能直接在堆中分配
    char *pDel = "er ";
    DeleteChars(pStr, pDel);
    printf("%s\n", pStr);
    return 0;
}
