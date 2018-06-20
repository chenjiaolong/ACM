#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define STACK_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef  int SElemType; //polymorphic date type
typedef int Status;

typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;
Status InitStack(SqStack *S)
{

    S -> base = (SElemType *)malloc(sizeof(int) * STACK_SIZE);

    if(!S -> base)exit(OVERFLOW);
    S -> top = S -> base;
    S -> stacksize = STACK_SIZE;
    return OK;
}
void DestroyStack(SqStack *S)
{
    if(S -> base)
    {
        free(S -> base);
        S -> stacksize = 0;
        S -> top = S -> base = NULL;
    }
}
void ClearStack(SqStack *S)
{
    if(S -> base) S -> top = S -> base;
}
bool StackEmpty(SqStack S)
{
    return S.top == S.base;
}
int StackLength(SqStack S)
{
    return S.top - S.base;
}
Status GetTop(SqStack S, SElemType *e)
{
    if(S.top == S.base) return ERROR;
    *e = *(S.top - 1);
    return OK;
}
Status Push(SqStack *S,SElemType e)
{
    if(S -> top - S -> base == S -> stacksize)
    {
        S -> base = (SElemType *) realloc(S -> base, (S -> stacksize + STACKINCREMENT) * sizeof(SElemType));
        if(!S -> base) exit(OVERFLOW);
        S -> top = S -> base + S -> stacksize;
        S -> stacksize +=  STACKINCREMENT;
    }
    *S -> top ++ = e;
    return OK;
}
Status Pop(SqStack *S,SElemType *e)
{
    if(S -> top == S -> base)return ERROR;
    *e = *(--S -> top);
    return OK;
}
void StackTraverse(SqStack S)
{
    while(S.top != S.base)
    {
        if(S.top - 1 == S.base) printf("%d\n", *(--S.top));
        else printf("%d ", *(--S.top));
    }
}
int main()
{
    SqStack S;
    SElemType temp;
    InitStack(&S);

    if(StackEmpty(S)) puts("The Stack is empty!!!");
    else puts("The Stack is not empty!!!");

    Push(&S,1);
    Push(&S,2);

    if(StackEmpty(S)) puts("The Stack is empty!!!");
    else puts("The Stack is not empty!!!");

    int len = StackLength(S);
    printf("The Stack's length is %d\n", len);

    StackTraverse(S);

    int rt;
    rt = GetTop(S, &temp);
    if(rt) printf("%d is the top elem.\n", temp);
    else puts("The Stack is nothing.");

    Pop(&S,&temp);
    printf("%d is popped\n", temp);

    Pop(&S, &temp);
    printf("%d is popped\n", temp);

    ClearStack(&S);

    rt = GetTop(S, &temp);
    if(rt) printf("%d is the top elem.\n", temp);
    else puts("The Stack is nothing.");

    StackTraverse(S);

    DestroyStack(&S);
    return 0;
}
