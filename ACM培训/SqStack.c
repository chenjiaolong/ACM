#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 1000

typedef struct
{
    int *data;
    int top;
}SqStack;

bool InitStack(SqStack *S)
{
    S -> data = (int *)malloc(sizeof(int) * MaxSize);
    if(!S -> data)
        return false;
   S -> top = -1;
    return true;
}
void DestroyStack(SqStack *S)
{
    free(S -> data);
    S -> data = NULL;
    S -> top = -1;
}
void ClearStack(SqStack *S)
{
    S -> top = -1;
}
bool StackEmpty(SqStack S)
{
    return S.top == -1;
    /*if(S.top == -1)
        return true;
    return false;*/
}
int StackLength(SqStack S)
{
    return S.top + 1;
}
bool GetTop(SqStack S, int *e)
{
    if(S.top == -1) return false;
    *e = S.data[S.top];
    return true;
}
bool Push(SqStack *S,int value)
{
    if(S -> top + 1 == MaxSize)
        return false;
    S -> data[ ++ S -> top] = value;
    return true;
}
bool Pop(SqStack *S, int *e)
{
    if(StackEmpty(*S)) return false;
    *e = S -> data[S -> top --];
    return true;
}
void StackTraverse(SqStack S)
{
    int i;
    for(i = S.top; i >=0 ; i--)
        printf("%d%c",S.data[i],i == 0 ? '\n' : ' ');
}
int main()
{
    SqStack S;
    int temp;
    int rt;
    InitStack(&S);

    if(StackEmpty(S)) puts("The Stack is empty!!!");
    else puts("The Stack is not empty!!!");

    Push(&S,1);
    Push(&S,2);
    Push(&S,3);
    Push(&S,4);

    StackTraverse(S);

    int len = StackLength(S);
    printf("The Stack's length is %d\n", len);

    rt = GetTop(S, &temp);
    if(rt) printf("%d is the top elem.\n", temp);
    else puts("The Stack is nothing.");

    Pop(&S, &temp);
    printf("%d is popped\n", temp);

    Pop(&S, &temp);
    printf("%d is popped\n", temp);

    while(!StackEmpty(S))
    {
		GetTop(S, &temp);
        printf("%d ", temp);
        Pop(&S, &temp);
    }
    puts("");
    ClearStack(&S);

    rt = GetTop(S, &temp);
    if(rt) printf("%d is the top elem.\n", temp);
    else puts("The Stack is nothing.");

    StackTraverse(S);

    DestroyStack(&S);

    return 0;
}
