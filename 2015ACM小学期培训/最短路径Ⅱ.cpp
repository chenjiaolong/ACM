//Frogger
//#include<stdio.h>
//#include<string.h>
//#include<math.h>
//#include<algorithm>
//
//const int maxn=210;
//const int inf=1<<29;
//
//double w[maxn][maxn],dist[maxn];
//bool vis[maxn];
//
//int n;
//struct node
//{
//    double x,y;
//} array[maxn];
//using namespace std;
//int main()
//{
//    int T=1;
//    while(~scanf("%d",&n),n)
//    {
//        for(int i=1; i<=n; i++)
//            for(int j=1; j<=n; j++)
//            {
//                w[i][j]=inf;
//                if(i==j)
//                    w[i][j]=0;
//            }
//        for(int i=1; i<=n; i++)
//            scanf("%lf%lf",&array[i].x,&array[i].y);
//        for(int i=1; i<n; i++)
//            for(int j=i+1; j<=n; j++)
//                w[i][j]=w[j][i]=sqrt(pow(array[i].x-array[j].x,2)+pow(array[i].y-array[j].y,2));
//        for(int k=1; k<=n; k++)
//            for(int i=1; i<=n; i++)
//                for(int j=1; j<=n; j++)
//                    if(k!=i&&k!=j&&w[i][k]!=inf&&w[k][j]!=inf)
//                        w[i][j]=min(w[i][j],max(w[i][k],w[k][j]));
//        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",T++,w[1][2]);
//    }
//    return 0;
//}

//Invitation Cards
//#include<queue>
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int maxn=1000010;
//const int maxm=1000010;
//const long long inf=1000000010;
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

//Heavy Transportation
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int maxn=1010;
//
//int w[maxn][maxn],dist[maxn];
//bool vis[maxn];
//
//int n,m;
//using namespace std;
//int Dijkstra()
//{
//    for(int i=1; i<=n; i++)
//    {
//        dist[i]=w[1][i];
//        vis[i]=false;
//    }
//    vis[1]=true;
//    for(int i=1; i<n; i++)
//    {
//        int now=0,x;
//        for(int j=1; j<=n; j++)
//            if(!vis[j]&&dist[j]>now)
//            {
//                now=dist[j];
//                x=j;
//            }
//        vis[x]=true;
//        for(int j=1; j<=n; j++)
//            if(!vis[j]&&dist[j]<min(dist[x],w[x][j]))
//                dist[j]=min(dist[x],w[x][j]);
//    }
//    return dist[n];
//}
//int main()
//{
//    int T;
//    while(~scanf("%d",&T))
//    {
//        for(int t=1; t<=T; t++)
//        {
//            scanf("%d%d",&n,&m);
//            for(int i=1; i<=n; i++)
//                for(int j=1; j<=n; j++)
//                        w[i][j]=0;
//            for(int i=1;i<=m;i++)
//            {
//                int u,v,c;
//                scanf("%d%d%d",&u,&v,&c);
//                if(w[u][v]<c)
//                    w[u][v]=w[v][u]=c;
//            }
//            printf("Scenario #%d:\n%d\n\n",t,Dijkstra());
//        }
//    }
//    return 0;
//}

//Candies(差分约束基础题，栈式SPFA)
//#include<stack>
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int maxn=150010;
//const int maxm=150010;
//const int inf=1<<29;
//
//int cnt[maxn],dist[maxn];
//int point[maxm],next[maxm],head[maxn],cost[maxm];
//bool vis[maxn];
//
//int N,M,e;
//using namespace std;
//void AddEdge(int u,int v,int c)
//{
//    point[e]=v;
//    cost[e]=c;
//    next[e]=head[u];
//    head[u]=e++;
//}
//bool SPFA(int s)
//{
//    for(int i=1; i<=N; i++)
//    {
//        dist[i]=inf;
//        vis[i]=false;
//    }
//    dist[s]=0;
//    stack<int >st;
//    st.push(s);
//    vis[s]=true;
//    while(!st.empty())
//    {
//        int u=st.top();
//        st.pop();
//        vis[u]=false;
//        for(int i=head[u]; i+1; i=next[i])
//        {
//            if(dist[point[i]]>dist[u]+cost[i])
//            {
//                dist[point[i]]=dist[u]+cost[i];
//                if(!vis[point[i]])
//                {
//                    if(++cnt[point[i]]>=N)
//                        return false;
//                    st.push(point[i]);
//                    vis[point[i]]=true;
//                }
//            }
//        }
//    }
//    return true;
//}
//int main()
//{
//    while(~scanf("%d%d",&N,&M))
//    {
//        e=0;
//        memset(head,-1,sizeof(head));
//        memset(cnt,0,sizeof(head));
//        for(int i=1;i<=M;i++)
//        {
//            int u,v,c;
//            scanf("%d%d%d",&u,&v,&c);
//            AddEdge(u,v,c);
//        }
//        SPFA(1);
//        printf("%d\n",dist[N]);
//    }
//    return 0;
//}

//Cow Contest（传递闭包floyed算法）
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//const int maxn=110;
//const int inf=1<<29;
//int w[maxn][maxn];
//int N,M;
//int main()
//{
//    while(~scanf("%d%d",&N,&M))
//    {
//        for(int i=1; i<=N; i++)
//            for(int j=1; j<=N; j++)
//                w[i][j]=0;
//        int A,B;
//        for(int i=1; i<=M; i++)
//        {
//            scanf("%d%d",&A,&B);
//            w[A][B]=1;
//        }
//        for(int k=1; k<=N; k++)
//            for(int i=1; i<=N; i++)
//                for(int j=1; j<=N; j++)
//                    if(w[i][k]&&w[k][j])
//                        w[i][j]=1;
//        int ans=0;
//        for(int i=1;i<=N;i++)
//        {
//            int sum=0;
//            for(int j=1;j<=N;j++)
//            {
//                if(i==j)
//                    continue;
//                if(w[i][j]||w[j][i])
//                    sum++;
//            }
//            if(sum==N-1)
//                ans++;
//        }
//        printf("%d\n",ans);
//    }
//    return 0;
//}

//Cow Contest（传递闭包floyed算法）
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
const int maxn=110;
const int inf=1<<29;
int w[maxn][maxn];
int N,M;
int main()
{
    while(~scanf("%d%d",&N,&M))
    {
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                {
                    w[i][j]=inf;
                    if(i==j)
                        w[i][j]=0;
                }
        int A,B;
        for(int i=1; i<=M; i++)
        {
            scanf("%d%d",&A,&B);
            w[A][B]=1;
        }
        for(int k=1; k<=N; k++)
            for(int i=1; i<=N; i++)
                for(int j=1; j<=N; j++)
                    w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
        int ans=0;
        for(int i=1;i<=N;i++)
        {
            int sum=0;
            for(int j=1;j<=N;j++)
                if(w[i][j]<inf||w[j][i]<inf)
                    sum++;
            if(sum==N)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
