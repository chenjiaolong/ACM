// HDU 3966 Aragorn's Story 树链剖分模板
//#include<vector>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//#define lson l, mid, rt << 1
//#define rson mid + 1, r, rt << 1 | 1
//
//#pragma comment(linker, "/STACK:1024000000", 1024000000)
//
//using namespace std;
//
//const int maxn = 5e4 + 100;
//
//int tim; // 时间戳
//
//int num[maxn]; // 树上每个节点的初始值
//int size[maxn]; // size[u]表示以u为根的节点的子树的节点数
//int depth[maxn];
//int father[maxn];
//int top[maxn]; //树链上深度最小的点，
//int son[maxn];
//int tid[maxn];// 节点的时间戳
//int rank[maxn];// rank[i] = j;表示时间戳为i的节点是j
//bool vis[maxn];
//vector<int> edge[maxn];
//
//struct node
//{
//    int l, r;
//    int val, lazy;
//} sto[maxn << 2];
//
//void Init(int n)
//{
//    for(int i = 1; i <= n; i ++)
//    {
//        size[i] = 0, son[i] = 0, depth[i] = 0, father[i] = 0;
//        tid[i] = 0, top[i] = 0, rank[i] = 0;
//        vis[i] = false;
//        tim = 0;
//        edge[i].clear();
//    }
//}
//// 无根树加双向边
//void AddEdge(int u, int v)
//{
//    edge[u].push_back(v);
//    edge[v].push_back(u);
//}
//// 树链剖分
//void Record_Heavy_Edge(int u, int pre)
//{
//    vis[u] = true;
//    depth[u] = depth[pre] + 1;// 注意根节点比较特殊
//    father[u] = pre;
//    size[u] = 1;
//    int sz = edge[u].size();
//    for(int i = 0; i < sz; i ++)
//    {
//        int v = edge[u][i];
//        if(v == father[u] || vis[v]) continue;
//        Record_Heavy_Edge(v, u);
//        size[u] += size[v];
//        if(son[u] == 0 || size[v] > size[son[u]]) son[u] = v;
//
//    }
//
//}
//void Heavy_Chain(int u, int tp)
//{
//    vis[u] = true;
//    top[u] = tp;
//    tid[u] = ++tim;
//    rank[tim] = u;
//    if(son[u] == 0) return ;
//    //同一条重链的顶部相同
//    Heavy_Chain(son[u], tp);
//    int sz = edge[u].size();
//    for(int i = 0; i < sz; i ++)
//    {
//        int v = edge[u][i];
//        // 注意去掉重儿子
//        if(son[u] != v && v != father[u] && !vis[v]) Heavy_Chain(v, v);
//    }
//}
//
//
//// 线段树
//void PushDown(int rt)
//{
//    if(sto[rt].lazy)
//    {
//        sto[rt << 1].val += sto[rt].lazy;
//        sto[rt << 1 | 1].val += sto[rt].lazy;
//        sto[rt << 1].lazy += sto[rt].lazy;
//        sto[rt << 1 | 1].lazy += sto[rt].lazy;
//        sto[rt].lazy = 0;
//    }
//}
//void BuildTree(int l, int r, int rt)
//{
//    sto[rt].l = l, sto[rt].r = r, sto[rt].val = 0, sto[rt].lazy = 0;
//    if(l == r)
//    {
//        sto[rt].val = num[rank[l]];
//        return ;
//    }
//
//    int mid = (l + r) >> 1;
//    BuildTree(lson);
//    BuildTree(rson);
//}
//
//void update(int l, int r, int rt, int value)
//{
//    if(sto[rt].l == l && sto[rt].r == r)
//    {
//        sto[rt].val += value;
//        sto[rt].lazy += value;
//        return ;
//    }
//    PushDown(rt);
//    int mid = (sto[rt].l + sto[rt].r) >> 1;
//    if(r <= mid) update(l, r, rt << 1, value);
//    else if(l > mid) update(l, r, rt << 1 | 1, value);
//    else
//    {
//        update(lson, value);
//        update(rson, value);
//    }
//}
//
//void change(int x, int y, int value)
//{
//    while(top[x] != top[y])
//    {
//        if(depth[top[x]] < depth[top[y]]) swap(x, y);
//        update(tid[top[x]], tid[x], 1,  value);// Heavy_Chain时顶部先访问，所以tid[top[]] 较小
//        x = father[top[x]];// 因为top[x] -> x路径上的所有点已经被更新了
//    }
//    if(depth[x] > depth[y]) swap(x, y);
//    update(tid[x], tid[y], 1, value);
//}
//int query(int p, int rt)
//{
//    if(sto[rt].l == sto[rt].r)
//        return sto[rt].val;
//    PushDown(rt);
//    int mid = (sto[rt].l + sto[rt].r) >> 1;
//    if(p <= mid) return query(p, rt << 1);
//    return query(p, rt << 1 | 1);
//}
//int main()
//{
//    int n, m, q;
//    while(scanf("%d%d%d", &n, &m, &q) != EOF)
//    {
//        Init(n);
//        for(int i = 1; i <= n; i ++)
//            scanf("%d", &num[i]);
//        int u, v;
//        for(int i = 1; i <= m; i ++)
//        {
//            scanf("%d%d", &u, &v);
//            AddEdge(u, v);
//        }
//        Record_Heavy_Edge(1, 0);
//        memset(vis, false, sizeof(vis));
//        Heavy_Chain(1, 1);
//        BuildTree(1, n, 1);
//
//        char oper[5];
//        int x, y, value;
//        while(q --)
//        {
//            scanf("%s", oper);
//            if(oper[0] == 'Q')
//            {
//                scanf("%d", &x);
//                printf("%d\n", query(tid[x], 1));
//            }
//            else
//            {
//                scanf("%d%d%d", &x, &y, &value);
//                if(oper[0] == 'I') change(x, y, value);
//                else change(x, y, -value);
//            }
//        }
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//#define lson l, mid, rt << 1
//#define rson mid + 1, r, rt << 1 | 1
//
//#pragma comment(linker, "/STACK:1024000000", 1024000000)
//
//using namespace std;
//
//const int maxn = 5e4 + 100;
//
//int tim;
//
//int num[maxn], size[maxn], top[maxn], son[maxn];
//int depth[maxn], tid[maxn], rank[maxn], father[maxn];
//
//int head[maxn], e;
//struct node
//{
//    int v;
//    int c;
//    int next;
//}edge[maxn << 1];
//
//struct Node
//{
//    int l, r;
//    int maxv, lazy;
//}sto[maxn << 2];
//
//void Init()
//{
//    memset(head, -1, sizeof(head));
//    memset(son, -1, sizeof(son));
//
//    tim = 0;
//    e = 0;
//}
//void AddEdge(int u, int v)
//{
//    edge[e].v = v;
//    edge[e].next = head[u];
//    head[u] = e ++;
//}
//
//// 树链剖分
//void Record_Heavy_Son(int u, int pa, int dep)
//{
//    depth[u] = dep;
//    father[u] = pa;
//    size[u] = 1;
//    for(int i = head[u]; ~i; i = edge[i].next)
//    {
//        int v = edge[i].v;
//        if(v != pa)
//        {
//            Record_Heavy_Son(v, u, dep + 1);
//            size[u] += size[v];
//            if(son[u] == -1 || size[v] > size[son[u]])
//                son[u] = v;
//        }
//    }
//}
//void Heavy_Chain(int u, int tp)
//{
//    top[u] = tp;
//    tid[u] = ++tim;
//    rank[tid[u]] = u;
//    if(son[u] == -1) return ;
//        Heavy_Chain(son[u], tp);
//    for(int i = head[u]; ~i; i = edge[i].next)
//    {
//        int v = edge[i].v;
//        if(v != son[u] && v != father[u])
//            Heavy_Chain(v, v);
//    }
//}
//
//// 线段树
//void PushUp(int rt)
//{
//    sto[rt].maxv = max(sto[rt << 1].maxv, sto[rt << 1 | 1].maxv);
//}
//
//void PushDown(int rt, int cnt)
//{
//    if(sto[rt].lazy)
//    {
//        sto[rt << 1].lazy += sto[rt].lazy;
//        sto[rt << 1 | 1].lazy += sto[rt].lazy;
//        sto[rt << 1].maxv += (cnt - (cnt >> 1)) * sto[rt].lazy;
//        sto[rt << 1 | 1].maxv += (cnt >> 1) * sto[rt].lazy;
//        sto[rt].lazy = 0;
//    }
//}
//void BuildTree(int l, int r, int rt)
//{
//    sto[rt].lazy = 0;
//    sto[rt].l = l, sto[rt].r = r;
//    if(l == r)
//    {
//        sto[rt].maxv = num[rank[l]];
//        return ;
//    }
//    int mid = (l + r) >> 1;
//    BuildTree(lson);
//    BuildTree(rson);
//    PushUp(rt);
//}
//
//void update(int l, int r, int rt, int value)
//{
//    if(sto[rt].l == l && sto[rt].r == r)
//    {
//        sto[rt].lazy += value;
//        sto[rt].maxv += (r - l + 1) * value;
//        return;
//    }
//    PushDown(rt, sto[rt].r - sto[rt].l + 1);
//    int mid = (sto[rt].l + sto[rt].r) >> 1;
//    if(r <= mid) update(l, r, rt << 1, value);
//    else if(l > mid) update(l, r, rt << 1 | 1, value);
//    else
//    {
//        update(lson, value);
//        update(rson, value);
//    }
//    PushUp(rt);
//}
//void Change(int x, int y, int value)
//{
//    while(top[x] != top[y])
//    {
//        if(depth[top[x]] < depth[top[y]]) swap(x, y);
//        update(tid[top[x]], tid[x], 1, value);
//        x = father[top[x]];
//    }
//    if(depth[x] > depth[y]) swap(x, y);
//    update(tid[x], tid[y], 1, value);
//}
//int query(int p, int rt)
//{
//    if(sto[rt].l == sto[rt].r)
//        return sto[rt].maxv;
//    PushDown(rt, sto[rt].r - sto[rt].l + 1);
//    int mid = (sto[rt].l + sto[rt].r) >> 1;
//    int res = 0;
//    if(p <= mid) res = query(p, rt << 1);
//    else res = query(p, rt << 1 | 1);
//    PushUp(rt);
//    return res;
//}
//int main()
//{
//    int n, m, q;
//    while(scanf("%d%d%d", &n, &m, &q) != EOF)
//    {
//        Init();
//        for(int i = 1; i <= n; i ++)
//            scanf("%d", &num[i]);
//        int u, v;
//        for(int i = 1; i <= m; i ++)
//        {
//            scanf("%d%d", &u, &v);
//            AddEdge(u, v);
//            AddEdge(v, u);
//        }
//        Record_Heavy_Son(1, 0, 0);
//        Heavy_Chain(1, 1);
//        BuildTree(1, n, 1);
//        char oper[5];
//        int x, y, value;
//        while(q --)
//        {
//            scanf("%s", oper);
//            if(oper[0] == 'Q')
//            {
//                scanf("%d", &x);
//                printf("%d\n", query(tid[x], 1));
//            }
//            else
//            {
//                scanf("%d%d%d", &x, &y, &value);
//                if(oper[0] == 'I') Change(x, y, value);
//                else Change(x, y, -value);
//
//            }
//        }
//    }
//    return 0;
//}

