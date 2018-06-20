// Greatest Common Increasing Subsequence
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//const int maxn = 505;
//int MAX(int a, int b)
//{
//    return a >= b ? a : b;
//}
//
//int main()
//{
//    int L;
//    scanf("%d", &L);
//    int a[maxn],b[maxn], dp[maxn];
//    while(L--)
//    {
//        int N, M;
//        scanf("%d", &N);
//        memset(dp, 0, sizeof(dp));
//        for(int i = 1; i <= N; i ++)
//            scanf("%d", &a[i]);
//        scanf("%d", &M);
//        for(int i = 1; i <= M; i ++)
//            scanf("%d", &b[i]);
//        for(int i = 0; i <= N; i ++)
//        {
//            int maxi = 0;
//            for(int j = 0; j <= M; j ++)
//            {
//                if(a[i] > b[j]) maxi = MAX(maxi, dp[j]);
//                if(a[i] == b[j] ) dp[j] = maxi + 1;
//            }
//        }
//        int len = 0;
//        for(int i = 0; i <= N; i ++)
//            len = MAX(len, dp[i]);
//        printf("%d\n", len);
//        if(L) puts("");
//    }
//    return 0;
//}

// Bridging signals
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<algorithm>
//
//using namespace std;
//
//const int maxn = 40010;
//int array[maxn], temp[maxn];
//int dp[maxn];
//int main()
//{
//    int n, p;
//    scanf("%d", &n);
//    while(n --)
//    {
//        scanf("%d", &p);
//        for(int i = 1; i <= p; i ++)
//        {
//            scanf("%d", &array[i]);
//            dp[i] = 1;
//        }
//        int maxi = 0, len = 0;
//        for(int i = 1; i <= p; i ++)
//        {
//            int num = array[i];
//            int l = lower_bound(temp + 1, temp + len + 1, num) - temp;// 递增子序列
//            // int l = upper_bound(temp + 1, temp + len + 1, num) - temp;// 非递减子序列
//            temp[l] = num;
//            dp[i] = l;
//            if(l > len) len = l;
//            if(dp[i] > maxi) maxi = dp[i];
//        }
//        printf("%d\n", len);
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<algorithm>
//
//using namespace std;
//const int maxn = 1100;
//
//int main()
//{
//    int array[maxn], dp[maxn];
//    int N;
//    while(scanf("%d", &N), N)
//    {
//        memset(dp, 0, sizeof(dp));
//        for(int i = 0; i < N; i ++)
//        {
//            scanf("%d", &array[i]);
//            dp[i] = array[i];
//        }
//
//        for(int i = 1; i < N; i ++)
//        {
//            int maxi = 0;
//            for(int j = 0; j < i; j ++)
//                if(array[i] > array[j]) dp[i] = max(dp[i], dp[j] + array[i]);
//        }
//        int ans = 0;
//        for(int i = 0; i < N; i ++) ans = max(ans, dp[i]);
//        printf("%d\n", ans);
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<algorithm>
//
//using namespace std;
//const int maxn = 5e5 + 100;
//
//int temp[maxn];
//
//int f[maxn];
//
//int main()
//{
//    int t = 1;
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        for(int i = 1; i <= n; i ++)
//        {
//            int p, r;
//            scanf("%d%d", &p, &r);
//            f[p] = r;
//        }
//        int l, r, mid, len = 0, maxi = 0;
//        for(int i = 1; i <= n; i ++)
//        {
//            int num = f[i];
//            l = 1, r = len;
//            while(l <= r)
//            {
//                mid = (l + r) >> 1;
//                if(num > temp[mid]) l = mid + 1;
//                else r = mid - 1;
//            }
//            temp[l] = num;
//            if(len < l) len ++;
//        }
//        if(len > 1) printf("Case %d:\nMy king, at most %d roads can be built.\n\n", t ++, len);
//        else printf("Case %d:\nMy king, at most %d road can be built.\n\n", t ++, len);
//    }
//    return 0;
//}

