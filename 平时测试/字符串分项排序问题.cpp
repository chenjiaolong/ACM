// hdu 3293 sort
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    char name[25];
    char origin[25];
    char rank[25];
} girl[510];
bool cmp(node p1, node p2)
{
    if(strcmp(p1.origin, p2.origin)) return strcmp(p1.origin, p2.origin) < 0;
    if(strcmp(p1.rank, p2.rank))
    {
        if(!strcmp(p1.rank, "wonderful")) return true;
        if(!strcmp(p2.rank, "wonderful")) return false;
        if(!strcmp(p2.rank, "so-so")) return true;
        if(!strcmp(p1.rank, "so-so")) return false;
    }
    return strcmp(p1.name, p2.name) < 0;
}
int main()
{
    int N;
    int t = 1;
    while(~scanf("%d", &N))
    {
        for(int i = 0; i < N; i ++)
            scanf("%s%s%s", girl[i].name, girl[i].origin, girl[i].rank);
        sort(girl, girl + N, cmp);
        printf("Case %d\n", t++);
        bool flag = false;
        for(int i = 0; i < N; i++)
        {
            if(!flag)
            {
                printf("%s:\n", girl[i].origin);
                flag = true;
            }
            printf("%10c%s %s\n", ' ', girl[i].name, girl[i].rank);
            if(strcmp(girl[i].origin, girl[i + 1].origin))
                flag = false;

        }
    }
    return 0;
}
