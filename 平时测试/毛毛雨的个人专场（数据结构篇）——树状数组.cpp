// hdu2688 Rotate
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//using namespace std;
//
//const int maxn = 1e4 + 10;
//const int maxm = 3e6 + 10;
//
//typedef __int64 LL;
//LL C[maxn];
//int ans[maxm];
//inline int lowbit(int x)// 判断最右边1的位置
//{
//    return x & (-x);
//}
//void Add(int pos)// 更新c[i]的值
//{
//    while(pos < maxn)
//    {
//        C[pos] ++;
//        pos += lowbit(pos);
//    }
//}
//LL Sum(int pos)// 求和c[1]+...+c[x]
//{
//    LL sum = 0ll;
//    while(pos > 0)
//    {
//        sum += C[pos];
//        pos -= lowbit(pos);
//    }
//    return sum;
//}
//int main()
//{
//    int n, m;
//    while(scanf("%d", &n) != EOF)
//    {
//        for(int i = 1; i < maxn; i ++) C[i] = 0ll;
//        LL val = 0ll;
//        for(int i = 0; i < n; i ++)
//        {
//            scanf("%d", &ans[i]);
//            val += Sum(ans[i] - 1);
//            Add(ans[i]);
//        }
//        scanf("%d", &m);
//        while(m --)
//        {
//            char str[4];
//            scanf("%s", str);
//            if(str[0] == 'Q')
//                printf("%I64d\n", val);
//            else
//            {
//                int s, e;
//                scanf("%d%d", &s, &e);
//                if(s > e)
//                {
//                    int tmp = s;
//                    s = e;
//                    e = tmp;
//                }
//                int v = ans[s];
//                for(int i = s; i < e; i ++)
//                {
//                    ans[i] = ans[i + 1];
//                    if(v < ans[i + 1]) val --;
//                    if(v > ans[i + 1]) val ++;
//                }
//                ans[e] = v;
//            }
//        }
//    }
//    return 0;
//}

// poj 3145(hdu 3303) Harmony Forever
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//const int mod_split = 1000;
//const int maxn = 5e5 + 10; // 在线做法把数组开到最大， 时间就卡死了！
//int q[mod_split + 5], c[maxn + 5], a[maxn + 5], time[mod_split + 5];
//int t;
//inline int lowbit(int x)
//{
//    return x & (-x);
//}
//// 更新c[i]的值
//void Add(int pos)
//{
//    while(pos < maxn)
//    {
//        ++c[pos];
//        pos += lowbit(pos);
//    }
//    return ;
//}
//
//// 树状数组求前n项和
//int Sum(int x)
//{
//    int sum = 0;
//    while(x > 0)
//    {
//        sum += c[x];
//        x -= lowbit(x);
//    }
//    return sum;
//}
//// 插入操作
//void Insert(int x)
//{
//    t++;
//    for(int i = 1; i <= mod_split; i ++)
//    {
//        int p = x % i;
//        if(p <= q[i])
//        {
//            q[i] = p;
//            time[i] = t;
//        }
//    }
//    Add(x);
//    a[x] = t;
//}
//
//// 查找每段的最小值
//int Binary(int l, int r)
//{
//    if(!l) l ++;
//    if(l >= maxn) l = maxn - 1;
//    if(r >= maxn) r = maxn - 1;
//    int pre = Sum(l - 1);
//    int askmin = -1;
//    // 二分查找
//    while(l <= r)
//    {
//        int mid = (l + r) >> 1;
//        int now = Sum(mid);
//        if(now > pre)
//        {
//            r = mid - 1;
//            askmin = mid;// 找到一个值才更新，改动左端点不更新
//        }
//        else l = mid + 1;
//    }
//    return askmin;
//}
//void enquiry(int x)
//{
//    // 空集输出'-1'
//    if(t == 0) puts("-1");
//    else if (x <= mod_split) printf("%d\n", time[x]);
//    else
//    {
//        // 分段
//        int l = 0, r = x - 1;
//        int MinVal = -1;
//        int MinTime;
//        while(1)
//        {
//            int k = Binary(l, r);
//            if(k != -1)
//            {
//                int Mod = k % x;
//                if(Mod < MinVal || MinVal == -1)
//                {
//                    MinVal = Mod;
//                    MinTime = a[k];
//                }
//                else if(Mod == MinVal)
//                    if(MinTime < a[k]) MinTime = a[k];
//            }
//            if(l >= maxn || r >= maxn)
//                break;
//            l += x, r += x;
//        }
//        printf("%d\n", MinTime);
//    }
//}
//int main()
//{
//    int Case = 1;
//    int T;
//    while(scanf("%d", &T), T)
//    {
//        if(Case != 1) puts("");
//        t = 0;
//        printf("Case %d:\n", Case++);
//        // 清除冗余数据
//        for(int i = 0; i <= mod_split; i ++)
//        {
//            q[i] = mod_split + 1;
//            time[i] = -1;
//        }
//        for(int i = 0; i <= maxn; i ++) c[i] = 0;
//        char command[2];
//        int x;
//        while(T--)
//        {
//            scanf("%s%d",command, &x);
//            if(command[0] == 'B') Insert(x);
//            else enquiry(x);
//        }
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//const int lim = 1000;
//const int maxn = 5e5 + 10; // 在线做法把数组开到最大， 时间就卡死了！
//int q[maxn + 5], c[maxn + 5], a[maxn + 5], time[maxn + 5];
//int t;
//inline int lowbit(int x)
//{
//    return x & (-x);
//}
//void Add(int x)
//{
//    while(x <= maxn)
//    {
//        c[x]++;
//        x += lowbit(x);
//    }
//}
//// 插入操作
//void Insert(int x)
//{
//    time[++t] = x;
//    a[x] = t;
//    for(int i = 1; i <= lim; i ++)
//    {
//        if(q[i] == 0) q[i] = t;
//        else if(x % i <= time[q[i]] % i) q[i] = t;
//    }
//    Add(x);
//}
//// 树状数组求前n项和
//int Sum(int x)
//{
//    int sum = 0;
//    while(x > 0)
//    {
//        sum += c[x];
//        x -= lowbit(x);
//    }
//    return sum;
//}
//// 查找每段的最小值
//int Binary(int be, int en)
//{
//    int l, r;
//    if(be == 0) l = 1;
//    else l = be;
//    if(en > maxn) r = maxn;
//    else r = en;
//    int pre = Sum(l - 1);
//    int askmin = -1;
//    // 二分查找
//    while(l <= r)
//    {
//        int mid = (l + r) >> 1;
//        int now = Sum(mid);
//        if(now > pre)
//        {
//            r = mid - 1;
//            askmin = mid;// 找到一个值才更新，改动左端点不更新
//        }
//        else l = mid + 1;
//    }
//    return askmin;
//}
//void enquiry(int x)
//{
//    // 空集输出'-1'
//    if(t == 0) puts("-1");
//    //小的询问直接输出
//    else if (x <= lim) printf("%d\n", q[x]);
//    else
//    {
//        int cur = x - 1;
//        // 分段
//        int l = 0, r = x - 1;
//        while(l <= maxn)
//        {
//            int k = Binary(l, r);
//            if(k > 0 && ((k % x < cur % x) || ((k % x == cur % x) && (a[k] > a[cur]))))
//                cur = k;
//            l += x, r += x;
//        }
//        printf("%d\n", a[cur]);
//    }
//}
//int main()
//{
//    int Case = 1;
//    int T;
//    while(scanf("%d", &T), T)
//    {
//        t = 0;
//        if(Case != 1) puts("");
//        printf("Case %d:\n", Case++);
//        // 清除冗余数据
//        for(int i = 0; i <= maxn; i ++)
//        {
//            q[i] = 0;
//            time[i] = 0;
//            c[i] = 0;
//            a[i] = 0;
//        }
//        char command[2];
//        int x;
//        while(T--)
//        {
//            scanf("%s%d",command, &x);
//            if(command[0] == 'B') Insert(x);
//            else enquiry(x);
//        }
//    }
//    return 0;
//}

