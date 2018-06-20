// XOR and Favorite Number
// http://codeforces.com/problemset/problem/617/E
#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 7;
const int maxm = 1 << 20;

int a[maxn];
long long flag[maxm]; // 每个前缀值出现的次数
long long ans[maxn];
int pos[maxn];

int L = 1, R = 0;
long long res = 0;
int k;

struct node
{
    int l, r;
    int id;
}Q[maxn];

bool cmp(node a, node b)
{
    if(pos[a.l] == pos[b.l])
        return a.r < b.r;
    return pos[a.l] < pos[b.l];
}
void Add(int x)
{
    res += flag[a[x] ^ k];
    flag[a[x]]++;
}
void Del(int x)
{
    flag[a[x]]--;
    res -= flag[a[x] ^ k];
}

int main()
{
    int n, m;
    while(scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        int sz = sqrt(n);
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i]);
            a[i] ^= a[i - 1];
            pos[i] = i / sz;
        }
        for(int i = 1; i <= m; i ++)
        {
            scanf("%d%d", &Q[i].l, &Q[i].r);
            Q[i].id = i;
        }
        sort(Q + 1, Q + m + 1, cmp);
        flag[0] = 1;
        for(int i = 1; i <= m; i ++)
        {
            while(L < Q[i].l)
            {
                Del(L - 1);
                L++;
            }
            while(L > Q[i].l)
            {
                L --;
                Add(L - 1);
            }
            while(R < Q[i].r)
            {
                R ++;
                Add(R);
            }
            while(R > Q[i].r)
            {
                Del(R);
                R --;
            }
            ans[Q[i].id] = res;
        }
        for(int i = 1; i <= m; i ++)
        printf("%lld\n", ans[i]);
    }
    return 0;
}
