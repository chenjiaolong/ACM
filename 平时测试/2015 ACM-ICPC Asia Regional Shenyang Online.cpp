// 	hdu 5461 Largest Point
//#include<map>
//#include<math.h>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//
//const int maxn = 5e6 + 100;
//const long long inf = 1e18 + 100;
//
//long long A[maxn];
//long long B[maxn];
//
//int main()
//{
//    int T, n;
//    long long a, b, t;
//    long long ans;
//    scanf("%d", &T);
//    for(int tt = 1; tt <= T; tt ++)
//    {
//        scanf("%d%lld%lld", &n, &a, &b);
//        for(int i = 1; i <= n; i ++)
//        {
//            scanf("%lld", &t);
//            A[i] = a * t * t;
//            B[i] = b * t;
//        }
//        long long M = -inf;
//        int cur;
//        for(int i = 1; i <= n; i ++)
//            if(A[i] > M)
//            {
//                cur = i;
//                M = A[i];
//            }
//        long long N = -inf;
//        for(int i = 1; i <= n; i ++)
//            if(B[i] > N && i != cur) N = B[i];
//        printf("Case #%d: %lld\n", tt, M + N);
//    }
//    return 0;
//}


// hdu 5452	Minimum Cut(Ì°ÐÄ)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 2e4 + 100;
const int inf = 1e9;
bool vis[maxn];
int degree[maxn], back[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t ++)
    {
        memset(degree, 0, sizeof(degree));
        memset(back, 0, sizeof(back));
        memset(vis, false, sizeof(vis));
        int n, m;
        scanf("%d%d", &n, &m);
        int u, v;
        for(int i = 1; i <=  n - 1; i++)
        {
            scanf("%d%d", &u, &v);
            degree[u]++;
            degree[v]++;
            if(degree[u] > 1) vis[u] = true;
            if(degree[v] > 1) vis[v] = true;
        }
        for(int i = 1; i <= m - n + 1; i ++)
        {
            scanf("%d%d", &u, &v);
            back[u]++;
            back[v]++;
        }
        int ans = inf;
        for(int i = 1; i <= n; i ++)
            if(!vis[i]) ans = min(ans, degree[i] + back[i]);
        printf("Case #%d: %d\n", t, ans);

    }
    return 0;
}