//#include<cstdio>
//#include<cstdlib>
//#include<cstring>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int maxn=50010;
//const int inf=1<<30;
//int n,tim;
//
//int num[maxn],siz[maxn],top[maxn],son[maxn];
//int dep[maxn],tid[maxn],ran[maxn],fa[maxn];
//int head[maxn],to[maxn<<1],nxt[maxn<<1],w[maxn<<1],edge;
//
//struct Edge
//{
//    int u,v,c;
//};
//Edge tmp[maxn<<1];
//
//void init()
//{
//    memset(head,-1,sizeof(head));
//    memset(son,-1,sizeof(son));
//
//    tim=0;
//    edge=0;
//}
//
//void addedge(int u,int v,int c)
//{
//    to[edge]=v;
//    w[edge]=c;
//    nxt[edge]=head[u];
//    head[u]=edge++;
//    to[edge]=u;
//    w[edge]=c;
//    nxt[edge]=head[v];
//    head[v]=edge++;
//}
//
////树链剖分
//void dfs1(int u,int father,int d)
//{
//    dep[u]=d;
//    fa[u]=father;
//    siz[u]=1;
//    for(int i=head[u]; i!=-1; i=nxt[i])
//    {
//        int v=to[i];
//        if(v!=father)
//        {
//            dfs1(v,u,d+1);
//            siz[u]+=siz[v];
//            if(son[u]==-1||siz[v]>siz[son[u]]) son[u]=v;
//        }
//    }
//}
//void dfs2(int u,int tp)
//{
//    top[u]=tp;
//    tid[u]=++tim;
//    ran[tid[u]]=u;
//    if(son[u]==-1) return;
//    dfs2(son[u],tp);
//    for(int i=head[u]; i!=-1; i=nxt[i])
//    {
//        int v=to[i];
//        if(v!=son[u]&&v!=fa[u]) dfs2(v,v);
//    }
//}
//
////线段树
//#define lson l,mid,rt<<1
//#define rson mid+1,r,rt<<1|1
//
//int Max[maxn<<2];
//
//void pushup(int rt)
//{
//    Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
//}
//void build(int l,int r,int rt)
//{
//    if(l==r)
//    {
//        Max[rt]=num[l];
//        return;
//    }
//    int mid=(l+r)>>1;
//    build(lson);
//    build(rson);
//    pushup(rt);
//}
//void update(int l,int r,int rt,int p,int val)
//{
//    if(l==r)
//    {
//        Max[rt]=val;
//        return;
//    }
//    int mid=(l+r)>>1;
//    if(p<=mid)
//        update(lson,p,val);
//    else
//        update(rson,p,val);
//    pushup(rt);
//}
//
//int Query(int l,int r,int rt,int L,int R)
//{
//    if(L<=l&&R>=r)
//        return Max[rt];
//    int mid=(l+r)>>1;
//    int ret=-inf;
//    if(L<=mid)
//        ret=max(ret,Query(lson,L,R));
//    if(R>mid)
//        ret=max(ret,Query(rson,L,R));
//
//    return ret;
//}
//void change(int x,int val)
//{
//    if(dep[tmp[x].u]>dep[tmp[x].v]) update(2,n,1,tid[tmp[x].u],val);
//    else update(2,n,1,tid[tmp[x].v],val);
//}
//
//int query(int x,int y)
//{
//    int ans=-inf;
//    while(top[x]!=top[y])
//    {
//        if(dep[top[x]]<dep[top[y]])swap(x,y);
//        ans=max(ans,Query(2,n,1,tid[top[x]],tid[x]));
//        x=fa[top[x]];
//    }
//    if(dep[x]>dep[y])swap(x,y);
//    if(x!=y)ans=max(ans,Query(2,n,1,tid[x]+1,tid[y]));
//    return ans;
//}
//int main()
//{
//    char oper[15];
//    int a,b,c,t;
//    scanf("%d",&t);
//    while(t--)
//    {
//        init();
//        scanf("%d",&n);
//        for(int i=1; i<n; i++)
//        {
//            scanf("%d%d%d",&a,&b,&c);
//            tmp[i].u=a,tmp[i].v=b;
//            tmp[i].c=c;
//            addedge(a,b,c);
//        }
//        dfs1(1,1,1);
//        // for(int i = 1; i <= n; i ++)
//            // printf("size[%d] = %d ", i, siz[i]);
//        // puts("");
//        // for(int i = 1; i <= n; i ++)
//            // printf("father[%d] = %d ", i, fa[i]);
//        // puts("");
//        // for(int i = 1; i <= n; i ++)
//            // printf("depth[%d] = %d ", i, dep[i]);
//        // puts("");
//        // for(int i = 1; i <= n; i ++)
//            // printf("son[%d] = %d ", i, son[i]);
//        // puts("");
//        dfs2(1,1);
//        // puts("");
//        // for(int i = 1; i <= n; i ++)
//            // printf("top[%d] = %d ", i, top[i]);
//        // puts("");
//        // for(int i = 1; i <= n; i ++)
//            // printf("tid[%d] = %d ", i, tid[i]);
//        // puts("");
//        // for(int i = 1; i <= n; i ++)
//            // printf("rank[%d] = %d ", i, ran[i]);
//        // puts("");
//        //用边的孩子节点来表示该边
//        for(int i=1; i<n; i++)
//        {
//            if(dep[tmp[i].u]>dep[tmp[i].v]) num[tid[tmp[i].u]]=tmp[i].c;
//            else num[tid[tmp[i].v]]=tmp[i].c;
//        }
//        // puts("");
//        // for(int i = 1; i <= n; i ++)
//            // printf("num[%d] = %d ", i, num[i]);
//        // puts("");
//        build(2,n,1);
//        while(1)
//        {
//            scanf("%s",oper);
//            if(oper[0]=='D')
//                break;
//            scanf("%d%d",&a,&b);
//            if(oper[0]=='Q') printf("%d\n",query(a,b));
//            else change(a,b);
//        }
//    }
//    return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

