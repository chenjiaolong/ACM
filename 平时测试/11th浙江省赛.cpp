// ZOJ 3785	What day is that day?
#pragma comment(linker, "/STACK:102400000, 102400000")
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
char str[8][12] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
int main()
{
    int ans[50] = {0};
    int sum = 0;
    for(int i = 1; i <= 42; i ++)
    {
        int temp = i % 7;
        for(int j = 1; j < i; j ++)
            temp = temp * i % 7;
        sum = (sum + temp) % 7;
        ans[i] = sum;
    }
    int T;
    while(~scanf("%d", &T))
    {
        while(T--)
        {
            int N;
            scanf("%d", &N);
            int res = (N / 42 % 7) * ans[42]+ ans[N % 42];
            res %= 7;
            printf("%s\n", str[res]);
        }
    }
    return 0;
}
