//Is a tree???

//#include<stdio.h>
//#include<string.h>
//#include<stdbool.h>
//int pa[200];
//bool flag[200];
//int Find(int k)
//{
//    if(pa[k]!=k)
//        pa[k]=Find(pa[k]);
//    return pa[k];
//}
//bool Union(int x,int y)
//{
//    int x1=Find(x);
//    int y1=Find(y);
//    if(x1==y1)
//        return false;
//    pa[y1]=x1;
//    return true;
//}
//int main()
//{
//    int x,y,k=1,first;
//    while(~scanf("%d%d",&x,&y))
//    {
//        if(x==-1&&y==-1)
//            break;
//        if(x==0&&y==0)
//        {
//            printf("Case %d is a tree.\n", k++);
//            continue;
//        }
//        int i;
//        for(i=1; i<=100; i++)
//        {
//            pa[i]=i;
//            flag[i]=false;
//        }
//        flag[x]=flag[y]=true;
//        first=x;
//        bool tree=true;
//        if(x==y) tree=false;
//        else Union(x,y);
//        while(scanf("%d%d",&x,&y)&&x!=0)
//        {
//            flag[x]=flag[y]=true;
//            if(Find(x)==Find(y)) tree=false;
//            if(tree) Union(x,y);
//        }
//        for(i=1; i<=100; i++)
//            if(flag[i]&&Find(i)!=Find(first))
//                tree=false;
//        if(tree)
//            printf("Case %d is a tree.\n", k++);
//        else
//            printf("Case %d is not a tree.\n", k++);
//    }
//    return 0;
//}

//Find them, Catch them
//#include<stdio.h>
//#include<stdbool.h>
//int pa[100010];
//int rank[100010];
//int Find(int k)
//{
//    if(pa[k]!=k)
//    {
//        int t;
//        t=pa[k];
//        pa[k]=Find(pa[k]);
//          rank[k]=(rank[k]+rank[t])%2;
//    }
//
//    return pa[k];
//}
//bool Union(int x,int y)
//{
//    int x1=Find(x);
//    int y1=Find(y);
//    if(x1==y1)
//        return false;
//    pa[y1]=x1;
//    rank[y1]=(rank[x]-rank[y]+1)%2;
//    return true;
//}
//int main()
//{
//    int T,N,M,i;
//    char ch[10];
//    while(~scanf("%d",&T))
//    {
//        for(i=1; i<=T; i++)
//        {
//            scanf("%d%d",&N,&M);
//            int j;
//            for(j=1; j<=N; j++)
//            {
//                pa[j]=j;
//                rank[j]=0;
//            }
//            int k,x,y;
//            for(k=0; k<M; k++)
//            {
//                scanf("%s%d%d",ch,&x,&y);
//                if(ch[0]=='D')
//                    Union(x,y);
//                else if(ch[0]=='A')
//                {
//                    if(Find(x)!=Find(y))
//                        printf("Not sure yet.\n");
//                    else
//                    {
//                        if(rank[x]==rank[y])
//                            printf("In the same gang.\n");
//                        else
//                            printf("In different gangs.\n");
//                    }
//                }
//            }
//
//        }
//    }
//    return 0;
//}

//The Suspects
//#include<stdio.h>
//#include<stdbool.h>
//int pa[30010];
//int num[30010];
//int Find(int k)
//{
//    int temp;
//    if(pa[k]!=k)
//        pa[k]=Find(pa[k]);
//    return pa[k];
//}
//bool Union(int x,int y)
//{
//    int x1=Find(x);
//    int y1=Find(y);
//    if(x1==y1)
//        return false;
//    if(num[x1]<=num[y1])
//    {
//        pa[x1]=y1;
//        num[y1]+=num[x1];
//    }
//    else
//    {
//        pa[y1]=x1;
//        num[x1]+=num[y1];
//    }
//    return true;
//}
//int main()
//{
//    int n,m,k,cnt=0;
//    while(~scanf("%d%d",&n,&m))
//    {
//        int i,j,x,y;
//        if(m+n==0)
//            break;
//        for(i=0; i<n; i++)
//        {
//            pa[i]=i;
//            num[i]=1;
//        }
//        for(i=0; i<m; i++)
//        {
//            scanf("%d",&k);
//            scanf("%d",&x);
//            for(j=1; j<k; j++)
//            {
//                scanf("%d",&y);
//                Union(x,y);
//            }
//        }
//        printf("%d\n",num[Find(0)]);
//    }
//    return 0;
//}

