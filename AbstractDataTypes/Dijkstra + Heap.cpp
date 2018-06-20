// poj 2502 Subway
#include<queue>
#include<math.h>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

const int maxn = 200 + 5;
const int inf = 1 << 30;
double dist[maxn], map[maxn][maxn];
int x[maxn], y[maxn];
int n;
typedef pair<double, int>PII;
double dis(int x1, int y1, int x2, int y2)
{
    return sqrt((double)((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))) / 1000;
}
double Dijkstra(int s, int t)
{
    bool vis[maxn] = {false};
    for(int i = 1; i <= n; i ++) dist[i]= inf;
    dist[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII> >q;
    q.push(make_pair(dist[s], s));
    while(!q.empty())
    {
        PII top = q.top();
        q.pop();
        int u = top.second;
        if(vis[u]) continue;
        vis[u] = true;
        for(int v = 1; v <= n; v ++)
        {
            if(map[u][v] + dist[u] < dist[v])
            {
                dist[v] = dist[u] + map[u][v];
                q.push(make_pair(dist[v], v));
            }
        }
    }
    return dist[t];
}
int main()
{
    scanf("%d%d%d%d", &x[1], &y[1], &x[2], &y[2]);
    n = 2;
    for(int i = 1; i < maxn; i ++)
        for(int j = 1; j < maxn; j ++)
            map[i][j] = inf;
    int s = n + 1;
    int xx, yy;
    while(scanf("%d%d", &xx, &yy) != EOF)
    {
        if(xx == -1 && yy == -1)
        {
            for(int i = s; i < n; i ++)
            {
                double temp = dis(x[i], y[i], x[i + 1], y[i + 1]) / 40;
                if(temp < map[i][i + 1])
                    map[i][i + 1] = map[i + 1][i] = temp;
            }
            s = n + 1;
            continue;
        }
        n ++;
        x[n] = xx;
        y[n] = yy;
    }
    for(int i = 1; i < n; i ++)
        for(int j = i + 1; j <= n; j ++ )
        {
            double temp = dis(x[i], y[i], x[j], y[j]) / 10;
            if(temp < map[i][j])
                map[i][j] = map[j][i] = temp;
        }
    double ans = Dijkstra(1, 2);
    printf("%.f\n", ans * 60);
    return 0;
}
