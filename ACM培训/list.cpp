#include <stdio.h>
#include <stdlib.h>
#define M 20
typedef int ElemType;
typedef struct
{
    ElemType data[M];
    int length;
} SeqList;
SeqList InitSeqlist()
{
    SeqList L;
    L.length=0;
    return L;
}
SeqList InsertSeqlist(SeqList L,int i,ElemType x)
{
    int j;
    if (L.length>=M)
    {
        printf("表满！\n");
        return L;
    }
    if (i<0||i>L.length)
    {
        printf("The position is mistake!\n");
        return L;
    }
    for (j=L.length-1; j>=i; j--)
        L.data[j+1]=L.data[j];
    L.data[i]=x;
    L.length++;
    return L;
}
SeqList input(SeqList L)
{
    ElemType x;
    int i=0;
    printf("请输入整数，当输入-1结束\n");
    scanf("%d",&x);
    while(x!=-1)
    {
        L.data[i++]=x;
        L.length++;
        scanf("%d",&x);
    }
    return L;
}
void output(SeqList L)
{
    int i;
    printf("L:");
    for (i=0; i<L.length; i++)
        printf("%d ",L.data[i]);
    printf("\n");
}
SeqList DeleteList(SeqList L,int i)
{
    int j;
    //判断位置i的合法性
    if (i<0||i>L.length-1)
    {
        printf("The position is mistake!\n");
        return L;
    }
    for (j=i+1; j<L.length; j++)
        L.data[j-1]=L.data[j];
    L.length--;
    return L;
}
int LocateSeq(SeqList L,ElemType x)
{
    int i;
    for (i=0; i<L.length; i++)
        if (L.data[i]==x)
            return i;
    return -1;
}
//顺序表合并
SeqList MergeList(SeqList La, SeqList Lb)
{
    int i=0,j=0,k=0;
    SeqList Lc=InitSeqlist();
    while(i<La.length&&j<Lb.length)
    {
        if (La.data[i]<=Lb.data[j])
        {
            Lc=InsertSeqlist(Lc,k,La.data[i]);
            i++;
            k++;
        }
        else
        {
            Lc=InsertSeqlist(Lc,k,Lb.data[j]);
            j++;
            k++;
        }
    }
    while (i<La.length)
    {
        Lc=InsertSeqlist(Lc,k,La.data[i]);
        i++;
        k++;
    }
    while (j<Lb.length)
    {
        Lc=InsertSeqlist(Lc,k,Lb.data[j]);
        j++;
        k++;
    }
    return Lc;
}
//顺序表选择菜单
int menu()
{
    int x;
    printf("------------顺序表操作-----------\n");
    printf("------1.创建顺序表   2.输出-----\n");
    printf("------3.插入         4.删除-----\n");
    printf("------5.查找         6.合并-----\n");
    printf("------7.折半查找-----------------\n");
    printf("------8.有序表的插入------------\n");
    printf("------0.退出----------------------\n");
    do
    {
        printf("请输入选项：");
        scanf("%d",&x);
    }
    while(x<0||x>8);
    return x;
}
int BinarySearch(SeqList L,int n,ElemType k)
{
    int low,high,mid;
    low=0;
    high=n-1;
    while (low<=high)
    {
        mid=(low+high)/2;
        if(k==L.data[mid])
            return mid;
        else if (k>L.data[mid])
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
SeqList insert(SeqList L,ElemType x)
{
    int i;
    for (i=L.length-1; i>=0&&x<L.data[i]; i--)
    {
        L.data[i+1]=L.data[i];
    }
    L.data[i+1]=x;
    L.length++;
    return L;
}

int main()
{
    SeqList L;
    int i,k;
    ElemType x;
    while (1)
    {
        switch(menu())
        {
        case 0:
            exit(0);
        case 1:
            L = InitSeqlist();
            L = input(L);
            break;
        case 2:
            output(L);
            break;
        case 3:
            printf("输入插入的位置：");
            scanf("%d",&i);
            printf("输入插入的元素：");
            scanf("%d",&x);
            L = InsertSeqlist(L,i,x);
            break;
        case 4:
            printf("请输入要删除元素的位置：");
            scanf("%d",&i);
            L = DeleteList(L,i);
            break;
        case 5:
            printf("请输入要查找的数据元素：");
            scanf("%d",&x);
            k = LocateSeq(L,x);
            if (k == -1)
                printf("查找失败!\n");
            else
                printf("查找成功!\n");
            break;
        case 6:
            SeqList La,Lb;
            La = InitSeqlist();
            Lb = InitSeqlist();
            SeqList Lc;
            La = input(La);
            Lb = input(Lb);
            Lc = MergeList(La,Lb);
            output(Lc);
            break;
        case 7:
            ElemType x;
            int i;
            printf("请输入查找的数据元素：");
            scanf("%d",&x);
            i=BinarySearch(L,L.length,x);
            if (i == -1)
                printf("查找失败\n");
            else
                printf("%d在表中第%d个位置！\n",x,i);
            break;
        case 8:
            //int x;
            printf("请输入待插入的元素：");
            scanf("%d",&x);
            L=insert(L,x);
            output(L);
            break;
        }
    }
    return 0;
}
