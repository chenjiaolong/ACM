//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//int N,cnt,flag;
//int array[11],ans[11],vis[11];
//void DFS(int cur)
//{
//    if(cur==N)
//    {
//        cnt++;
//        int i;
//        for(i=0; i<N; i++)
//            if(array[i]!=ans[i])
//                break;
//        if(i==N)
//            flag=1;
//        return ;
//    }
//    for(int i=1; i<=N; i++)
//    {
//        if(!vis[i])
//        {
//            vis[i]=1;
//            ans[cur]=i;
//            if(flag)
//                return ;
//            DFS(cur+1);
//            vis[i]=0;
//        }
//    }
//}
//int main()
//{
//    while(~scanf("%d",&N))
//    {
//        flag=0,cnt=0;
//        for(int i=0; i<N; i++)
//            scanf("%d",&array[i]);
//        memset(vis,0,sizeof(vis));
//        DFS(0);
//        printf("%d\n",cnt);
//    }
//    return 0;
//}

//#include<queue>
//#include<stdio.h>
//#include<string.h>
//
//char map[510][510];
//int dir[4][2]= {{-1,0},{0,1},{1,0},{0,-1}};
//int vis[510][510];
//typedef struct
//{
//    int x,y,step;
//} node;
//node s,g;
//using namespace std;
//int n,m;
//int BFS(int x1,int y1,int x2,int y2)
//{
//    memset(vis,0,sizeof(vis));
//    int i;
//    s.x=x1,s.y=y1,s.step=0;
//    g.x=x2,g.y=y2;
//    queue<node>q;
//    q.push(s);
//    node t,h;
//    while(!q.empty())
//    {
//        t=q.front();
//        q.pop();
//        if(t.x==g.x&&t.y==g.y)
//            return t.step;
//        for(i=0; i<4; i++)
//        {
//            h.x=t.x+dir[i][0];
//            h.y=t.y+dir[i][1];
//            h.step=t.step+1;
//            if(h.x>=0&&h.y>=0&&h.x<n&&h.y<m&&map[h.x][h.y]!='*'&&vis[h.x][h.y]==0)
//            {
//                vis[h.x][h.y]=1;
//                q.push(h);
//            }
//        }
//    }
//    return -1;
//}
//int main()
//{
//    node S,E,X;
//    while(~scanf("%d%d",&n,&m))
//    {
//        for (int i = 0; i < n; i++)
//            scanf("%s",map[i]);
//        for (int i = 0; i < n; i++)
//            for (int j = 0; j < m; j++)
//            {
//                if (map[i][j] == 'S')
//                {
//                    S.x = i;
//                    S.y = j;
//                }
//                else if (map[i][j] == 'E')
//                {
//                    E.x = i;
//                    E.y = j;
//                }
//                else if(map[i][j]=='X')
//                {
//                    X.x=i;
//                    X.y=j;
//                }
//            }
//        int res1=BFS(S.x,S.y,X.x,X.y);
//        int res2=BFS(X.x,X.y,E.x,E.y);
//        if(res1==-1||res2==-1)
//            printf("DBZ Cheat Us\n");
//        else
//            printf("%d\n",res1+res2);
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    int n,m;
//    while(~scanf("%d%d",&n,&m))
//    {
//        char str[100],s[100];
//        for(int i=1; i<=m; i++)
//        {
//            scanf("%s",str);
//            if(strcmp(str,"~")==0)
//            {
//                n=~n;
//                printf("%d\n",n);
//            }
//            else
//            {
//                int num;
//                scanf("%d",&num);
//                if(strcmp(str,">>")==0)
//                    n=(n>>num);
//                if(strcmp(str,"<<")==0)
//                    n=(n<<num);
//                if(strcmp(str,"|")==0)
//                    n=n|num;
//                if(strcmp(str,"&")==0)
//                    n=n&num;
//                if(strcmp(str,"^")==0)
//                    n=n^num;
//                printf("%d\n",n);
//            }
//        }
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//int main()
//{
//    int a,b;
//    while(~scanf("%d%d",&a,&b))
//    {
//        int sum=0;
//        for(int i=a;i<=b;i++)
//            sum+=i*i*i;
//        printf("%d\n",sum);
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//int vis[500005];
//int N,M;
//
//using namespace std;
//int main()
//{
//    int T;
//    while(~scanf("%d",&T))
//    {
//        while(T--)
//        {
//            memset(vis,0,sizeof(vis));
//            scanf("%d%d",&N,&M);
//            for(int i=1; i<=M; i++)
//            {
//                char str[5];
//                scanf("%s",str);
//                if(str[0]=='Q')
//                {
//                    int pos;
//                    scanf("%d",&pos);
//                    if(vis[pos])
//                        printf("face-up\n");
//                    else
//                        printf("face-down\n");
//                }
//                else if(str[0]=='T')
//                {
//                    int first,last;
//                    scanf("%d%d",&first,&last);
//                    for(int i=first; i<=last; i++)
//                        vis[i]=(vis[i]==0?1:0);
//                }
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}


