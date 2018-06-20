//敌兵布阵 树状数组算法
//#include<cstdio>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int c[50010],N,array[50010];
//int Lowbit(int x)
//{
//    return x&(-x);
//}
//void Add(int i,int x)
//{
//    while(i<=N)
//    {
//        c[i]+=x;
//        i+=Lowbit(i);
//    }
//}
//void Sub(int i,int x)
//{
//    while(i<=N)
//    {
//        c[i]-=x;
//        i+=Lowbit(i);
//    }
//}
//int Sum(int x)
//{
//    int sum=0;
//    while(x>0)
//    {
//        sum+=c[x];
//        x-=Lowbit(x);
//    }
//    return sum;
//}
//int main()
//{
//    int T;
//    while(~scanf("%d",&T))
//    {
//        for(int t=1;t<=T;t++)
//        {
//            scanf("%d",&N);
//            memset(c,0,sizeof(c));
//            for(int i=1;i<=N;i++)
//                {
//                    scanf("%d",&array[i]);
//                    Add(i,array[i]);
//                }
//                char str[20];
//                printf("Case %d:\n",t);
//                int u,v;
//                while(~scanf("%s",str)&&strcmp(str,"End"))
//                {
//                    scanf("%d%d",&u,&v);
//                    if(strcmp(str,"Query")==0)
//                    printf("%d\n",Sum(v)-Sum(u-1));
//                    else if(strcmp(str,"Add")==0)
//                        {
//                            Add(u,v);
//                            array[u]+=v;
//                        }
//                    else if(strcmp(str,"Sub")==0)
//                        {
//                            Sub(u,v);
//                            array[u]-=v;
//                        }
//                }
//        }
//    }
//    return 0;
//}

//敌兵布阵 线段树算法
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#define MAX 50010<<2
//using namespace std;
//int array[MAX],temp[MAX];
//int N;
//void init(int left,int right,int pa)
//{
//    temp[pa]=0;
//    if(left==right)
//    {
//        scanf("%d",&array[pa]);
//        return ;
//    }
//    int mid=(left+right)>>1;
//    int child=pa<<1;
//    init(left,mid,child);
//    init(mid+1,right,child|1);
//    array[pa]=array[child]+array[child|1];
//}
//void updown(int cnt,int pa)
//{
//    if(temp[pa])
//    {
//        int child=pa<<1;
//        temp[child]+=temp[pa];
//        temp[child|1]+=temp[pa];
//        array[child]+=(cnt-(cnt>>1))*temp[pa];
//        array[child|1]+=(cnt>>1)*temp[pa];
//        temp[pa]=0;
//    }
//}
//int update(int left,int right,int pa,int start,int end,int num)
//{
//    if(start<=left&&right<=end)
//    {
//        if(num!=1<<29)
//        {
//            temp[pa]+=num;
//            array[pa]+=(right-left+1)*num;
//        }
//        return array[pa];
//    }
//    updown(right-left+1,pa);
//    int mid=(left+right)>>1;
//    int child=pa<<1;
//    int sum=0;
//    if(start<=mid)
//        sum+=update(left,mid,child,start,end,num);
//    if(mid<end)
//    sum+=update(mid+1,right,child|1,start,end,num);
//    array[pa]=array[child]+array[child|1];
//    return sum;
//}
//int main()
//{
//    int T;
//    while(~scanf("%d",&T))
//    {
//        for(int t=1;t<=T;t++)
//        {
//            scanf("%d",&N);
//            init(1,N,1);
//            char str[10];
//            printf("Case %d:\n",t);
//            while(~scanf("%s",str)&&strcmp(str,"End"))
//            {
//                int x,y;
//                scanf("%d%d",&x,&y);
//                if(strcmp(str,"Query")==0)
//                printf("%d\n",update(1,N,1,x,y,1<<29));
//                else if(strcmp(str,"Add")==0)
//                    update(1,N,1,x,x,y);
//                else if(strcmp(str,"Sub")==0)
//                    update(1,N,1,x,x,-y);
//            }
//        }
//    }
//    return 0;
//}

