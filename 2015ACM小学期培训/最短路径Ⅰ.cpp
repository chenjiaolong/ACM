//Til the Cows Come Home
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int maxn=1001;
//const int inf=1<<29;
//
//struct node
//{
//    int from,to,c;
//} e[maxn*maxn>>1];
//int d[maxn];
//int N,T;
//bool Bellman_Ford(int st)
//{
//    for(int i=0; i<=N; i++)
//        d[i]=inf;
//    d[st]=0;
//    for(int i=1; i<N; i++)
//        for(int j=0; j<2*T; j++)
//            if(d[e[j].to]>d[e[j].from]+e[j].c)
//                d[e[j].to]=d[e[j].from]+e[j].c;
//    for(int i=0; i<2*T; i++)
//        if(d[e[i].to]>d[e[i].from]+e[i].c)
//            return true;
//    return false;
//}
//int main()
//{
//    while(~scanf("%d%d",&T,&N))
//    {
//        for(int i=0;i<2*T;i+=2)
//        {
//            scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].c);
//            e[i+1].from=e[i].to;
//            e[i+1].to=e[i].from;
//            e[i+1].c=e[i].c;
//        }
//        Bellman_Ford(1);
//        printf("%d\n",d[N]);
//    }
//    return 0;
//}

//畅通工程续
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int maxn=205;
//const int inf=0x3f3f3f3f;
//
//int w[maxn][maxn];
//int N,M;
//using namespace std;
//int main()
//{
//    while(~scanf("%d%d",&N,&M))
//    {
//        memset(w,inf,sizeof(w));
//        for(int i=1; i<=N; i++)
//            w[i][i]=0;
//        while(M--)
//        {
//            int A,B,X;
//            scanf("%d%d%d",&A,&B,&X);
//            if(X<w[A+1][B+1])
//                w[A+1][B+1]=w[B+1][A+1]=X;
//        }
//        for(int k=1; k<=N; k++)
//            for(int i=1; i<=N; i++)
//                for(int j=1; j<=N; j++)
//                    if(i!=k&&j!=k&&w[i][k]!=inf&&w[k][j]!=inf)
//                        w[i][j]=w[j][i]=min(w[i][j],w[i][k]+w[k][j]);
//        int S,T;
//        scanf("%d%d",&S,&T);
//        if(w[S+1][T+1]==inf)
//            printf("-1\n");
//        else
//            printf("%d\n",w[S+1][T+1]);
//    }
//    return 0;
//}

//hdu3790 最短路径问题
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int N=1100;
//const int inf=1<<29;
//
//struct node
//{
//    int d,p;
//} w[N][N],d[N];
//bool vis[N];
//int n,m;
//void Dijkstra(int start)
//{
//    for(int i=1; i<=n; i++)
//    {
//        d[i].d=inf;
//        d[i].p=inf;
//    }
//    d[start].d=0;
//    d[start].p=0;
//    for(int i=0; i<n; i++)
//    {
//        int now=inf,x;
//        for(int j=1; j<=n; j++)
//            if(d[j].d<now&&!vis[j])
//            {
//                now=d[j].d;
//                x=j;
//            }
//        vis[x]=true;
//        for(int j=1; j<=n; j++)
//        {
//            if(!vis[j]&&d[j].d>d[x].d+w[x][j].d)
//            {
//                d[j].d=d[x].d+w[x][j].d;
//                d[j].p=d[x].p+w[x][j].p;
//            }
//            if(!vis[j]&&d[j].d==d[x].d+w[x][j].d&&d[j].p>d[x].p+w[x][j].p)
//                d[j].p=d[x].p+w[x][j].p;
//        }
//    }
//}
//int main()
//{
//    while(~scanf("%d%d",&n,&m)&&m+n)
//    {
//        memset(vis,false,sizeof(vis));
//        for(int i=1; i<=n; i++)
//            for(int j=1; j<=n; j++)
//            {
//                w[i][j].d=inf;
//                w[i][j].p=inf;
//            }
//        for(int i=1; i<=m; i++)
//        {
//            int a,b,d,p;
//            scanf("%d%d%d%d",&a,&b,&d,&p);
//            if(w[a][b].d>d)
//            {
//                w[a][b].d=w[b][a].d=d;
//                w[a][b].p=w[b][a].p=p;
//            }
//            if(w[a][b].d==d&&w[a][b].p>p)
//                w[a][b].p=w[b][a].p=p;
//        }
//        int s,t;
//        scanf("%d%d",&s,&t);
//        Dijkstra(s);
//        printf("%d %d\n",d[t].d,d[t].p);
//    }
//    return 0;
//}

