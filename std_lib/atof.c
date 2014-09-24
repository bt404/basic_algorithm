#include <stdio.h>
#include <string.h>
#include <assert.h>

int is_digit(char ch)
{
    if(ch>='0' && ch<='9')
        return 1;
    return 0;
}

int is_space(char ch)
{
    if(ch==' ')
        return 1;
    return 0;
}

double atof(char *s)
{
    assert(s!=NULL);
    double power, value;
    int i, sign;
    for(i=0; is_space(s[i]); ++i);
    sign = s[i]=='-'? -1 :1;
    if(s[i]=='-' || s[i]=='+')
        ++i;
    for(value=0.0; is_digit(s[i]); ++i)
        value = value*10.0+(s[i]-'0');
    if(s[i]=='.')
        ++i;
    for(power=1.0; is_digit(s[i]); ++i)
    {
        value = value*10.0+(s[i]-'0');
        power *= 10.0;
    }
    return sign * value / power;
}

int main()
{
    double sum;
    char intStr[] = "   -223.54";
    sum = atof(intStr);
    printf("%f\n", sum);
    return 0;
}