#pragma comment(linker, "/STACK:1024000000", 1024000000)

using namespace std;

const int maxn = 5e4 + 100;
const int inf = 1 << 30;

int tim;

int num[maxn], size[maxn], depth[maxn], father[maxn], top[maxn], son[maxn], tid[maxn], rank[maxn];

int head[maxn], to[maxn << 1], cost[maxn << 1], next[maxn << 1];
struct node
{
    int u;
    int v;
    int c;
}edge[maxn << 1];
int e;

struct Node
{
    int l, r;
    int maxv;
}sto[maxn << 2];

void Init()
{
    memset(head, -1, sizeof(head));
    memset(son, -1, sizeof(son));

    tim = 0;
    e = 0;
}

void AddEdge(int u, int v, int c)
{
    to[e] = v;
    cost[e] = c;
    next[e] = head[u];
    head[u] = e ++;
}

// 树链剖分
void Record_Heavy_Edge(int u, int pa, int dep)
{
    depth[u] = dep;
    father[u] = pa;
    size[u] = 1;
    for(int i = head[u]; ~i; i = next[i])
    {
        int v = to[i];
        if(v == pa) continue;
        Record_Heavy_Edge(v, u, dep + 1);
        size[u] += size[v];
        if(son[u] == -1 || size[v] > size[son[u]]) son[u] = v;

    }

}
void Heavy_Chain(int u, int tp)
{
    top[u] = tp;
    tid[u] = ++tim;
    rank[tid[u]] = u;
    if(son[u] == -1) return ;
    Heavy_Chain(son[u], tp);
    for(int i = head[u]; ~i; i = next[i])
    {
        int v = to[i];
        if(son[u] == v || v == father[u]) continue;
        Heavy_Chain(v, v);
    }
}

