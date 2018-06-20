// MaxFlow
//#include<queue>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//
//const int inf = 0x7fffffff;
//const int maxn = 1000;
//const int maxm = maxn * maxn;
//int head[maxn], flow[maxn], to[maxn], next[maxm], capacity[maxm], tot;
//int level[maxn];
//int s, t;
//void AddEdge(int u, int v, int c)
//{
//    to[++tot] = v;
//    next[tot] = head[u];
//    head[u] = tot;
//    flow[tot] = c;
//    capacity[tot] = flow[tot];
//}
//queue<int>q;
//bool BFS()
//{
//    memset(level, 0, sizeof(level));
//    level[s] = 1;
//    q.push(s);
//    while(!q.empty())
//    {
//        int u = q.front();
//        q.pop();
//        for(int i = head[u]; i; i = next[i])
//        {
//            int v = to[i];
//            if(flow[i] > 0 && !level[v])
//            {
//                level[v] = level[u] + 1;
//                q.push(v);
//            }
//        }
//    }
//    return level[t];
//}
//int DFS(int u, int maxf)
//{
//    if(u == t || maxf == 0) return maxf;
//    int f = maxf;
//    for(int i = head[u]; i; i = next[i])
//    {
//        int v = to[i];
//        if(flow[i] > 0 && level[v] == level[u] + 1)
//        {
//            int tmp = DFS(v, min(flow[i], maxf));
//            flow[i] -= tmp;
//            flow[i ^ 1] += tmp;
//            maxf -= tmp;
//            if(!maxf) break;
//        }
//    }
//    if(f == maxf) level[u] = -1;
//    return f - maxf;
//}
//int Dinic()
//{
//    int maxflow = 0;
//    while(BFS()) maxflow += DFS(s, inf);
//    return maxflow;
//}
//int main()
//{
//    int n ,m;
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        memset(head, 0, sizeof(head));
//		  tot = 0;
//        int u, v, c;
//        for(int i = 1; i <= m; i ++)
//        {
//            scanf("%d%d%d", &u, &v, &c);
//            AddEdge(u, v, c);
//            AddEdge(v, u, 0);
//        }
//        s = 0;
//        t = 5;
//        int maxflow = Dinic();
//        printf("%d\n", maxflow);
//    }
//    return 0;
//}

//#include<queue>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//
//const int maxn = 1000;
//const int maxm = maxn * maxn;
//const int inf = 0x7fffffff;
//int s, t;
//int head[maxn], e;
//struct node
//{
//    int v;
//    int c;
//    int next;
//}edge[maxm];
//int level[maxn];
//void AddEdge(int u, int v, int c)
//{
//    edge[e].v = v;
//    edge[e].c = c;
//    edge[e].next = head[u];
//    head[u] = e ++;
//}
//bool BFS()
//{
//    queue<int >q;
//    memset(level, 0, sizeof(level));
//    level[s] = 1;
//    q.push(s);
//    while(q.size())
//    {
//        int u = q.front();
//        q.pop();
//        for(int i = head[u]; ~i; i = edge[i].next)
//        {
//            int v = edge[i].v;
//            if(!level[v] && edge[i].c)
//            {
//                level[v] = level[u] + 1;
//                q.push(v);
//                if(v == t) return level[v];
//            }
//        }
//    }
//    return level[t];
//}
//int DFS(int u, int maxf)
//{
//    if(maxf == 0 || u == t) return maxf;
//    int f = 0;
//    for(int i = head[u]; ~i; i = edge[i].next)
//    {
//        int v = edge[i].v;
//        if(level[v] == level[u] + 1 && edge[i].c)
//        {
//            int tmp = DFS(v, min(edge[i].c, maxf));
//            edge[i].c -= tmp;
//            edge[i ^ 1].c += tmp;
//            maxf -= tmp;
//            f += tmp;
//            if(!maxf) break;
//        }
//    }
//    if(!maxf) level[u] = 0;// »¡ÓÅ»¯
//    return f;
//}
//int Dinic()
//{
//    int maxflow = 0;
//    while(BFS()) maxflow += DFS(s, inf);
//    return maxflow;
//}
//int main()
//{
//    int n, m;
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        memset(head, -1, sizeof(head));
//        e = 0;
//        int u, v, c ;
//        for(int i = 1; i <= m; i ++)
//        {
//            scanf("%d%d%d", &u, &v, &c);
//            AddEdge(u, v, c);
//            AddEdge(v, u, 0);
//        }
//        s = 0;
//        t = 5;
//        int maxflow = Dinic();
//        printf("%d\n", maxflow);
//    }
//    return 0;
//}

