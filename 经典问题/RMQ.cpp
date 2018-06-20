// Range Minimum/Maximum Query

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

#define maxn 100005

using namespace std;

int maxsum[maxn][20];

void RMQ(int n)
{
    for(int j = 1; j < 15; j ++)
        for(int i = 1; i <= n; i ++)
            if(i + (1 << j) - 1 <= n)
                maxsum[i][j] = max(maxsum[i][j - 1], maxsum[i + (1 << j - 1)][j - 1]);
}

int main()
{
    int n, m;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; i ++) scanf("%d", &maxsum[i][0]);
        scanf("%d", &m);
        int l, r;
        RMQ(n);
        for(int i = 0; i < m; i ++)
        {
            scanf("%d%d", &l, &r);
            int k = (int ) 1.0 * log(r - l + 1)/ log(2);
            printf("%d\n", max(maxsum[l + 1][k], maxsum[r + 1 - (1 << k) + 1][k]));
        }
    }
    return 0;
}


