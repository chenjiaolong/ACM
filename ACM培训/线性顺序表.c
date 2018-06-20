//@copyright by prajna979
#include<stdio.h>
#include<stdlib.h>

#define LIST_INIT_SIZE 1000
#define LISTINCREMENT 10
#define TRUE 1
#define FLASE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int ElemType; //polymorphic date type
typedef int Status;

int compare(ElemType a,ElemType b)
{
    if(a == b)
        return TRUE;
    return FLASE;
}
int vist()
{
    return OK;
}
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} sqlist;

Status InitList(sqlist *L)
{
    L -> elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));

    if(!L -> elem)exit(OVERFLOW);
    L -> length = 0;
    L -> listsize = LISTINCREMENT;
    return OK;
}//build a list
Status DestroyList(sqlist *L)
{
    if(!L -> elem)return ERROR;
    int i;
    for(i = 0; i < L -> length; i ++)
        free(L -> elem + i);
    L -> length = -1;
    L -> elem = NULL;
    return OK;
}//destroy the list
Status ClearList(sqlist *L)
{
    if(!L -> elem)
        return ERROR;
    L -> length = 0;
    return OK;
}//clear the list  !!pay attention to the difference between clearing list and destroying list
Status ListEmpty(sqlist L)
{
    if(!L.elem)
        return INFEASIBLE;
    if(L.length)
        return TRUE;
    return FLASE;
}//judge whether the list is empty
Status ListLength(sqlist L)
{
    if(!L.elem)
        return ERROR;
    return L.length;
}//get the length of the list
Status GetElem(sqlist L,int i,ElemType *e)
{
    if(!L.elem || i > ListLength(L))
        return ERROR;
    *e = L.elem[i - 1];
    return OK;

}//get the elem in the i place of the list

Status LocateElem(sqlist L,ElemType e,int compare())
{
    if(!L.elem)
        return ERROR;
    int i;
    for(i = 0; i <= ListLength(L) - 1; i ++)
        if(compare(e,*(L.elem + i)))
            return i + 1;
    return FLASE;
}//find the place of first number is the same as e in the list
Status PriorElem(sqlist L,ElemType cur_e,ElemType *pre_e)
{
    if(!L.elem)
        return ERROR;
    int i;
    for(i = 0; i < ListLength(L) - 1; i ++)
        if(*(L.elem + i) == cur_e)
        {
            if(i == 0)
                return INFEASIBLE;
            else
            {
                pre_e = L.elem + i - 1;
                return OK;
            }
        }
    return INFEASIBLE;

}//find the prior number of the number is the same as cur_e
Status NextElem(sqlist L,ElemType cur_e,ElemType *next_e)
{
    if(!L.elem)return ERROR;
    int i;
    for(i = 0; i < ListLength(L) - 1; i ++)
        if(*(L.elem + i) == cur_e)
        {
            if(i == L.length - 1)
                return INFEASIBLE;
            else
            {
                next_e = L.elem + i + 1;
                return OK;
            }
        }
    return INFEASIBLE;
}//find the next number of the number is the same as cur_e
Status ListInsert(sqlist *L,int i,ElemType e)
{
    ElemType *newbase;
    ElemType *q,*p;
    if(i < 1 || i > L -> length + 1)
        return ERROR;
    if(L -> length >= L -> listsize)
    {
        newbase = (ElemType *)realloc(L -> elem,(L -> listsize + LISTINCREMENT) * sizeof(ElemType));
        if(!newbase)exit(OVERFLOW);
        L -> elem = newbase;
        L -> listsize += LISTINCREMENT;
    }
    q = &(L -> elem[i - 1]);
    for(p = &(L -> elem[L -> length - 1]); p >= q; p -- )
        *(p + 1) = * p;
    *q = e;
    L -> length ++;
    return OK;
}//Insert e into the i place of the list and the elements after it will be pushed to it's next place
Status ListDelete(sqlist *L,int i,ElemType *e)
{
    ElemType *q,*p;
    if(i < 1 || i > L -> length)
        return ERROR;
    p = &(L -> elem[i - 1]);
    *e = *p;
    for(q = L -> elem + L -> length - 1, ++ p; p <= q; p ++)
        *(p - 1) = *p;
    L -> length --;
    return OK;
}//delete the element in the i place and the elements after it will be pushed to it's front place
Status ListTraverse(sqlist *L,int visit())
{
    if(!L -> elem)
        return ERROR;
    ElemType *i;
    for(i = L -> elem; i <= L -> elem + L -> length - 1; i ++)
        if(!vist())
        return  INFEASIBLE;
    return OK;
}//do the function of visit() to all element

Status OutputList(sqlist L)
{
    if(!L.elem)
        return ERROR;
    int i;
    for(i = 0; i < L.length; i ++)
        printf("%d ",L.elem[i]);
    printf("\n");
    return OK;
}//output the list
Status ListUnion(sqlist *a,sqlist b)
{
    int La_len = a -> length,Lb_len = b.length;
    if(!La_len || !Lb_len)
        return ERROR;
    int i;
    ElemType e;
    for(i = 1; i <= Lb_len; i ++)
    {
        GetElem(b,i,&e);
        if(!LocateElem(*a,e,compare))
            ListInsert(a,a -> length + 1,e);
    }
    return  OK;
}//insert all the elements that are not in the list a in the list b into list a
Status MergeList(sqlist La,sqlist Lb,sqlist *Lc)
{
    int i = 1,j = 1,k = 0;
    int La_len = ListLength(La),Lb_len = ListLength(Lb);
    ElemType ai,bj;

    while(i <= La_len && j <= Lb_len)
    {
        GetElem(La,i,&ai);
        GetElem(Lb,j,&bj);
        if(ai <= bj)
        {
            ListInsert(Lc,++k,ai);
            i ++;
        }
        else
        {
            ListInsert(Lc,++k,bj);
            j ++;
        }
    }
    while(i <= La_len)
    {
        GetElem(La,i ++,&ai);
        ListInsert(Lc,++ k,ai);
    }
    while(j <= Lb_len)
    {
        GetElem(Lb,j ++,&bj);
        ListInsert(Lc,++ k,bj);
    }

}//list a and b are not descending order and union a and b into c ;c is not descending order too~
int main()
{
    //the statement is used to test the functions above
    sqlist L,M,H;

    InitList(&L);
    ListInsert(&L,1,1);
    ListInsert(&L,1,2);
    OutputList(L);
    ListInsert(&L,3,5);
    OutputList(L);
    int len = ListLength(L);
    printf("%d\n",len);

    ElemType *a = (ElemType *)malloc(sizeof(ElemType));

    printf("%d\n",ListEmpty(L));

    ListDelete(&L,1,a);
    OutputList(L);


    InitList(&M);
    ListInsert(&M,1,10);
    ListInsert(&M,2,1);
    ListInsert(&M,2,1);
    ListInsert(&M,4,8);
    OutputList(M);
    ListUnion(&L,M);
    OutputList(L);

    ClearList(&L);
    ClearList(&M);
    ListInsert(&L,1,1);
    ListInsert(&L,2,3);
    ListInsert(&L,3,3);
    ListInsert(&L,4,5);

    ListInsert(&M,1,2);
    ListInsert(&M,2,3);
    ListInsert(&M,3,4);
    ListInsert(&M,4,8);
    OutputList(L);
    OutputList(M);

    InitList(&H);
    MergeList(L,M,&H);
    OutputList(H);

    return 0;
}