//6 10
//0 1 16
//0 2 2
//1 2 10
//2 1 4
//1 3 12
//3 2 9
//2 4 14
//4 3 7
//3 5 20
//4 5 4


// minimum cost maximum flow(MCMF)
//#include<queue>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//const int maxn = 1000;
//const int maxm = maxn * maxn;
//const int inf = 0x7fffffff;
//int head[maxn], from[maxm], to[maxm], next[maxm], cost[maxm], flow[maxm], tot;
//int s, t;
//int f, c;
//int dis[maxn], minb[maxn], pre[maxn];
//struct node
//{
//    int u, w;
//    node(int a = 0, int b = 0){ u = a, w = b; }
//    friend bool operator<(node a, node b)
//    {
//        return a.w > b.w;
//    }
//};
//inline void AddEdge(int u, int v, int w, int c)
//{
//    to[++tot] = v;
//    from[tot] = u;
//    next[tot] = head[u];
//    head[u] = tot;
//    flow[tot] = w;
//    cost[tot] = c;
//}
//bool SPFA()
//{
//    priority_queue<node>q;
//    memset(dis, inf, sizeof(dis));
//    dis[s] = 0, minb[s] = inf, pre[s] = 0;
//    q.push(node(s, 0));
//    int u;
//    while(!q.empty())
//    {
//        u = q.top().u;
//        q.pop();
//        if(u == t) continue;
//        for(int i = head[u]; i; i = next[i])
//        {
//            int v = to[i];
//            if(flow[i] && dis[v] > dis[u] + cost[i])
//            {
//                dis[v] = dis[u] + cost[i];
//                minb[v] = min(minb[u], flow[i]);
//                pre[v] = i;
//                q.push(node(v, dis[v]));
//            }
//        }
//        while(!q.empty() && dis[q.top().u] != q.top().w)
//            q.pop();
//    }
//    if(dis[t] == inf) return false;
//
//    f += minb[t];
//    c += minb[t] * dis[t];
//    u = t;
//    while(u != s)
//    {
//        int v = pre[u];
//        flow[v] -= minb[t];
//        flow[v^1] += minb[t];
//        u = from[v];
//    }
//    return true;
//}
//int main()
//{
//    int n, m;
//    int maxflow, mincost;
//    while(SPFA());
//    maxflow = f, mincost = c;
//    return 0;
//}


