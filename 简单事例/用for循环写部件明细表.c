#include<stdio.h>
void main()
{
    int num,p,n=0;
    printf("ĳ��˾���ò�����ϸ��\n");
    for(num=1;num<=4;num++)
    {
        for(p=1;p<=9;p++,n++)
            {
                if (n%9==0)
                    printf("\n");
                printf("%2d\t",num*p);
            }
    }
    printf("\t\t\t\t\t\t\t   2007��4��7��");
}
