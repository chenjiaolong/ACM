#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int j = 1; j <= 2 *(n - 1); j ++) printf(" ");
        printf("1\n");
        for(int i = 2; i <= n; i ++)
        {
            for(int j = 1; j <= 2 *(n - i); j ++) printf(" ");
            for(int j = 1; j <= i; j ++) printf("%d ", j);
            for(int j = i - 1; j >= 1; j --) printf("%d%c", j, j == 1 ? '\n' : ' ');
        }
    }
    return 0;
}
