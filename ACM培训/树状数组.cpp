#include<stdio.h>
#include<string.h>
int c[100000],a[100000],n;//c数组中元素c[i]表示a[i–lowbit(i)+1]至A[i]的结合值
int lowbit(int x)//lowbit(i)是i的二进制中最后一个不为零的位数的2次方
{
    return x&(-x);//return x&(x^(x-1));
}
int Sum(int x)
{
    int sum=0;
    while(x>0)
    {
        sum=sum+c[x];
        x=x-lowbit(x);//n=n–lowbit(n)等价于将n的二进制的最后一个1减去。
    }
    return sum;
}
void Add(int i,int x)//修改一个节点，必须修改其所有祖先，最坏情况下为修改第一个元素，最多有log(n)的祖先
{
    while(i<=n)
    {
        c[i]=c[i]+x;
        printf("c[%d]=%d ",i,c[i]);
        i=i+lowbit(i); //把末尾1补为0的过程
    }
    printf("\n");
}
int main()
{
    while(~scanf("%d",&n))
    {
        memset(c,0,sizeof(c));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            Add(i,a[i]);
        }
        for(int i=1; i<=n; i++)
            printf("%d%c",c[i],i==n?'\n':' ');
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n",Sum(v)-Sum(u-1));
    }
    return 0;
}