// Common Subsequence
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//using namespace std;
//const int maxn = 1100;
//
//int MAX(int a, int b)
//{
//    return a >= b ? a : b;
//}
//int main()
//{
//    char a[maxn], b[maxn];
//    int dp[4][maxn];
//    while(scanf("%s%s", a, b) != EOF)
//    {
//        int len1 = strlen(a);
//        int len2 = strlen(b);
//        memset(dp, 0, sizeof(dp));
//        for(int i = 1; i <= len1; i ++)
//            for(int j = 1; j <= len2; j ++)
//            {
//                int cur = i % 2;
//                if(a[i - 1] == b[j -1]) dp[cur % 2][j] = dp[(cur + 1) % 2][j - 1] + 1;
//                else dp[cur % 2][j] = MAX(dp[(cur + 1) % 2][j], dp[cur % 2][j - 1]);
//
//            }
//        printf("%d\n", dp[len1 % 2][len2]);
//    }
//    return 0;
//}

// 汉诺塔II
//#include<math.h>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//const int INF = 1 << 29;
//
//int main()
//{
//    int Hanoi[65] = {0};
//    Hanoi[1] = 1, Hanoi[2] = 3;
//    for(int i = 3; i <= 64; i++)
//    {
//        int MIN = INF;
//        for(int j = 1; j < i; j ++)
//            if(2 * Hanoi[j] + pow(2.0, i - j) - 1 < MIN)
//            MIN = 2 * Hanoi[j] + pow(2.0, i - j) - 1;
//        Hanoi[i] = MIN;
//    }
//    int N;
//    while(scanf("%d", &N) != EOF)
//        printf("%d\n", Hanoi[N]);
//    return 0;
//}

// Waring TV
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

const int maxn = 1e5 + 100;

struct node
{
    int s, e;
    int v;
    bool operator <(const node &C)const
    {
        if(e == C.e)
            return s < C.s;
        return e < C.e;
    }
} array[maxn];

int dp[maxn];
int main()
{
    int N;
    while(scanf("%d", &N) != EOF)
    {
        for(int i = 0; i < N; i ++)
            scanf("%d%d%d", &array[i].s, &array[i].e, &array[i].v);
        sort(array, array + N);
        memset(dp, 0, sizeof(dp));
        dp[0] = array[0].v;
        for(int i = 1; i < N; i ++)
        {
            dp[i] = array[i].v;
            int l = 0, r = i - 1, mid, cur = -1;
            while(l <= r)
            {
                mid = (l + r) >> 1;
                if(array[mid].e < array[i].s)
                {
                    cur = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            if(cur != -1) dp[i] = max(dp[i], dp[cur] + array[i].v);
            dp[i] = max(dp[i], dp[i - 1]);
        }
        printf("%d\n", dp[N - 1]);
    }
    return 0;
}


// Kyoya and Colored Balls
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//const int mod =  1e9 + 7;
//const int maxn = 1010;
//long long C[maxn][maxn] = {0};
//int main()
//{
//    C[0][0] = 1;
//    for(int i = 1; i < maxn; i ++)
//    {
//        C[i][0] = 1, C[i][i] = 1;
//        for(int j = 1; j < i; j ++)
//            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
//    }
//    int k;
//    while(scanf("%d", &k) != EOF)
//    {
//        int ci;
//        long long ans = 1;
//        int cnt = 0;
//        for(int i = 0; i < k; i ++)
//        {
//            scanf("%d", &ci);
//            cnt += ci;
//            ans = (ans * C[cnt - 1][ci - 1] )% mod;
//
//        }
//        printf("%I64d\n", ans);
//    }
//    return 0;
//}

// Bear and Blocks
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<algorithm>
//
//using namespace std;
//
//const int maxn = 1e5 + 100;
//int pre[maxn], next[maxn], h[maxn];
//
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        memset(pre, 0, sizeof(pre));
//        memset(next, 0, sizeof(next));
//        h[0] = 0, h[n + 1] = 0;
//        for(int i = 1; i <= n; i ++)
//        {
//            scanf("%d", &h[i]);
//            pre[i] = pre[i - 1] + 1;
//            if(h[i] < pre[i]) pre[i] = h[i];
//        }
//        for(int i = n; i >= 1; i --)
//        {
//            next[i] = next[i + 1] + 1;
//            if(h[i] < next[i]) next[i] = h[i];
//        }
//        int ans = 0;
//        for(int i = 1; i <= n; i ++)
//            ans = max(ans, min(pre[i], next[i]));
//        printf("%d\n", ans);
//    }
//    return 0;
//}
