#include<stdio.h>
bool IsLeapYear(int YY)
{
    return YY % 400 == 0 || (YY % 4 == 0&&YY % 100 != 0);
}
int main()
{
    int YY, MM, DD;
    int moths[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    while(scanf("%d%d%d",&YY,&MM,&DD) == 3)
    {
        int Y = YY,M = MM,D = DD;
        for(int day = 1; day <= 10000; day ++)
        {
            if(IsLeapYear(Y))
                moths[2] = 29;
            else
                moths[2] = 28;
            if(D == moths[M])
            {
                if(M == 12)
                {
                    Y ++;
                    M = 0;
                }
                M ++;
                D = 0;
            }
            D ++;
        }
        printf("%d-%d-%d\n",Y,M,D);
    }
    return 0;
}
