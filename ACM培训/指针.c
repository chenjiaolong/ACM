//Shift+Ctrl+c:��ѡ�в���ע�ͣ�
//Shift+Ctrl+x:��ѡ�в���ȡ��ע�ͣ�

//���������5��ʹ��ָ��
/*#include<stdio.h>
void test(int *val)
{
    *val-=5;
}
int main()
{
    int a,*p;
    scanf("%d",&a);
    p=&a;
    test(p);
    printf("%d\n",a);
    return 0;
}*/

//����������ʹ��ָ��
/*#include<stdio.h>
void swap(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    swap(&a,&b);
    printf("%d %d\n",a,b);
    return 0;
}*/

//��ͬ�ֵ�������ַ�ʽ������*��&֮��Ĺ�ϵ
/*#include<stdio.h>
int main()
{
    int a[100],i,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; i++)
            scanf("%d",a+i);
        for(i=0; i<n; i++)
            printf("%d ",a[i]);
        printf("\n");
        for(i=0; i<n; i++)
            printf("%d ",*(a+i));
        printf("\n");
        for(i=0; i<n; i++)
            printf("%d ",i[a]);
        printf("\n");
    }
    return 0;
}*/

//�ж������ַ����ĳ���,�˽�strlen������ԭ��
/*#include<stdio.h>
int Strlen(char *str)
{
    int len=0;
    char *p=str;
    while(*p!='\0')
    {
        len++;
        p++;
    }
    return len;
}
int main()
{
    char str[1001];
    while(scanf("%s",str)!=EOF)
    {
        printf("%d\n",Strlen(str));
    }
    return 0;
}*/

//����ָ�������ά����Ԫ��
/*#include<stdio.h>
int main()
{
    int a[5][5],i,j;
    for(i=0; i<5; i++)
        for(j=0; j<5; j++)
            a[i][j]=i*5+j;
    for(i=0; i<5; i++)
        for(j=0; j<5; j++)
            printf("%d%c",*(*(a+i)+j),j==4?'\n':' ');
    return 0;
}*/

//�ַ�����ָ��
/*#include<stdio.h>
#include<stdlib.h>//malloc������ʹ��
int main()
{
    int *p;
    char *str;
    p=(int *)malloc(sizeof(int));
    scanf("%d",p);
    printf("%d\n",*p);
    str=(char *)malloc(sizeof(char)*100);//�ȼ���char str[100]
    str=(char *)malloc(sizeof(char)*100);
    scanf("%s",str);
    printf("%s\n",str);
    return 0;
}*/

//�ṹ���ָ��
/*#include<stdio.h>
#include<stdlib.h>
struct student
{
    char name[20];
    int age;
    char sex[5];
};
int main()
{
    struct student *student;
    student=(struct student *)malloc(sizeof(struct student));
    scanf("%s%d%s",&student->name,&student->age,&student->sex);
    printf("%s %d %s\n",student->name,student->age,student->sex);
    return 0;
}*/

//����ָ��ƴ�������ַ���
#include<stdio.h>
#include<stdlib.h>
void Strcat_str(char *str1,char *str2)
{
    char *p1=str1,*p2=str2;
    while(*p1!='\0')
    {
        p1++;
    }
    while(*p2!='\0')
    {
        *p1=*p2;
        p1++;
        p2++;
    }
    *p1='\0';
}
int main()
{
    char *str1,*str2;
    str1=(char *)malloc(sizeof(char)*1010);
    str2=(char *)malloc(sizeof(char)*501);
    while(scanf("%s%s",str1,str2)!=EOF)
    {
        Strcat_str(str1,str2);
        printf("%s\n",str1);
    }
    return 0;
}
