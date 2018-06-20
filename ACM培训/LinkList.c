#include<stdio.h>
#include<stdlib.h>//#include<malloc.h>

typedef struct node
{
    int data;
    struct node *next;
} LNode,*LinkList;
//LinkList L == struct node *L
//struct node *L == LNode *L

LinkList InitList()
{
    LinkList pHead;
    //struct node *pHead;
    pHead = (LinkList )malloc(sizeof(LNode));//pHead = (LNode *)malloc(sizeof(LNode));
    pHead -> next = NULL;
    return pHead;
}
void DestroyList(LinkList pHead)
{
    LinkList p = pHead,q;//LNode *p = pHead;
    while(p != NULL)
    {
        q = p -> next;
        free(p);
        p = q;
    }
}
void ClearList(LinkList pHead)
{
    LinkList p = pHead -> next,q;
    while(p != NULL)
    {
        q = p -> next;
        free(p);
        p = q;
    }
    pHead -> next = NULL;
}
void CreateLinkListHead(LinkList pHead,int n)
{
    int i;
    for(i = 0; i < n; i ++)
    {
        LinkList p = (LinkList )malloc(sizeof(LNode));
        scanf("%d",&p -> data);
        p -> next = pHead -> next;
        pHead -> next = p;
    }
}
void CreateLinkListTail(LinkList pHead,int n)
{
    int i;
    LinkList p = pHead;
    for(i = 0; i < n; i ++)
    {
        LinkList q = (LinkList )malloc(sizeof(LNode));
        scanf("%d",&q -> data);
        q -> next = p -> next;
        p -> next = q;
        p = q;
    }
}
int ListLength(LinkList pHead)
{
    int length=0;
    LinkList p = pHead -> next;
    while(p != NULL)
    {
        p = p -> next;
        length++;
    }
    return length;
}
int IsEmpty(LinkList pHead)
{
    if(pHead -> next == NULL)
        return 1;
    return 0;
}
int GetElem(LinkList pHead,int i,int *e)
{
    LinkList p = pHead -> next;
    int cnt = 0;
    if(i < 1)
        return 0;
    while(p != NULL)
    {
        if(++cnt == i)
        {
            *e = p -> data;
            return 1;
        }
        p = p -> next;
    }
    return 0;

}
int LocateElem(LinkList pHead,int e)
{
    LinkList p = pHead -> next;
    int cnt = 0;
    while(p != NULL)
    {
        cnt++;
        if(p->data == e)
            return cnt;
        p = p -> next;
    }
    return -1;
}
int ModifyElem(LinkList pHead,int i,int e)
{
    LinkList p = pHead -> next;
    int cnt = 0;
    if(i < 1)
        return 0;
    while(p != NULL)
    {
        if(++cnt == i)
        {
            p -> data = e;
            return 1;
        }
        p = p -> next;
    }
    return 0;
}
void LinkListOutput(LinkList pHead)
{
    LinkList p=pHead -> next;
    while(p != NULL)
    {
        if(p -> next == NULL)
            printf("%d\n",p -> data);
        else
            printf("%d ",p -> data);
        p = p -> next;
    }
}
int ListInsert(LinkList pHead,int i,int e)
{
    LinkList p = pHead,pNew;
    int cnt = 0;
    if(i < 1)
        return 0;
    while(p -> next != NULL)
    {
        if(++cnt == i)
        {
            pNew = (LinkList )malloc(sizeof(LNode));
            pNew -> data = e;
            pNew -> next = p -> next;
            p -> next = pNew;
            return 1;
        }
        p=p -> next;
    }
    pNew = (LinkList )malloc(sizeof(LNode));//如果插入位置超过已知长度一个或一个以上以后,直接放在末尾
    pNew -> data = e;
    pNew -> next = p -> next;
    p -> next = pNew;
    return 1;
}
int ListDelete(LinkList pHead,int i)
{
    LinkList p = pHead,q;
    int cnt = 0;
    if(i<1) return 0;
    while(p -> next != NULL)
    {
        if(++cnt == i)
        {
            q = p -> next;
            p -> next = p -> next -> next; // p -> next = q -> next;
            free(q);
            return 1;
        }
        p = p -> next;
    }
    return 0;
}
void BubbleSort(LinkList pHead,int n)
{
    if(pHead -> next == NULL || pHead -> next -> next == NULL)
        return ;
    int i, j;
    for(i = 0 ; i < n - 1; i ++)
    {
        LinkList pre = pHead, p = pHead -> next;
        for(j = 0; j < n - 1 - i; j ++)
        {
            LinkList q = p -> next;
            if(p -> data > q  -> data)
            {
                p -> next = q -> next;
                pre -> next = q;
                q -> next = p;
                p = q;
            }
            pre = pre -> next;
            p = p -> next;
        }
    }
}
void InsertSort(LinkList pHead)
{
    if(pHead -> next == NULL || pHead -> next -> next == NULL)
        return ;
    LinkList p,q,pre;
    p = pHead -> next -> next;
    pHead -> next -> next = NULL;
    while(p)
    {
        pre = pHead;
        q = p;
        p = p -> next;
        while(pre -> next && pre -> next -> data < q -> data)
            pre = pre -> next;
        q -> next = pre -> next;
        pre -> next = q;
    }
}
int main()
{
    LinkList pHead = NULL;//LNode *pHead = NULL;
    pHead = InitList();
    ListInsert(pHead,1,1);
    ListInsert(pHead,3,2);
    LinkListOutput(pHead);
    ListInsert(pHead,3,3);
    ListInsert(pHead,4,4);
    ListInsert(pHead,2,8);
    LinkListOutput(pHead);
    printf("Length %d\n",ListLength(pHead));
    ListDelete(pHead,2);
    LinkListOutput(pHead);
    ListDelete(pHead,1);
    LinkListOutput(pHead);
    ListDelete(pHead,4);
    LinkListOutput(pHead);
    ClearList(pHead);
    LinkListOutput(pHead);
    CreateLinkListHead(pHead,5);
    LinkListOutput(pHead);
    BubbleSort(pHead,5);
    LinkListOutput(pHead);
    ClearList(pHead);
    CreateLinkListTail(pHead,5);
    LinkListOutput(pHead);
    InsertSort(pHead);
    LinkListOutput(pHead);
    DestroyList(pHead);
    return 0;
}