//hdu 2112 HDU Today
//#include<stdio.h>
//#include<string.h>
//#include<map>
//#include<string>
//#include<algorithm>
//
//const int maxn=200;
//const int inf=1<<29;
//
//int w[maxn][maxn],dis[maxn];
//bool vis[maxn];
//int N,M;
//using namespace std;
//map<string,int>des;
//void Dijkstra(int start,int end)
//{
//    for(int i=1; i<=N; i++)
//        dis[i]=inf;
//    dis[start]=0;
//    for(int i=0; i<N; i++)
//    {
//        int now=inf,x;
//        for(int j=1; j<=N; j++)
//            if(!vis[j]&&dis[j]<now)
//            {
//                now=dis[j];
//                x=j;
//            }
//        vis[x]=true;
//        for(int j=1; j<=N; j++)
//            if(!vis[j]&&dis[j]>dis[x]+w[x][j])
//                dis[j]=dis[x]+w[x][j];
//    }
//    if(dis[end]==inf)
//        printf("-1\n");
//    else
//        printf("%d\n",dis[end]);
//}
//int main()
//{
//    while(~scanf("%d",&M)&&M!=-1)
//    {
//        des.clear();
//        memset(vis,false,sizeof(vis));
//        for(int i=1; i<=maxn; i++)
//            for(int j=i+1; j<=maxn; j++)
//            {
//                w[i][j]=w[j][i]=inf;
//                if(i==j)
//                    w[i][j]=w[j][i]=0;
//            }
//        N=0;
//        char start[32],end[32];
//        scanf("%s%s",start,end);
//        if(!des[start])
//            des[start]=++N;
//        if(!des[end])
//            des[end]=++N;
//        char s[32],e[32];
//        int time;
//        for(int i=1; i<=M; i++)
//        {
//            scanf("%s%s%d",s,e,&time);
//            if(!des[s])
//                des[s]=++N;
//            if(!des[e])
//                des[e]=++N;
//            if(w[des[s]][des[e]]>time)
//                w[des[s]][des[e]]=w[des[e]][des[s]]=time;
//        }
//        Dijkstra(des[start],des[end]);
//    }
//    return 0;
//}

//hdu 2544 最短路
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int maxn=105;
//const int inf=1<<29;
//
//int w[maxn][maxn];
//int N,M;
//using namespace std;
//int main()
//{
//    while(~scanf("%d%d",&N,&M)&&N+M)
//    {
//        for(int i=1; i<=N; i++)
//            for(int j=1; j<=N; j++)
//                w[i][j]=inf;
//        int A,B,C;
//        for(int i=1; i<=M; i++)
//        {
//            scanf("%d%d%d",&A,&B,&C);
//            if(w[A][B]>C)
//                w[A][B]=w[B][A]=C;
//        }
//        for(int k=1; k<=N; k++)
//            for(int i=1; i<=N; i++)
//                for(int j=1; j<=N; j++)
//                    if(k!=i&&k!=j&&w[i][k]!=inf&&w[k][j]!=inf)
//                        w[i][j]=w[j][i]=min(w[i][j],w[i][k]+w[k][j]);
//        printf("%d\n",w[1][N]);
//    }
//    return 0;
//}

//hdu 2680 Choose the best route
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int maxn=1010;
//const int inf=1<<29;
//
//int w[maxn][maxn],dis[maxn];
//bool vis[maxn];
//int n,m;
//using namespace std;
//void Dijkstra(int end)
//{
//    for(int i=1; i<=n; i++)
//        dis[i]=inf;
//    dis[end]=0;
//    for(int i=0; i<n; i++)
//    {
//        int now=inf,x;
//        for(int j=1; j<=n; j++)
//            if(!vis[j]&&dis[j]<now)
//            {
//                now=dis[j];
//                x=j;
//            }
//        vis[x]=true;
//        for(int j=1; j<=n; j++)
//            if(!vis[j]&&dis[j]>dis[x]+w[x][j])
//                dis[j]=dis[x]+w[x][j];
//    }
//    return ;
//}
//int main()
//{
//    int s;
//    while(~scanf("%d%d%d",&n,&m,&s))
//    {
//        memset(vis,false,sizeof(vis));
//        for(int i=1; i<=n; i++)
//            for(int j=1; j<=n; j++)
//            {
//                w[i][j]=inf;
//                if(i==j)
//                    w[i][j]=0;
//            }
//        int p,q,t;
//        for(int i=1; i<=m; i++)
//        {
//            scanf("%d%d%d",&p,&q,&t);
//            if(w[q][p]>t)
//                w[q][p]=t;
//        }
//        Dijkstra(s);
//        int w;
//        scanf("%d",&w);
//        int array[1000];
//        int Min=inf;
//        for(int i=1; i<=w; i++)
//        {
//            scanf("%d",&array[i]);
//            if(Min>dis[array[i]])
//                Min=dis[array[i]];
//        }
//        if(Min==inf)
//            printf("-1\n");
//        else
//            printf("%d\n",Min);
//    }
//    return 0;
//}

