// CSU 1809 Parenthesis
// 思路：括号的题目有一种经典的套路就是遇到(加一，遇到)减一，
// 这样整个序列最后的前缀和一定是非负的，
// 同样的这里贪心一下就会发现只有把( 和 )交换的时候才会出问题，
// 那么可以用一个线段树或者RMQ维护区间最小值，
// 然后如果交换之后(a,b-1)这个区间有前缀和<2的话那么就是No
// 线段树 + 前缀和
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//#define lson l, mid, rt << 1
//#define rson mid + 1, r, rt << 1 | 1
//
//using namespace std;
//
//const int inf = 1e9;
//const int maxn = 1e5 + 100;
//char str[maxn];
//int left[maxn];
//struct node
//{
//    int l, r;
//    int mini;
//} sto[maxn << 2];
//
//void PushUp(int rt)
//{
//    sto[rt].mini = min(sto[rt << 1].mini, sto[rt << 1 | 1].mini);
//}
//
//void BuildTree(int l, int r, int rt)
//{
//    sto[rt].l = l, sto[rt].r = r;
//    if(l == r)
//    {
//        sto[rt].mini = left[l];
//        return ;
//    }
//    int mid = (l + r) >> 1;
//    BuildTree(lson);
//    BuildTree(rson);
//    PushUp(rt);
//}
//void query(int l, int r, int rt, int &min1)
//{
//    if(sto[rt].l == l && sto[rt].r == r)
//    {
//        min1 = sto[rt].mini;
//        return ;
//    }
//    int mid = (sto[rt].l + sto[rt].r) >> 1;
//    if(l > mid) query(l, r, rt << 1 | 1, min1);
//    else if(mid >= r) query(l, r, rt << 1, min1);
//    else
//    {
//        int min2;
//        query(lson, min1);
//        query(rson, min2);
//        min1 = min(min1, min2);
//    }
//}
//int main()
//{
//    int n, q;
//    while(scanf("%d%d", &n, &q) != EOF)
//    {
//        scanf("%s", str + 1);
//        int cnt = 0;
//        for(int i = 1; i <= n; i ++)
//        {
//            if(str[i] == '(') left[i] = ++ cnt;
//            else left[i] = --cnt;
//        }
//        BuildTree(1, n, 1);
//        int l, r;
//        for(int i = 1; i <= q; i ++)
//        {
//            scanf("%d%d", &l, &r);
//            if(l > r) swap(l, r);
//            if(str[l] == str[r])
//            {
//                puts("Yes");
//                continue;
//            }
//            if(str[l] == ')' && str[r] == '(')
//            {
//                puts("Yes");
//                continue;
//            }
//            int min1 = inf;
//            query(l, r - 1, 1, min1);
//            if(min1 < 2) puts("No");
//            else puts("Yes");
//        }
//    }
//    return 0;
//}

// RMQ
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//const int maxn = 1e5 + 100;
//int Min[maxn][20];
//int lg[maxn];
//char str[maxn];
//
//void RMQ(int n)
//{
//    for(int j = 1; (1 << j) <= n; j ++)
//        for(int i = 1; i <= n; i ++)
//        {
//            if(i + (1 << j - 1) > n) break;
//            Min[i][j] = min(Min[i][j - 1], Min[i + (1 << j - 1)][j - 1]);
//        }
//}
//int main()
//{
//    int n, q;
//    while(scanf("%d%d", &n, &q) != EOF)
//    {
//        scanf("%s", str + 1);
//        int x = 0;
//        lg[0] = -1;
//        for(int i = 1; i <= n; i ++)
//        {
//            x += str[i] == '(' ? 1 : -1;
//            Min[i][0] = x;
//            lg[i] = lg[i / 2] + 1;
//        }
//        RMQ(n);
//        int l, r;
//        int k;
//        while(q--)
//        {
//            scanf("%d%d", &l, &r);
//            if(l > r) swap(l, r);
//            if(str[l] == str[r] || str[l] == ')' && str[r] == '(')
//            {
//                puts("Yes");
//                continue;
//            }
//            r = r - 1;
//            k = lg[r - l + 1];
//            if(min(Min[l][k], Min[r - (1 << k) + 1][k]) < 2) puts("No");
//            else puts("Yes");
//        }
//    }
//    return 0;
//}

// 12 12
// (((()))(()))
// 4 10
// 4 7

/**
 * RMQ
 */
#include <ctime>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// #define FIN             freopen("input.txt","r",stdin)
#define lson            l, mid, (rt << 1)
#define rson            mid + 1, r, (rt << 1 | 1)
#define _mid_           int mid = (l + r) >> 1
#define ONLINE_JUDGE
typedef long long LL;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int N, Q;
char buf[MAXN];
int pre[MAXN];
int dp[MAXN][20];
int mm[MAXN];
void initRMQ(int n, int b[])
{
    mm[0] = -1;
    for(int i = 1; i <= n; i++)
    {
        mm[i] = ((i & (i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
        dp[i][0] = b[i];
    }
    for(int i = 1; i <= n; i ++) printf("%d%c", mm[i], i == n ? '\n' : ' ');
    for(int j = 1; j <= mm[n]; j++)
        for(int i = 1; i + (1 << j) - 1 <= n; i++)
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
}
int rmq(int x, int y)
{
    int k = mm[y - x + 1];
    return min(dp[x][k], dp[y - (1 << k) + 1][k]);
}
int main()
{
#ifndef ONLINE_JUDGE
    FIN;
#endif // ONLINE_JUDGE
    int a, b;
    while(~scanf("%d %d", &N, &Q))
    {
        scanf("%s", buf + 1);
        pre[0] = 0;
        for (int i = 1; i <= N; i++)
        {
            if(buf[i] == '(') pre[i] = pre[i - 1] + 1;
            else pre[i] = pre[i - 1] - 1;
        }
        initRMQ(N, pre);
        while(Q --)
        {
            scanf("%d %d", &a, &b);
            if(a > b) swap(a, b);
            if(buf[a] == buf[b] || (buf[a] == ')' && buf[b] == '('))
            {
                printf("Yes\n");
            }
            else
            {
                int mi = rmq(a, b - 1);
                if(mi < 2) printf("No\n");
                else printf("Yes\n");
            }
        }
    }
    return 0;
}
