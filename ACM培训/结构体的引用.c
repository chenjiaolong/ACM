#include<stdio.h>
struct date
{
    int year;
    int month;
    int day;
}t1,t2,t3;
void main()
{
    scanf("%d%d%d",&t1.year,&t2.month,&t3.day);
    printf("%d %d %d",t1.year,t2.month,t3.day);
}
/*#include<stdio.h>
struct node
{
    char name[100];
    char sex[10];
    int age;
    int score;
}per[1000];
void main()
{
    int i;
    for(i=0;i<3;i++)
        scanf("%s%s%d%d",per[i].name,per[i].sex,&per[i].age,&per[i].score);
    printf("sssss\n");
    for(i=0;i<3;i++)
        printf("%s,%s,%d,%d\n",per[i].name,per[i].sex,per[i].age,per[i].score);
}*/