//hdu 1596 find the safest road
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int maxn=1010;
//const int inf=1<<29;
//
//double w[maxn][maxn],dis[maxn];
//bool vis[maxn];
//int n;
//void Dijkstra(int start,int end)
//{
//    memset(vis,false,sizeof(vis));
//    for(int i=1; i<=n; i++)
//        dis[i]=0;
//    dis[start]=1;
//    for(int i=0; i<n; i++)
//    {
//        double now=0;
//        int x;
//        for(int j=1; j<=n; j++)
//            if(!vis[j]&&dis[j]>now)
//            {
//                now=dis[j];
//                x=j;
//            }
//        vis[x]=true;
//        for(int j=1; j<=n; j++)
//            if(!vis[j]&&dis[j]<dis[x]*w[x][j])
//                dis[j]=dis[x]*w[x][j];
//    }
//    if(!dis[end])
//        printf("What a pity!\n");
//    else
//        printf("%.3lf\n",dis[end]);
//}
//int main()
//{
//    while(~scanf("%d",&n))
//    {
//        for(int i=1; i<=n; i++)
//            for(int j=1; j<=n; j++)
//                scanf("%lf",&w[i][j]);
//        int Q,u,v;
//        scanf("%d",&Q);
//        for(int i=1; i<=Q; i++)
//        {
//            scanf("%d%d",&u,&v);
//            if(u==v)
//                printf("1.000\n");
//            else
//            Dijkstra(u,v);
//        }
//    }
//    return 0;
//}

//hdu 1142 A Walk Through the Forest
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int maxn=1010;
//const int inf=1<<29;
//
//int w[maxn][maxn],dis[maxn];
//bool vis[maxn];
//int N,M;
//int path[maxn];
//using namespace std;
//void Dijkstra()
//{
//    memset(vis,false,sizeof(vis));
//    for(int i=1; i<=N; i++)
//        dis[i]=inf;
//    dis[2]=0;
//    for(int i=0; i<N; i++)
//    {
//        int now=inf,x;
//        for(int j=1; j<=N; j++)
//            if(!vis[j]&&dis[j]<now)
//            {
//                now=dis[j];
//                x=j;
//            }
//        vis[x]=true;
//        for(int j=1; j<=N; j++)
//            if(!vis[j]&&dis[j]>dis[x]+w[x][j])
//                dis[j]=dis[x]+w[x][j];
//    }
//    return;
//}
//int DFS(int u)
//{
//    if(path[u]!=-1)
//        return path[u];
//    if(u==2)
//        return 1;
//    int cnt=0;
//    for(int v=1; v<=N; v++)
//        if(w[u][v]!=inf&&dis[u]>dis[v])
//            cnt+=DFS(v);
//    path[u]=cnt;
//    return path[u];
//}
//int main()
//{
//    while(~scanf("%d",&N),N)
//    {
//        scanf("%d",&M);
//        for(int i=1; i<=N; i++)
//        {
//            path[i]=-1;
//            for(int j=1; j<=N; j++)
//            {
//                w[i][j]=inf;
//                if(i==j)
//                    w[i][j]=0;
//            }
//        }
//        for(int i=1; i<=M; i++)
//        {
//            int u,v,c;
//            scanf("%d%d%d",&u,&v,&c);
//            if(w[u][v]>c)
//                w[u][v]=w[v][u]=c;
//        }
//        Dijkstra();
//        printf("%d\n",DFS(1));
//    }
//    return 0;
//}

//hdu 1162 Eddy's picture(最小生成树)
//#include<stdio.h>
//#include<string.h>
//#include<math.h>
//#include<algorithm>
//
//const int maxn=1e5;
//
//struct node
//{
//    int u,v;
//    double w;
//    bool operator<(const node &S)const
//    {
//        return w<S.w;
//    }
//}t[maxn];
//struct Node
//{
//    double x,y;
//} array[maxn];
//int n,m;
//int pa[102];
//using namespace std;
//int cha(int x)
//{
//    return x==pa[x]?pa[x]:cha(pa[x]);
//}
//double Kruskal()
//{
//    double sum=0;
//    int tol=0;
//    for(int i=0; i<m; i++)
//    {
//        int x=t[i].u;
//        int y=t[i].v;
//        x=cha(x);
//        y=cha(y);
//        if(x!=y)
//        {
//            pa[x]=y;
//            sum+=t[i].w;
//            tol++;
//        }
//        if(tol==n-1)
//            return sum;
//    }
//    return 0;
//}
//int main()
//{
//    while(~scanf("%d",&n))
//    {
//        for(int i=0; i<=n; i++)
//            pa[i]=i;
//        for(int i=1; i<=n; i++)
//            scanf("%lf%lf",&array[i].x,&array[i].y);
//        m=0;
//        for(int i=1; i<n; i++)
//            for(int j=i+1; j<=n; j++)
//            {
//                t[m].u=i;
//                t[m].v=j;
//                t[m].w=sqrt((array[i].x-array[j].x)*(array[i].x-array[j].x)+(array[i].y-array[j].y)*(array[i].y-array[j].y));
//                m++;
//            }
//        sort(t,t+m);
//        printf("%.2lf\n",Kruskal());
//    }
//}

