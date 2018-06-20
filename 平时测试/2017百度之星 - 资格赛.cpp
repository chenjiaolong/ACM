#include <bits/stdc++.h>

using namespace std;
int a[100100], b[100100];
int k[1010], p[1010];
typedef long long LL;
LL dp[1010][15];
int n, m;

void Solve()
{
    for(int i = 0; i <= 1000; i ++)
        for(int j = 0; j <= 10; j ++)
            dp[i][j] = 1e18;
    for(int i = 0; i <= 10; i ++) dp[0][i] = 0ll;
    for(int x = 0; x <= 1000; x ++)
        for(int y = 0; y <= 10; y ++)
            for(int z = 1; z <= m; z ++)
                if(p[z] >= y)
                {
                    int o = x + (p[z] - y); // ԭʼֵ
                    if(o > 1000) o = 1000;
                    dp[o][y] = min(dp[o][y], dp[x][y] + k[z]);
                }
    for(int i = 1000; i >= 0; i --)
        for(int j = 10; j >= 0; j --)
        {
            if(i == 1000 && j == 10) continue;
            if(i < 1000)
                dp[i][j] = min(dp[i][j], dp[i + 1][j]);
            if(j < 10) dp[i][j] = min(dp[i][j], dp[i][j + 1]);
            if(i < 1000 && j < 10)
                dp[i][j] = min(dp[i][j], dp[i + 1][j + 1]);
        }

}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; i ++) scanf("%d%d", &a[i], &b[i]);
        for(int i = 1; i <= m; i ++) scanf("%d%d", &k[i], &p[i]);
        Solve();
        LL ans = 0ll;
        for(int i = 1; i <= n; i ++)
        {
            if(dp[a[i]][b[i]] == 1e18)
            {
                ans = -1;
                break;
            }
            else ans += dp[a[i]][b[i]];
        }
        printf("%I64d\n", ans);

    }
    return 0;
}