//I Hate It
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#define MAX 200010<<2
//using namespace std;
//int array[MAX],N;
//int T[MAX];
//void init(int left,int right,int pa)
//{
//    T[pa]=0;
//    if(left==right)
//    {
//        scanf("%d",&array[pa]);
//        return ;
//    }
//    int mid=(left+right)>>1;
//    int child=pa<<1;
//    init(left,mid,child);
//    init(mid+1,right,child|1);
//    array[pa]=max(array[child],array[child|1]);
//}
//void updown(int cnt,int pa)
//{
//    if(T[pa])
//    {
//        int child=pa<<1;
//        T[child]=T[pa];
//        T[child|1]=T[pa];
//        array[child]=(cnt-(cnt>>1))*T[pa];
//        array[child|1]=(cnt>>1)*T[pa];
//        T[pa]=0;
//    }
//}
//int update(int left,int right,int pa,int start,int end,int num)
//{
//    if(start<=left&&right<=end)
//        {
//            if(num!=1<<29)
//            {
//                T[pa]=num;
//                array[pa]=(right-left+1)*num;
//            }
//            return array[pa];
//        }
//    updown(right-left+1,pa);
//    int mid=(left+right)>>1;
//    int child=pa<<1;
//    int ans=-1<<29;
//    if(start<=mid)
//        ans=max(ans,update(left,mid,child,start,end,num));
//    if(mid<end)
//        ans=max(ans,update(mid+1,right,child|1,start,end,num));
//    array[pa]=max(array[child],array[child|1]);
//    return ans;
//}
//int main()
//{
//    int M,A,B;
//    char C[10];
//    while(~scanf("%d%d",&N,&M))
//    {
//        init(1,N,1);
//        for(int i=1;i<=M;i++)
//        {
//            scanf("%s%d%d",C,&A,&B);
//            if(C[0]=='Q')
//                printf("%d\n",update(1,N,1,A,B,1<<29));
//            else if(C[0]=='U')
//            update(1,N,1,A,A,B);
//        }
//    }
//    return 0;
//}

//Sliding Window 各个击破
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//#define MAXSIZE 1000100<<2
//using namespace std;
//struct node
//{
//    int value;
//    int Min;
//    int Max;
//} array[MAXSIZE];
//int M[MAXSIZE],N[MAXSIZE];
//void init(int left,int right,int pa)
//{
//    if(left==right)
//    {
//        scanf("%d",&array[pa].value);
//        array[pa].Max=array[pa].value;
//        array[pa].Min=array[pa].value;
//        return ;
//    }
//    int mid=(left+right)>>1;
//    int child=pa<<1;
//    init(left,mid,child);
//    init(mid+1,right,child|1);
//    array[pa].Max=max(array[child].Max,array[child|1].Max);
//    array[pa].Min=min(array[child].Min,array[child|1].Min);
//}
//int GetMax(int left,int right,int pa,int start,int end)
//{
//    if(start<=left&&right<=end)
//        return array[pa].Max;
//    int mid=(left+right)>>1;
//    int child=pa<<1;
//    int MAX=-1<<29;
//    if(start<=mid)
//        MAX=max(MAX,GetMax(left,mid,child,start,end));
//    if(mid<end)
//        MAX=max(MAX,GetMax(mid+1,right,child|1,start,end));
//    return MAX;
//}
//int GetMin(int left,int right,int pa,int start,int end)
//{
//    if(start<=left&&right<=end)
//        return array[pa].Min;
//    int mid=(left+right)>>1;
//    int child=pa<<1;
//    int MIN=1<<29;
//    if(start<=mid)
//        MIN=min(MIN,GetMin(left,mid,child,start,end));
//    if(mid<end)
//        MIN=min(MIN,GetMin(mid+1,right,child|1,start,end));
//    return MIN;
//}
//int main()
//{
//    int n,k;
//    while(~scanf("%d%d",&n,&k))
//    {
//        init(1,n,1);
//        int cur=0;
//        for(int i=1; i+k-1<=n; i++)
//        {
//            N[cur]=GetMin(1,n,1,i,i+k-1);
//            M[cur]=GetMax(1,n,1,i,i+k-1);
//            cur++;
//        }
//        for(int i=0; i<cur; i++)
//            printf("%d%c",N[i],i==cur-1?'\n':' ');
//        for(int i=0; i<cur; i++)
//            printf("%d%c",M[i],i==cur-1?'\n':' ');
//
//    }
//    return 0;
//}