//hdu 1217 Arbitrage
//#include<stdio.h>
//#include<string.h>
//#include<string>
//#include<algorithm>
//#include<map>
//
//const int maxn=35;
//const int inf=-1;
//
//using namespace std;
//map<string,int>pos;
//double w[maxn][maxn];
//int n,m;
//int main()
//{
//    int T=0;
//    while(~scanf("%d",&n),n)
//    {
//        pos.clear();
//        for(int i=1; i<=n; i++)
//            for(int j=1; j<=n; j++)
//            {
//                w[i][j]=inf;
//                if(i==j)
//                    w[i][j]=1;
//            }
//        char str[100];
//        for(int i=1; i<=n; i++)
//        {
//            scanf("%s",str);
//            pos[str]=i;
//        }
//        scanf("%d",&m);
//        char s[100],e[100];
//        double c;
//        for(int i=1; i<=m; i++)
//        {
//            scanf("%s%lf%s",s,&c,e);
//                w[pos[s]][pos[e]]=c;
//        }
//        for(int k=1; k<=n; k++)
//            for(int i=1; i<=n; i++)
//                for(int j=1; j<=n; j++)
//                    if(k!=i&&k!=j&&w[i][k]!=inf&&w[k][j]!=inf)
//                        w[i][j]=max(w[i][j],w[i][k]*w[k][j]);
//        bool flag=false;
//        for(int i=1; i<=n; i++)
//                if(w[i][i]>1)
//                {
//                    printf("%lf\n",w[i][i]);
//                    flag=true;
//                    break;
//                }
//        if(flag)
//            printf("Case %d: Yes\n",++T);
//        else
//            printf("Case %d: No\n",++T);
//    }
//    return 0;
//}

//MPI Maelstrom
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int maxn=110;
//const int inf=1<<29;
//
//int w[maxn][maxn],dis[maxn];
//bool vis[maxn];
//
//int n,m;
//using namespace std;
//int Dijkstra()
//{
//    memset(vis,false,sizeof(vis));
//    for(int i=1; i<=n; i++)
//        dis[i]=inf;
//    dis[1]=0;
//    for(int i=0; i<n; i++)
//    {
//        int now=inf,x;
//        for(int j=1; j<=n; j++)
//            if(!vis[j]&&dis[j]<now)
//            {
//                now=dis[j];
//                x=j;
//            }
//        vis[x]=true;
//        for(int j=1; j<=n; j++)
//            if(!vis[j]&&dis[j]>dis[x]+w[x][j])
//                dis[j]=dis[x]+w[x][j];
//    }
//    int Max=0;
//    for(int i=1; i<=n; i++)
//        if(dis[i]>Max&&dis[i]!=inf)
//            Max=dis[i];
//    return Max;
//}
//int main()
//{
//    while(~scanf("%d",&n))
//    {
//        for(int i=1; i<=n; i++)
//            for(int j=1; j<=n; j++)
//            {
//                w[i][j]=inf;
//                if(i==j)
//                    w[i][j]=0;
//            }
//        char str[100];
//        for(int i=2; i<=n; i++)
//            for(int j=1; j<=i-1; j++)
//            {
//                scanf("%s",str);
//                if(strcmp(str,"x")==0)
//                    w[i][j]=w[j][i]=inf;
//                else
//                {
//                    int len=strlen(str),ans=0;
//                    for(int k=0; k<len; k++)
//                        ans=10*ans+str[k]-'0';
//                    w[i][j]=w[j][i]=ans;
//                }
//
//            }
//        printf("%d\n",Dijkstra());
//    }
//    return 0;
//}

//Silver Cow Party
#include<stdio.h>
#include<string.h>
#include<algorithm>

const int maxn=1010;
const int inf=1<<29;

int w[maxn][maxn],Fir_dis[maxn],Last_dis[maxn];
bool vis[maxn];

