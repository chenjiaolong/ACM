//#include<stdio.h>
//#include<string.h>
//int c[200010],array[200010],N;
//int lowbit(int x)
//{
//    return x&(-x);
//}
//int Sum(int x)
//{
//    int sum=0;
//    while(x>0)
//    {
//        sum+=c[x];
//        x=x-lowbit(x);
//    }
//    return sum;
//}
//void Add(int i,int x)
//{
//    while(i<=N)
//    {
//        c[i]+=x;
//        i+=lowbit(i);
//    }
//}
//int main()
//{
//    int cnt=1;
//    while(~scanf("%d",&N)&&N)
//    {
//        if(cnt!=1)
//            printf("\n");
//        memset(c,0,sizeof(c));
//        for(int i=1; i<=N; i++)
//        {
//            scanf("%d",&array[i]);
//            Add(i,array[i]);
//        }
//        char str[20];
//        int ans[200010];
//        int cur=0;
//        while(1)
//        {
//            scanf("%s",str);
//            if(strcmp(str,"END")==0)
//                break;
//            else if(str[0]=='M')
//            {
//                int x,y;
//                scanf("%d%d",&x,&y);
//                ans[cur++]=Sum(y)-Sum(x-1);
//            }
//            /*else if(str[0]=='S')
//            {
//                int x,r;
//                scanf("%d%d",&x,&r);
//                Add(x,-array[x]);
//                array[x]=r;
//                Add(x,array[x]);
//            }*/
//            else if(str[0]=='S')
//            {
//                int x,r;
//                scanf("%d%d",&x,&r);
//                Add(x,r-array[x]);
//                array[x]=r;
//            }
//        }
//        printf("Case %d:\n",cnt++);
//        for(int i=0; i<cur; i++)
//            printf("%d\n",ans[i]);
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<time.h>
//#include<algorithm>
//using namespace std;
//int array[200010];
//int c[200010],n,m;
//int lowbit(int x)
//{
//    return x&(-x);
//}
//int Sum(int x)
//{
//    int sum=0;
//    while(x>0)
//    {
//        sum+=c[x];
//        x-=lowbit(x);
//    }
//    return sum;
//}
//void Add(int i,int x)
//{
//    while(i<=n+m)
//    {
//        c[i]+=x;
//        i+=lowbit(i);
//    }
//}
//int main()
//{
//    int T;
//    int ans[200005];
//    //clock_t start,finish;
//    //start=clock();
//    while(~scanf("%d",&T))
//    {
//        while(T--)
//        {
//            memset(c,0,sizeof(c));
//            scanf("%d%d",&n,&m);
//            for(int i=1;i<=n;i++)
//                {
//                    array[i]=n-i+1;
//                    Add(i,1);
//                }
//            int temp,h=n;
//            for(int i=1;i<=m;i++)
//            {
//                scanf("%d",&temp);
//                ans[i]=Sum(h)-Sum(array[temp]);
//                Add(array[temp],-1);
//                array[temp]=++h;
//                Add(h,1);
//            }
//            for(int i=1;i<=m;i++)
//                printf("%d%c",ans[i],i==m?'\n':' ');
//        }
//    }
//    //finish=clock();
//    //printf("%f",double(finish-start)/CLOCKS_PER_SEC);
//    return 0;
//}

//Ultra-QuickSort 归并排序
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int array[500005];
//int temp[500005];
//long long Merge(int low,int mid,int high)
//{
//    int i=low,j=mid+1,k=low;
//    long long cnt=0;
//    while(i<=mid&&j<=high)
//    {
//        if(array[i]<=array[j])
//            temp[k++]=array[i++];
//        else
//        {
//            temp[k++]=array[j++];
//            cnt+=(j-k);
//        }
//    }
//    while(i<=mid)
//        temp[k++]=array[i++];
//    while(j<=high)
//        temp[k++]=array[j++];
//    for(i=low; i<=high; i++)
//        array[i]=temp[i];
//    return cnt;
//}
//long long MergeSort(int low,int high)
//{
//    long long cnt=0;
//    if(low<high)
//    {
//        int mid=(low+high)/2;
//        cnt+=MergeSort(low,mid);
//        cnt+=MergeSort(mid+1,high);
//        cnt+=Merge(low,mid,high);
//    }
//    return cnt;
//}
//int main()
//{
//    int n;
//    while(~scanf("%d",&n)&&n)
//    {
//        for(int i=0; i<n; i++)
//            scanf("%d",&array[i]);
//        printf("%lld\n",MergeSort(0,n-1));
//    }
//    return 0;
//}

