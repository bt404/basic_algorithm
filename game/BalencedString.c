#include <stdio.h>
#define MAX_NUM 100

typedef struct
{
    int data[MAX_NUM];
    int top;
}Stack;

/* 使用栈来存储记录左括号 */
int IsBalencedWithStack(char *str)
{
    if(str == NULL)
        return -1;
    Stack stack;
    stack.top = -1;
    char *p = str;
    while(*p!='\0' || stack.top>-1)
    {
        while(*p=='(')
        {
            stack.data[++stack.top] = '(';
            ++p;
        }
        while(*p==')')
        {
            --stack.top;
            ++p;
        }
        if(*p!='(' && *p!=')' && *p!='\0')
        {
            return -1;
        }
        if(stack.top<-1)
        {
            return 0;
        }
    }
    if(*p=='\0' && stack.top==-1)
        return 1;
    else
        return 0;
}

/* 本例中仅需要记录已有未配对的左括号数量，所以不需要用栈也可实现。 */
int IsBalenced(char *str)
{
    if(str == NULL)
        return -1;
    int num = 0;
    char *p = str;
    while(*p!='\0' || num>0)
    {
        while(*p=='(')
        {
            ++num;
            ++p;
        }
        while(*p==')')
        {
            --num;
            ++p;
        }
        if(*p!='(' && *p!=')' && *p!='\0')
        {
            return -1;
        }
        if(num<0)   /* 说明出现了未配对的右括号，若不判断，则之后补齐左括号仍返回平衡，与事实矛盾。 */
        {
            return 0;
        }
    }
    if(*p=='\0' && num==0)
        return 1;
    else
        return 0;
}

int main(void)
{
    char *strBalenced = "(()(()))";
    char *strNotBalenced = "(()()))(";
    char *strInvalid = "((not ))";
    int ret1 = IsBalenced(strBalenced);
    int ret2 = IsBalenced(strNotBalenced);
    int ret3 = IsBalenced(strInvalid);
    printf("%d, %d, %d\n", ret1, ret2, ret3);
    return 0;
}