int N,M;
using namespace std;
void Dijkstra(int start)
{
    memset(vis,false,sizeof(vis));
    for(int i=1; i<=N; i++)
        Last_dis[i]=inf;
    Last_dis[start]=0;
    for(int i=0; i<N; i++)
    {
        int now=inf,x;
        for(int j=1; j<=N; j++)
            if(!vis[j]&&Last_dis[j]<now)
            {
                now=Last_dis[j];
                x=j;
            }
        vis[x]=true;
        for(int j=1; j<=N; j++)
            if(!vis[j]&&Last_dis[j]>Last_dis[x]+w[x][j])
                Last_dis[j]=Last_dis[x]+w[x][j];
    }
}
int main()
{
    int X;
    while(~scanf("%d%d%d",&N,&M,&X))
    {
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
            {
                w[i][j]=inf;
                if(i==j)
                    w[i][j]=0;
            }
        int A,B,T;
        for(int i=1; i<=M; i++)
        {
            scanf("%d%d%d",&A,&B,&T);
            if(w[B][A]>T)
                w[B][A]=T;
        }
        Dijkstra(X);
        for(int i=1; i<=N; i++)
            Fir_dis[i]=Last_dis[i];
        for(int i=1; i<N; i++)
            for(int j=i+1; j<=N; j++)
                swap(w[i][j],w[j][i]);
        Dijkstra(X);
        int Max=0;
        for(int i=1; i<=N; i++)
            if(Max<Fir_dis[i]+Last_dis[i])
                Max=Fir_dis[i]+Last_dis[i];
        printf("%d\n",Max);
    }
}

//Wormholes
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int maxn=520;
//const int inf=1<<29;
//
//struct node
//{
//    int from,to,c;
//} e[maxn*maxn];
//int d[maxn];
//int N,M,T;
//bool Bellman_Ford(int st)
//{
//    for(int i=0; i<=N; i++)
//        d[i]=inf;
//    d[st]=0;
//    for(int i=1; i<N; i++)
//        for(int j=0; j<2*M+T; j++)
//            if(d[e[j].to]>d[e[j].from]+e[j].c)
//                d[e[j].to]=d[e[j].from]+e[j].c;
//    for(int i=0; i<2*M+T; i++)
//        if(d[e[i].to]>d[e[i].from]+e[i].c)
//            return true;
//    return false;
//}
//int main()
//{
//    int F;
//    while(~scanf("%d",&F))
//    {
//        while(F--)
//        {
//            scanf("%d%d%d",&N,&M,&T);
//            for(int i=0; i<2*M; i+=2)
//            {
//                scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].c);
//                e[i+1].to=e[i].from;
//                e[i+1].from=e[i].to;
//                e[i+1].c=e[i].c;
//            }
//            for(int i=0; i<T; i++)
//            {
//                int c;
//                scanf("%d%d%d",&e[i+2*M].from,&e[i+2*M].to,&c);
//                e[i+2*M].c=-c;
//            }
//            if(Bellman_Ford(1))
//                printf("YES\n");
//            else
//                printf("NO\n");
//        }
//    }
//    return 0;
//}

//Heavy Cargo
//#include<stdio.h>
//#include<string.h>
//#include<string>
//#include<map>
//#include<algorithm>
//
//const int maxn=210;
//const int inf=1<<29;
//
//int w[maxn][maxn],dist[maxn];
//bool vis[maxn];
//
//int n,r;
//using namespace std;
//map<string,int> temp;
//int main()
//{
//    int T=1;
//    while(~scanf("%d%d",&n,&r)&&n+r)
//    {
//        temp.clear();
//        for(int i=1; i<=n; i++)
//            for(int j=1; j<=n; j++)
//                w[i][j]=0;
//        char u[35],v[35];
//        int c,m=0;
//        for(int i=1; i<=r; i++)
//        {
//            scanf("%s%s%d",u,v,&c);
//            if(!temp[u])
//                temp[u]=++m;
//            if(!temp[v])
//                temp[v]=++m;
//            w[temp[u]][temp[v]]=w[temp[v]][temp[u]]=c;
//        }
//        for(int k=1; k<=n; k++)
//            for(int i=1; i<=n; i++)
//                for(int j=1; j<=n; j++)
//                    w[i][j]=max(w[i][j],min(w[i][k],w[k][j]));
//        char s[35],e[35];
//        scanf("%s%s",s,e);
//        printf("Scenario #%d\n",T++);
//        printf("%d tons\n\n",w[temp[s]][temp[e]]);
//    }
//    return 0;
//}

