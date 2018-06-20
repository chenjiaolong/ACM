#include <stdio.h>
union Categ
{
    int clas;
    char position[10];
};
struct
{
    int num;
    char name[10];
    char sex;
    char job;
    union Categ category;
} person[2];
int main()
{
    int i;
    for(i=0; i<2; i++)
    {
        scanf("%d %s%*c%c%*c%c",&person[i].num, &person[i].name, &person[i].sex, &person[i].job);
        if(person[i].job == 's') scanf("%d",&person[i].category.clas);
        else if(person[i].job == 't') scanf("%s",person[i].category.position);
        else printf("Input error!");
    }
    printf("\n");
    for(i=0; i<2; i++)
    {
        if (person[i].job == 's')
            printf("%-6d%-10s%-4c%-4c%-10d\n",person[i].num,person[i].name,person[i].sex,person[i].job,person[i].category.clas);
        else
            printf("%-6d%-10s%-4c%-4c%-10s\n",person[i].num,person[i].name,person[i].sex, person[i].job,person[i].category.position);
    }
    return 0;
}

