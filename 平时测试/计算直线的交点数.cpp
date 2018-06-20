// nsu 1084
// hdu 1466
/**
 *n条直线时，交点数情况存到arr[n]中。
 *分成两组，选任意一条A作为代表，与A平行的都在A组，其他的放到B组，
 *则交点数为a * b + arr[b];
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    bool dp[25][210] = {0};// 标记法某种程度上具备排序的性质
    for(int i = 0; i <= 20; i ++)
    {
        dp[i][0] = true;// 0一定有，有则标记
        for(int j = 1; j < i; j ++)
        {
            int p = i - j;
            int maxn = p * (p - 1) / 2;
            for(int k = 0; k <= maxn; k ++)
                if(dp[p][k]) dp[i][p * j + k] = true;
        }
    }
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int maxn = n * (n - 1) / 2;
        printf("0");
        for(int i = 1; i <= maxn; i ++)
            if(dp[n][i]) printf(" %d", i);
        puts("");
    }
    return 0;
}

