#include<stdio.h>
void main()
{
    int num,p,n=0;
    printf("某公司费用部件明细表\n");
    for(num=1;num<=4;num++)
    {
        for(p=1;p<=9;p++,n++)
            {
                if (n%9==0)
                    printf("\n");
                printf("%2d\t",num*p);
            }
    }
    printf("\t\t\t\t\t\t\t   2007年4月7日");
}
