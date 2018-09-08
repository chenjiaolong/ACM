// Floyd
//#include <bits/stdc++.h>
//
//using namespace std;
//
//const int maxn = 105;
//const int inf = 0x3f3f3f3f;
//
//int G[maxn][maxn];
//
//int main()
//{
//    int n, m;
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        for(int i = 1; i <= n; i ++)
//            for(int j = 1; j <= n; j ++)
//                G[i][j] = (i == j ? 0 : inf);
//        for(int i = 1; i <= m; i ++)
//        {
//            int u, v, w;
//            scanf("%d%d%d", &u, &v, &w);
//            G[u][v] = G[v][u] = min(w, G[u][v]);
//        }
//        for(int k = 1; k <= n; k ++)
//            for(int i = 1; i <= n; i ++)
//                for(int j = 1; j <= n; j ++)
//                    if(i != k && j != k && G[i][k] != inf && G[k][j] != inf)
//                        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
//        for(int i = 1; i <= n; i ++)
//            for(int j = 1; j <= n; j ++)
//                printf("%d -> %d = %d\n", i, j, G[i][j]);
//    }
//    return 0;
//}

// Dijkstra
//#include <bits/stdc++.h>
//
//using namespace std;
//
//const int maxn = 1010;
//const int inf = 0x3f3f3f3f;
//
//int G[maxn][maxn], n, m;
//int dis[maxn];
//bool vis[maxn];
//
//void Dijkstra(int s)
//{
//    for(int i = 1; i <= n; i ++)
//    {
//        dis[i] = G[s][i];
//        vis[i] = false;
//    }
//    vis[s] = true;
//    for(int i = 1; i < n; i ++)
//    {
//        int mini = inf, to = -1;
//        for(int j = 1; j <= n; j ++)
//        {
//            if(!vis[j] && dis[j] < mini)
//            {
//                mini = dis[j];
//                to = j;
//            }
//        }
//        vis[to] = true;
//        for(int j = 1; j <= n; j ++)
//            if(!vis[j] && dis[j] > dis[to] + G[to][j])
//                dis[j] = dis[to] + G[to][j];
//    }
//}
//int main()
//{
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        for(int i = 1; i <= n; i ++)
//            for(int j = 1; j <= n; j ++)
//                G[i][j] = (i == j ? 0 : inf);
//        for(int i = 1; i <= m; i ++)
//        {
//            int u, v, w;
//            scanf("%d%d%d", &u, &v, &w);
//            G[u][v] = G[v][u] = min(w, G[u][v]);
//        }
//        Dijstra(1);
//        for(int i = 1; i <= n; i ++)
//            printf("1 -> %d = %d\n", i, dis[i]);
//    }
//    return 0;
//}

// Bellman-Ford
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
const int maxm = maxn * maxn;
const int inf = 0x3f3f3f3f;

int n, m;
int dis[maxn];

struct node
{
    int u, v, w;
} G[maxm];

bool Bellman_Ford(int s)
{
    for(int i = 1; i <= n; i ++)
        dis[i] = inf;
    dis[s] = 0;
    for(int i = 1; i < n; i ++)
        for(int j = 1; j <= 2 * m; j ++)
        {
            int u = G[j].u;
            int v = G[j].v;
            int w = G[j].w;
            if(dis[u] + w < dis[v]) dis[v] = dis[u] + w;
        }
    for(int j = 1; j <= 2 * m; j ++)
    {
        int u = G[j].u;
        int v = G[j].v;
        int w = G[j].w;
        if(dis[u] + w < dis[v]) return false;
    }
    return true;
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 1; i <= 2 * m; i += 2)
        {
            scanf("%d%d%d", &G[i].u, &G[i].v, &G[i].w);
            G[i + 1].u = G[i].v;
            G[i + 1].v = G[i].u;
            G[i + 1].w = G[i].w;
        }
        bool flag = Bellman_Ford(1);
        if(!flag) puts("-1");
        else
            for(int i = 1; i <= n; i ++)
                printf("1 -> %d = %d\n", i, dis[i]);
    }
    return 0;
}

