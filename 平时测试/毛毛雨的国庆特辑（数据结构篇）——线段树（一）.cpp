//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//
//#define lson l, mid, rt << 1
//#define rson mid + 1, r, rt << 1 | 1
//
//using namespace std;
//
//const int maxn = 5e4 + 100;
//
//int n, m;
//struct node
//{
//    int year;
//    int rain;
//} point[maxn];
//
//struct tree
//{
//    int l, r;
//    int Max;
//} sto[maxn << 2];
//
//int Max(int a, int b)
//{
//    return a > b ? a : b;
//}
//
//void PushUp(int rt)
//{
//    sto[rt].Max = Max(sto[rt << 1].Max, sto[rt << 1 | 1].Max);
//}
//
//void Init(int l, int r, int rt)
//{
//    sto[rt].l = l, sto[rt].r = r;
//    if(l == r)
//    {
//        sto[rt].Max = point[l].rain;
//        return ;
//    }
//    int mid = (l + r) >> 1;
//    Init(lson);
//    Init(rson);
//    PushUp(rt);
//}
//int Query(int l, int r, int rt)
//{
//    if(r < sto[rt].l || l > sto[rt].r)
//        return 0;
//    if(l <= sto[rt].l && sto[rt].r <= r)
//        return sto[rt].Max;
//    return Max(Query(l, r, rt << 1), Query(l, r, rt << 1 | 1));
//}
//int Binary(int l, int r, int val)
//{
//    int ans = 0;
//    while(l <= r)
//    {
//        int mid = (l + r) >> 1;
//        if(point[mid].year <= val)
//        {
//            l = mid + 1;
//            ans = mid;
//        }
//        else r = mid - 1;
//    }
//    return ans;
//}
//int main()
//{
//    bool flag = false;
//    while(scanf("%d", &n) != EOF)
//    {
//        if(flag && n) puts("");
//        flag = true;
//        // 连续的块种类
//        int Coces[maxn] = {0};
//        for(int i = 1; i <= n; i ++)
//        {
//            scanf("%d%d", &point[i].year, &point[i].rain);
//            if(i == 1) Coces[i] = 1;
//            else
//            {
//                if(point[i].year - point[i - 1].year == 1) Coces[i] = Coces[i - 1];
//                else Coces[i] = Coces[i - 1] + 1;
//            }
//        }
//        for(int i = 1; i <= n; i ++) printf("%d ", Coces[i]);
//        puts("");
//        if(n) Init(1, n, 1);
//        scanf("%d", &m);
//        if(n == 0 && m == 0) break;
//        for(int i = 1; i <= m; i ++)
//        {
//            int Y, X;
//            int ans; // 0 false 1 true 2 maybe
//            scanf("%d%d", &Y, &X);
//            int fY = Binary(1, n, Y);
//            int fX = Binary(1, n, X);
//            if(point[fY].year == Y && point[fX].year == X)
//            {
//                // 都能找到数据中有的年份
//
//                int Yr = Query(fY, fY, 1);
//                int Zr = Query(fY + 1, fX - 1, 1);
//                // Y + 1 == X的情况在Zr返回的是0，所以肯定满足
//                int Xr = Query(fX, fX, 1);
//                if(Coces[fY] == Coces[fX])
//                {
//                    // 之间的年份全部连续
//                    if(Yr >= Xr && Zr < Xr) ans = 1;
//                    else ans = 0;
//                }
//                else
//                {
//                    // 之间的年份不连续
//                    if(Yr >= Xr && Zr < Xr) ans = 2;
//                    else ans = 0;
//                }
//            }
//            else if(point[fX].year == X)
//            {
//                // X 这一年数据中有
//                if(Y + 1 == X) ans = 2; // 当前两年连续
//                else
//                {
//                    int Zr = Query(fY + 1, fX - 1, 1);
//                    int Xr = Query(fX, fX, 1);
//                    if(Zr < Xr) ans = 2;
//                    else ans = 0;
//                }
//            }
//            else if(point[fY].year == Y)
//            {
//                int Yr = Query(fY, fY, 1);
//                int Zr = Query(fY + 1, fX, 1);
//                if(Yr > Zr) ans = 2;
//                else ans = 0;
//            }
//            else ans = 2; // X 和 Y都没出现，肯定是maybe
//
//            if(!ans) puts("false");
//            else if(ans == 1) puts("true");
//            else puts("maybe");
//        }
//
//    }
//    return 0;
//}

