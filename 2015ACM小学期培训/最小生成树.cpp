//Jungle Roads
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int N=27;
//const int inf=1<<29;
//
//using namespace std;
//
//bool flag[N];
//int w[N][N];
//int dis[N];
//int n;
//int Prim()
//{
//    int sum=0;
//    memset(flag,false,sizeof(flag));
//    for(int i=1; i<=n; i++)
//        dis[i]=w[1][i];
//    flag[1]=true;
//    for(int i=1; i<n; i++)
//    {
//        int Min=inf,to=-1;
//        for(int j=1; j<=n; j++)
//            if(dis[j]<Min&&!flag[j])
//            {
//                Min=dis[j];
//                to=j;
//            }
//        if(to==-1)
//            return -1;
//        flag[to]=true;
//        sum+=Min;
//        for(int j=1; j<=n; j++)
//            dis[j]=min(dis[j],w[to][j]);
//    }
//    return sum;
//}
//int main()
//{
//    while(~scanf("%d",&n)&&n)
//    {
//        for(int i=1; i<=n; i++)
//            for(int j=1; j<=n; j++)
//                w[i][j]=inf;
//        char u[2],v[2];
//        int c,num;
//        for(int i=0; i<n-1; i++)
//        {
//            scanf("%s%d",u,&num);
//            for(int j=0; j<num; j++)
//            {
//                scanf("%s%d",v,&c);
//                w[u[0]-'A'+1][v[0]-'A'+1]=w[v[0]-'A'+1][u[0]-'A'+1]=c;
//            }
//        }
//        printf("%d\n",Prim());
//    }
//}

//Networking
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int N=52;
//const int inf=1<<29;
//
//bool flag[N];
//int dis[N];
//int w[N][N];
//int n;
//using namespace std;
//int Prim()
//{
//    int sum=0;
//    memset(flag,false,sizeof(flag));
//    for(int i=1; i<=n; i++)
//        dis[i]=w[1][i];
//    flag[1]=true;
//    for(int i=1; i<n; i++)
//    {
//        int Min=inf,to=-1;
//        for(int j=1; j<=n; j++)
//            if(dis[j]<Min&&!flag[j])
//            {
//                Min=dis[j];
//                to=j;
//            }
//        if(to==-1)
//            return -1;
//        flag[to]=true;
//        sum+=Min;
//        for(int j=1; j<=n; j++)
//            dis[j]=min(dis[j],w[to][j]);
//    }
//    return sum;
//}
//int main()
//{
//    int m;
//    while(~scanf("%d%d",&n,&m)&&n)
//    {
//        for(int i=1; i<=n; i++)
//            for(int j=1; j<=n; j++)
//                w[i][j]=inf;
//        int u,v,c;
//        for(int i=0; i<m; i++)
//        {
//            scanf("%d%d%d",&u,&v,&c);
//            w[u][v]=w[v][u]=min(w[u][v],c);
//        }
//        printf("%d\n",Prim());
//    }
//    return 0;
//}

//畅通工程再续
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//#include<math.h>
//
//const int N=1e5;
//
//struct node
//{
//    int u,v;
//    double w;
//    bool operator<(const node &C)const
//    {
//        return w<C.w;
//    }
//} t[N];
//struct Node
//{
//    int x,y;
//} array[101];
//int m,n;
//int p[101];
//double sum;
//using namespace std;
//int cha(int x)
//{
//    return x==p[x]?p[x]:cha(p[x]);
//}
//int Kruskal()
//{
//    sum=0;
//    int tol=0;
//    for(int i=0; i<m; i++)
//    {
//        int x=t[i].u;
//        int y=t[i].v;
//        x=cha(x);
//        y=cha(y);
//        if(x!=y&&t[i].w<=1000&&t[i].w>=10)
//        {
//            p[x]=y;
//            sum+=t[i].w;
//            tol++;
//        }
//        if(tol==n-1)
//            return 1;
//    }
//    return 0;
//}
//int main()
//{
//    int T;
//    while(~scanf("%d",&T))
//    {
//        while(T--)
//        {
//            scanf("%d",&n);
//            for(int i=0; i<=n; i++)
//                p[i]=i;
//            for(int i=0; i<n; i++)
//                scanf("%d%d",&array[i].x,&array[i].y);
//            m=0;
//            for(int i=0; i<n; i++)
//                for(int j=i+1; j<n; j++)
//                {
//                    t[m].u=i;
//                    t[m].v=j;
//                    t[m].w=(double)sqrt((array[i].x-array[j].x)*(array[i].x-array[j].x)+(array[i].y-array[j].y)*(array[i].y-array[j].y));
//                    m++;
//                }
//            sort(t,t+m);
//            if(Kruskal()==0)
//                printf("oh!\n");
//            else
//            {
//                double ans=sum*100;
//                printf("%.1lf\n",ans);
//            }
//        }
//    }
//    return 0;
//}

