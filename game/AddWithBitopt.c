#include <stdio.h>

int add(int a, int b)
{
    if (!a) return b;
    else
        return add((a & b) << 1, a^b);
}


int main(void)
{
    int c = add(3, -2);
    int d = add(0, 2);
    printf("%d %d\n", c, d);
    return 0;
}