//#include<queue>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//const int maxn = 1000;
//const int inf = 0x7fffffff;
//
//int n;
//
//int head[maxn], e;
//struct node
//{
//    int v;
//    int capacity;
//    int cost;
//    int next;
//    int reverse;// reverse 记录逆边下标
//} edge[maxn * maxn];
//
//int pre[maxn], dis[maxn];
//bool vis[maxn];
//
//int s, t;
//int maxflow, mincost;
//inline void AddEdge(int u, int v, int capacity, int cost)
//{
//    edge[e].v = v;
//    edge[e].capacity = capacity;
//    edge[e].cost = cost;
//    edge[e].reverse = e + 1;
//    edge[e].next = head[u];
//    head[u] = e ++;
//
//    edge[e].v = u;
//    edge[e].capacity = 0;
//    edge[e].cost = -cost;
//    edge[e].reverse = e - 1;
//    edge[e].next = head[v];
//    head[v] = e ++;
//}
//bool SPFA()
//{
//    queue<int> q;
//    for(int i = 0; i <= n; i ++)
//    {
//        dis[i] = inf;
//        vis[i] = false;
//    }
//    dis[s] = 0;
//    vis[s] = true;
//    q.push(s);
//    while(q.size())
//    {
//        int u = q.front();
//        q.pop();
//        for(int i = head[u]; ~i; i = edge[i].next)
//        {
//            int v = edge[i].v;
//            if(edge[i].capacity && dis[v] > dis[u] + edge[i].cost)
//            {
//                dis[v] = dis[u] + edge[i].cost;
//                pre[v] = i;
//                if(!vis[v])
//                {
//                    vis[v] = true;
//                    q.push(v);
//                }
//
//            }
//        }
//        vis[u] = false;
//    }
//    if(dis[t] == inf) return false;
//    return true;
//}
//void end()
//{
//    int p;
//    maxflow = inf;
//    for(int u = t; u != s; u = edge[edge[p].reverse].v)
//    {
//        p = pre[u];
//        maxflow = min(maxflow, edge[p].capacity);
//    }
//    for(int u = t; u != s; u = edge[edge[p].reverse].v)
//    {
//        p = pre[u];
//        edge[p].capacity -= mincost;
//        edge[edge[p].reverse].capacity += mincost;
//        mincost += maxflow * edge[p].cost;// cost 记录的为单位时间流量费用， 必须得乘以流量
//    }
//}
//int main()
//{
//    memset(head, -1, sizeof(head));
//    mincost = 0;
//    while(SPFA()) end();
//    return 0;
//}

#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;
const int inf = 0x7fffffff;
const int maxn = 1100;
const int maxm = maxn * maxn;
int e = 0, head[maxn], cost[maxm], next[maxm], to[maxm], flow[maxm];
int s, t;
int dist[maxn], pre[maxn], cnt[maxn];
bool vis[maxn];
int n;
int maxflow, mincost;
inline void AddEdge(int u, int v, int c, int f)
{
    to[e] = v;
    next[e] = head[u];
    cost[e] = c;
    flow[e] = f;
    head[u] = e ++;

    to[e] = u;
    next[e] = head[v];
    cost[e] = -c;
    flow[e] = 0;
    head[v] = e ++;
}
bool SPFA()
{
    queue<int>q;
    //fill(&dist[0], &dist[maxn], inf);
    for(int i = s; i <= t; i ++)
    {
        dist[i] = inf;
        cnt[i] = 0;
        vis[i] = false;
        pre[i] = -1;
    }
    dist[s] = 0;
    q.push(s);
    vis[s] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = head[u]; ~i; i = next[i])
        {
            int v = to[i];
            if(flow[i] && dist[v] > dist[u] + cost[i])
            {
                dist[v] = dist[u] + cost[i];
                pre[v] = i;//连接边的编号是多少，pre初始值为-1，连接当前点的边是哪一条
                if(!vis[v])
                {
                    q.push(v);
                    vis[v] = true;
                    if(++cnt[v] >= n) return false;
                }
            }
        }
    }
    return dist[t] != inf;//如果从原点到汇点不能到达则为inf
}
void MCMF()
{
    mincost = 0;
    while(SPFA())
    {
        maxflow = inf;
        int v;
        for(int i = pre[t]; ~i; i = pre[v])
        {
            v = to[i ^ 1];
            maxflow = min(maxflow, flow[i]);
        }
        for(int i = pre[t]; ~i; i = pre[v])
        {
            v = to[i ^ 1];
            flow[i] -= maxflow;
            flow[i ^ 1] += maxflow;
        }
        mincost += maxflow * dist[t];
    }
}
int main()
{
    int m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(head, -1, sizeof(head));
        e = 0;
        int u, v, c;
        AddEdge(0, 1, 0, 2);
        AddEdge(n, n + 1, 0, 2);
        for(int i = 1; i <= m; i ++)
        {
            scanf("%d%d%d", &u, &v, &c);
            AddEdge(u, v, c, 1);
            AddEdge(v, u, c, 1);
        }
        s = 0;
        t = n + 1;
        MCMF();
        printf("%d\n", mincost);
    }
    return 0;
}