//Sliding Window 结构体
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//
//#define MAXSIZE 1000010<<2
//using namespace std;
//struct node
//{
//    int Max;
//    int Min;
//} array[MAXSIZE];
//struct node M[1000010];
//int MAX=-1<<29,MIN=1<<29;
//void init(int left,int right,int pa)
//{
//    if(left==right)
//    {
//        scanf("%d",&array[pa].Max);
//        array[pa].Min=array[pa].Max;
//        return;
//    }
//    int mid=(left+right)>>1;
//    int child=pa<<1;
//    init(left,mid,child);
//    init(mid+1,right,child|1);
//    array[pa].Max=max(array[child].Max,array[child|1].Max);
//    array[pa].Min=min(array[child].Min,array[child|1].Min);
//}
//struct node update(int left,int right,int pa,int start,int end)
//{
//    if(start<=left&&right<=end)
//        return array[pa];
//    int mid=(left+right)>>1;
//    int child=pa<<1;
//    struct node p;
//    if(start<=mid)
//    {
//        p=update(left,mid,child,start,end);
//        MAX=max(p.Max,MAX);
//        MIN=min(p.Min,MIN);
//    }
//    if(mid<end)
//    {
//        p=update(mid+1,right,child|1,start,end);
//        MAX=max(p.Max,MAX);
//        MIN=min(p.Min,MIN);
//    }
//    p.Max=MAX;
//    p.Min=MIN;
//    return p;
//}
//int main()
//{
//    int n,k;
//    while(~scanf("%d%d",&n,&k))
//    {
//        init(1,n,1);
//        int cur=0;
//        struct node p;
//        for(int i=1; i+k-1<=n; i++)
//        {
//            MAX=-1<<29,MIN=1<<29;
//            p=update(1,n,1,i,i+k-1);
//            M[cur]=p;
//            cur++;
//        }
//        for(int i=0; i<cur; i++)
//            printf("%d%c",M[i].Min,i==cur-1?'\n':' ');
//        for(int i=0; i<cur; i++)
//            printf("%d%c",M[i].Max,i==cur-1?'\n':' ');
//
//    }
//    return 0;
//}

//Minimum Inversion Number 树状数组算法
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int tree[5005];
//int n;
//int Lowbit(int x)
//{
//    return x&(-x);
//}
//void Add(int i,int x)
//{
//    while(i<=n)
//    {
//        tree[i]+=x;
//        i+=Lowbit(i);
//    }
//}
//int Sum(int x)
//{
//    int sum=0;
//    while(x>0)
//    {
//        sum+=tree[x];
//        x-=Lowbit(x);
//    }
//    return sum;
//}
//int main()
//{
//    int array[5005],temp[5005];
//    while(~scanf("%d",&n))
//    {
//        for(int i=1; i<=n; i++)
//        {
//            scanf("%d",&array[i]);
//            array[i]+=1;
//        }
//        memset(tree,0,sizeof(tree));
//        long long ans=0;
//        for(int i=1;i<=n;i++)
//        {
//            Add(array[i],1);
//            ans+=i-Sum(array[i]);
//        }
//        long long Min=ans;
//        for(int i=1; i<n; i++)
//                {
//                    ans=ans-(array[i]-1)+n-array[i];
//                    Min=min(ans,Min);
//                }
//        printf("%lld\n",Min);
//    }
//    return 0;
//}

//Minimum Inversion Number 归并算法
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int A[5005],T[5005];
//long long Merge(int low,int mid,int high)
//{
//    int i=low,j=mid+1,k=low;
//    long long cnt=0;
//    while(i<=mid&&j<=high)
//    {
//        if(A[i]<=A[j])
//            T[k++]=A[i++];
//        else
//        {
//            T[k++]=A[j++];
//            cnt+=j-k;
//        }
//    }
//    while(i<=mid)
//        T[k++]=A[i++];
//    while(j<=high)
//        T[k++]=A[j++];
//    for(int i=low;i<=high;i++)
//        A[i]=T[i];
//    return cnt;
//}
//long long MergeSort(int low,int high)
//{
//    long long cnt=0;
//    if(low<high)
//    {
//        int mid=(low+high)>>1;
//        cnt+=MergeSort(low,mid);
//        cnt+=MergeSort(mid+1,high);
//        cnt+=Merge(low,mid,high);
//    }
//    return cnt;
//}
//int main()
//{
//    int n;
//    int array[5005];
//    while(~scanf("%d",&n))
//    {
//        for(int i=1; i<=n; i++)
//        {
//            scanf("%d",&array[i]);
//            array[i]+=1;
//            A[i]=array[i];
//        }
//        long long ans=0;
//        ans=MergeSort(1,n);
//        long long Min=ans;
//        for(int i=1; i<n; i++)
//                {
//                    ans=ans-(array[i]-1)+n-array[i];
//                    Min=min(ans,Min);
//                }
//        printf("%lld\n",Min);
//    }
//    return 0;
//}

