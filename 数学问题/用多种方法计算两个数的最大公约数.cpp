/*--------------------用多种方法计算两个数的最大公约数----------------------*/
/*-----------------作者：200910405429--------开发环境：DEV C++----------------*/
#include "stdio.h"
#include "conio.h"
#include"time.h"
/*------------------------以下是分解质因数法--------------------------------*/
int gcd_factor(int a,int b)
{
    int k=1,i,temp;
    if(a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    if(a%b==0)
        return b;
    else
        for(i=2; i<b; i++)
        {
            while(a%i==0&&b%i==0)
            {
                k=k*i;
                a=a/i;/*要除以已经选出来的质因数，以免重复计算*/
                b=b/i;
            }
        }
    return k;
}
/*-----------------------------以下是更相减损术-----------------------------*/
int gcd_reduction(int a,int b)//时间复杂度 T = O(N) N 为原先的两个数中较大的一个
{
    int temp;
    if(a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    if(a==b)
        return a;
    return gcd_reduction(b,a-b);
}
/*-----------------------------连续整数检测法-------------------------------*/
int gcd_continuous(int a ,int b)
{
    int i,k,temp;
    temp=a<b?a:b;
    for(i=0; i<temp; i++)  /*最大公约数*/
    {
        k=temp-i;
        if(a%k==0&&b%k==0)
            return k;
    }
}
/*------------------------------欧几里德算法--------------------------------*/
int gcd_Euclidean (int a,int b)//时间复杂度 T = O(log(N)) N 为原先两个数中较大的一个
{
    if (!b)
        return a;
    return gcd_Euclidean (b,a%b);
}
/*---------------------------------主函数-----------------------------------*/
int main()
{
    int a, b,i=1000;
    double start=0,end=0,time[4];
    printf("输入两个整数:");
    while(~scanf ("%d%d",&a,&b))
    {
        start=clock(); /*以下测算gcd_factor(a,b)的时间*/
        while(i>0)
        {
            gcd_factor(a,b);
            i--;
        }
        end=clock();
        time[0]=(end-start);
        end=0;
        i=1000;
        start=clock(); /*以下测算gcd_Euclidean(a,b)的时间*/
        while(i>0)
        {
            gcd_Euclidean(a,b);
            i--;
        }
        end=clock();
        time[1]=(end-start);
        start=clock(); /*以下测算gcd_continuous(a,b)的时间*/
        i=1000;
        while(i>0)
        {
            gcd_continuous(a,b);
            i--;
        }
        end=clock();
        time[2]=(end-start);
        start=clock(); /*以下测算gcd_reduction(a,b)的时间*/
        i=1000;
        while(i>0)
        {
            gcd_reduction(a,b);
            i--;
        }
        end=clock();
        time[3]=(end-start);
        printf("\n\n");
        printf("\n\t------几种求最小公约数的算法-----\n");
        printf("\n\t*----------------------------------------------*");
        printf("\n\t--  1-----分解质因数法:%d  运行时间:%f----",gcd_factor(a,b),time[0]);
        printf("\n\t--  2-----殴 几 里  德:%d  运行时间:%f----",gcd_Euclidean(a,b),time[1]);
        printf("\n\t--  3-----连续整数检测:%d  运行时间:%f----",gcd_continuous(a,b),time[2]);
        printf("\n\t--  4-----更相减损算术:%d  运行时间:%f----",gcd_reduction(a,b),time[3]);
        printf("\n\t---  注：以上运行时间为延迟1000倍所得----------");
        printf("\n\t*----------------------------------------------*\n");
        getch();
    }
    return 0;
    /*----------------------------------程序完----------------------------------*/
}