//Subway
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//#include<math.h>
//
//const int maxn=210;
//const double inf=1<<29;
//
//double w[maxn][maxn],dist[maxn];
//bool vis[maxn];
//struct node
//{
//    double x,y;
//} node[maxn];
//int n;
//using namespace std;
//double Dijkstra()
//{
//    for(int i=1; i<=n; i++)
//    {
//        dist[i]=inf;
//        vis[i]=false;
//    }
//    dist[1]=0;
//    for(int i=0; i<n; i++)
//    {
//        int now=inf,x=-1;
//        for(int j=1; j<=n; j++)
//            if(!vis[j]&&dist[j]<now)
//            {
//                now=dist[j];
//                x=j;
//            }
//        if(x==-1)
//            break;
//        vis[x]=true;
//        for(int j=1; j<=n; j++)
//            if(!vis[j]&&dist[j]>dist[x]+w[x][j])
//                dist[j]=dist[x]+w[x][j];
//    }
//    return dist[2];
//}
//int main()
//{
//    scanf("%lf%lf%lf%lf",&node[1].x,&node[1].y,&node[2].x,&node[2].y);
//    for(int i=1; i<maxn; i++)
//        for(int j=1; j<maxn; j++)
//        {
//            w[i][j]=inf;
//            if(i==j)
//                w[i][j]=0;
//        }
//    double a,b;
//    int cur=3;
//    n=2;
//    while(~scanf("%lf%lf",&a,&b))
//    {
//        if(a==-1&&b==-1)
//        {
//            cur=n+1;
//            continue;
//        }
//        n++;
//        node[n].x=a,node[n].y=b;
//        if(cur!=n)
//            w[n][n-1]=w[n-1][n]=min(w[n][n-1],sqrt((node[n].x-node[n-1].x)*(node[n].x-node[n-1].x)+(node[n].y-node[n-1].y)*(node[n].y-node[n-1].y))*3.0/2000);
//    }
//    for(int i=1; i<=n; i++)
//        for(int j=1; j<=n; j++)
//            w[i][j]=min(w[i][j],sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y))*3.0/500);
//    printf("%.0lf\n",Dijkstra());
//    return 0;
//}

//Currency Exchange
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int maxn=1010;
//const int inf=-1<<29;
//
//struct node
//{
//    int u,v;
//    double R,C;
//} e[maxn*maxn];
//
//double dist[maxn];
//int n,m;
//double num;
//bool Bellman_Ford(int start)
//{
//    for(int i=1; i<=n; i++)
//        dist[i]=-1;
//    dist[start]=num;
//    for(int i=1; i<n; i++)
//        for(int j=0; j<2*m; j++)
//            if(dist[e[j].v]<(dist[e[j].u]-e[j].C)*e[j].R)
//                dist[e[j].v]=(dist[e[j].u]-e[j].C)*e[j].R;
//    for(int i=0; i<2*m; i++)
//        if(dist[e[i].v]<(dist[e[i].u]-e[i].C)*e[i].R)
//            return true;
//    return false;
//}
//int main()
//{
//    int start;
//    while(~scanf("%d%d%d%lf",&n,&m,&start,&num))
//    {
//        for(int i=0; i<2*m; i+=2)
//        {
//            scanf("%d%d%lf%lf%lf%lf",&e[i].u,&e[i].v,&e[i].R,&e[i].C,&e[i+1].R,&e[i+1].C);
//            e[i+1].v=e[i].u;
//            e[i+1].u=e[i].v;
//        }
//        if(Bellman_Ford(start))
//            printf("YES\n");
//        else
//            printf("NO\n");
//    }
//    return 0;
//}

//#include<queue>
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int maxn=25;
//const int inf=1<<29;
//
//int w[maxn][maxn],dist[maxn],pre[maxn];
//bool vis[maxn];
//int N;
//using namespace std;
//void Dijkstra(int start)
//{
//    for(int i=1;i<=N;i++)
//    {
//        dist[i]=inf;
//        vis[i]=false;
//    }
//    dist[start]=0;
//    for(int i=0;i<N;i++)
//    {
//        int now=inf,x;
//        for(int j=1;j<=N;j++)
//        if(!vis[j]&&dist[j]<now)
//        {
//            now=dist[j];
//            x=j;
//        }
//        vis[x]=true;
//        for(int j=1;j<=N;j++)
//            if(!vis[j]&&dist[j]<dist[x]+w[x][j])
//    }
//    return ;
//}
//int main()
//{
//    while(~scanf("%d",&N))
//    {
//        for(int u=1; u<=N; u++)
//            for(int v=1; v<=N; v++)
//            {
//                scanf("%d",&w[u][v]);
//                if(c==-1)
//                    c=inf;
//            }
//        int u;
//        scanf("%d",&u);
//        SPFA(u);
//        int count=0;
//        while(~scanf("%d",&temp[count].v))
//        {
//            temp[count].d=dist[temp[count].v];
//            count++;
//        }
//        sort(temp,temp+count);
//        printf("Org\tDest\tTime\tPath\n");
//        for(int i=0; i<count; i++)
//        {
//            printf("%d\t%d\t%d\t",temp[i].v,u,dist[temp[i].v]);
//            SPFA1(temp[i].v);
//            DFS(2);
//            printf("\n");
//        }
//    }
//    return 0;
//}

