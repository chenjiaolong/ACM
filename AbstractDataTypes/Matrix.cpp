#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 12500

#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define UNDERFLOW -1

typedef int ElemType;
typedef int Status;

typedef struct
{
    int i,j;
    ElemType e;
} Triple;
typedef struct
{
    Triple data[MAXSIZE+1];
    int mu,nu,tu;
} TSMatrix;
Status CreatSMatrix(TSMatrix  &M)
//�����µ�ϡ�����
{
    printf("����ϡ�跽�������,�����Լ�����Ԫ������");
    scanf("%d%d%d",&M.mu,&M.nu,&M.tu);
    while(M.tu>M.mu * M.nu)
    {
        printf("����ϡ�跽�������,�����Լ�����Ԫ������");
        scanf("%d%d%d",&M.mu,&M.nu,&M.tu);

    }
    int k;
    for( k=1; k<=M.tu; k++)
    {
        printf("�����%d����0Ԫ�ص�����,�����Լ�ֵ:",k);
        scanf("%d%d%d",&M.data[k].i,&M.data[k].j,&M.data[k].e);
        if(M.data[k].i>M.mu|| M.data[k].j>M.nu )
        {

            printf("�������!\n");
            system("PAUSE");
            exit(1);
        }
        if(M.data[k].e==0)
        {
            printf("����ı����Ƿ���Ԫ��!\n");
            scanf("%d%d%d",&M.data[k].i,&M.data[k].j,&M.data[k].e);
        }

    }

    return OK;
}
Status TransposeSMatrix(TSMatrix M,TSMatrix &T)
{
    int col;
    T.mu=M.nu,T.nu=M.mu,T.tu=M.tu;
    if(T.tu)
    {
        int q=1,p;
        for(col=1; col<=M.nu; ++col)
            for(p=1; p<=M.tu; ++p)
                if(M.data[p].j==col)
                {
                    T.data[q].i=M.data[p].j;
                    T.data[q].j=M.data[p].i;
                    T.data[q].e=M.data[p].e;
                    ++q;
                }
    }
    return OK;
}
Status FastTransposeMatrix(TSMatrix M,TSMatrix &T)
{
    int t,col,num[MAXSIZE],cpot[MAXSIZE];
    T.mu=M.nu,T.nu=M.mu,T.tu=M.tu;
    if(T.tu)
    {
        for(col=1; col<M.nu; ++col)
            num[col]=0;
        for(t=1; t<=M.tu; ++t)
            ++num[M.data[t].j];
        cpot[1]=1;
        int q=1,p;
        for(col=2; col<=M.nu; ++col)
            cpot[col]=cpot[col-1]+num[col-1];
        for(p=1; p<=M.tu; ++p)
        {
            col=M.data[p].j;
            q=cpot[col];
            T.data[q].i=M.data[p].j;
            T.data[q].j=M.data[p].i;
            T.data[q].e=M.data[p].e;
            ++cpot[col];
        }
    }
    return OK;
}
Status PrintSMatrix(TSMatrix X)
{
    if(!X.tu)
    {
        printf("����Ϊ��!\n");
        return 0;
    }
    int i,j,k=1;
    for(i=1; i<=X.mu; i++)
    {
        for(j=1; j<=X.nu; j++)
        {
            if(i==X.data[k].i && j==X.data[k].j)
            {
                printf("%2d ",X.data[k].e);
                k++;
            }
            else printf(" 0 ");

        }
        printf("\n");
    }
    return OK;
}
int main()
{
    TSMatrix M_matrix,T_matrix;
    int choice;
    do
    {
        printf("\n���������ѡ��\n");
        printf("1  ����ϡ�����\n");
        printf("2  �þ����תֵ\n");
        printf("0    �˳�\n");

        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\n");
            CreatSMatrix(M_matrix);
            printf("\n");
            PrintSMatrix(M_matrix);
            break;
        case 2:
            printf("\n");
            TransposeSMatrix(M_matrix,T_matrix);
            //FastTransposeMatrix(M_matrix,T_matrix);
            printf("\n");
            PrintSMatrix(T_matrix);
            break;
        default:
            printf("\n\n��������ź���Ч!\n\n");
            break;

        }
    }
    while(choice!=0);
}

