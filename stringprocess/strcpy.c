#include <stdio.h>
#include <assert.h>

char * strcpy(char *pDest, const char *pSource)
{
    assert((pDest != NULL) && (pSource != NULL));
    char * addr = pDest;
    while((*pDest++ = *pSource++)!='\0')
        NULL;
    return addr;
}

int main(void)
{
    char dest[40];
    char *source = "hello world";
    char *ret = strcpy(dest, source);
    printf("%s\n", ret);
    return 0;
}
