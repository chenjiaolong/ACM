#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

const int maxn = 1100;

int main()
{
    char a[maxn], b[maxn];
    int dp[maxn];
    while(scanf("%s%s", a, b) != EOF)
    {
        int n = strlen(a);
        int m  = strlen(b);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i ++)
        {
            int maxi = 0;
            for(int j = 1; j <= m; j ++)
            {
                if(a[i - 1] > b[j - 1]) maxi = max(maxi, dp[j]);
                if(a[i - 1] == b[j - 1]) dp[j] = maxi + 1;
            }
        }
        int maxi = 0;
        for(int i = 1; i <= m; i ++)
        {
            maxi = max(maxi, dp[i]);
            printf("sss i = %d , dp[%d] = %d\n", i, i, dp[i]);
        }
        printf("%d\n", maxi);
    }
    return 0;
}