//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//
//#define lson l, mid, rt << 1
//#define rson mid + 1, r, rt << 1 | 1
//
//using namespace std;
//
//const int maxn = 5e4 + 100;
//
//struct node
//{
//    int s, t;
//    int ls, rs, ms;
//    int lazy, cnt, cover;
//} sto[maxn << 2];
//
//void PushDown(int l, int mid, int r, int rt)
//{
//    if(sto[rt].lazy != -1)
//    {
//        sto[rt << 1].lazy = sto[rt << 1 | 1].lazy = sto[rt].lazy;
//        sto[rt << 1].ms = sto[rt << 1].ls = sto[rt << 1].rs = (mid - l + 1) * sto[rt].lazy;
//        sto[rt << 1 | 1].ms = sto[rt << 1 | 1].ls = sto[rt << 1 | 1].rs = (r - mid) * sto[rt].lazy;
//        sto[rt << 1].s = sto[rt << 1 | 1].s = sto[rt].s;
//        sto[rt << 1].t = sto[rt << 1 | 1].t = sto[rt].t;
//        sto[rt].lazy = -1;
//    }
//}
//void PushUp(int l, int mid, int r, int rt)
//{
//    sto[rt].ls = sto[rt << 1].ls;
//    sto[rt].rs = sto[rt << 1 | 1].rs;
//    if(sto[rt].ls == mid - l + 1) sto[rt].ls += sto[rt << 1 | 1].ls;
//    if(sto[rt].rs == r - mid) sto[rt].rs += sto[rt << 1].rs;
//    sto[rt].ms = max(max(sto[rt << 1].ms, sto[rt << 1 | 1].ms), sto[rt << 1].rs + sto[rt << 1 | 1].ls);
//}
//
//void Insert(int L, int R, int t, int l, int r, int rt) // t为 0释放该空间，为1则分配空间
//{
//    if(L <= l && r <= R)
//    {
//        sto[rt].lazy = t;
//        sto[rt].ls = sto[rt].rs = sto[rt].ms = t * (r - l + 1);
//        if(t) sto[rt].s = sto[rt].t = -1;
//        else
//        {
//            sto[rt].s = L;
//            sto[rt].t = R;
//        }
//        return ;
//    }
//    int mid = (l + r) >> 1;
//    PushDown(l, mid, r, rt);
//    if(L <= mid) Insert(L, R, t, lson);
//    if(R > mid) Insert(L, R, t, rson);
//    PushUp(l, mid, r, rt);
//}
//void Reset(int n)
//{
//    Insert(1, n, 1, 1, n, 1);
//    sto[1].cover = 1;
//    sto[1].cnt = 0;
//}
//int New(int x, int l, int r, int rt)
//{
//    if(l == r) return l;
//    int mid = (l + r) >> 1;
//    PushDown(l, mid, r, rt);
//    if(sto[rt << 1].ms >= x) return New(x, lson);
//    else if(sto[rt << 1].rs + sto[rt << 1 | 1].ls >= x) return mid - sto[rt << 1].rs + 1;
//    return New(x, rson);
//}
//int Free(int x, int l, int r, int rt)
//{
//    if(l == r) return rt;
//    int mid = (l + r) >> 1;
//    PushDown(l, mid, r, rt);
//    if(x <= mid) return Free(x, lson);
//    return Free(x, rson);
//}
//void CountUp(int rt)
//{
//    sto[rt].cnt = sto[rt << 1].cnt + sto[rt << 1 | 1].cnt;
//}
//void CountDown(int rt)
//{
//    if(sto[rt].cover)
//    {
//        sto[rt << 1].cnt = sto[rt << 1 | 1].cnt = 0;
//        sto[rt << 1].cover = sto[rt << 1 | 1].cover = 1;
//        sto[rt].cover = 0;
//    }
//}
//int Get(int x, int l, int r, int rt)
//{
//    if(l == r) return l;
//    int mid = (l + r) >> 1;
//    CountDown(rt);
//    if(sto[rt << 1].cnt >= x) return Get(x, lson);
//    return Get(x - sto[rt << 1].cnt, rson);
//}
//void Count(int x, int t, int l, int r, int rt)
//{
//    if(l == r)
//    {
//        sto[rt].cnt = t;
//        return ;
//    }
//    int mid = (l + r) >> 1;
//    CountDown(rt);
//    if(x <= mid) Count(x, t, lson);
//    else Count(x, t, rson);
//    CountUp(rt);
//}
//int main()
//{
//    char str[20];
//    int n, m, x, ans;
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        Reset(n); // 初始状态既是内存全部释放的状态
//        while(m --)
//        {
//            scanf("%s", str);
//            if(str[0] == 'R')
//            {
//                Reset(n);
//                puts("Reset Now");
//            }
//            else if(str[0] == 'N')
//            {
//                scanf("%d", &x);
//                if(sto[1].ms >= x)
//                {
//                    ans = New(x, 1, n, 1);
//                    printf("New at %d\n", ans);
//                    Count(ans, 1, 1, n, 1);
//                    Insert(ans, ans + x - 1, 0, 1, n, 1);
//                }
//                else puts("Reject New");
//            }
//            else if(str[0] == 'F')
//            {
//                scanf("%d", &x);
//                ans = Free(x, 1, n, 1);
//                if(sto[ans].s < 0)
//                    puts("Reject Free");
//                else
//                {
//                    printf("Free from %d to %d\n", sto[ans].s, sto[ans].t);
//                    Count(sto[ans].s, 0, 1, n, 1);
//                    Insert(sto[ans].s, sto[ans].t, 1, 1, n, 1);
//                }
//            }
//            else
//            {
//                scanf("%d", &x);
//                if(x > sto[1].cnt) puts("Reject Get");
//                else printf("Get at %d\n", Get(x, 1, n, 1));
//            }
//        }
//        puts("");
//    }
//    return 0;
//}

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

