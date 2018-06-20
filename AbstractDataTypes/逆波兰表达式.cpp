#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    NOP,
    ADD,
    SUB,
    MUL,
    DIV,
    FUNC1,
    FUNC2
} e_t;
int Add(int a, int b)
{
    return a+b;
}
int Sub(int a, int b)
{
    return a-b;
}
int Mul(int a, int b)
{
    return a*b;
}
int Div(int a, int b)
{
    return a/b;
}
int func1(int a,int b,int c)
{
    return a+b*c;
}
int func2(int a,int b,int c)
{
    return a/b+c;
}

typedef struct
{
    e_t op;
    int n;
} x_t;

int cal(x_t*a, int len)
{
    int stack[1000];
    int top=-1;
    int i;
    for(i=0; i<len; i++)
    {
        switch(a[i].op)
        {
        case NOP:
            stack[++top] = a[i].n;
            break;
        case ADD:
            stack[top-1] = Add(stack[top-1],stack[top]);
            top--;
            break;
        case SUB:
            stack[top-1] = Sub(stack[top-1],stack[top]);
            top--;
            break;
        case MUL:
            stack[top-1] = Mul(stack[top-1],stack[top]);
            top--;
            break;
        case DIV:
            stack[top-1] = Div(stack[top-1],stack[top]);
            top--;
            break;
        case FUNC1:
            stack[top-2] = func1(stack[top-2],stack[top-1],stack[top]);
            top-=2;
            break;
        case FUNC2:
            stack[top-2] = func2(stack[top-2],stack[top-1],stack[top]);
            top-=2;
            break;
        }
    }
    return stack[0];
}

x_t a[] =
{
    {NOP,10},
    {NOP,2},
    {NOP,3},
    {ADD,0},
    {SUB,0},
    {NOP,10},
    {MUL,0},
    {NOP,5},
    {DIV,0},
    {NOP,9},
    {NOP,10},
    {FUNC1,0},
    {NOP,1},
    {NOP,2},
    {FUNC2,0}
};
int main()
{
    int res = cal(a,sizeof(a)/sizeof(a[0]));
    printf("%d\n",res);
    system("pause");
    return 0;
}