//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int dp[10000][10000];
//int main()
//{
//    char str[10000],str2[10000];
//    while(~scanf("%s%s",str,str2))
//    {
//        for(int i=0; i<1000; i++)
//            dp[i][0]=0;
//        for(int j=0; j<1000; j++)
//            dp[0][j]=0;
//        int Max=0;
//        for(int i=1; i<=strlen(str); i++)
//            for(int j=1; j<=strlen(str2); j++)
//            {
//                if(str[i-1]==str2[j-1])
//                    dp[i][j]=dp[i-1][j-1]+1;
//                else
//                    dp[i][j]=0;
//                if(dp[i][j]>Max)
//                    Max=dp[i][j];
//            }
//        printf("%d\n",Max);
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//const int N=1e6+10;
//
//struct node
//{
//    int u,v;
//    long long w;
//    bool operator<(const node &C)const
//    {
//        return w<C.w;
//    }
//} t[N];
//int m,n;
//int Last;
//int p[100010];
//using namespace std;
//int cha(int x)
//{
//    if(p[x]!=x)
//        p[x]=cha(p[x]);
//    return p[x];
//}
//long long Kruskal()
//{
//    long long sum=0;
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
//            Last=t[i].w;
//            tol++;
//        }
//        if(tol==n-1)
//            return (n-1)*Last-sum;
//    }
//    return -1;
//}
//int main()
//{
//    while(~scanf("%d%d",&n,&m))
//    {
//        for(int i=1; i<=n; i++)
//            p[i]=i;
//        for(int i=0; i<m; i++)
//            scanf("%d%d%lld",&t[i].u,&t[i].v,&t[i].w);
//        sort(t,t+m);
//        printf("%lld\n",Kruskal());
//    }
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//    long long n,ans;
//    int T;
//    while(~scanf("%d",&T))
//    {
//        while(T--)
//        {
//            scanf("%lld",&n);
//            if(n <= 2)
//                ans = n;
//            else if(n % 2)
//                ans = n * (n - 1) * (n - 2);
//            else
//            {
//                if(n%3) ans = n * (n-1) * (n-3);
//                else ans=(n-1) * (n-2) * (n-3);
//            }
//            printf("%lld\n",ans);
//        }
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//unsigned int LISSEx(const int array[], size_t length, int result[])
//{
//    unsigned int i, j, k, l, max;
//
//    //栈数组参数，C99新特性，这里的liss数组与上一个函数意义不同，liss[i]记录长度为i + 1
//    //递增子序列中最大值最小的子序列的最后一个元素（最大元素）在array中的位置
//    unsigned int liss[length];
//
//    //前驱元素数组，用于打印序列
//    unsigned int pre[length];
//
//    liss[0] = 0;
//
//    for(i = 0; i < length; ++i)
//        pre[i] = i;
//    for(i = 1, max = 1; i < length; ++i)
//    {
//        //找到这样的j使得在满足array[liss[j]] > array[i]条件的所有j中，j最小
//        j = 0, k = max - 1;
//        while(k - j > 1)
//        {
//            l = (j + k) / 2;
//            if(array[liss[l]] < array[i])
//                j = l;
//            else
//                k = l;
//        }
//        if(array[liss[j]] < array[i])
//            j = k;
//        //array[liss[0]]的值也比array[i]大的情况
//        if(j == 0)
//            //此处必须加等号，防止array中存在多个相等的最小值时，将最小值填充到liss[1]位置
//            if(array[liss[0]] >= array[i])
//            {
//                liss[0] = i;
//                continue;
//            }
//        //array[liss[max -1]]的值比array[i]小的情况
//        if(j == max - 1)
//            if(array[liss[j]] < array[i])
//            {
//                pre[i] = liss[j];
//                liss[max++] = i;
//                continue;
//            }
//        pre[i] = liss[j - 1];
//        liss[j] = i;
//    }
//    //输出递增子序列
//    i = max - 1;
//    k = liss[max - 1];
//    while(pre[k] != k)
//    {
//        result[i--] = array[k];
//        k = pre[k];
//    }
//    result[i] = array[k];
//    return max;
//}
//int main()
//{
//    int array[] = {1,-1,2,-3,4,-5,6,-7};
//    int ans[8];
//    int max=LISSEx(array,sizeof(array)/sizeof(int),ans);
//    printf("%d\n",max);
//    for(int i=0; i<max; i++)
//        printf("%d%c",ans[i],i==max-1?'\n':' ');
//    return 0;
//}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;
const int maxn = 1e6 + 10;
int n;
int a[maxn],b[maxn], _forward[maxn], back[maxn];
int main()
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i]);
            _forward[i] = 1;
            back[i] = 1;
        }
        int l, r, mid, maxi = 0, len = 0;
        for(int i = 1; i <= n; i ++)
        {
            int num = a[i];
            l = 1;
            r = len;
            while(l <= r)
            {
                mid = (l + r) >> 1;
                //if(num > b[mid]) l = mid + 1; // 递增子序列 lower_bound返回一个非递减序列[first, last)中的第一个大于等于值val的位置。
                if(num >= b[mid]) l = mid + 1;// 非递减子序列 upper_bound返回一个非递减序列[first, last)中第一个大于val的位置
                else r = mid - 1;
            }
            b[l] = num;
            _forward[i] = l;
            if(len < l) len = l;
            if(maxi < _forward[i]) maxi = _forward[i];
        }
        maxi = 0;
        len = 0;
        for(int i = n; i >= 1; i --)
        {
            int num = a[i];
            l = 1;
            r = len;
            while(l <= r)
            {
                mid = (l + r) >> 1;
                // if(num > b[mid]) l = mid + 1; // 递增子序列 lower_bound返回一个非递减序列[first, last)中的第一个大于等于值val的位置。
                if(num >= b[mid]) l = mid + 1;// 非递减子序列 upper_bound返回一个非递减序列[first, last)中第一个大于val的位置
                else r = mid - 1;
            }
            b[l] = num;
            back[i] = l;
            if(len < l) len = l;
            if(maxj < back[i]) maxj = back[i];
        }
        len = 0;
        for(int i = 1; i <= n; i ++)
            if(len < _forward[i] + back[i])
                len = _forward[i] + back[i] - 1;
        printf("%d\n", len);
    }
    return 0;
}