//还是畅通工程
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
//int p[101];
//using namespace std;
//int cha(int x)
//{
//    return x==p[x]?p[x]:cha(p[x]);
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
//    return 0;
//}
//int main()
//{
//    while(~scanf("%d",&n)&&n)
//    {
//        for(int i=1; i<=n; i++)
//            p[i]=i;
//        m=n*(n-1)/2;
//        for(int i=0; i<m; i++)
//            scanf("%d%d%d",&t[i].u,&t[i].v,&t[i].w);
//        sort(t,t+m);
//        printf("%d\n",Kruskal());
//    }
//    return 0;
//}

//Agri-Net
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int N=105;
//const int inf=1<<29;
//
//bool flag[N];
//int dis[N];
//int w[N][N];
//int n;
//using namespace std;
//int Prim()
//{
//    int sum=0;
//    memset(flag,false,sizeof(flag));
//    for(int i=1; i<=n; i++)
//        dis[i]=w[1][i];
//    flag[1]=true;
//    for(int i=1; i<n; i++)
//    {
//        int Min=inf,to=-1;
//        for(int j=1; j<=n; j++)
//            if(dis[j]<Min&&!flag[j])
//            {
//                Min=dis[j];
//                to=j;
//            }
//        if(to==-1)
//            return -1;
//        flag[to]=true;
//        sum+=Min;
//        for(int j=1; j<=n; j++)
//            dis[j]=min(dis[j],w[to][j]);
//    }
//    return sum;
//}
//int main()
//{
//    int m;
//    while(~scanf("%d",&n)&&n)
//    {
//        for(int i=1; i<=n; i++)
//            for(int j=1; j<=n; j++)
//                scanf("%d",&w[i][j]);
//        printf("%d\n",Prim());
//    }
//    return 0;
//}

//Constructing Roads
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int N=101;
//const int inf=1<<29;
//
//int dis[N],w[N][N];
//bool flag[N];
//int n;
//using namespace std;
//int Prim()
//{
//    int sum=0;
//    memset(flag,false,sizeof(flag));
//    for(int i=1; i<=n; i++)
//        dis[i]=w[1][i];
//    flag[1]=true;
//    for(int i=1; i<n; i++)
//    {
//        int Min=inf,to=-1;
//        for(int j=1; j<=n; j++)
//            if(!flag[j]&&dis[j]<Min)
//            {
//                Min=dis[j];
//                to=j;
//            }
//        if(to==-1)
//            return -1;
//        sum+=Min;
//        flag[to]=true;
//        for(int j=1; j<=n; j++)
//            dis[j]=min(dis[j],w[to][j]);
//    }
//    return sum;
//}
//int main()
//{
//    while(~scanf("%d",&n))
//    {
//        for(int i=1; i<=n; i++)
//            for(int j=1; j<=n; j++)
//                scanf("%d",&w[i][j]);
//        int Q,start,end;
//        scanf("%d",&Q);
//        for(int i=1; i<=Q; i++)
//        {
//            scanf("%d%d",&start,&end);
//            w[start][end]=w[end][start]=0;
//        }
//        printf("%d\n",Prim());
//    }
//    return 0;
//}

// Building a Space Station
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//#include<math.h>
//
//const int N=1e5;
//
//struct node
//{
//    int u,v;
//    double w;
//    bool operator<(const node &C)const
//    {
//        return w<C.w;
//    }
//} t[N];
//struct Node
//{
//    double x,y,z,r;
//} array[101];
//int m,n;
//int p[101];
//using namespace std;
//int cha(int x)
//{
//    return x==p[x]?p[x]:cha(p[x]);
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
//            p[x]=y;
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
//    while(~scanf("%d",&n)&&n)
//    {
//        for(int i=0; i<=n; i++)
//            p[i]=i;
//        for(int i=0; i<n; i++)
//            scanf("%lf%lf%lf%lf",&array[i].x,&array[i].y,&array[i].z,&array[i].r);
//        m=0;
//        for(int i=0; i<n; i++)
//            for(int j=i+1; j<n; j++)
//            {
//                t[m].u=i;
//                t[m].v=j;
//                double temp=sqrt((array[i].x-array[j].x)*(array[i].x-array[j].x)+(array[i].y-array[j].y)*(array[i].y-array[j].y)+(array[i].z-array[j].z)*(array[i].z-array[j].z))-(array[i].r+array[j].r);
//                if(temp<0)
//                    t[m].w=0;
//                else
//                    t[m].w=temp;
//                m++;
//            }
//        sort(t,t+m);
//        printf("%.3lf\n",Kruskal());
//    }
//    return 0;
//}

