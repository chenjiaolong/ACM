#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TREE_SIZE 150

typedef char TElemType;

typedef TElemType SqBiTree[MAX_TREE_SIZE];
SqBiTree bt;
//TElemType bt[MAX_TREE_SIZE];

void PreOrderTraveral(int index)
{
    if(bt[index-1]=='#')
        return ;
    printf("%c",bt[index-1]);
    PreOrderTraveral(index*2);
    PreOrderTraveral(index*2+1);
}
void InOrderTraveral(int index)
{
    if(bt[index-1]=='#')
        return ;
    InOrderTraveral(index*2);
    printf("%c",bt[index-1]);
    InOrderTraveral(index*2+1);
}
void PostOrderTraveral(int index)
{
    if(bt[index-1]=='#')
        return ;
    PostOrderTraveral(index*2);
    PostOrderTraveral(index*2+1);
    printf("%c",bt[index-1]);
}
int main()
{

    while(scanf("%s",bt)!=EOF)
    {
        PreOrderTraveral(1);
        printf("\n");
        InOrderTraveral(1);
        printf("\n");
        PostOrderTraveral(1);
        printf("\n");
        printf("\n");
    }
    return 0;
}