//Ultra-QuickSort 树状数组
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//int c[500010],n;
//using namespace std;
//struct node
//{
//    int data;
//    int id;
//}array[500010];
//int cmp(node p1,node p2)
//{
//    return p1.data<p2.data;
//}
//int CMP(node p1,node p2)
//{
//    return p1.id<p2.id;
//}
//int lowbit(int x)
//{
//    return x&(-x);
//}
//int Sum(int x)
//{
//    int sum=0;
//    while(x>0)
//    {
//        sum+=c[x];
//        x-=lowbit(x);
//    }
//    return sum;
//}
//void Add(int i,int x)
//{
//    while(i<=n)
//    {
//        c[i]+=x;
//        i+=lowbit(i);
//    }
//}
//int main()
//{
//    while(~scanf("%d",&n)&&n)
//    {
//        for(int i=1;i<=n;i++)
//        {
//            scanf("%d",&array[i].data);
//            array[i].id=i;
//        }
//        sort(array+1,array+1+n,cmp);
//        for(int i=1;i<=n;i++)
//            array[i].data=i;
//        sort(array+1,array+1+n,CMP);
//        //for(int i=1;i<=n;i++)
//            //printf("%d ",array[i].data);
//        memset(c,0,sizeof(c));
//        long long ans=0;
//        for(int i=1;i<=n;i++)
//        {
//            Add(array[i].data,1);
//            ans+=Sum(n)-Sum(array[i].data);
//        }
//        printf("%lld\n",ans);
//    }
//    return 0;
//}

//Ultra-QuickSort 用数组来牺牲空间复杂度换取时间
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//int c[500010],data[500010],n;//树状数组，离散化后的数组
//using namespace std;
//struct node
//{
//    int data;
//    int id;
//}array[500010];
//int cmp(node p1,node p2)
//{
//    return p1.data<p2.data;
//}
//int lowbit(int x)
//{
//    return x&(-x);
//}
//int Sum(int x)
//{
//    int sum=0;
//    while(x>0)
//    {
//        sum+=c[x];
//        x-=lowbit(x);
//    }
//    return sum;
//}
//void Add(int i,int x)
//{
//    while(i<=n)
//    {
//        c[i]+=x;
//        i+=lowbit(i);
//    }
//}
//int main()
//{
//    while(~scanf("%d",&n)&&n)
//    {
//        //离散化
//        for(int i=1;i<=n;i++)
//        {
//            scanf("%d",&array[i].data);
//            array[i].id=i;
//        }
//        sort(array+1,array+1+n,cmp);
//        for(int i=1;i<=n;i++)
//            data[array[i].id]=i;
//        //for(int i=1;i<=n;i++)
//            //printf("%d%c",data[i],i==n?'\n':' ');
//        //树状数组求逆序
//        memset(c,0,sizeof(c));
//        long long ans=0;
//        for(int i=1;i<=n;i++)
//        {
//            Add(data[i],1);
//            ans+=Sum(n)-Sum(data[i]);
//        }
//        printf("%lld\n",ans);
//    }
//    return 0;
//}

//修桥求交叉点的个数，树状数组算法
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int c[1010],N,M,K;
//struct node
//{
//    int x;
//    int y;
//    bool operator <(const node &s)const
//    {
//        if(x==s.x)
//            return y<s.y;
//        return x<s.x;
//    }
//}array[1000005];
//int lowbit(int x)
//{
//    return x&(-x);
//}
//int Sum(int x)
//{
//    int sum=0;
//    while(x>0)
//    {
//        sum+=c[x];
//        x-=lowbit(x);
//    }
//    return sum;
//}
//void Add(int i,int x)
//{
//    while(i<=M)
//    {
//        c[i]+=x;
//        i+=lowbit(i);
//    }
//}
//int main()
//{
//    int T;
//    while(~scanf("%d",&T))
//    {
//        for(int t=1;t<=T;t++)
//        {
//            scanf("%d%d%d",&N,&M,&K);
//            for(int i=1;i<=K;i++)
//                scanf("%d%d",&array[i].x,&array[i].y);
//            sort(array+1,array+K+1);
//            memset(c,0,sizeof(c));
//            long long ans=0;
//            for(int i=1;i<=K;i++)
//            {
//                Add(array[i].y,1);
//                ans+=i-Sum(array[i].y);
//            }
//            printf("Test case %d: %lld\n",t,ans);
//        }
//    }
//    return 0;
//}

