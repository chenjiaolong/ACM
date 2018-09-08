// SPFA
//#include <bits/stdc++.h>
//
//using namespace std;
//
//const int maxn = 1100;
//const int maxm = maxn * maxn;
//const int inf = 0x3f3f3f3f;
//
//int head[maxn], e;
//struct node
//{
//    int to;
//    int next;
//    int cost;
//} edge[maxm];
//
//int dis[maxn], pre[maxn], cnt[maxn];
//int n, m;
//bool vis[maxn];
//
//void Init()
//{
//    e = 0;
//    memset(head, -1, sizeof(head));
//    memset(pre, -1, sizeof(pre));
//    memset(cnt, 0, sizeof(cnt));
//    memset(vis, false, sizeof(vis));
//}
//
//inline void AddEdge(int u, int v, int c)
//{
//    edge[e].to = v;
//    edge[e].next = head[u];
//    edge[e].cost = c;
//    head[u] = e ++;
//}
//
//bool SPFA(int s)
//{
//    for(int i = 0; i <= n; i ++)
//        dis[i] = inf;
//    dis[s] = 0;
//    queue<int >q;
//    q.push(s);
//    while(!q.empty())
//    {
//        int u = q.front();
//        q.pop();
//        vis[u] = 0;
//        for(int i = head[u]; ~i; i = edge[i].next)
//        {
//            int v = edge[i].to;
//            if(dis[v] > dis[u] + edge[i].cost)
//            {
//                pre[v] = u;
//                dis[v] = dis[u] + edge[i].cost;
//                if(!vis[v])
//                {
//                    if(++ cnt[v] == n) return true;
//                    q.push(v);
//                    vis[v] = true;
//                }
//            }
//        }
//    }
//    return false;
//}
//void DFS(int u)
//{
//    if(pre[u] == -1)
//    {
//        printf("%d", u);
//        return;
//    }
//    DFS(pre[u]);
//    printf(" -> %d", u);
//}
//int main()
//{
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        Init();
//        while(m --)
//        {
//            int u, v, c;
//            scanf("%d%d%d", &u, &v, &c);
//            AddEdge(u, v, c);
//            AddEdge(v, u, c);
//        }
//        if(SPFA(1)) puts("-1");
//        else
//            for(int i = 2; i <= n; i ++)
//            {
//                printf("sss %d %d\n", i, dis[i]);
//                DFS(i);
//                puts("");
//            }
//
//    }
//    return 0;
//}

// SPFA
//#include <bits/stdc++.h>
//
//using namespace std;
//const int maxn = 205;
//
//vector<pair<int, int>>E[maxn];
//
//int n, m;
//int d[maxn];
//bool inq[maxn];
//
//void Init()
//{
//    for(int i = 0; i < maxn; i ++)
//    {
//        E[i].clear();
//        inq[i] = false;
//        d[i] = 1e9;
//    }
//}
//
//int main()
//{
//    while(cin >> n >> m)
//    {
//        Init();
//        for(int i = 0; i < m; i ++)
//        {
//            int x, y, z;
//            scanf("%d%d%d", &x, &y, &z);
//            E[x].push_back(make_pair(y, z));
//            E[y].push_back(make_pair(x, z));
//        }
//        int s, t;
//        scanf("%d%d", &s, &t);
//        queue<int>Q;
//        Q.push(s), d[s] = 0, inq[s] = true;
//        while(!Q.empty())
//        {
//            int now = Q.front();
//            Q.pop();
//            inq[now] = false;
//            for(int i = 0; i < E[now].size(); i ++)
//            {
//                int v = E[now][i].first;
//                if(d[v] > d[now] + E[now][i].second)
//                {
//                    d[v] = d[now] + E[now][i].second;
//                    if(inq[v]) continue;
//                    Q.push(v);
//                    inq[v] = true;
//                }
//            }
//        }
//        if(d[t] == 1e9) puts("-1");
//        else printf("%d\n", d[t]);
//    }
//    return 0;
//}

// 迪杰特斯拉算法：Dijkstra + Heap
#include <bits/stdc++.h>

using namespace std;
const int maxn = 205;

vector<pair<int, int>>E[maxn];

int n, m;
int d[maxn];

void Init()
{
    for(int i = 0; i < maxn; i ++)
    {
        E[i].clear();
        d[i] = 1e9;
    }
}

int main()
{
    while(cin >> n >> m)
    {
        Init();
        for(int i = 0; i < m; i ++)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            E[x].push_back(make_pair(y, z));
            E[y].push_back(make_pair(x, z));
        }
        int s, t;
        scanf("%d%d", &s, &t);
        priority_queue<pair<int, int>>Q;
        Q.push(make_pair(-d[s], s)), d[s] = 0;
        while(!Q.empty())
        {
            int now = Q.top().second;
            Q.pop();
            for(int i = 0; i < E[now].size(); i ++)
            {
                int v = E[now][i].first;
                if(d[v] > d[now] + E[now][i].second)
                {
                    d[v] = d[now] + E[now][i].second;
                    Q.push(make_pair(-d[v], v));
                }
            }
        }
        if(d[t] == 1e9) puts("-1");
        else printf("%d\n", d[t]);
    }
    return 0;
}
