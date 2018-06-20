//求2000~2500年的闰年？
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int year;
    for (year=2000; year<=2500; year++)
    {
        if ((year%4==0&&year%100!=0)||(year%400==0))
            printf("%d\n",year);
    }
    system("pause");
    return 0;
}
