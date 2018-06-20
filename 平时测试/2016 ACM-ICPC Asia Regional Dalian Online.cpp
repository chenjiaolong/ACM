// hdu 5877 Weak Pair: Treap(树堆) + dfs序
// 从根开始dfs,
// 用treap维护当前节点uu到根的节点权值序列,
// 然后就在treap上查询小于等于K/a[v]​​的数的个数.
// 之后把a[u]加到treap中, 退栈的时候把a[u]从treap中删除. 复杂度是nlogn的.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;

typedef long long LL;
const int maxn = 1e5 + 10;
const LL INF = 1e18 + 10;
LL a[maxn], k;
LL ans;
int N;

int head[maxn], e;
struct node
{
    int v;
    int next;
}edge[maxn << 1];
int depth[maxn];

struct Node
{
    int l, r;
    int size;// 区间大小
    int rnd; // 优先级
    int w;
    LL v;
}Treap[maxn];
int root, size;

inline void AddEdge(int u, int v)
{
    edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e ++;
}
void update(int k)
{
    Treap[k].size = Treap[Treap[k].l].size + Treap[Treap[k].r].size + Treap[k].w;
}
void lturn(int &k)
{
    int t = Treap[k].r;
    Treap[k].r = Treap[t].l;

    Treap[t].l = k;
    Treap[t].size = Treap[k].size;

    update(k);
    k = t;
}
void rturn(int &k)
{
    int t = Treap[k].l;
    Treap[k].l = Treap[t].r;

    Treap[t].r = k;
    Treap[t].size = Treap[k].size;

    update(k);
    k = t;
}
void insert(int &k, LL x)
{
    if(k == 0)
    {
       size ++, k = size;
       Treap[k].size = Treap[k].w = 1;
       Treap[k].v = x;
       Treap[k].rnd = rand();
       return ;
    }
    Treap[k].size ++;
    if(Treap[k].v == x) Treap[k].w ++;// 每个结点顺便记录下与该节点相同值的数的个数
    else if(x > Treap[k].v)
    {
        insert(Treap[k].r, x);
        if(Treap[Treap[k].r].rnd < Treap[k].rnd) lturn(k);// 维护堆性质
    }
    else
    {
        insert(Treap[k].l, x);
        if(Treap[Treap[k].l].rnd < Treap[k].rnd) rturn(k);
    }
}
void del(int &k, LL x)
{
    if(k == 0) return ;
    if(Treap[k].v == x)
    {
        if(Treap[k].w > 1)
        {
            Treap[k].w --;
            Treap[k].size --;// 若不止相同值的个数有多个，删去一个
            return ;
        }
        if(Treap[k].l * Treap[k].r == 0) k = Treap[k].l + Treap[k].r;// 有一个儿子为空
        else if(Treap[Treap[k].l].rnd < Treap[Treap[k].r].rnd) rturn(k), del(k, x);
        else lturn(k), del(k, x);
    }
    else if(x > Treap[k].v)
        Treap[k].size --, del(Treap[k].r, x);
    else Treap[k].size --, del(Treap[k].l, x);
}
int query_rank(int k, LL x)
{
    if(k == 0) return 0;
    if(Treap[k].v == x) return Treap[Treap[k].l].size + Treap[k].w;
    else if(x > Treap[k].v) return Treap[Treap[k].l].size + Treap[k].w + query_rank(Treap[k].r, x);
    return query_rank(Treap[k].l, x);
}
void DFS(int u, int fa)
{
    LL limit = INF;
    if(a[u]) limit = k / (a[u]);
    ans += query_rank(root, limit);
    insert(root, a[u]);
    for(int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v == fa) continue;
        DFS(v, u);
    }
    del(root, a[u]);
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(head, -1, sizeof(head));
        e = 0;
        root = 0;
        size = 0;
        for(int i = 1; i < maxn; ++i)
        {
            Treap[i].l = 0;
            Treap[i].r = 0;
            depth[i] = 0;
        }
        scanf("%d%I64d", &N, &k);
        for(int i = 1; i <= N; ++i) scanf("%I64d", &a[i]);
        int u, v;
        for(int i = 1; i < N; ++ i)
        {
            scanf("%d%d", &u, &v);
            AddEdge(u, v);
            AddEdge(v, u);
            depth[v]++;
        }
        int rt;
        for(int i = 1; i <= N; ++ i )
            if(!depth[i]) rt = i;
        ans = 0;
        DFS(rt, 0);
        printf("%I64d\n", ans);
    }
    return 0;
}

/*5
8 250
11 16 31 9 18 14 22 15
1 2
2 3
2 4
1 5
5 6
6 7
6 8
8 25
1 6 3 9 8 4 2 5
1 2
2 3
2 4
1 5
5 6
6 7
6 8
11 25
1 6 3 9 8 4 2 5 6 7 2
1 2
2 3
2 4
1 5
5 6
6 7
6 8
8 9
8 10
9 11
11 18
1 6 3 9 8 4 2 5 6 7 2
1 2
2 3
2 4
1 5
5 6
6 7
6 8
8 9
8 10
9 11
6 6
6 0 4 6 6 6
1 2
2 3
3 4
4 5
5 6*/