//Minimum Inversion Number 线段树算法
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#define MAXSIZE 5005<<2
//using namespace std;
//int array[MAXSIZE],T[MAXSIZE];
//struct node
//{
//    int id;
//    int data;
//    bool operator <(const node &S)const
//    {
//        return data>S.data;
//    }
//} temp[5005];
//int data[5005];
//void init(int left,int right,int pa)
//{
//    T[pa]=0;
//    if(left==right)
//    {
//        array[pa]=0;
//        return ;
//    }
//    int mid=(left+right)>>1;
//    int child=pa<<1;
//    init(left,mid,child);
//    init(mid+1,right,child|1);
//    array[pa]=array[child]+array[child|1];
//}
//void updonw(int cnt,int pa)
//{
//    if(T[pa])
//    {
//        int child=pa<<1;
//        T[child]+=T[pa];
//        T[child|1]+=T[pa];
//        array[child]+=(cnt-(cnt>>1))*T[pa];
//        array[child|1]+=(cnt>>1)*T[pa];
//        T[pa]=0;
//    }
//}
//int update(int left,int right,int pa,int start,int end,int num)
//{
//    if(start<=left&&right<=end)
//    {
//        if(num==1)
//        {
//            T[pa]+=1;
//            array[pa]+=(right-left+1)*T[pa];
//        }
//        return array[pa];
//    }
//    updonw(right-left+1,pa);
//    int mid=(left+right)>>1;
//    int child=pa<<1;
//    int sum=0;
//    if(start<=mid)
//        sum+=update(left,mid,child,start,end,num);
//    if(mid<end)
//        sum+=update(mid+1,right,child|1,start,end,num);
//    array[pa]=array[child]+array[child|1];
//    return sum;
//}
//int main()
//{
//    int n;
//    while(~scanf("%d",&n))
//    {
//        init(1,n,1);
//        for(int i=1; i<=n; i++)
//        {
//            scanf("%d",&temp[i].data);
//            data[i]=++temp[i].data;
//            temp[i].id=i;
//        }
//        sort(temp+1,temp+n+1);
//        long long ans=0;
//        for(int i=1; i<=n; i++)
//            {
//                update(1,n,1,temp[i].id,temp[i].id,1);
//                ans+=update(1,n,1,1,temp[i].id,1<<29)-1;
//            }
//        long long Min=ans;
//        for(int i=1; i<n; i++)
//        {
//            ans=ans+n+1-2*data[i];//ans=ans-(data[i]-1)+n-data[i];
//            Min=min(ans,Min);
//        }
//        printf("%lld\n",Min);
//    }
//    return 0;
//}