//FDNY to the Rescue! SPFA算法
//#include<queue>
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int maxn=25;
//const int maxm=maxn*maxn;
//const int inf=1<<29;
//
//int cnt[maxn],dist[maxn];
//int point[maxm],next[maxm],cost[maxm],head[maxn],pre[maxm];
//bool vis[maxn];
//
//struct node
//{
//    int v,d;
//    bool operator<(const node &S)const
//    {
//        return d<S.d;
//    }
//} temp[100];
//struct Node
//{
//    int u,v,c;
//}array[maxm];
//int N,e;
//using namespace std;
//void AddEdge(int u,int v,int c)
//{
//    point[e]=v;
//    cost[e]=c;
//    next[e]=head[u];
//    head[u]=e++;
//}
//bool SPFA(int start)
//{
//    for(int i=1; i<=N; i++)
//        dist[i]=inf;
//    memset(vis,false,sizeof(vis));
//    memset(cnt,0,sizeof(cnt));
//    memset(pre,-1,sizeof(pre));
//    dist[start]=0;
//    vis[start]=true;
//    queue<int>q;
//    q.push(start);
//    while(!q.empty())
//    {
//        int u=q.front();
//        q.pop();
//        vis[u]=false;
//        for(int i=head[u]; i+1; i=next[i])
//        {
//            if(dist[point[i]]>dist[u]+cost[i])
//            {
//                dist[point[i]]=dist[u]+cost[i];
//                pre[point[i]]=u;
//                if(!vis[point[i]])
//                {
//                    if(++cnt[point[i]]>=N)
//                        return true;
//                    q.push(point[i]);
//                    vis[point[i]]=true;
//                }
//            }
//        }
//    }
//    return false;
//}
//void DFS(int u)
//{
//    if(pre[u]==-1)
//    {
//        printf("%d",u);
//        return ;
//    }
//    DFS(pre[u]);
//    printf("\t%d",u);
//}
//int main()
//{
//    while(~scanf("%d",&N))
//    {
//        e=0;
//        memset(head,-1,sizeof(head));
//        int c;
//        int count=0;
//        for(int u=1; u<=N; u++)
//            for(int v=1; v<=N; v++)
//            {
//                scanf("%d",&c);
//                if(c==-1)
//                    c=inf;
//                AddEdge(v,u,c);
//                array[count].u=u;
//                array[count].v=v;
//                array[count++].c=c;
//            }
//        int u;
//        scanf("%d",&u);
//        SPFA(u);
//        int cur=0;
//        while(~scanf("%d",&temp[cur].v))
//        {
//            temp[cur].d=dist[temp[cur].v];
//            cur++;
//        }
//        sort(temp,temp+cur);
//        e=0;
//        memset(head,-1,sizeof(head));
//        for(int i=0;i<count;i++)
//                AddEdge(array[i].u,array[i].v,array[i].c);
//        printf("Org\tDest\tTime\tPath\n");
//        for(int i=0; i<cur; i++)
//        {
//            printf("%d\t%d\t%d\t",temp[i].v,u,temp[i].d);
//            SPFA(temp[i].v);
//            DFS(u);
//            printf("\n");
//        }
//    }
//    return 0;
//}

//FDNY to the Rescue! Dijkstra算法
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int maxn=25;
//const int inf=1<<29;
//
//int w[maxn][maxn],dist[maxn],pre[maxn];
//bool vis[maxn];
//
//struct node
//{
//    int v,d;
//    bool operator <(const node &S)const
//    {
//        return d<S.d;
//    }
//} array[maxn];
//
//int N;
//using namespace std;
//void Dijkstra(int start)
//{
//    for(int i=1; i<=N; i++)
//    {
//        dist[i]=inf;
//        vis[i]=false;
//        if(i!=start)
//            pre[i]=start;
//        else
//            pre[i]=-1;
//    }
//    dist[start]=0;
//    for(int i=0; i<N; i++)
//    {
//        int now=inf,x;
//        for(int j=1; j<=N; j++)
//            if(!vis[j]&&dist[j]<now)
//            {
//                now=dist[j];
//                x=j;
//            }
//        vis[x]=true;
//        for(int j=1; j<=N; j++)
//            if(!vis[j]&&dist[j]>dist[x]+w[x][j])
//            {
//                dist[j]=dist[x]+w[x][j];
//                pre[j]=x;
//            }
//    }
//}
//void DFS(int u)
//{
//    if(pre[u]==-1)
//    {
//        printf("%d",u);
//        return ;
//    }
//    DFS(pre[u]);
//    printf("\t%d",u);
//}
//int main()
//{
//    while(~scanf("%d",&N))
//    {
//        for(int i=1; i<=N; i++)
//            for(int j=1; j<=N; j++)
//            {
//                scanf("%d",&w[j][i]);
//                if(w[j][i]==-1)
//                    w[j][i]=inf;
//            }
//        int u;
//        scanf("%d",&u);
//        Dijkstra(u);
//        int cur=0;
//        while(~scanf("%d",&array[cur].v))
//        {
//            array[cur].d=dist[array[cur].v];
//            cur++;
//        }
//        sort(array,array+cur);
//        for(int i=1; i<N; i++)
//            for(int j=i+1; j<=N; j++)
//                swap(w[i][j],w[j][i]);
//        printf("Org\tDest\tTime\tPath\n");
//        for(int i=0; i<cur; i++)
//        {
//            printf("%d\t%d\t%d\t",array[i].v,u,array[i].d);
//            Dijkstra(array[i].v);
//            DFS(u);
//            printf("\n");
//        }
//    }
//    return 0;
//}