using namespace std;

const int maxn = 1e4 + 100;
bool Hash[maxn];
int li[maxn], ri[maxn];
int X[maxn * 3];
int col[maxn << 4];
int cnt, n, m;
void PushDown(int rt)
{
    if(col[rt] != -1)
    {
        col[rt << 1] = col[rt << 1 | 1] = col[rt];
        col[rt] = -1;
    }
}
void Update(int L, int R, int c, int l, int r, int rt)
{
    if(L <= l && r <= R)
    {
        col[rt] = c;
        return ;
    }
    PushDown(rt);
    int mid = (l + r) >> 1;
    if(L <= mid) Update(L, R, c, lson);
    if(mid < R) Update(L, R, c, rson);
}
void Query(int l, int r, int rt)
{
    if(col[rt] != -1)
    {
        if(!Hash[col[rt]]) cnt ++;
        Hash[col[rt]] = true;
        return ;
    }
    if(l == r) return ;
    int mid = (l + r) >> 1;
    Query(lson);
    Query(rson);
}
int Binary(int key)
{
    int l = 0, r = n - 1;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(X[mid] == key) return mid;
        if(X[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &m);
        int cur = 0;
        for(int i = 0; i < m; i ++)
        {
            scanf("%d%d", &li[i], &ri[i]);
            X[cur ++] = li[i];
            X[cur ++] = ri[i];
        }
        sort(X, X + cur);
        n = 1;
        for(int i = 1; i < cur; i ++)
            if(X[i] != X[i - 1]) X[n ++] = X[i];
        for(int i = n - 1; i >= 1; i --)
            if(X[i] != X[i - 1] + 1) X[n ++] = X[i - 1] + 1;
        sort(X, X + n);
        memset(col, -1, sizeof(col));
        for(int i = 0; i < m; i ++)
        {
            int l = Binary(li[i]);
            int r = Binary(ri[i]);
            printf("%d %d\n", l, r);
            Update(l, r, i, 0, n, 1);
        }
        cnt = 0;
        memset(Hash, false, sizeof(Hash));
        Query(0, n, 1);
        printf("%d\n", cnt);
    }
    return 0;
}

