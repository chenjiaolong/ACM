//有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
#include<stdio.h>
int main()
{
    int a, b, c;
    int count=0;
    for(a=1; a<5; a++) //百位
        for(b=1; b<5; b++) //十位
            for(c=1; c<5; c++) //个位
                if(a!=b&&a!=c&&b!=c)
                {
                    printf("%d%d%d\n",a,b,c);
                    count++;
                }
    printf("排列情况为%d种\n",count);
	return 0;
}
