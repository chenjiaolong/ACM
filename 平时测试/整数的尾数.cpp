//从a * 100 / b 开始，到 (a * 100 + 99) / b这样遍历，速度更快。
#include <stdio.h>
int main()
{
    int a, b, i, r, flag;
    while(~scanf("%d%d", &a, &b), a || b)
    {
        flag = 0;
        for(i = a * 100 / b; i <= (a * 100 + 99) / b; i ++)
            if(b * i >= a * 100 && b * i <= a*100 + 99)
            {
                r = b * i - a * 100;
                if (flag)
                    printf(" ");
                flag = 1;
                printf("%02d",r);
            }
        printf("\n");
    }
    return 0;
}
