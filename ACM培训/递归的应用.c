//������ϵ��
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
//������ϵ��
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
//�����µݹ鹫ʽ����ֵ�� x=1ʱ f(x)=10��x>1ʱ f(x)=f(x-1)+2
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
//쳲���������
//1��1��2��3��5��8��13��21��34��55��89��������������Ϊ��쳲��������С�������ÿ�����ֶ��ǡ�쳲�����������
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
