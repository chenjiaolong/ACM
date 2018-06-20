#include<stdio.h>
#include<math.h>
#define MAX 10000000
int A[MAX + 5];
//方法一
/*void isprime()
{
    int i,j;
    for(i=0;i<=MAX;i++)
        A[i]=0;
    A[0]=1,A[1]=1;
    for(i=2;i<=MAX;i++)
    {
        if(A[i]==0)//if(!A[i])
        for(j=2;i*j<=MAX;j++)
            A[i*j]=1;
    }
    for(i=1;i<=100;i++)
        if(A[i]==0)
            printf("%d ",i);
}*/
//方法二
/*void isprime()
{
    int i,j;
    for(i=0;i<=MAX;i++)
        A[i]=i;
    A[1]=0;
    for(i=2;i<=MAX;i++)
    {
        if(A[i]!=0)//if(A[i])
        for(j=2*i;j<=MAX;j+=i)
            A[j]=0;
    }
    for(i=1;i<=100;i++)
        if(A[i])
            printf("%d ",A[i]);
}*/
//方法三
void isprime()
{
    int i,j;
    for(i=0; i<=MAX; i++)
    {
        if(i%2) A[i]=1;
        else A[i]=0;
    }
    A[1]=0,A[2]=1;
    for(i=2; i<=(int)sqrt(MAX); i++)
    {
        if(A[i]!=0)//if(A[i])
            for(j=i+i; j<=MAX; j+=i)
                A[j]=0;
    }

    for(i=1; i<=100; i++)
        if(A[i])
            printf("%d ",i);
}
int main()
{
    isprime();
    return 0;
}
