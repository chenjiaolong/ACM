#include<stdio.h>
#include<string.h>
int c[100000],a[100000],n;//c������Ԫ��c[i]��ʾa[i�Clowbit(i)+1]��A[i]�Ľ��ֵ
int lowbit(int x)//lowbit(i)��i�Ķ����������һ����Ϊ���λ����2�η�
{
    return x&(-x);//return x&(x^(x-1));
}
int Sum(int x)
{
    int sum=0;
    while(x>0)
    {
        sum=sum+c[x];
        x=x-lowbit(x);//n=n�Clowbit(n)�ȼ��ڽ�n�Ķ����Ƶ����һ��1��ȥ��
    }
    return sum;
}
void Add(int i,int x)//�޸�һ���ڵ㣬�����޸����������ȣ�������Ϊ�޸ĵ�һ��Ԫ�أ������log(n)������
{
    while(i<=n)
    {
        c[i]=c[i]+x;
        printf("c[%d]=%d ",i,c[i]);
        i=i+lowbit(i); //��ĩβ1��Ϊ0�Ĺ���
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
