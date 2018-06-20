#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxSize 1000
#define MaxSub 3
int length=0;
typedef struct student
{
    char No[100];
    char name[20];
    float score[MaxSub];
} per;
char Menu()
{
    char option;
    printf("|*****ѧ���ɼ�����ϵͳ*****|\n");
    printf("|--------------------------|\n");
    printf("|         ���˵�ѡ��       |\n");
    printf("|--------------------------|\n");
    printf("|     1---¼��ѧ����Ϣ     |\n");
    printf("|     2---��ѯѧ����Ϣ     |\n");
    printf("|     3---�޸�ѧ����Ϣ     |\n");
    printf("|     4---ɾ��ѧ����Ϣ     |\n");
    printf("|     5---��ʾѧ����Ϣ     |\n");
    printf("|     0---�˳�ϵͳ         |\n");
    printf("|  ��ѡ����Ӧ��ѡ�0-5�� |\n");
    printf("|**************************|\n");
    do
    {
        fflush(stdin);
        scanf("%c%*c",&option);
        if(option<'0'||option>'5')
        {
            printf("�Բ�������������������������������ѡ��0-5��:\n");
            Menu();
        }
    }
    while(option<'0'||option>'5');
    return option;
}
void Input(per *p)
{
    int i=0,j=0,k=0;
    char option;
    fflush(stdin);
    for(i=length; i<MaxSize-1; i++,p++)
    {
        printf("��������Ҫ¼���ͬѧ��ѧ�ţ�\n");
        gets(p->No);
        for(j=0; j<strlen(p->No); j++)
            if(p->No[j]<'0'||p->No[j]>'9')
            {
                printf("�Բ����������ѧ������\n");
                Input(p);
            }
        printf("�������ͬѧ��������\n");
        gets(p->name);
        for(k=0; k<MaxSub; k++)
        {
            printf("�������ͬѧ��%d�ųɼ���\n",k+1);
            scanf("%f",&p->score[k]);
            if(p->score[k]<0||p->score[k]>100)
            {
                k--;
                printf("������������������������룺\n");
            }
        }
        length++;
        do
        {
            printf("|************************|\n");
            printf("|   1---�������˵�       |\n");
            printf("|   2---����             |\n");
            printf("|************************|\n");
            fflush(stdin);
            scanf("%c%*c",&option);
            if(option=='1')
                return;
        }
        while(option!='1'&&option!='2');
    }
    if(i==MaxSize-1)
    {
        printf("�ɼ�����ϵͳ�ѱ�����\n");
        return;
    }
}
void Locate(per *p,char *stu)
{
    char No[100],option;
    int i,j;
    float sum=0;
    while(1)
    {
        sum=0;
        fflush(stdin);
        printf("����������Ҫ��ѯѧ����ѧ�ţ�\n");
        gets(No);
        p=stu;
        for(i=0; i<length; i++,p++)
            if(strcmp(p->No,No)==0)
                break;
        if(i==length)
            printf("�Բ���û�и����ĳɼ���Ϣ��\n");
        else
        {
            printf("|******************************************************************|\n");
            printf("|       ѧ��      |   ����  | ��1�ųɼ�| ��2�ųɼ�| ��3�ųɼ�| ƽ���ɼ�|\n");
            printf("|-----------------|---------|----------|----------|----------|---------|\n");
            printf("|   %11s   |   %4s  |",p->No,p->name);
            for(j=0; j<MaxSub; j++)
            {
                printf("   %.2f |",p->score[j]);
                sum=sum+p->score[j];
            }
            printf("  %.2f |\n",sum/3);
            printf("|******************************************************************|\n");
        }
        do
        {
            printf("|************************|\n");
            printf("|   1---�������˵�       |\n");
            printf("|   2---����             |\n");
            printf("|************************|\n");
            fflush(stdin);
            scanf("%c%*c",&option);
            if(option=='1')
                return;
        }
        while(option!='1'&&option!='2');
    }
}
int Modify(per *p,char *stu)
{
    char No[100],option;
    int i,j;
    while(1)
    {
        fflush(stdin);
        printf("��������Ҫ�޸�ͬѧ��ѧ�ţ�\n");
        gets(No);
        p=stu;
        for(i=0; i<length; i++,p++)
            if(strcmp(p->No,No)==0)
                break;
        if(i==length)
            printf("�Բ���û�и����ĳɼ���Ϣ��\n");

        else
        {
            for(j=0; j<MaxSub; j++)
            {
                printf("�������ͬѧ��%d�ųɼ���\n",j+1);
                scanf("%f",&p->score[j]);
                if(p->score[j]<0||p->score[j]>100)
                {
                    j--;
                    printf("������������������������룺\n");
                }
            }
            printf("���˳ɼ��ѳɹ��޸ģ���\n");
        }
        do
        {
            printf("|************************|\n");
            printf("|   1---�������˵�       |\n");
            printf("|   2---����             |\n");
            printf("|************************|\n");
            fflush(stdin);
            scanf("%c%*c",&option);
            if(option=='1')
                return;
        }
        while(option!='1'&&option!='2');
    }
}
int Delete(per *p,char *stu)
{
    char No[100],option;
    per *p1=p;
    int i,j,k;
    while(1)
    {
        fflush(stdin);
        printf("��������Ҫɾ��ͬѧ��ѧ�ţ�\n");
        gets(No);
        p=stu;
        for(i=0; i<length; i++,p++)
            if(strcmp(p->No,No)==0)
                break;
        if(i==length)
            printf("�Բ���û�и����ĳɼ���Ϣ��\n");
        else
        {
            for(j=i; j<length-1; j++,p++)
            {
                p1=p+1;
                strcpy(p->No,p1->No);
                strcpy(p->name,p1->name);
                for(k=0; k<MaxSub; k++)
                    p->score[k]=p1->score[k];
            }
            printf("�ѳɹ�ɾ���������ݣ�\n");
            length--;
        }
        do
        {
            printf("|************************|\n");
            printf("|   1---�������˵�       |\n");
            printf("|   2---����             |\n");
            printf("|************************|\n");
            fflush(stdin);
            scanf("%c%*c",&option);
            if(option=='1')
                return;
        }
        while(option!='1'&&option!='2');
    }
}
void Display(per *p)
{
    int i,j;
    float sum=0;
    printf("|******************************************************************|\n");
    printf("|       ѧ��      |   ����  | ��1�ųɼ�| ��2�ųɼ�| ��3�ųɼ�| ƽ���ɼ�|\n");
    printf("|-----------------|---------|----------|----------|----------|---------|\n");
    for(i=0; i<length; i++,p++)
    {
        printf("|   %11s   |   %4s  |",p->No,p->name);
        sum=0;
        for(j=0; j<MaxSub; j++)
        {
            printf("   %.2f |",p->score[j]);
            sum=sum+p->score[j];
        }
        printf("  %.2f |\n",sum/3);
    }
    printf("|******************************************************************|\n");
}
int main()
{
    per stu[MaxSize];
    per *p=stu;
    printf("��ӭʹ�ã�\n");
    while(1)
    {
        switch(Menu())
        {
        case '1':
            Input(p);
            break;
        case '2':
            Locate(p,stu);
            break;
        case '3':
            Modify(p,stu);
            break;
        case '4':
            Delete(p,stu);
            break;
        case '5':
            Display(p);
            break;
        case '0':
            printf("ллʹ�ã�\n");
            exit(0);
            break;
        }
    }
    return 0;
}
