#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
}SNode, *LinkStackPtr;

typedef struct
{
    LinkStackPtr top;
    int len;
}LinkStack;

bool InitStack(LinkStack *S)
{
    S -> top = (LinkStackPtr )malloc(sizeof(SNode));
    if(!S -> top) return false;
    S -> top = NULL;
    S -> len = 0;
    return true;
}
void ClearStack(LinkStack *S)
{
    LinkStackPtr p, q;
    p = S -> top;
    while(p)
    {
        q = p -> next;
        free(p);
        p = q;
    }
    S -> len = 0;
}
bool StackEmpty(LinkStack S)
{
    return S.top == NULL;
}
int StackLength(LinkStack S)
{
    return S.len;
}
bool GetTop(LinkStack S, int *e)
{
    if(StackEmpty(S)) return false;
    *e = S.top -> data;
    return true;
}
bool Push(LinkStack *S, int e)
{
    LinkStackPtr p = (LinkStackPtr )malloc(sizeof(SNode));
    if(!p) return false;
    p -> data = e;
    p -> next = S -> top;
    S -> top = p;
    S -> len ++;
    return true;
}
bool Pop(LinkStack *S, int *e)
{
    if(S -> len == 0) return false;
    LinkStackPtr p = S -> top;
    *e = S -> top -> data;
    S -> top = p -> next;
    free(p);
    S -> len --;
    return true;
}

void StackTraverse(LinkStack S)
{
    LinkStackPtr p = S.top;
    while(p)
    {
        if(p -> next == NULL) printf("%d\n", p -> data);
        else printf("%d ", p -> data);
        p = p -> next;
    }
}

int main()
{
    int temp;
    int rt;
    LinkStack S;
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

    Pop(&S, &temp);
    printf("%d is popped\n", temp);

    Pop(&S, &temp);
    printf("%d is popped\n", temp);

    while(!StackEmpty(S))
    {
        GetTop(S, &temp);
        printf("%d ",temp);
        Pop(&S, &temp);
    }
    puts("");
    ClearStack(&S);

    rt = GetTop(S, &temp);
    if(rt) printf("%d is the top elem.\n", temp);
    else puts("The Stack is nothing.");

    StackTraverse(S);

    return 0;
}