//Transport Goods
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int maxn=120;
//const int inf=-1;
//
//double w[maxn][maxn],dist[maxn];
//int cost[maxn];
//bool vis[maxn];
//
//int N,M;
//using namespace std;
//double Dijkstra()
//{
//    for(int i=1; i<=N; i++)
//    {
//        dist[i]=w[N][i];
//        vis[i]=false;
//    }
//    vis[N]=true;
//    for(int i=1; i<N; i++)
//    {
//        int x;
//        double now=inf;
//        for(int j=1; j<=N; j++)
//            if(!vis[j]&&dist[j]>now)
//            {
//                now=dist[j];
//                x=j;
//            }
//        vis[x]=true;
//        for(int j=1; j<=N; j++)
//            if(!vis[j]&&dist[j]<dist[x]*w[x][j])
//                dist[j]=dist[x]*w[x][j];
//    }
//    double sum=0;
//    for(int i=1; i<N; i++)
//        sum+=dist[i]*cost[i];
//    return sum;
//}
//int main()
//{
//    while(~scanf("%d%d",&N,&M))
//    {
//        memset(w,0,sizeof(w));
//        for(int i=1; i<N; i++)
//            scanf("%d",&cost[i]);
//        for(int i=1; i<=M; i++)
//        {
//            int u,v;
//            double c;
//            scanf("%d%d%lf",&u,&v,&c);
//            if(w[u][v]<1-c)
//                w[u][v]=w[v][u]=1-c;
//        }
//        printf("%.2lf\n",Dijkstra());
//    }
//    return 0;
//}

//Invitation Cards
//#include<queue>
//#include<stdio.h>
//#include<string.h>
//#include<limits.h>
//#include<algorithm>
//
//const int maxn=1000010;
//const int maxm=1000010;
//const long long inf=LONG_LONG_MAX;
//
//int cnt[maxn];
//long long dist[maxn];
//int point[maxm],next[maxm],cost[maxm],head[maxn];
//bool vis[maxn];
//
//int P,Q,e;
//struct node
//{
//    int u,v,c;
//}temp[maxm];
//using namespace std;
//void AddEdge(int u,int v,int c)
//{
//    point[e]=v;
//    cost[e]=c;
//    next[e]=head[u];
//    head[u]=e++;
//}
//bool SPFA(int start)
//{
//    for(int i=1;i<=P;i++)
//        {
//            dist[i]=inf;
//            vis[i]=false;
//        }
//    dist[start]=0;
//    vis[start]=true;
//    queue<int>q;
//    q.push(start);
//    while(!q.empty())
//    {
//        int u=q.front();
//        q.pop();
//        vis[u]=false;
//        for(int i=head[u];i+1;i=next[i])
//        {
//            if(dist[point[i]]>dist[u]+cost[i])
//            {
//                dist[point[i]]=dist[u]+cost[i];
//                if(!vis[point[i]])
//                {
//                    if(++cnt[point[i]]>=P)
//                        return false;
//                    q.push(point[i]);
//                    vis[point[i]]=true;
//                }
//            }
//        }
//    }
//    return true;
//}
//int main()
//{
//    int N;
//    while(~scanf("%d",&N))
//    {
//        for(int i=1;i<=N;i++)
//        {
//            scanf("%d%d",&P,&Q);
//            e=0;
//            memset(head,-1,sizeof(head));
//            memset(cnt,0,sizeof(cnt));
//            for(int i=1;i<=Q;i++)
//            {
//                int u,v,c;
//                scanf("%d%d%d",&u,&v,&c);
//                AddEdge(u,v,c);
//                temp[e].u=v;
//                temp[e].v=u;
//                temp[e].c=c;
//            }
//            SPFA(1);
//            long long sum=0;
//            for(int i=2;i<=P;i++)
//                sum+=dist[i];
//            memset(head,-1,sizeof(head));
//            memset(cnt,0,sizeof(cnt));
//            e=0;
//            for(int i=1;i<=Q;i++)
//                AddEdge(temp[i].u,temp[i].v,temp[i].c);
//            SPFA(1);
//            for(int i=2;i<=P;i++)
//                sum+=dist[i];
//            printf("%lld\n",sum);
//        }
//    }
//}
