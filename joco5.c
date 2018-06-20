//判断一个数是否是水仙花数
#include <stdio.h>
int main()
{
    int n,n1,n2,n3;
    scanf("%d",&n);
    n1=n%10;
    n2=n/10%10;//n2=n%100/10;
    n3=n/100;
    if(n1*n1*n1+n2*n2*n2+n3*n3*n3==n)
        printf("1");
    else
        printf("0");
    return 0;
}