//Highways Kruskal算法
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//#include<math.h>
//
//const int N=800;
//
//struct node
//{
//    int u,v;
//    double w;
//    bool operator<(const node &S)const
//    {
//        return w<S.w;
//    }
//} t[N*N>>1];
//struct Node
//{
//    double x,y;
//} array[N];
//int pa[N];
//int tol;
//int n,m;
//using namespace std;
//int cha(int x)
//{
//    return x==pa[x]?pa[x]:cha(pa[x]);
//}
//void Kruskal()
//{
//    for(int i=0; i<m; i++)
//    {
//        int x=t[i].u;
//        int y=t[i].v;
//        x=cha(x);
//        y=cha(y);
//        if(x!=y)
//        {
//            pa[x]=y;
//            printf("%d %d\n",t[i].u,t[i].v);
//            tol++;
//        }
//        if(tol==n-1)
//            break;
//    }
//    return ;
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
//                t[m].w=(double)sqrt((array[i].x-array[j].x)*(array[i].x-array[j].x)+(array[i].y-array[j].y)*(array[i].y-array[j].y));
//                m++;
//            }
//        sort(t,t+m);
//        int edge;
//        int from,to;
//        scanf("%d",&edge);
//        tol=0;
//        for(int i=1; i<=edge; i++)
//        {
//            scanf("%d%d",&from,&to);
//            int x=cha(from);
//            int y=cha(to);
//            if(x!=y)
//                {
//                    pa[x]=y;
//                    tol++;
//                }
//        }
//        Kruskal();
//    }
//    return 0;
//}

//Highways Prim算法
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//#define MAXN 1100
//#define INF 1<<29
//
//int map[MAXN][MAXN];
//int path[MAXN];
//int dis[MAXN];
//int vis[MAXN];
//int x[MAXN],y[MAXN];
//int n,m;
//void Prim()
//{
//    memset(vis,0,sizeof(vis));
//    for(int i=1; i<=n; i++)
//    {
//        dis[i]=map[1][i];
//        path[i]=1;
//    }
//    vis[1]=1;
//    for(int i=1; i<=n; i++)
//    {
//        int to=0;
//        int min=INF;
//        for(int j=1; j<=n; j++)
//            if(!vis[j]&&dis[j]<min)
//            {
//                min=dis[j];
//                to=j;
//            }
//        vis[to]=1;
//        if(map[path[to]][to])
//            printf("%d %d\n",to,path[to]);
//        for(int j=1; j<=n; j++)
//            if(!vis[j]&&dis[j]>map[to][j])
//            {
//                dis[j]=map[to][j];
//                path[j]=to;
//            }
//    }
//}
//int main()
//{
//    while(~scanf("%d",&n))
//    {
//        for(int i=1; i<=n; i++)
//        {
//            scanf("%d%d",&x[i],&y[i]);
//            for(int j=1; j<=i; j++)
//                map[i][j]=map[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
//        }
//        scanf("%d",&m);
//        int a,b;
//        for(int i=1; i<=m; i++)
//        {
//            scanf("%d%d",&a,&b);
//            map[a][b]=map[b][a]=0;
//        }
//        Prim();
//    }
//    return 0;
//}


//The Unique MST
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int N=1e5;
//
//struct node
//{
//    int u,v,w;
//    bool operator<(const node&S)const
//    {
//        return w<S.w;
//    }
//} t[N];
//int n,m;
//int pa[101];
//int path[10010];
//int sum;
//using namespace std;
//int cha(int x)
//{
//    return x==pa[x]?pa[x]:cha(pa[x]);
//}
//int Kruskal()
//{
//    int first=0,tol=0;
//    for(int i=0; i<m; i++)
//    {
//        int x=t[i].u;
//        int y=t[i].v;
//        x=cha(x);
//        y=cha(y);
//        if(x!=y)
//        {
//            path[tol++]=i;
//            pa[x]=y;
//            first+=t[i].w;
//        }
//        if(tol==n-1)
//            break;
//    }
//    for(int i=0; i<tol; i++)
//    {
//        for(int j=0; j<=n; j++)
//            pa[j]=j;
//        int last=0,cnt=0;
//        for(int j=0; j<m; j++)
//        {
//            if(path[i]==j)
//                continue;
//            int x=t[j].u;
//            int y=t[j].v;
//            x=cha(x);
//            y=cha(y);
//            if(x!=y)
//            {
//                pa[x]=y;
//                last+=t[j].w;
//                cnt++;
//            }
//            if(cnt==n-1&&first==last)
//                return 1;
//        }
//    }
//    sum=first;
//    return 0;
//}
//int main()
//{
//    int T;
//    while(~scanf("%d",&T))
//    {
//        while(T--)
//        {
//            scanf("%d%d",&n,&m);
//            for(int i=0; i<=n; i++)
//                pa[i]=i;
//            for(int i=0; i<m; i++)
//                scanf("%d%d%d",&t[i].u,&t[i].v,&t[i].w);
//            sort(t,t+m);
//            int ans=Kruskal();
//            if(ans)
//                printf("Not Unique!\n");
//            else
//                printf("%d\n",sum);
//        }
//    }
//    return 0;
//}

