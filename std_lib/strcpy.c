#include <stdio.h>
#include <assert.h>

char *strcpy(char *str1, const char *str2)
{
    assert(str1!=NULL && str2!=NULL);
    char *addr = str1;
    while((*str1++ = *str2++)!='\0');
    return addr;
}

int main(void)
{
    char str1[] = "fucky lucky";
    char str2[] = "godaddy";
    char *p = strcpy(str1, str2);
    printf("%s\n", p);
    return 0;
}
