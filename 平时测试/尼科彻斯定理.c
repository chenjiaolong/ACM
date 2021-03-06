//验证尼科彻斯定理，即：任何一个正整数的立方都可以写成一串连续奇数的和。
//输入：任一正整数
//输出：该数的立方分解为一串连续奇数的和
//证明：对于任一正整数a,不论a是奇数还是偶数，整数(a×a-a+1)必然为奇数。
//构造一个等差数列，数列的首项为(a×a-a+1),等差数列的差值为2(奇数数列)，则前a项的和为：
//a×((a×a-a+1))+2×a(a-1)/2
//=a×a×a-a×a+a+a×a-a
//=a×a×a
//定理成立。证毕。
//思路：通过定理的证明过程可知L所要求的奇数数列的首项为(a×a-a+1)，长度为a。编程的算法不需要特殊设计，可按照定理的证明过直接进行验证。
#include<stdio.h>
int main()
{
    int i,n,m,a;
    scanf("%d",&n);
    m=n*n*n;
    for(a=1;; a++)
        if(m==a*(a*a-a+1)+2*a*(a-1)/2)
            break;
    // printf("***%d\n",a);
    printf("%d*%d*%d=%d=",n,n,n,m);
    for(i=1; i<=a; i++)
        printf("%d%c",a*a-a+1+2*(i-1),i==a?'\n':'+');
    return 0;
}
