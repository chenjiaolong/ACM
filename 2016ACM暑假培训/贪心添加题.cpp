// "Or" Game：前后缀和 + 贪心
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<algorithm>
//
//using namespace std;
//
//const int maxn = 2e5 + 5;
//long long array[maxn];
//long long pre[maxn];
//long long next[maxn];
//
//int main()
//{
//    int n, k, x;
//    int s;
//    while(scanf("%d%d%d", &n, &k, &x) != EOF)
//    {
//        s = 1;
//        for(int i = 1; i <= k; i ++)
//            s *= x;
//        array[0] = 0;
//        pre[0] = 0;
//        long long ans = 0;
//        for(int i = 1; i <= n; i ++)
//        {
//            scanf("%lld", &array[i]);
//            pre[i] = pre[i - 1] | array[i - 1];
//        }
//        array[n + 1] = 0;
//        next[n + 1] = 0;
//        for(int i = n; i >= 1; i --)
//            next[i] = next[i + 1] | array[i + 1];
//        for(int i = 1; i <= n; i ++)
//        {
//            long long temp = array[i];
//            temp = temp * s;
//            temp = pre[i] | temp | next[i];
//            ans = max(ans, temp);
//        }
//        printf("%lld\n", ans);
//    }
//    return 0;
//}

// Finding Team Member
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<algorithm>
//
//using namespace std;
//const int maxn = (800 * 800) >> 1;
//struct node
//{
//    int u,v;
//    int strength;
//    bool operator <(const node &s) const
//    {
//        return strength > s.strength;
//    }
//}array[maxn];
//int main()
//{
//    //printf("%d\n", maxn);
//    int n;
//    int cur = 0;
//    while(scanf("%d", &n) != EOF)
//    {
//        for(int i = 2; i <= 2 * n; i ++)
//        {
//            for(int j = 1; j < i; j ++)
//            {
//                scanf("%d", &array[cur].strength);
//                array[cur].u = i;
//                array[cur].v = j;
//                cur++;
//            }
//        }
//        sort(array, array + cur);
//        bool vis[810] = {0};
//        int ans[810] = {0};
//        for(int i = 0; i < cur; i ++)
//        {
//            if(!vis[array[i].u] && !vis[array[i].v])
//            {
//                ans[array[i].u] = array[i].v;
//                ans[array[i].v] = array[i].u;
//                vis[array[i].u] = true;
//                vis[array[i].v] = true;
//            }
//        }
//        for(int i = 1; i <= 2 * n; i ++)
//            printf("%d%c", ans[i], i == 2 * n ? '\n' : ' ');
//
//    }
//    return 0;
//}

// Duff and Meat
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//const int maxn = 1e5 + 5;
//
//struct node
//{
//    int a, p;
//}array[maxn];
//
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        scanf("%d%d", &array[0].a, &array[0].p);
//        for(int i = 1; i < n; i ++)
//        {
//            scanf("%d%d", &array[i].a, &array[i].p);
//            if(array[i].p > array[i - 1].p)
//                array[i].p = array[i - 1].p;
//        }
//        int money = 0;
//        for(int i = 0; i < n; i ++)
//            money += array[i].a * array[i].p;
//        printf("%d\n", money);
//    }
//    return 0;
//}

// Simple Game
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//int main()
//{
//    int n, m;
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        if(n == 1)
//        {
//            printf("1\n");
//            continue;
//        }
//        if(m == n)
//        {
//            printf("%d\n", m - 1);
//            continue;
//        }
//        if(n > 2 * m - 1) printf("%d\n", m + 1);
//        else printf("%d\n", m - 1);
//    }
//    return 0;
//}

// Duff and Weight Lifting
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//const int maxn = 1e6 + 5;
//int w[maxn];
//
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        memset(w, 0, sizeof(w));
//        int temp;
//        int MAX = 0;
//        for(int i = 0; i < n; i ++)
//        {
//            scanf("%d", &temp);
//            MAX = MAX < temp ? temp : MAX;
//            w[temp]++;
//        }
//        int step = 0;
//        for(int i = 0; i <= MAX; i ++)
//        {
//            w[i + 1] += (w[i] >> 1);
//            if(w[i] & 1) step ++;
//        }
//        int x=w[MAX + 1];
//        while(x)
//        {
//            if(x&1) step++;
//            x>>=1;
//        }
//        printf("%d\n", step);
//    }
//    return 0;
//}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

struct node
{
    int V, B;
    bool operator <(const node &S)const
    {
        return V > S.V;
    }
} array[25];

int main()
{
    int N, C;
    while(scanf("%d%d", &N, &C) != EOF)
    {
        for(int i = 0; i < N; i ++)
            scanf("%d%d", &array[i].V, &array[i].B);
        sort(array, array + N);
        int day = 0;
        int V;
        do
        {
            V = C;
            for(int i = 0; i < N; i ++)
            {
                int k = min(array[i].B, (int) V / array[i].V);
                array[i].B -= k;
                V -= array[i].V * k;
            }
            for(int i = N - 1; i >= 0; i--)
                if(array[i].B > 0 && V > 0)
                {
                    array[i].B --;
                    V -= array[i].V;
                }
            if(V <= 0) day ++;
        }
        while(V <= 0);
        printf("%d\n",day);
    }
    return 0;
}
