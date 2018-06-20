/*
主席树：对于序列的每一个前缀建一棵以序列里的值为下标的线段树（所以要先离散化），
记录该前缀序列里出现的值的次数；
记离散后的标记为1~n; （下面值直接用1~n代替;）
对于区间[x,y]的第k大的值，那么从root[x-1],root[y]开始，
t=root[y].[1,mid]-root[x-1].[1,mid] ,t表示区间[x,y]内值在[1,mid]的个数
先判断t是否大于K，如果t大于k,那么说明在区间[x,y]内存在[1,mid]的数的个数大于k,
也就是第k大的值在[1,mid]中，否则在[mid+1,r]中；

这样我们依次同时从root[x-1],root[y]往下走
当l==r时 第k大的值就是离散后标记为l的值；

如果每棵线段都建完整的话，n*(n<<2)肯定会mle，
我们发现对于前缀[1,i]和前缀[1,i+1]的线段树，如果b[i+1]<=mid (b[i+1]表示a[i+1]离散后的标记)
那么线段树i和线段树i+1的左边是完全相同的，根本不需要在建，只需要用指针指一下就好；
那么对于一棵新的线段树其实我们最多要建的节点数为log(n)；nlog(n)的节点数还是可以忍受的；
*/
// hdu 2665 Kth number
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#define w(i) T[(i)].w
#define ls(i) T[(i)].ls
#define rs(i) T[(i)].rs
using namespace std;
const int N=100000+10;
struct node
{
    int ls,rs,w;
    node(){ ls = rs = w = 0; }
} T[N*20];
int a[N],b[N],p[N],root[N],sz;
int cmp(int i,int j)
{
    return a[i]<a[j];
}
int n,m;
void ins(int &i,int l,int r,int x)
{
    T[++sz]=T[i];
    i=sz;
    w(i)++;
    if (l==r) return;
    int m=(l+r)>>1;
    if (x<=m) ins(ls(i),l,m,x);
    else ins(rs(i),m+1,r,x);
}
int query(int i,int j,int l,int r,int k)
{
    if (l==r) return l;
    int t=w(ls(j))-w(ls(i));
    int m=(l+r)>>1;
    if (t>=k) return query(ls(i),ls(j),l,m,k);
    else return query(rs(i),rs(j),m+1,r,k-t);
}
int main()
{
    int Cas;
    scanf("%d",&Cas);
    while (Cas--)
    {
        root[0]=0;
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            p[i]=i;
        }
        sort(p+1,p+1+n,cmp);//间接排序，p[i]表示第i小的值在a[]中的下标；
        for (int i=1; i<=n; i++) b[p[i]]=i; //离散化

        // for (int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
        // for (int i=1;i<=n;i++) cout<<p[i]<<" ";cout<<endl;
        // for (int i=1;i<=n;i++) cout<<b[i]<<" ";cout<<endl;

        sz=0;
        for (int i=1; i<=n; i++)
        {
            root[i]=root[i-1];
            ins(root[i],1,n,b[i]);
        }
        for (int i=0; i<m; i++)
        {
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            int t=query(root[x-1],root[y],1,n,k);
            printf("%d\n",a[p[t]]);
        }
    }
    return 0;
}

//poj 2104 K-th Number 主席树
//#include<vector>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//const int maxn = 1e5 + 100;
//int cnt, root[maxn], data[maxn];
//struct node
//{
//    int l, r;
//    int sum;
//} T[maxn * 20];
//vector<int>v;// 离散化
//int getid(int x)
//{
//    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
//}
//void update(int l, int r, int &x, int y, int pos)
//{
//    T[++cnt] = T[y], T[cnt].sum ++, x = cnt;
//    printf("%d\n", T[y]);
//    if(l == r) return;
//    int mid = (l + r) >> 1;
//    if(mid >= pos) update(l, mid, T[x].l, T[y].l, pos);
//    else update(mid + 1, r, T[x].r, T[y].r, pos);
//}
//int query(int l, int r, int x, int y, int k)
//{
//    if(l == r) return l;
//    int mid = (l + r) >> 1;
//    int sum = T[T[y].l].sum - T[T[x].l].sum;
//    if(sum >= k) return query(l, mid, T[x].l, T[y].l, k);
//    return query(mid + 1, r, T[x].r, T[y].r, k - sum);
//}
//int main()
//{
//    int n, m;
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        cnt = 0;
//        v.clear();
//        for(int i = 1; i <= n; i ++) scanf("%d", data + i), v.push_back(data[i]);
//        sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end());
//        for(int i = 1; i <= n; i ++)
//        {
//            update(1, n, root[i], root[i - 1], getid(data[i]));
//            puts("SSSSSS");
//        }
//        for(int i = 1; i <= m; i ++)
//        {
//            int x, y, k;
//            scanf("%d%d%d", &x, &y, &k);
//            printf("%d\n", v[query(1, n, root[x - 1], root[y], k) - 1]);
//        }
//    }
//    return 0;
//}


// 51Nod 1175 区间中第K大的数
// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1175
//#include<cstdio>
//#include<cstring>
//#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<cstdlib>
//#define w(i) T[(i)].w
//#define ls(i) T[(i)].ls
//#define rs(i) T[(i)].rs
//using namespace std;
//const int N=50005;
//struct node
//{
//    int ls,rs,w;
//    node(){ ls = rs = w = 0; }
//} T[N*20];
//int a[N],b[N],p[N],root[N],sz;
//int cmp(int i,int j)
//{
//    return a[i]>a[j];
//}
//int n,m;
//void ins(int &i,int l,int r,int x)
//{
//    T[++sz]=T[i];
//    i=sz;
//    w(i)++;
//    if (l==r) return;
//    int m=(l+r)>>1;
//    if (x<=m) ins(ls(i),l,m,x);
//    else ins(rs(i),m+1,r,x);
//}
//int query(int i,int j,int l,int r,int k)
//{
//    if (l==r) return l;
//    int t=w(ls(j))-w(ls(i));
//    int m=(l+r)>>1;
//    if (t>=k) return query(ls(i),ls(j),l,m,k);
//    else return query(rs(i),rs(j),m+1,r,k-t);
//}
//int main()
//{
//    int n,m;
//    while(scanf("%d",&n) != EOF)
//    {
//        root[0]=0;
//        for (int i=1; i<=n; i++)
//        {
//            scanf("%d",&a[i]);
//            p[i]=i;
//        }
//        sort(p+1,p+1+n,cmp);//间接排序，p[i]表示第i小的值在a[]中的下标；
//        for (int i=1; i<=n; i++) b[p[i]]=i; //离散化
//
////        for (int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
////        for (int i=1;i<=n;i++) cout<<p[i]<<" ";cout<<endl;
////        for (int i=1;i<=n;i++) cout<<b[i]<<" ";cout<<endl;
//
//        sz=0;
//        for (int i=1; i<=n; i++)
//        {
//            root[i]=root[i-1];
//            ins(root[i],1,n,b[i]);
//        }
//        scanf("%d", &m);
//        for (int i=0; i<m; i++)
//        {
//            int x,y,k;
//            scanf("%d%d%d",&x,&y,&k);
//            x += 1, y += 1;
//            int t=query(root[x-1],root[y],1,n,k);
//            printf("%d\n",a[p[t]]);
//        }
//    }
//    return 0;
//}
