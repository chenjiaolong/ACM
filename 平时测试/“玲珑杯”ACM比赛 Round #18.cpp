// 计算几何你瞎暴力
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 5e4 + 100;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        int co[12][12][12] = {0};
        long long r[maxn] = {0};
        for(int i = 1; i <= n; i ++)
        {
            int xi, yi, zi;
            scanf("%d%d%d", &xi, &yi, &zi);
            co[xi][yi][zi]++;
        }
        for(int i= 0; i <=10; i ++)
            for(int j = 0; j <= 10; j ++)
                for(int k = 0; k <= 10; k ++)
                    for(int l = 0; l <= 10; l ++)
                        for(int m = 0; m <= 10; m ++)
                            for(int n = 0; n <= 10; n ++)
                                if(i == l && j == m && k == n )
                                    r[0] += (long long)co[i][j][k]*(co[i][j][k]-1)/2;
                                else
                                {
                                    int x = abs(i-l)+abs(j-m)+abs(k-n);
                                    r[x] += (long long)co[i][j][k]*co[l][m][n];
                                }
        for(int i=1; i<=30; i++) r[i]/=2;
        for(int i=1; i<=30; i++) r[i] += r[i-1];
        while(q--)
        {
            int R;
            scanf("%d",&R);
            if(R > 30) R = 30;
            printf("%lld\n",r[R]);
        }
    }
    return 0;
}
