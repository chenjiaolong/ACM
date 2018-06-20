// The Two Routes: Flyod
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<algorithm>
//
//using namespace std;
//
//const int INF = 0x3f3f3f3f;
//int n, m;
//int railway[405][405];
//
//int main()
//{
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        memset(railway, INF, sizeof(railway));
//        for(int i = 1; i <= n; i ++)
//            railway[i][i] = 0;
//        int u, v;
//        for(int i = 0; i < m; i ++)
//        {
//            scanf("%d%d", &u, &v);
//            railway[u][v] = railway[v][u] = 1;
//        }
//        if(railway[1][n] == 1)
//        {
//            for(int i = 1; i <= n; i ++)
//                for(int j = i + 1; j <= n; j ++)
//                    if(railway[i][j] == 1) railway[i][j] = railway[j][i] = INF;
//                    else if(railway[i][j] == INF)railway[i][j] = railway[j][i] = 1;
//        }
//        for(int k = 1; k <= n; k ++)
//            for(int i = 1; i <= n; i++)
//                for(int j = 1; j <= n; j++)
//                    if(k != i && i != j && railway[i][k] != INF && railway[k][j] != INF)
//                        railway[i][j] = railway[j][i] = min(railway[i][j], railway[i][k] + railway[k][j]);
//        if(railway[1][n] == INF) printf("-1\n");
//        else printf("%d\n", railway[1][n]);
//    }
//    return 0;
//}

// The Two Routes: BFS
#include<queue>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int railway[405][405];
struct node
{
    int u, step;
} s, h, t;

int BFS()
{
    bool vis[405] = {0};
    s.u = 1, s.step = 0;
    queue<node> q;
    q.push(s);
    vis[1] = true;
    while(!q.empty())
    {
        h = q.front();
        q.pop();
        if(h.u == n) return h.step;
        for(int v = 1; v <= n; v ++)
            if(!vis[v] && railway[h.u][v] == 1)
            {
                vis[v] = true;
                railway[h.u][v] = railway[v][h.u] = INF;
                t.u = v;
                t.step = h.step + 1;
                q.push(t);
            }
    }
    return -1;
}
int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(railway, INF, sizeof(railway));
        for(int i = 1; i <= n; i ++)
            railway[i][i] = 0;
        int u, v;
        for(int i = 0; i < m; i ++)
        {
            scanf("%d%d", &u, &v);
            railway[u][v] = railway[v][u] = 1;
        }
        if(railway[1][n] == 1)
        {
            for(int i = 1; i <= n; i ++)
                for(int j = i + 1; j <= n; j ++)
                    if(railway[i][j] == 1) railway[i][j] = railway[j][i] = INF;
                    else if(railway[i][j] == INF)railway[i][j] = railway[j][i] = 1;
        }
        int res = BFS();
        printf("%d\n", res);
    }
    return 0;
}
