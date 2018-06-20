//猴子吃桃问题
#include<stdio.h>
int digui(int sum,int n)
{
    if(n==1) return sum;
    sum=2*(sum+1);
    n--;
    return digui(sum,n);
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",digui(1,n));
    return 0;
}
