// 计蒜课 13
// https://nanti.jisuanke.com/t/13
#include<stdio.h>
int main()
{
    static char* a[4][10]= {
        {"","I","II","III","IV","V","VI","VII","VIII","IX"},
        {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
        {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
        {"", "M", "MM", "MMM"},
        };      /*建立对照表*/
    int n;
    while(scanf("%d", &n) != EOF)
    {
        printf("%s", a[3][n / 1000 % 10]);
        printf("%s", a[2][n / 100 % 10]);
        printf("%s", a[1][n / 10 % 10]);
        printf("%s\n", a[0][n % 10]);
    }
    return 0;
}