// 线段树
void PushUp(int rt)
{
    sto[rt].maxv = max(sto[rt << 1].maxv, sto[rt << 1 | 1].maxv);
}

void BuildTree(int l, int r, int rt)
{
    sto[rt].l = l, sto[rt].r = r;
    if(l == r)
    {
        sto[rt].maxv = num[l];
        return ;
    }
    int mid = (l + r) >> 1;
    BuildTree(lson);
    BuildTree(rson);
    PushUp(rt);
}
void update(int p, int val, int rt)
{
    if(sto[rt].l == sto[rt].r)
    {
        sto[rt].maxv = val;
        return ;
    }
    int mid = (sto[rt].l + sto[rt].r) >> 1;
    if(p <= mid) update(p, val, rt << 1);
    else update(p, val, rt << 1 | 1);
    PushUp(rt);
}
void change(int x, int value)
{
    if(depth[edge[x].u] > depth[edge[x].v])
        update(tid[edge[x].u], value, 1);
    else update(tid[edge[x].v], value, 1);
}
int query(int l, int r, int rt)
{
    if(sto[rt].l == l && sto[rt].r == r)
        return sto[rt].maxv;
    int mid = (sto[rt].l + sto[rt].r) >> 1;
    int res = -inf;
    if(r <= mid) res = max(res, query(l, r, rt << 1));
    else if(l > mid) res = max(res, query(l, r, rt << 1 | 1));
    else
    {
        res = max(res, query(lson));
        res = max(res, query(rson));
    }
    return res;
}
int Query(int x, int y)
{
    int ans = -inf;
    while(top[x] != top[y])
    {
        if(depth[top[x]] < depth[top[y]]) swap(x, y);
        ans = max(ans, query(tid[top[x]], tid[x], 1));
        x = father[top[x]];
    }
    if(depth[x] > depth[y]) swap(x, y);
    if(x != y) ans = max(ans, query(tid[x] + 1, tid[y], 1));
    return ans;
}
int main()
{
    int t;
    int n;
    scanf("%d", &t);
    while(t --)
    {
        Init();
        scanf("%d", &n);
        int u, v, c;
        for(int i = 1; i < n; i ++)
        {
            scanf("%d%d%d", &u, &v, &c);
            edge[i].u = u,edge[i].v = v, edge[i].c = c;
            AddEdge(u, v, c);
            AddEdge(v, u, c);
        }
        char oper[5];
        Record_Heavy_Edge(1, 1, 1);
        Heavy_Chain(1, 1);

        for(int i = 1; i < n; i ++)
        {
            if(depth[edge[i].u] > depth[edge[i].v])
                num[tid[edge[i].u]] = edge[i].c;
            else num[tid[edge[i].v]] = edge[i].c;
        }
        BuildTree(2, n, 1);
        int x, y;
        while(scanf("%s", oper), oper[0] != 'D')
        {
            scanf("%d%d", &x, &y);
            if(oper[0] == 'Q') printf("%d\n", Query(x, y));
            else change(x, y);
        }
    }
    return 0;
}


