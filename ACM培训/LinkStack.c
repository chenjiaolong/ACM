#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct SNode
{
    int data;
    struct SNode *next;
} SNode,*LinkStack;
LinkStack InitStack()
{
    LinkStack top = (LinkStack )malloc(sizeof(SNode));
    //top = (SNode *)malloc(sizeof(SNode));
    top -> next = NULL;
    return top;
}
void DestroyStack(LinkStack top)
{
    SNode *p;
    while(top != NULL)
    {
        p = top -> next;
        free(top);
        top = p;
    }
}
void ClearStack(LinkStack top)
{
    SNode *p,*q;
    p = top -> next;
    while(p != NULL)
    {
        q = p -> next;
        free(p);
        p = q;
    }
    top -> next = NULL;
}
bool StackEmpty(LinkStack top)
{
    return top -> next == NULL;
}
bool GetTop(LinkStack top, int *e)
{
    if(top -> next == NULL) return false;
    *e = top -> next -> data;
    return true;
}
bool Push(LinkStack top,int val)
{
    SNode *tNew = (SNode *)malloc(sizeof(SNode));
    if(!tNew) return false;
    tNew -> data = val;
    tNew -> next = top -> next;
    top -> next = tNew;
    return true;
}
bool Pop(LinkStack top, int *e)
{
    if(top -> next == NULL) return false;
    SNode *p;
    p = top -> next;
    * e = p -> data;
    top -> next = p -> next;// top -> next = top -> next -> next;
    free(p);
    return true;
}
void StackTraverse(LinkStack top)
{
    top = top -> next;
    while(top != NULL)
    {
        if(top -> next == NULL)
            printf("%d\n",top -> data);
        else
            printf("%d ",top -> data);
        top = top -> next;
    }
}
int StackLength(LinkStack top)
{
    int length=0;
    top = top -> next;
    while(top != NULL)
    {
        length++;
        top = top -> next;
    }
    return length;
}
int main()
{
    int temp;
    int rt;
    LinkStack top=InitStack();
    if(StackEmpty(top)) puts("The Stack is empty!!!");
    else puts("The Stack is not empty!!!");

    Push(top,1);
    Push(top,2);
    Push(top,3);
    Push(top,4);
    StackTraverse(top);

    int len = StackLength(top);
    printf("The Stack's length is %d\n", len);

    Pop(top, &temp);
    printf("%d is popped\n", temp);

    Pop(top, &temp);
    printf("%d is popped\n", temp);

    while(!StackEmpty(top))
    {
        GetTop(top, &temp);
        printf("%d ", temp);
        Pop(top, &temp);
    }
    puts("");
    ClearStack(top);

    rt = GetTop(top, &temp);
    if(rt) printf("%d is the top elem.\n", temp);
    else puts("The Stack is nothing.");

    StackTraverse(top);
    DestroyStack(top);

    return 0;
}
