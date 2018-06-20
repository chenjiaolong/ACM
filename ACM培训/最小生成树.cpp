//邻接矩阵-prim算法
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int N=1001;
//const int inf=1<<29;
//
//int w[N][N];
//int dis[N],flag[N];
//int m,n,u,v,c;
//
//using namespace std;
//int Prim()
//{
//    int sum=0;
//    memset(flag,0,sizeof(flag));
//    for(int i=1; i<=n; i++)
//        dis[i]=w[1][i];
//    flag[1]=1;
//    for(int i=1; i<n; i++)
//    {
//        int to=-1,mini=inf;
//        for(int j=1; j<=n; j++)
//            if(!flag[j]&&dis[j]<mini)
//            {
//                to=j;
//                mini=dis[j];
//            }
//        if(to==-1)
//            return -1;
//        flag[to]=1;
//        sum+=mini;
//        for(int j=1; j<=n; j++)
//            dis[j]=min(dis[j],w[to][j]);
//    }
//    return sum;
//}
//int main()
//{
//    while(~scanf("%d%d",&n,&m))
//    {
//        for(int i=1; i<=n; i++)
//            for(int j=1; j<=n; j++)
//                w[i][j]=inf;
//        for(int i=0; i<m; i++)
//        {
//            scanf("%d%d%d",&u,&v,&c);
//            w[u][v]=w[v][u]=c;
//        }
//        printf("%d\n",Prim());
//    }
//    return 0;
//}

// 邻接表的创建
//#include<iostream>
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int maxn=1100;
//const int maxm=maxn*maxn>>1;
//
//int n,m;
//int e,head[maxn],next[maxm],data[maxm],cost[maxm];
//using namespace std;
//void AddEdge(int u,int v,int c)
//{
//    data[e]=v;
//    cost[e]=c;
//    next[e]=head[u];
//    head[u]=e++;
//}
//int main()
//{
//    while(~scanf("%d%d",&n,&m))
//    {
//        e=0;
//        memset(head,-1,sizeof(head));
//        for(int i=0;i<m;i++)
//        {
//            int u,v,c;
//            scanf("%d%d%d",&u,&v,&c);
//            AddEdge(u,v,c);
//        }
//        for(int u=1;u<=n;u++)
//        {
//            printf("%d:",u);
//            for(int v=head[u];v!=-1;v=next[v])
//                printf(" → %d cost=%d",data[v],cost[v]);
//            puts("");
//        }
//    }
//    return 0;
//}

//邻接表-prim算法
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int maxn=1001;
//const int inf=1<<29;
//const int maxm=maxn*maxn/2;
//
//int head[maxn],point[maxm],next[maxm],e;
//int cost[maxm],dist[maxn];
//int n,m;
//bool vis[maxn];
//
//using namespace std;
//void AddEdge(int u,int v,int c)
//{
//    point[e]=v;
//    cost[e]=c;
//    next[e]=head[u];
//    head[u]=e++;
//}
//int Prim()
//{
//    int ans=0;
//    memset(vis,false,sizeof(vis));
//    for(int i=1; i<=n; i++)
//        dist[i]=inf;
//    vis[1]=true;//选择第一个作为起始点。
//    for(int i=head[1]; i!=-1; i=next[i])
//        dist[point[i]]=cost[i];//将1到其他的点权值赋给dist[]数组；
//    for(int i=1; i<n; i++)
//    {
//        int mini=inf,u=-1;
//        for(int j=1; j<=n; j++)
//            if(dist[j]<mini&&!vis[j])
//            {
//                mini=dist[j];
//                u=j;
//            }
//        if(u==-1) break;//不能构成最小生成树
//        ans+=mini;
//        vis[u]=true;
//        for(int j=head[u]; j!=-1; j=next[j]) //用这个符合的u到其他点距离比较当前数组存的值。
//            dist[point[j]]=min(dist[point[j]],cost[j]);
//    }
//    return ans;
//}
//int main()
//{
//    while(~scanf("%d%d",&n,&m))
//    {
//        e=0;
//        memset(head,-1,sizeof(head));
//        for(int i=0; i<m; i++)
//        {
//            int u,v,c;
//            scanf("%d%d%d",&u,&v,&c);
//            AddEdge(u,v,c);
//            AddEdge(v,u,c);
//        }
//        printf("%d\n",Prim());
//    }
//    return 0;
//}

