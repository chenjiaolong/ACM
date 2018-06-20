// hdu 2856 How far away ？
// LCA在线算法ST(Sparse Table)算法
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//// #pragma comment(linker, "/STACK:102400000, 102400000")
//
//using namespace std;
//
//const int maxn = 4e4 + 100;
//const int maxm = 25;
//int dp[maxn << 1][maxm]; // 这个数组记得开到 2 * maxn, 因为遍历后序列长度为 2 * maxn - 1
//bool vis[maxn];
//int tot, head[maxn], e;
//struct node
//{
//    int u, v, w;
//    int next;
//} edge[maxn << 1];
//
//inline void AddEdge(int u, int v, int w)
//{
//    edge[e].u = u;
//    edge[e].v = v;
//    edge[e].w = w;
//    edge[e].next = head[u];
//    head[u] = e ++;
//}
//// ver:节点编号 R:深度first : 点编号的位置 dist：距离
//int ver[maxn << 1], R[maxn << 1], first[maxn], dist[maxn];
//void DFS(int u, int depth)
//{
//    vis[u] = true;
//    ver[++tot] = u;
//    first[u] = tot;
//    R[tot] = depth;
//    for(int i = head[u]; ~i; i = edge[i].next)
//    {
//        int v = edge[i].v;
//        if(!vis[v])
//        {
//            int w = edge[i].w;
//            dist[v] = dist[u] + w;
//            DFS(v, depth + 1);
//            ver[++tot] = u;
//            R[tot] = depth;
//        }
//    }
//}
//
//void ST(int n)
//{
//    for(int i = 1; i <= n; i ++)
//        dp[i][0] = i;
//    for(int j = 1; (1 << j) <= n; j ++)
//        for(int i = 1; i + (1 << j) - 1 <= n; i ++)
//        {
//            int a = dp[i][j - 1], b = dp[i + 1 << j - 1][j - 1];
//            dp[i][j] = R[a] < R[b] ? a : b;
//        }
//
//}
//// 中间部分是交叉的
//int RMQ(int l, int r)
//{
//    int k = 0;
//    while((1 << (k + 1)) <= r - l + 1)
//        k ++;
//    int a = dp[l][k], b = dp[r - (1 << k) + 1][k];
//    return R[a] < R[b] ? a : b;
//}
//int LCA(int u, int v)
//{
//    int x = first[u], y = first[v];
//    if(x > y) swap(x, y);
//    int res = RMQ(x, y);
//    return ver[res];
//}
//int main()
//{
//    int T;
//    scanf("%d", &T);
//    int n, q;
//    while(T--)
//    {
//        e = 0;
//        scanf("%d%d", &n, &q);
//        for(int i = 0; i < maxn; i ++)
//        {
//            head[i] = -1;
//            vis[i] = false;
//        }
//        int u, v, w;
//        for(int i = 1; i < n; i ++)
//        {
//            scanf("%d%d%d", &u, &v, &w);
//            AddEdge(u, v, w);
//            AddEdge(v, u, w);
//        }
//        tot = 0;
//        dist[1] = 0;
//        DFS(1, 1);
////        puts("节点 ver ");
////        for(int i = 1; i <= 2 * n - 1; i ++)
////            printf("%d%c", ver[i], i == 2 * n - 1 ? '\n' : ' ');
////        puts("深度 R");
////        for(int i = 1; i <= 2 * n - 1; i ++)
////            printf("%d%c", R[i], i == 2 * n - 1 ? '\n' : ' ');
////        puts("首位 first");
////        for(int i = 1; i <= n; i ++)
////            printf("%d%c", first[i], i == n ? '\n' : ' ');
////        puts("距离 dist");
////        for(int i = 1; i <= n; i ++)
////            printf("%d%c", dist[i], i == n ? '\n' : ' ');
//        ST(2 * n - 1);
//        while(q--)
//        {
//            scanf("%d%d", &u, &v);
//            int lca = LCA(u, v);
//            printf("%d\n", dist[u] + dist[v] - 2 * dist[lca]);
//        }
//    }
//    return 0;
//}

//1
//7 3
//1 3 2
//1 2 4
//2 4 11
//2 5 5
//5 6 8
//5 7 6

