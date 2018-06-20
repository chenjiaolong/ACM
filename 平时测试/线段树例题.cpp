#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100005;
#define f first
#define s second
typedef __int64 ll;
int n, a[N];
ll dp[N];

struct SegTree
{
    inline int get_id(int l, int r)
    {
        return (l + r) | (l != r);
    }
    pair<int, int> x[N << 1];

    void build(int l, int r)
    {
        int rt = get_id(l, r);
        if(l == r)
        {
            x[rt].f = a[l];
            x[rt].second = l;
//			printf("l %d r %d rt %d f %d s %d\n", l, r, rt, x[rt].f, x[rt].s);
            return;
        }
        int mid = l + r >> 1;
        build(l, mid);
        build(mid + 1, r);
        up(l, r);
    }

    void up(int l, int r)
    {
        int mid = l + r >> 1;
        int rt = get_id(l, r);
        int lrt = get_id(l, mid), rrt = get_id(mid + 1, r);
        if(x[lrt].f >= x[rrt].f) x[rt] = x[lrt];
        else x[rt] = x[rrt];
//		printf("l %d r %d rt %d f %d s %d\n", l, r, rt, x[rt].f, x[rt].s);
    }

    pair<int, int> query(int L, int R, int l, int r)
    {
        int rt = get_id(l, r);
        if(L <= l && r <= R) return x[rt];
        int mid = l + r >> 1;
        pair<int, int> ans = make_pair(-1, 0);
        if(L <= mid) ans = max(ans, query(L, R, l, mid));
        if(R > mid) ans = max(ans, query(L, R, mid + 1, r));
        return ans;
    }

} st;

int main(void)
{
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n - 1; i ++)
        {
            scanf("%d", &a[i]);
            a[i] --;
        }
        a[n - 1] = n - 1;
        st.build(0, n - 1);
        dp[n - 1] = 0;
        ll sum = 0;
        for(int i = n - 2; i >= 0; i --)
        {
            int m = st.query(i + 1, a[i], 0, n - 1).s;
//			printf("m %d\n", m);
            dp[i] = dp[m] - (a[i] - m) + n - i - 1;
            sum += dp[i];
        }
        printf("%I64d\n", sum);
    }
    return 0;
}
