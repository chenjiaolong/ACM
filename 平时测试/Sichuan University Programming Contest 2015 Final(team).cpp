#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 8000000;
long long ans[maxn + 5];
int main()
{
    ans[0] = 0;
    for(int i = 1; i <= maxn; i ++)
        ans[i] = (ans[i - 1] * i + i) % mod;
    int T, N;
    while(scanf("%d",&T) != EOF)
    {
        while(T --)
        {
            scanf("%d", &N);
            printf("%lld\n",ans[N]);
        }
    }
    return 0;
}