// poj 1990 MooFest
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//
//const int maxn = 2e4 + 10;
//typedef long long LL;
//
//LL c[3][maxn + 5];
//int n;
//
//struct node
//{
//    int v;
//    int x;
//    bool operator<(const node &s)const
//    {
//        return v < s.v;
//    }
//}cow[maxn + 5];
//
//inline int lowbit(int x)
//{
//    return x & (-x);
//}
//void Add(int id, int x, int v)
//{
//    while(x <= maxn)
//    {
//        c[id][x] += v;
//        x += lowbit(x);
//    }
//}
//LL Sum(int id, int x)
//{
//    LL sum = 0;
//    while(x > 0)
//    {
//        sum += c[id][x];
//        x -= lowbit(x);
//    }
//    return sum;
//}
//
//int main()
//{
//    while(scanf("%d", &n) != EOF)
//    {
//        for(int i = 1; i <= n; i ++)
//            scanf("%d%d", &cow[i].v, &cow[i].x);
//        sort(cow + 1, cow + n + 1);
//        for(int i = 1; i <= maxn; i ++)
//            c[0][i] = c[1][i] = 0;
//        LL ans = 0;
//        int tot = 0; // 记录所有的坐标和
//        for(int i = 1; i <= n; i ++)
//        {
//            int x = cow[i].x;
//            tot += x;
//            Add(1, x, 1);
//            Add(2, x, x);
//            int s1 = Sum(1, x);// 在i牛前面的牛有多少头（包括i自己）
//            int s2 = Sum(2, x);// 在i牛前面的牛坐标和为多少（包括i自己）
//            int tmp1 = s1 * x - s2;// i 左边的坐标差
//            int tmp2 = tot - s2 - x * (i - s1);// i 右边的坐标差
//            ans += (LL)(tmp1 + tmp2) * cow[i].v;
//        }
//        printf("%I64d\n", ans);
//    }
//    return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;
const int maxn = 2e5 + 10;
int ans[maxn + 10];
struct node
{
    int pos;
    int val;
} Tickets[maxn + 10];

int c[maxn + 10];
int n;
inline int lowbit(int x)
{
    return x & (-x);
}
void Add(int i, int x)
{
    while(i <= n)
    {
        c[i] += x;
        i += lowbit(i);
    }
}
int Sum(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
int main()
{
    while(scanf("%d", &n) != EOF)
    {
        memset(c, 0, sizeof(c));
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d%d", &Tickets[i].pos, &Tickets[i].val);
            Tickets[i].pos ++;
        }

        for(int i = n; i >= 1; i --)
        {
            int l = 1, r = n;
            int cur = 1;
            while(l <= r)
            {
                int mid = (l + r) >> 1;
                if(mid - Sum(mid) >= Tickets[i].pos)
                {
                    r = mid - 1;
                    cur = mid;
                }
                else l = mid + 1;
            }
            ans[cur] = Tickets[i].val;
            Add(cur, 1);
        }
        for(int i = 1; i <= n; i ++)
            printf("%d%c", ans[i], i == n ? '\n' : ' ');
    }
    return 0;
}
