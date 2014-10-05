/* A(n) = 1 + x + x^2 + ... + x^n, x>0, n>=0
 * 尽量减少乘法次数，多使用加法。
 * 如下算法对于给定整数n，使用n次乘法。
 */

#include <stdio.h>

int A(int x, int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return 1 + x * A(x, n-1);
    }
}

int main(void)
{
    int ret = A(2, 4);
    printf("%d\n", ret);
    ret = A(3, 3);
    printf("%d\n", ret);
    ret = A(3, 0);
    printf("%d\n", ret);
    return 0;
}