//修桥求交叉点的个数，归并算法
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int T[1000010],N,M,K;
//struct node
//{
//    int x;
//    int y;
//    bool operator <(const node &s)const
//    {
//        if(x==s.x)
//            return y<s.y;
//        return x<s.x;
//    }
//} array[1000010];
//long long Merge(int low,int mid,int high)
//{
//    int i=low,j=mid+1,k=low;
//    long long cnt=0;
//    while(i<=mid&&j<=high)
//    {
//        if(array[i].y<=array[j].y)
//            T[k++]=array[i++].y;
//        else
//        {
//            T[k++]=array[j++].y;
//            cnt+=(j-k);
//        }
//    }
//    while(i<=mid)
//        T[k++]=array[i++].y;
//    while(j<=high)
//        T[k++]=array[j++].y;
//    for(i=low; i<=high; i++)
//        array[i].y=T[i];
//    return cnt;
//}
//long long MergeSort(int low,int high)
//{
//    long long cnt=0;
//    if(low<high)
//    {
//        int mid=(low+high)/2;
//        cnt+=MergeSort(low,mid);
//        cnt+=MergeSort(mid+1,high);
//        cnt+=Merge(low,mid,high);
//    }
//    return cnt;
//}
//int main()
//{
//    int T;
//    while(~scanf("%d",&T))
//    {
//        for(int t=1; t<=T; t++)
//        {
//            scanf("%d%d%d",&N,&M,&K);
//            for(int i=0; i<K; i++)
//                scanf("%d%d",&array[i].x,&array[i].y);
//            sort(array,array+K);
//            printf("Test case %d: %lld\n",t,MergeSort(0,K-1));
//        }
//    }
//    return 0;
//}


// POJ2352 Stars
//#include <cstdio>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int maxn = 32010;
//
//int c[maxn + 10];
//int ans[maxn + 10];
//inline int lowbit(int x)
//{
//    return x & (-x);
//}
//void Add(int i, int x)
//{
//    while(i <= maxn)
//    {
//        c[i] += x;
//        i += lowbit(i);
//    }
//}
//int Sum(int x)
//{
//    int sum = 0;
//    while(x > 0)
//    {
//        sum += c[x];
//        x -= lowbit(x);
//    }
//    return sum;
//}
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//
//        for(int i = 0; i <= maxn; i ++)
//            c[i] = ans[i] = 0;
//        for(int i = 1; i <= n; i ++)
//        {
//            int x, y;
//            scanf("%d%d", &x, &y);
//            x ++;
//            Add(x, 1);
//            int res = Sum(x);
//            ans[res]++;
//        }
//        for(int i = 1; i <= n; i ++)
//            printf("%d\n", ans[i]);
//    }
//    return 0;
//}

// POJ2481Cows真子集的个数
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int maxn = 1e5 + 100;
//
//int c[maxn];
//int ans[maxn];
//
//struct node
//{
//    int s,e;
//    int id;
//    bool operator <(const node &C) const
//    {
//        if(e == C.e) return s < C.s;
//        return e > C.e;
//    }
//} p[maxn];
//inline int lowbit(int x)
//{
//    return x & (-x);
//}
//void Add(int i, int x)
//{
//    while(i <= maxn)
//    {
//        c[i] += x;
//        i += lowbit(i);
//    }
//}
//int Sum(int x)
//{
//    int sum = 0;
//    while(x > 0)
//    {
//        sum += c[x];
//        x -= lowbit(x);
//    }
//    return sum;
//}
//int main()
//{
//    int N;
//    while(scanf("%d", &N), N)
//    {
//        for(int i = 0; i <= maxn; i ++)
//            c[i] = ans[i] = 0;
//        for(int i = 1; i <= N; i ++)
//        {
//            scanf("%d%d", &p[i].s, &p[i].e);
//            p[i].s ++;
//            p[i].e ++;
//            p[i].id = i;
//        }
//        sort(p + 1, p + N + 1);
//        for(int i = 1; i <= N; i ++)
//        {
//            if(p[i].s == p[i - 1].s && p[i].e == p[i - 1].e)ans[p[i].id] = ans[p[i - 1].id];
//            else ans[p[i].id] = Sum(p[i].s);
//            Add(p[i].s, 1);
//        }
//        for(int i = 1; i <= N; i ++)
//            printf("%d%c", ans[i], i == N ? '\n' : ' ');
//    }
//    return 0;
//}