//Just a Hook
//#include<cstdio>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#define MAXSIZE 100000<<2
//using namespace std;
//int array[MAXSIZE],temp[MAXSIZE];
//void init(int left,int right,int pa)
//{
//    temp[pa]=0;
//    if(left==right)
//    {
//        array[pa]=1;
//        return ;
//    }
//    int mid=(left+right)>>1;
//    int child=pa<<1;
//    init(left,mid,child);
//    init(mid+1,right,child|1);
//    array[pa]=array[child]+array[child|1];
//}
//void updown(int cnt,int pa)
//{
//    if(temp[pa])
//    {
//        int child=pa<<1;
//        temp[child]=temp[pa];
//        temp[child|1]=temp[pa];
//        array[child]=(cnt-(cnt>>1))*temp[pa];
//        array[child|1]=(cnt>>1)*temp[pa];
//        temp[pa]=0;
//    }
//}
//int update(int left,int right,int pa,int start,int end,int num)
//{
//    if(start<=left&&right<=end)
//    {
//        temp[pa]=num;
//        array[pa]=(right-left+1)*temp[pa];
//        return array[pa];
//    }
//    updown(right-left+1,pa);
//    int mid=(left+right)>>1;
//    int child=pa<<1;
//    int sum=0;
//    if(start<=mid)
//        sum+=update(left,mid,child,start,end,num);
//    if(mid<end)
//        sum+=update(mid+1,right,child|1,start,end,num);
//    array[pa]=array[child]+array[child|1];
//    return sum;
//}
//
//int main()
//{
//    int T,N,M;
//    while(~scanf("%d",&T))
//    {
//        for(int t=1; t<=T; t++)
//        {
//            scanf("%d",&N);
//            init(1,N,1);
//            scanf("%d",&M);
//            int X,Y,Z;
//            for(int i=1; i<=M; i++)
//            {
//                scanf("%d%d%d",&X,&Y,&Z);
//                update(1,N,1,X,Y,Z);
//            }
//            printf("Case %d: The total value of the hook is %d.\n",t,array[1]);
//        }
//    }
//    return 0;
//}


// hdu5023 A Corrupt Mayor's Performance Art
#include <bits/stdc++.h>

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

using namespace std;

const int maxn = 1e6 + 7;

struct node
{
    int l, r;
    int val;
    bool flag;
} sto[maxn << 2];

void PushUp(int rt)
{
    sto[rt].val = sto[rt << 1].val | sto[rt << 1 | 1].val;
}
void PushDown(int rt)
{
    if(!sto[rt].flag) return ;
    sto[rt << 1].val = sto[rt << 1 | 1].val = sto[rt].val;
    sto[rt].flag = false;
    sto[rt << 1].flag = true;
    sto[rt << 1 | 1].flag = true;
}
void Init(int l, int r, int rt)
{
    sto[rt].l = l, sto[rt].r = r, sto[rt].val = 0, sto[rt].flag = true;
    if(l == r)
    {
        sto[rt].val = 2;
        return ;
    }
    int mid = (l + r) >> 1;
    Init(lson);
    Init(rson);
    PushUp(rt);
}

void Update(int l, int r, int rt, int color)
{
    if(l == sto[rt].l && sto[rt].r == r)
    {
        sto[rt].val =  1 << (color - 1);
        sto[rt].flag = true;
        return ;
    }
    PushDown(rt);
    int mid = (sto[rt].l + sto[rt].r) >> 1;
    if(r <= mid) Update(l, r, rt << 1, color);
    else if(l > mid) Update(l, r, rt << 1 | 1, color);
    else
    {
        Update(lson, color);
        Update(rson, color);
    }
    PushUp(rt);
}
int Query(int l, int r, int rt)
{
    if(l == sto[rt].l && sto[rt].r == r)
        return sto[rt].val;
    PushDown(rt);
    int mid = (sto[rt].l + sto[rt].r) >> 1;
    if(r <= mid) return Query(l, r, rt << 1);
    else if(l > mid) return Query(l, r, rt << 1 | 1);
    else return Query(lson) | Query(rson);
    PushUp(rt);
}

int ans[35];
int Count(int x)
{
    int cnt = 0;
    int digit = 1;
    while(x)
    {
        if(x&1)
            ans[cnt ++] = digit;
        digit ++;
        x >>= 1;
    }
    return cnt;
}

int main()
{
    int N, M;
    while(scanf("%d%d", &N, &M), N + M)
    {
        Init(1, N, 1);
        char op[5];
        for(int i = 1; i <= M; i ++)
        {
            scanf("%s", op);
            if(op[0] == 'P')
            {
                int x, y, color;
                scanf("%d%d%d", &x, &y, &color);
                Update(x, y, 1, color);
            }
            else
            {
                for(int i = 0; i < 30; i ++) ans[i] = 0;
                int x, y;
                int val;
                scanf("%d%d", &x, &y);
                int re = Query(x, y, 1);
                int res = Count(re);
                // printf("%d\n", res);
                for(int i = 0; i < res; i ++)
                    printf("%d%c", ans[i], i == res - 1? '\n' : ' ');
            }

        }
    }
    return 0;
}