//QS Network
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int N=1e6;
//
//struct node
//{
//    int u,v,w;
//    bool operator<(const node &S)const
//    {
//        return w<S.w;
//    }
//} t[N];
//int n,m,pa[1005];
//int array[1005];
//using namespace std;
//int cha(int x)
//{
//    return x==pa[x]?pa[x]:cha(pa[x]);
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
//    int T;
//    while(~scanf("%d",&T))
//    {
//        while(T--)
//        {
//            scanf("%d",&n);
//            for(int i=0; i<=n; i++)
//                pa[i]=i;
//            for(int i=1; i<=n; i++)
//                scanf("%d",&array[i]);
//            m=0;
//            for(int i=1; i<=n; i++)
//                for(int j=1; j<=n; j++)
//                {
//                    scanf("%d",&t[m].w);
//                    if(i<j)
//                    {
//                        t[m].u=i;
//                        t[m].v=j;
//                        t[m].w+=array[i]+array[j];
//                        m++;
//                    }
//                }
//            sort(t,t+m);
//            printf("%d\n",Kruskal());
//        }
//    }
//    return 0;
//}

//Truck History
//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int N=2e6;
//
//struct node
//{
//    int u,v,w;
//    bool operator<(const node &S)const
//    {
//        return w<S.w;
//    }
//} t[N];
//int n,m;
//int pa[2005];
//char str[2005][2005];
//using namespace std;
//int cha(int x)
//{
//    return x==pa[x]?pa[x]:cha(pa[x]);
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
//            pa[x]=y;
//            sum+=t[i].w;
//            tol++;
//        }
//        if(tol==n-1)
//            return sum;
//    }
//    return sum;
//}
//int main()
//{
//    while(~scanf("%d",&n)&&n)
//    {
//        for(int i=0;i<=n;i++)
//            pa[i]=i;
//        for(int i=0; i<n; i++)
//            scanf("%s",str[i]);
//        m=0;
//        int len=strlen(str[0]);
//        for(int i=0; i<n-1; i++)
//            for(int j=i+1; j<n; j++)
//            {
//                t[m].u=i+1;
//                t[m].v=j+1;
//                int cnt=0;
//                for(int k=0; k<len; k++)
//                    if(str[i][k]!=str[j][k])
//                        cnt++;
//                t[m].w=cnt;
//                m++;
//            }
//        sort(t,t+m);
//        printf("The highest possible quality is 1/%d.\n",Kruskal());
//    }
//    return 0;
//}

//Arctic Network
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>

const int N=3e5;
struct node
{
    int u,v;
    double w;
    bool operator<(const node &S) const
    {
        return w<S.w;
    }
} t[N];
struct Node
{
    double x,y;
} array[505];
int pa[505];
int n,m,num;
using namespace std;
int cha(int x)
{
    return x==pa[x]?pa[x]:cha(pa[x]);
}
double Kruskal()
{
    int tol=0;
    for(int i=0; i<m; i++)
    {
        int x=t[i].u;
        int y=t[i].v;
        x=cha(x);
        y=cha(y);
        if(x!=y)
        {
            pa[x]=y;
            tol++;
        }
        if(tol==n-num)
            return t[i].w;
    }
    return 0;
}
int main()
{
    int T;
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            scanf("%d%d",&num,&n);
            for(int i=0; i<=n; i++)
                pa[i]=i;
            for(int i=1; i<=n; i++)
                scanf("%lf%lf",&array[i].x,&array[i].y);
            m=0;
            for(int i=1; i<n; i++)
                for(int j=i+1; j<=n; j++)
                {
                    t[m].u=i;
                    t[m].v=j;
                    t[m].w=sqrt((array[i].x-array[j].x)*(array[i].x-array[j].x)+(array[i].y-array[j].y)*(array[i].y-array[j].y));
                    m++;
                }
            sort(t,t+m);
            printf("%.2lf\n",Kruskal());
        }
    }
    return 0;
}
