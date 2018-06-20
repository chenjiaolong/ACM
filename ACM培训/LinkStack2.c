#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} SNode,*LinkStack;

void InitStack(LinkStack *S)
{
    *S = NULL;
}
void DestroyStack(LinkStack *S)
{
    LinkStack p;
    while(*S)
    {
        p = (*S) -> next;
        free(*S);
        *S = p;
    }
}

void ClearStack(LinkStack *S)
{
    LinkStack p = *S;
    while(*S)
    {
        p = (*S) -> next;
        free(*S);
        *S = p;
    }
}
bool StackEmpty(LinkStack S)
{
    return S == NULL;
}
int StackLength(LinkStack S)
{
    LinkStack p = S;
    int size = 0;
    while(p)
    {
        size ++;
       p = p -> next;
    }
    return size;
}
bool Push(LinkStack *S, int e)
{
    LinkStack pNew = (LinkStack )malloc(sizeof(SNode));
    if(!pNew) return false;
    pNew -> data = e;
    pNew -> next = *S;
    *S = pNew;
    return true;
}
bool Pop(LinkStack *S, int *e)
{
    if(*S == NULL) return false;
    LinkStack p = *S;
    *e = p -> data;
    *S = (*S) -> next;
    free(p);
    return true;
}
bool GetTop(LinkStack S, int *e)
{
    if(S == NULL) return false;
    *e = S -> data;
    return true;
}

void StackTraverse(LinkStack S)
{
    LinkStack p = S;
    while(p)
    {
        if(p -> next == NULL)printf("%d\n", p -> data);
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
    DestroyStack(&S);
    return 0;
}