// LCA离线算法(Tarjan)算法
// 思想就是以一个点 root 作为跟变成有根数，然后深搜处理处所有点到跟的距离。求要求的两个点的LCA（最近公共祖先），
// 然后ans = dis【x】 + dis【y】 - 2 * dis【LCA（x，y）】
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//
//const int maxn = 4e4 + 100;
//const int maxm = 210;
//
//typedef struct node
//{
//    int v;
//    int w;
//    struct node *next;
//}Node;
//
//Node *head[maxn];
//Node edge1[maxn << 1]; // 树中的边
//int idx1;
//
//Node *link[maxn];
//Node edge2[maxn << 1];
//int idx2;
//
//int res[maxm][3];// 记录结果，res[i][0] : u  res[i][1] : v res[i][2] : LCA(u, v)
//int father[maxn];
//bool vis[maxn];
//int dist[maxn];
//
//inline void AddEdge(int u, int v, int w, Node edge[], Node *Link[], int &idx)
//{
//    edge[idx].v = v;
//    edge[idx].w = w;
//    edge[idx].next = Link[u];
//    Link[u] = edge + idx ++;
//}
//// 并查集路径压缩
//int Find(int x)
//{
//    if(x != father[x]) return  father[x] = Find(father[x]);
//    return father[x];
//}
//void Tarjan(int u)
//{
//    vis[u] = true;
//    father[u] = u;
//    for(Node *p = link[u]; p; p = p -> next)
//    {
//        int v = p -> v;
//        if(vis[v])
//        res [p -> w][2] = Find(p -> v);// 存的是最近公共祖先节点
//
//    }
//    for(Node *p = head[u]; p; p = p -> next)
//    {
//        int v = p -> v;
//        if(!vis[v])
//        {
//            dist[v] = dist[u] + p -> w;
//            Tarjan(v);
//            father[v] = u;
//        }
//    }
//}
//
//int main()
//{
//    int T;
//    scanf("%d", &T);
//    int n, q;
//    while(T--)
//    {
//        scanf("%d%d", &n, &q);
//        idx1 = 0;
//        memset(head, 0, sizeof(head));
//        int u, v, w;
//        for(int i = 1; i < n; i ++)
//        {
//            scanf("%d%d%d", &u, &v, &w);
//            AddEdge(u, v, w, edge1, head, idx1);
//            AddEdge(v, v, w, edge1, head, idx1);
//        }
//        idx2 = 0;
//        memset(link, 0, sizeof(link));
//        for(int i = 1; i <= q; i ++)
//        {
//            scanf("%d%d", &u, &v);
//            AddEdge(u, v, i, edge2, link, idx2);
//            AddEdge(v, u, i, edge2, link, idx2);
//            res[i][0] = u;
//            res[i][1] = v;
//        }
//        memset(vis, false, sizeof(vis));
//        dist[1] = 0;
//        Tarjan(1);
//        for(int i = 1; i <= q; i ++)
//            printf("%d\n", dist[res[i][0]] + dist[res[i][1]] - 2 * dist[res[i][2]]);
//    }
//    return 0;
//}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
const int N = 44000;
#define INF 1000000000
using namespace std;
struct Node
{
    int to,val;
};
vector<Node> v[N];
vector<int> query[N],num[N];
int ans[N];
bool vis[N];
int dis[N],father[N];
void isit(int n)
{
    for(int i = 0;i<=n;i++)
    {
        v[i].clear();
        query[i].clear();
        num[i].clear();
        vis[i] = false;
        dis[i] = 0;
        father[i] = i;
    }
}
int find(int x)
{
    if(x==father[x])
        return x;
    return father[x] = find(father[x]);
}
void Union(int x,int y)
{
    x = find(x);
    y = find(y);
    if(x!=y)
        father[y] = x; //让孩子节点指向父节点
}
void Tarjan(int o,int val)
{
    vis[o] = true;
    dis[o] = val;
    for(int i = 0; i < v[o].size();i++)
    {
        Node tmp = v[o][i];
        if(vis[tmp.to])
            continue;
        Tarjan(tmp.to,val+tmp.val);
        Union(o,tmp.to);
    }
    for(int i=0;i<query[o].size();i++)
    {
        int tmp = query[o][i];
        if(vis[tmp])
            ans[num[o][i]] = dis[o] + dis[tmp] - 2*dis[find(tmp)];
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        isit(n);
        for(int i = 1;i < n; i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            v[x].push_back((Node){y,z});
            v[y].push_back((Node){x,z});
        }
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            query[x].push_back(y);
            num[x].push_back(i);
            query[y].push_back(x);
            num[y].push_back(i);
        }
        Tarjan(1,0);
        for(int i = 0;i<m;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}

