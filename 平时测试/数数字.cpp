// 软件服务外包学院OJ 5884
// http://59.71.36.28:8080/JudgeOnline/problem.php?cid=1270&pid=5
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int a = n / 2;
        int b = n / 3;
        int c = n / 5;

        int ab = n / 6;
        int ac = n / 10;
        int bc = n / 15;

        int abc = n / 30;

        int ans = a + b + c - ab - ac - bc + abc;
        printf("%d\n", ans);
    }
    return 0;
}
