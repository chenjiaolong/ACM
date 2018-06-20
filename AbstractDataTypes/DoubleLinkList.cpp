#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

using namespace std;

typedef struct node
{
    int data;
    struct node *prior, *next;
} DuLNode, *DuLinkList;

void InitDuLinkList(DuLinkList *pHead)
{
    (*pHead) = (DuLinkList )malloc(sizeof(DuLNode));
    if(!(*pHead)) return ;
    (*pHead) -> next = (*pHead) -> prior = (*pHead);
}
void CreateDuLinkList(DuLinkList *pHead, int n)
{
    DuLinkList p = *pHead;
    for(int i = 0; i < n; i ++)
    {
        DuLinkList s = (DuLinkList )malloc(sizeof(DuLNode));
        scanf("%d", &s -> data);
        s -> prior = p;
        p -> next = s;
        p = s;
    }
    p -> next = *pHead;
    (*pHead) -> prior = p;
}
void DestroyDuLinkList(DuLinkList *pHead)
{
    DuLinkList p = *pHead, q;
    while(p -> next != *pHead)
    {
        q = p -> next;
        p -> next = q -> next;
        p -> prior = *pHead;
        (*pHead) -> next = p;
        free(q);
    }
    free(*pHead);
}
void ClearDuLinkList(DuLinkList *pHead)
{
    DuLinkList p = *pHead, q;
    while(p -> next != *pHead)
    {
        q = p -> next;
        p -> next = q -> next;
        p -> prior = *pHead;
        (*pHead) -> next = p;
        free(q);
    }
    (*pHead) -> next = (*pHead) -> prior = (*pHead);
}
bool DuLinkListInsert(DuLinkList *pHead, int index, int e)
{
    int cnt = 0;
    DuLinkList p = (*pHead) -> next;
    while(p != (*pHead))
    {
        if(++ cnt== index)
        {
            DuLinkList s = (DuLinkList )malloc(sizeof(DuLNode));
            s -> data = e;
            p -> prior -> next = s;
            s -> prior = p -> prior;
            s -> next = p;
            p -> prior = s;
            return true;
        }
        p = p -> next;
    }
    DuLinkList s = (DuLinkList )malloc(sizeof(DuLNode));
    s -> data = e;
    p -> prior -> next = s;
    s -> prior = p -> prior;
    s -> next = p;
    p -> prior = s;
    return true;
}
bool DuLinkListDelete(DuLinkList *pHead, int index, int *e)
{
    if(index < 0 || (*pHead) -> next == (*pHead)) return false;
    DuLinkList p = (*pHead) -> next;
    int cnt = 0;
    while(p != (*pHead))
    {
        if(++ cnt == index)
        {
            *e = p -> data;
            p -> prior -> next = p -> next;
            p -> next -> prior = p -> prior;
            free(p);
            return true;
        }
        p = p -> next;
    }
    return false;
}
void DuLinkListOutput(DuLinkList pHead)
{
    if(pHead -> next == pHead) return ;
    DuLinkList p = pHead -> next;
    while(p != pHead)
    {
        printf("%d%c", p -> data, p -> next == pHead ? '\n' : ' ');
        p = p -> next;
    }
    p = pHead -> prior;
    while(p != pHead)
    {
        printf("%d%c", p -> data, p -> prior == pHead ? '\n' : ' ');
        p = p -> prior;
    }
}
int main()
{
    DuLinkList pHead;
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int e;
        InitDuLinkList(&pHead);
        // CreateDuLinkList(&pHead, n);
        DuLinkListInsert(&pHead, 1, 1);
        DuLinkListInsert(&pHead, 2, 2);
        DuLinkListInsert(&pHead, 4, 3);
        DuLinkListOutput(pHead);
        if(DuLinkListDelete(&pHead, 1, &e))
        printf("%d\n", e);
        if(DuLinkListDelete(&pHead, 2, &e))
        printf("%d\n", e);
        if(DuLinkListDelete(&pHead, 4, &e))
        printf("%d\n", e);
        DuLinkListOutput(pHead);
        ClearDuLinkList(&pHead);
    }
    DestroyDuLinkList(&pHead);
    return 0;
}
