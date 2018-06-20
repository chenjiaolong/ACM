//不容易系列
//#include<stdio.h>
//int pan(int sum,int m)
//{
//    if(m==0) return sum;
//    sum=(sum-1)*2;
//    return pan(sum,m-1);
//}
//int main()
//{
//    int i,N,a;
//    scanf("%d",&N);
//    for(i=0;i<N;i++)
//    {
//        scanf("%d",&a);
//        printf("%d\n",pan(3,a));
//    }
//    return 0;
//}
//不容易系列
#include<stdio.h>
int digui(int b)
{
    if(b==0) return 3;
    return (digui(b-1)-1)*2;
}
void main()
{
    int i,n,m;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        int res=digui(m);
        printf("%d\n",res);

    }
}
//按如下递归公式求函数值。 x=1时 f(x)=10；x>1时 f(x)=f(x-1)+2
/*#include<stdio.h>
int Function(int x)
{
    if(x==1) return 10;
    return Function(x-1)+2;
}
int main()
{
    int x,vlaue;
    scanf("%d",&x);
    vlaue=Function(x);
    printf("%d",vlaue);
    return 0;
}*/
//斐波纳契数列
//1，1，2，3，5，8，13，21，34，55，89……这个数列则称为“斐波纳契数列”，其中每个数字都是“斐波纳契数”。
/*#include<stdio.h>
int Function(int x)
{
    if(x==1) return 1;
    else if(x==2) return 1;
    else if(x>1)
        return Function(x-1)+Function(x-2);
}
int main()
{
    int x=1,N,vlaue;
    scanf("%d",&N);
    do
        {
        vlaue=Function(x);
        printf("%d ",vlaue);
        x++;
       }while(x<=N);
    return 0;
}*/
