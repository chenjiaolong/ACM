//n阶勒让德多项式定义为：
//pn(x) = 1(n=0)
//pn(x) = x(n=1)
//pn(x) = ((2*n-1)*x-p(n-1)(x)-(n-1)*pn-2(x))/n (n>1)

//输入两个整数x和n

//输出pn(x)的值，其值为浮点数，小数点后保留到第二位。
#include<bits/stdc++.h>
double P(int x, int n)
{
    if(n == 0)
        return 1.0;
    else if(n == 1)
        return x * 1.0;
    return ((2 * n - 1) * x - P(x, n - 1) - (n -1) * P(x, n -2)) * 1.0/n;
}
int main()
{
    int x,n;
    while(scanf("%d%d",&x,&n) == 2)
            printf("%.2f\n",P(x,n));
    return 0;
}