// POJ3321 Apple Tree dfs序的应用
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<algorithm>
//#include <iostream>
//
//using namespace std;
//
//const int maxn = 2e5 + 10100;
//
//struct node
//{
//    int v, next;
//} edge[maxn];
//int head[maxn], e;
//int tot;
//// DFS 序入栈和出栈的时间戳
//int in[maxn], out[maxn];
//// 树状数组
//int C[maxn], h[maxn];
//int n;
//void DFS(int u)
//{
//    in[u] = ++tot;
//    for(int v = head[u]; v; v = edge[v].next)
//        DFS(edge[v].v);
//    out[u] = tot;
//    return ;
//}
//inline int lowbit(int x)
//{
//    return x & (-x);
//}
//
//void update(int i, int v)
//{
//    while(i <= n)
//    {
//        C[i] += v;
//        i += lowbit(i);
//    }
//}
//int getSum(int x)
//{
//    int sum = 0;
//    while(x)
//    {
//        sum += C[x];
//        x -= lowbit(x);
//    }
//    return sum;
//}
//int main()
//{
//    int m;
//    while(scanf("%d", &n) != EOF)
//    {
//        int u, v;
//        e = 0;
//        tot = 0;
//        for(int i = 0; i <= n; i ++)
//        {
//            head[i] = 0;
//            h[i] = 0;
//            C[i] = 0;
//        }
//        for(int i = 1; i < n; i ++)
//        {
//            scanf("%d%d", &u, &v);
//            edge[++e].v = v;
//            edge[e].next = head[u];
//            head[u] = e;
//        }
//        DFS(1);
//        for(int i = 1; i <= n; i ++)
//        {
//            h[i] = 1;
//            update(in[i], 1);
//        }
//        scanf("%d", &m);
//        char str[5];
//        int x;
//        while(m --)
//        {
//            scanf("%s%d", str, &x);
//            if(str[0] == 'C')
//            {
//                if(h[x]) update(in[x], -1);
//                else update(in[x], 1);
//                h[x] ^= 1;
//            }
//            else printf("%d\n", getSum(out[x]) - getSum(in[x] - 1));
//        }
//    }
//    return 0;
//}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include <iostream>

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

using namespace std;

const int maxn = 1e5 + 100;

struct edge
{
    int v, next;
} edge[maxn << 1];
int head[maxn], e;
int tot, dfs[maxn];
// DFS 序入栈和出栈的时间戳
int in[maxn], out[maxn];

struct node
{
    int l, r;
    int value;
}sto[maxn << 2];

inline int AddEdge(int u, int v)
{
    edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e ++;
}

void DFS(int u)
{
    in[u] = ++tot;
    for(int v = head[u]; ~v; v = edge[v].next)
        DFS(edge[v].v);
    out[u] = tot;
    return ;
}
void PushUp(int rt)
{
    sto[rt].value = sto[rt << 1].value + sto[rt << 1 | 1].value;
}
void Init(int l, int r, int rt)
{
    sto[rt].l = l, sto[rt].r = r, sto[rt].value = 0;
    if(l == r)
    {
        sto[rt].value = 1;
        return ;
    }
    int mid = (l + r) >> 1;
    Init(lson);
    Init(rson);
    PushUp(rt);
}
void Update(int p, int rt)
{
    if(sto[rt].l == sto[rt].r)
    {
        sto[rt].value ^= 1;
        return;
    }
    int mid = (sto[rt].l + sto[rt].r) >> 1;
    if(p <= mid) Update(p, rt << 1);
    else Update(p, rt << 1 | 1);
    PushUp(rt);
}
int Query(int l, int r, int rt)
{
    if(sto[rt].l == l && sto[rt].r == r)
        return sto[rt].value;
    int mid = (sto[rt].l + sto[rt].r) >> 1;
    if(r <= mid) return Query(l, r, rt << 1);
    else if(l > mid) return Query(l, r, rt << 1 | 1);
    else
    {
        int num = 0;
        num += Query(lson);
        num += Query(rson);
        return num;
    }
}
int main()
{
    int N, M;
    while(scanf("%d", &N) != EOF)
    {
        int u, v;
        e = 0;
        tot = 0;
        for(int i = 0; i <= N; i ++) head[i] = -1;
        for(int i = 1; i <= N - 1; i ++)
        {
            scanf("%d%d", &u, &v);
            AddEdge(u, v);
        }
        DFS(1);
        Init(1, N, 1);
        scanf("%d", &M);
        char str[5];
        int x;
        while(M --)
        {
            scanf("%s%d", str, &x);
            if(str[0] == 'C') Update(in[x], 1);
            else printf("%d\n", Query(in[x], out[x], 1));
        }
    }
    return 0;
}

