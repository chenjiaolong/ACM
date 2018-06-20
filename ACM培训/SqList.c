#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 1000

typedef struct
{
    int *elem;
    int Length;
} SqList;

bool InitList(SqList *L)//初始化线性表L
{
    L -> elem = (int *) malloc(sizeof(int) * MaxSize);
    if(!L -> elem)
        return false;
    L -> Length = 0;
    return true;
}
void DestroyList(SqList *L)//销毁线性表L
{
    free(L -> elem);
	L -> Length = 0;
}
void ClearList(SqList *L)//清空线性表L
{
    L -> Length = 0;
}
bool IsEmpty(SqList L)//判断线性表L是否为空
{
    return !L.Length;
    /*if(L.Length == 0) return 1;
    return 0;*/
}
int ListLength(SqList L)//求线性表L的长度
{
    return L.Length;
}
bool GetElem(SqList L, int i, int *e)//获取线性表L中的某个数据元素内容||取出线性表中的第i个元素（下标为i-1）
{
    if(i < 1 || i > L.Length) return false;
    *e = L.elem[i - 1];
    return true;
}
int LocateElem(SqList L,int e)//查找
{
    int i;
    for(i = 0; i < L.Length; i ++)
        if(L.elem[i] == e) return i;
    return -1;
}
bool ModifyElem(SqList *L,int i,int e)//修改第i个元素为e
{
    if(i < 1 || i > L -> Length) return false;
    L -> elem[i - 1] = e;
    return true;
}
bool ListInsert(SqList *L, int i, int e)//插入
{
    int j;
    if(i < 1 || L -> Length == MaxSize) return false;
    if(i > L -> Length) i = L -> Length + 1;
    for(j = L -> Length; j >= i; j --)
        L -> elem[j] = L -> elem[j - 1];
    L -> elem[i - 1] = e;
    L -> Length ++;
    return true;
}
bool ListDelete(SqList *L, int i, int *e)//删除
{
    int j;
    if(L -> Length == 0) return false;
    if(i < 1 || i > L -> Length) return false;
    *e = L -> elem[i - 1];
    for(j = i - 1; j <= L -> Length - 2; j++)
        L -> elem[j] = L -> elem[j + 1];
    L -> Length --;
    return true;
}
void ListOutput(SqList L)
{
    int i;
    for(i = 0; i < L.Length; i ++)
        printf("%d%c", L.elem[i], i == L.Length - 1 ? '\n' : ' ');
}
int main()
{
    int e;
    SqList list;
    InitList(&list);
    ListInsert(&list,1,1);
    ListInsert(&list,3,2);
    ListOutput(list);
    ListInsert(&list,3,3);
    ListInsert(&list,4,4);
    printf("Length %d\n",ListLength(list));
    ListInsert(&list,2,8);
    ListOutput(list);
    int index;
    printf("Please input your position: ");
    scanf("%d", &index);
    if(!ListDelete(&list,index, &e)) printf("%d is not a legal position!!!\n", index);
    else printf("%d is Deleted!!!\n", e);
    ListOutput(list);
    ModifyElem(&list,2,5);
    ListOutput(list);
    printf("Please input your search: ");
    scanf("%d",&e);
    if(LocateElem(list,e)==-1)
        printf("Sorry, There is not in here!!!\n");
    else
        printf("%d\n",LocateElem(list,e));
    ClearList(&list);
    ListOutput(list);
    DestroyList(&list);
    return 0;
}
