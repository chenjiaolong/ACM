//辗转相除法求m和n的最大公约数（GCD），最小公倍数（LCM）=m*n/GCD;
/*#include<stdio.h>
int main()
{
    int m,n,a,b,r;
    scanf("%d%d",&m,&n);
    a=m,b=n;
    do
    {
        r=m%n;
        if(r!=0)
        {
            m=n;
            n=r;
        }
    }
    while(m%n!=0);
    printf("%d\n%d\n",n,(a*b)/n);
    return 0;
}*/
//求1+2!+3!+4!+…+30!。科学计数法，保留两位小数。
/*#include <stdio.h>
// 使用递归计算阶乘
double Mult(int num)
{
	if (num==1)
		return 1;
	else return num * Mult(num-1);
}
void main()
{
	int i;
	double sum=0;
	for (i=1; i<=30; i++)
		sum=sum+Mult(i);
	printf("%.3g\n", sum);//printf("%.2e\n",sum);
	// result: 2.7e+032  2.7*(10^32)
}*/

