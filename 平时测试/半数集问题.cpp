#include<stdio.h>
int set[1001];
int isdealt[1001];
int Set(int n)
{
    if(n==1||n==2)
        return 1;
    if(isdealt[n]==1)
        return set[n];
    else
    {
        int total=0;
        int half = n /2;
        for(int i=1; i<=half; i++)
            total+=Set(i);
        isdealt[n]=1;
        set[n]=total;
        return total;
    }
}
int main()
{
    for(int i=0; i<1001; i++)
        isdealt[i]=0;
    isdealt[1]=1;
    isdealt[2]=1;
    set[1]=1;
    set[2]=1;
    for(int i=1; i<1001; i++)
        Set(i);
    set[0]=0;
    set[1]=1;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n == 1)
            printf("1\n");
        else
            printf("%d\n",2 * set[n]);
    }
    return 0;
}