//邻接表-Kruskal算法
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int N=1e5;
//
//struct node
//{
//    int u,v,w;
//    bool operator<(const node &C)const
//    {
//        return w<C.w;
//    }
//}t[N];
//int m,n;
//int p[1001];
//using namespace std;
//int cha(int x)
//{
//    return x == p[x] ? p[x] = x :cha(p[x]);
//}
//int Kruskal()
//{
//    int sum=0,tol=0;
//    for(int i=0; i<m; i++)
//    {
//        int x=t[i].u;
//        int y=t[i].v;
//        x=cha(x);
//        y=cha(y);
//        if(x!=y)
//        {
//            p[x]=y;
//            sum+=t[i].w;
//            tol++;
//        }
//        if(tol==n-1)
//            return sum;
//    }
//    return -1;
//}
//int main()
//{
//    while(~scanf("%d%d",&n,&m))
//    {
//        for(int i=1; i<=n; i++) p[i]=i;
//        for(int i=0; i<m; i++) scanf("%d%d%d",&t[i].u,&t[i].v,&t[i].w);
//        sort(t,t+m);
//        printf("%d\n",Kruskal());
//    }
//    return 0;
//}

// hdu 1863 畅通工程 Kruskal算法
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<algorithm>
//
//using namespace std;
//
//const int maxn = 105;
//struct node
//{
//    int from, to;
//    int cost;
//    bool operator < (const node &S) const
//    {
//        return cost < S.cost;
//    }
//} Edge[maxn * maxn];
//
//int father[maxn];
//int N, M;
//void Init()
//{
//    for(int i = 1; i < maxn; i ++) father[i] = i;
//}
//int Find(int x)
//{
//    if(x == father[x]) return father[x];
//    return father[x] = Find(father[x]);
//}
//bool Same(int x, int y)
//{
//    return Find(x) == Find(y);
//}
//void UnionSet(int x, int y)
//{
//    int u = Find(x), v = Find(y);
//    if(u == v) return;
//    father[u] = v;
//}
//int Kruscal()
//{
//    sort(Edge + 1, Edge + M + 1);
//    int res = 0;
//    for(int i = 1; i <= M; i ++)
//    {
//        if(Same(Edge[i].from, Edge[i].to)) continue;
//        UnionSet(Edge[i].from, Edge[i].to);
//        res += Edge[i].cost;
//    }
//    return res;
//}
//int main()
//{
//    while(scanf("%d%d", &M, &N), M)
//    {
//        Init();
//        for(int i = 1; i <= M; i ++)
//            scanf("%d%d%d", &Edge[i].from, &Edge[i].to, &Edge[i].cost);
//        int res = Kruscal();
//        for(int i = 1; i <= N; i ++)
//            if(!Same(i, 1)) res = -1;
//        if(res == -1) printf("?\n", res);
//        else printf("%d\n", res);
//    }
//    return 0;
//}

// hdu 1863 畅通工程 Prim算法
#include<queue>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;
const int maxn = 105;

struct edge
{
    int to;
    int cost;
    edge(int tt, int cc) : to(tt), cost(cc) {}
    edge() {}
    bool operator <(const edge &S) const
    {
        return S.cost < cost;
    }
};
priority_queue<edge>q;
vector<edge>G[maxn];
int N, M;
bool vis[maxn];
int Prim()
{
    int res = 0;
    vis[1] = true;
    for(int i = 0; i < G[1].size(); i ++)
        q.push(G[1][i]);
    while(q.size())
    {
        edge e = q.top();
        q.pop();
        if(vis[e.to]) continue;
        vis[e.to] = true;
        res += e.cost;
        for(int i = 0; i < G[e.to].size(); i ++)
            q.push(G[e.to][i]);
    }
    return res;
}
int main()
{
    while(scanf("%d%d", &M, &N), M)
    {
        for(int i = 0; i <= N; i ++)
            G[i].clear();
        while(q.size()) q.pop();
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= M; i ++)
        {
            int u, v, cost;
            scanf("%d%d%d", &u, &v, &cost);
            G[u].push_back(edge(v, cost));
            G[v].push_back(edge(u, cost));
        }
        int res = Prim();
        for(int i = 1; i <= N; i ++)
            if(!vis[i]) res = -1;
        if(res == -1) puts("?");
        else printf("%d\n", res);
    }
    return 0;
}
