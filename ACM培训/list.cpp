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
        printf("������\n");
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
    printf("������������������-1����\n");
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
    //�ж�λ��i�ĺϷ���
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
//˳���ϲ�
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
//˳���ѡ��˵�
int menu()
{
    int x;
    printf("------------˳������-----------\n");
    printf("------1.����˳���   2.���-----\n");
    printf("------3.����         4.ɾ��-----\n");
    printf("------5.����         6.�ϲ�-----\n");
    printf("------7.�۰����-----------------\n");
    printf("------8.�����Ĳ���------------\n");
    printf("------0.�˳�----------------------\n");
    do
    {
        printf("������ѡ�");
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
            printf("��������λ�ã�");
            scanf("%d",&i);
            printf("��������Ԫ�أ�");
            scanf("%d",&x);
            L = InsertSeqlist(L,i,x);
            break;
        case 4:
            printf("������Ҫɾ��Ԫ�ص�λ�ã�");
            scanf("%d",&i);
            L = DeleteList(L,i);
            break;
        case 5:
            printf("������Ҫ���ҵ�����Ԫ�أ�");
            scanf("%d",&x);
            k = LocateSeq(L,x);
            if (k == -1)
                printf("����ʧ��!\n");
            else
                printf("���ҳɹ�!\n");
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
            printf("��������ҵ�����Ԫ�أ�");
            scanf("%d",&x);
            i=BinarySearch(L,L.length,x);
            if (i == -1)
                printf("����ʧ��\n");
            else
                printf("%d�ڱ��е�%d��λ�ã�\n",x,i);
            break;
        case 8:
            //int x;
            printf("������������Ԫ�أ�");
            scanf("%d",&x);
            L=insert(L,x);
            output(L);
            break;
        }
    }
    return 0;
}