//Ubiquitous Religions
//#include<stdio.h>
//#include<stdbool.h>
//int pa[50010];
//int Find(int k)
//{
//    while(pa[k]!=k)
//        k=pa[k];
//    return k;
//}
//bool Union(int x,int y)
//{
//    int a=Find(x);
//    int b=Find(y);
//    if(a==b)
//        return false;
//    pa[a]=b;
//    return true;
//}
//int main()
//{
//    int n,m,num=0;
//    while(~scanf("%d%d",&n,&m)&&m!=0&&n!=0)
//    {
//        int i,j,cnt=0;
//        for(i=1; i<=n; i++)
//            pa[i]=i;
//        int x,y;
//        for(i=1; i<=m; i++)
//        {
//            scanf("%d%d",&x,&y);
//            Union(x,y);
//        }
//        for(i=1; i<=n; i++)
//            if(pa[i]==i)
//                cnt++;
//        printf("Case %d: %d\n",++num,cnt);
//    }
//}

//哈密顿绕行世界问题
//#include<stdio.h>
//#include<string.h>
//#include<stdbool.h>
//int num[21][3]= {0};
//int tracert[25];
//bool vis[25];
//int n,m;
//void DFS(int cur,int cnt)
//{
//    int i;
//    if(cnt==21)
//    {
//        if(tracert[21]==m)
//        {
//        int i;
//        printf("%d:  %d",++n,tracert[1]);
//        for(i=2; i<=21; i++)
//            printf(" %d",tracert[i]);
//        printf("\n");
//        }
//        return ;
//    }
//    for(i=0; i<3; i++)
//    {
//        if(!vis[num[cur][i]])
//        {
//            vis[num[cur][i]]=true;
//            tracert[cnt+1]=num[cur][i];
//            DFS(num[cur][i],cnt+1);
//            vis[num[cur][i]]=false;
//        }
//    }
//
//}
//int main()
//{
//    int i,j;
//    for(i=1; i<=20; i++)
//        for(j=0; j<3; j++)
//            scanf("%d",&num[i][j]);
//    while(~scanf("%d",&m)&&m)
//    {
//        n=0;
//        //memset(tracert,0,sizeof(tracert));
//        memset(vis,false,sizeof(vis));
//        tracert[1]=m;
//        DFS(m,1);
//    }
//    return 0;
//}

//食物链
#include<stdio.h>

int pa[50010];
int rank[50010];
int D,cnt=0;
int Find(int k)
{
    if(pa[k]!=k)
    {
        int t;
        t=pa[k];
        pa[k]=Find(pa[k]);
        rank[k]=(rank[k]+rank[t]+3)%3;
    }
    return pa[k];
}
void Union(int x, int y)
{
    int a=Find(x);
    int b=Find(y);
    if(a==b)
    {
        if(D==1&&rank[x]!=rank[y])
            cnt++;
        if(D==2&&(rank[y]-rank[x]+3)%3!=D-1)
            cnt++;
    }
    else
    {
        pa[b]=a;
        rank[b]=(rank[x]-rank[y]+(D-1)+3)%3;
    }
}
int main()
{
    int N,K,t;
    scanf("%d%d",&N,&K);
    t=N;
    cnt=0;
    while(t--)
    {
        pa[t]=t;
        rank[t]=0;
    }
    while(K--)
    {
        int x,y;
        scanf("%d%d%d",&D,&x,&y);
        if(x>N||y>N)
            cnt++;
        else if(D==2&&x==y)
            cnt++;
        else Union(x, y);
    }
    printf("%d\n",cnt);
    return 0;
}
