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
    printf("|*****学生成绩管理系统*****|\n");
    printf("|--------------------------|\n");
    printf("|         主菜单选项       |\n");
    printf("|--------------------------|\n");
    printf("|     1---录入学生信息     |\n");
    printf("|     2---查询学生信息     |\n");
    printf("|     3---修改学生信息     |\n");
    printf("|     4---删除学生信息     |\n");
    printf("|     5---显示学生信息     |\n");
    printf("|     0---退出系统         |\n");
    printf("|  请选择相应的选项（0-5） |\n");
    printf("|**************************|\n");
    do
    {
        fflush(stdin);
        scanf("%c%*c",&option);
        if(option<'0'||option>'5')
        {
            printf("对不起，你输入的数据有误！请重新输入你的选择（0-5）:\n");
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
        printf("请输入需要录入的同学的学号：\n");
        gets(p->No);
        for(j=0; j<strlen(p->No); j++)
            if(p->No[j]<'0'||p->No[j]>'9')
            {
                printf("对不起，你输入的学号有误！\n");
                Input(p);
            }
        printf("请输入该同学的姓名：\n");
        gets(p->name);
        for(k=0; k<MaxSub; k++)
        {
            printf("请输入该同学第%d门成绩：\n",k+1);
            scanf("%f",&p->score[k]);
            if(p->score[k]<0||p->score[k]>100)
            {
                k--;
                printf("你输入的数据有误，请重新输入：\n");
            }
        }
        length++;
        do
        {
            printf("|************************|\n");
            printf("|   1---返回主菜单       |\n");
            printf("|   2---继续             |\n");
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
        printf("成绩管理系统已爆满！\n");
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
        printf("请输入你需要查询学生的学号：\n");
        gets(No);
        p=stu;
        for(i=0; i<length; i++,p++)
            if(strcmp(p->No,No)==0)
                break;
        if(i==length)
            printf("对不起，没有该生的成绩信息！\n");
        else
        {
            printf("|******************************************************************|\n");
            printf("|       学号      |   姓名  | 第1门成绩| 第2门成绩| 第3门成绩| 平均成绩|\n");
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
            printf("|   1---返回主菜单       |\n");
            printf("|   2---继续             |\n");
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
        printf("请输入需要修改同学的学号：\n");
        gets(No);
        p=stu;
        for(i=0; i<length; i++,p++)
            if(strcmp(p->No,No)==0)
                break;
        if(i==length)
            printf("对不起，没有该生的成绩信息！\n");

        else
        {
            for(j=0; j<MaxSub; j++)
            {
                printf("请输入该同学第%d门成绩：\n",j+1);
                scanf("%f",&p->score[j]);
                if(p->score[j]<0||p->score[j]>100)
                {
                    j--;
                    printf("你输入的数据有误，请重新输入：\n");
                }
            }
            printf("个人成绩已成功修改！！\n");
        }
        do
        {
            printf("|************************|\n");
            printf("|   1---返回主菜单       |\n");
            printf("|   2---继续             |\n");
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
        printf("请输入需要删除同学的学号：\n");
        gets(No);
        p=stu;
        for(i=0; i<length; i++,p++)
            if(strcmp(p->No,No)==0)
                break;
        if(i==length)
            printf("对不起，没有该生的成绩信息！\n");
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
            printf("已成功删除个人数据！\n");
            length--;
        }
        do
        {
            printf("|************************|\n");
            printf("|   1---返回主菜单       |\n");
            printf("|   2---继续             |\n");
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
    printf("|       学号      |   姓名  | 第1门成绩| 第2门成绩| 第3门成绩| 平均成绩|\n");
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
    printf("欢迎使用！\n");
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
            printf("谢谢使用！\n");
            exit(0);
            break;
        }
    }
    return 0;
}
