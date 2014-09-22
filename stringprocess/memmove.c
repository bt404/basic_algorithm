#include <stdio.h>
#include <assert.h>

void *memmove(void *pDest, const void *pSource, size_t size)
{
    assert((pDest!=NULL) && (pSource!=NULL));
    char *dest = pDest;
    const char *source = pSource;

    if (dest <= source)
    {
        while(--size)
        {
            *dest-- = *source--;
        }
    }
    else
    {
        dest += size;
        source += size;
        while(--size)
        {
            *--dest = *--source;
        }
    }
    return pDest;
}

int main(void)
{
    char source[] = "hello world";
    char dest[40];
    char *ret = memmove(dest, source, sizeof(source));
    printf("%s\n%lu\n", ret, sizeof(source));
    return 0;
}
