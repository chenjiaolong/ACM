// 如果N是偶数，那么X ^ N = X * X ^┖N/2┚;
// 如果N是奇数，那么X ^ N = X * X ^(N - 1) = X * (X * X) ^ ┖N/2┚;
// 其中┖N┚是指小于或者等于N的最大整数
#include<stdio.h>
/*函数功能：利用模运算规则，采用递归方式，计算X ^ N (%P)函数名：PowerMod输入值：unsigned int X，底数 x unsigned int N，指数unsigned int P，模P返回值：unsigned int， X ^ N (%P)*/
unsigned int PowerMod(unsigned int X,unsigned int N,unsigned int P)
{
    if(N == 0)
        return 1;
    unsigned int temp = PowerMod((X * X) % P,N/2,P);//递归计算（X * X）^┖N/2┚;
    if(N & 1)//判断N的奇偶性
        temp = (temp * X) % P;
    return temp;
}
int main(int argc, char *argv[])
{
    unsigned int X,N,P;
    while(scanf("%u%u%u",&X,&N,&P) == 3)
        printf("%u\n",PowerMod(X,N,P));
    return 0;
}

//#include<stdio.h>
//// 快速指数模运算
//// m底数,e指数,n模数
//int mod(int m,int e,int n)
//{
//    int c = 1;
//    while(e)
//    {
//        if(e&1)
//        {
//            e = e-1 ;
//            c = (c*m)%n ;
//        }
//        else
//        {
//            e = e/2 ;
//            m = (m*m)%n ;
//        }
//    }
//    return c ;
//}
//
//int main()
//{
//    //测试
//    printf("模n的大整数次幂 = %d\n",mod(11,7,13));
//    getch();
//    return 0;
//}
