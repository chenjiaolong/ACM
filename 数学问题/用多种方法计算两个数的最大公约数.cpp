/*--------------------�ö��ַ������������������Լ��----------------------*/
/*-----------------���ߣ�200910405429--------����������DEV C++----------------*/
#include "stdio.h"
#include "conio.h"
#include"time.h"
/*------------------------�����Ƿֽ���������--------------------------------*/
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
                a=a/i;/*Ҫ�����Ѿ�ѡ�������������������ظ�����*/
                b=b/i;
            }
        }
    return k;
}
/*-----------------------------�����Ǹ��������-----------------------------*/
int gcd_reduction(int a,int b)//ʱ�临�Ӷ� T = O(N) N Ϊԭ�ȵ��������нϴ��һ��
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
/*-----------------------------����������ⷨ-------------------------------*/
int gcd_continuous(int a ,int b)
{
    int i,k,temp;
    temp=a<b?a:b;
    for(i=0; i<temp; i++)  /*���Լ��*/
    {
        k=temp-i;
        if(a%k==0&&b%k==0)
            return k;
    }
}
/*------------------------------ŷ������㷨--------------------------------*/
int gcd_Euclidean (int a,int b)//ʱ�临�Ӷ� T = O(log(N)) N Ϊԭ���������нϴ��һ��
{
    if (!b)
        return a;
    return gcd_Euclidean (b,a%b);
}
/*---------------------------------������-----------------------------------*/
int main()
{
    int a, b,i=1000;
    double start=0,end=0,time[4];
    printf("������������:");
    while(~scanf ("%d%d",&a,&b))
    {
        start=clock(); /*���²���gcd_factor(a,b)��ʱ��*/
        while(i>0)
        {
            gcd_factor(a,b);
            i--;
        }
        end=clock();
        time[0]=(end-start);
        end=0;
        i=1000;
        start=clock(); /*���²���gcd_Euclidean(a,b)��ʱ��*/
        while(i>0)
        {
            gcd_Euclidean(a,b);
            i--;
        }
        end=clock();
        time[1]=(end-start);
        start=clock(); /*���²���gcd_continuous(a,b)��ʱ��*/
        i=1000;
        while(i>0)
        {
            gcd_continuous(a,b);
            i--;
        }
        end=clock();
        time[2]=(end-start);
        start=clock(); /*���²���gcd_reduction(a,b)��ʱ��*/
        i=1000;
        while(i>0)
        {
            gcd_reduction(a,b);
            i--;
        }
        end=clock();
        time[3]=(end-start);
        printf("\n\n");
        printf("\n\t------��������С��Լ�����㷨-----\n");
        printf("\n\t*----------------------------------------------*");
        printf("\n\t--  1-----�ֽ���������:%d  ����ʱ��:%f----",gcd_factor(a,b),time[0]);
        printf("\n\t--  2-----Ź �� ��  ��:%d  ����ʱ��:%f----",gcd_Euclidean(a,b),time[1]);
        printf("\n\t--  3-----�����������:%d  ����ʱ��:%f----",gcd_continuous(a,b),time[2]);
        printf("\n\t--  4-----�����������:%d  ����ʱ��:%f----",gcd_reduction(a,b),time[3]);
        printf("\n\t---  ע����������ʱ��Ϊ�ӳ�1000������----------");
        printf("\n\t*----------------------------------------------*\n");
        getch();
    }
    return 0;
    /*----------------------------------������----------------------------------*/
}
