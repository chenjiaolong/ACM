//շת�������m��n�����Լ����GCD������С��������LCM��=m*n/GCD;
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
//��1+2!+3!+4!+��+30!����ѧ��������������λС����
/*#include <stdio.h>
// ʹ�õݹ����׳�
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

