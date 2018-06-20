//#include <stdio.h>
//#include <string.h>
//
//const int maxn = 100005;
//     // 后来看了下数据，这道题要用long long 才能过.
//long long sum[maxn << 2],mar[maxn << 2];
//
//void pushup(int o)
//{
//    sum[o] = sum[o << 1] + sum[o << 1 | 1];
//}
//
//void pushdown(int o,int m) // m 表示节点o下有多少个数
//{
//    //  m 就是 r - l + 1
//    if (mar[o])
//    {
//        //-----------------------------------------
//        // 注意这里的更新是将上一次的更新传递给子树。
//        // 以防止以后更新中用到了子节点
//        mar[o << 1] += mar[o];
//        mar[o << 1 | 1] += mar[o];
//        //-----------------------------------------
//        // sum 这里，之前没注意，这里更新时应该乘上
//        // 这个区间包含的数的个数
//        sum[o << 1] += mar[o] * (m - (m >> 1));
//        sum[o << 1 | 1] += mar[o] * (m >> 1);
//        //-----------------------------------------
//        mar[o] = 0;
//    }
//}
//
//void build(int l,int r,int o)
//{
//    mar[o] = 0;
//    if (l == r)
//    {
//        scanf("%lld",&sum[o]);
//        return;
//    }
//    int m = (l + r) >> 1;
//    build(l,m,o << 1);
//    build(m + 1,r,o << 1 | 1);
//    pushup(o);
//}
//
//void update(int L,int R,int d,int l,int r,int o)
//{
//    if (L <= l && r <= R)
//    {
//        // 这里 mar 为什么用 += ，请自己思考.
//        mar[o] += d;
//        sum[o] += d * (r - l + 1);
//        return;
//    }
//    pushdown(o,r - l + 1);
//    int m = (l + r) >> 1;
//    if (L <= m)
//        update(L,R,d,l,m,o << 1);
//    if (m < R)
//        update(L,R,d,m + 1,r,o << 1 | 1);
//    pushup(o);
//
//}
//
//long long query(int L,int R,int l,int r,int o)
//{
//    if (L <= l && r <= R)
//        return sum[o];
//    pushdown(o,r - l + 1);
//    int m = (l + r) >> 1;
//    long long res = 0;
//    if (L <= m)
//        res += query(L,R,l,m,o << 1);
//    if (m < R)
//        res += query(L,R,m + 1,r,o << 1 | 1);
//    return res;
//}
//
//int main()
//{
//    int n,q;
//    while (~scanf("%d %d",&n,&q) && n)
//    {
//        build(1,n,1);
//        while (q--)
//        {
//            char str[10];
//            scanf("%s",str);
//            if (str[0] == 'Q')
//            {
//                int x,y;
//                scanf("%d %d",&x,&y);
//                printf("%lld\n",query(x,y,1,n,1));
//            }
//            else
//            {
//                int x,y,d;
//                scanf("%d %d %d",&x,&y,&d);
//                update(x,y,d,1,n,1);
//            }
//        }
//    }
//}

//点更新
//#include<cstdio>
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#define N 100100<<2
//using namespace std;
//int sto[N];
//int n,q,x,y;
//void init(int t,int w,int o)
//{
//    printf("******t=%d,w=%d,o=%d\n",t,w,o);
//    if(t==w)//分配到叶结点，具体的位置
//    {
//        printf("*****t=%d,w=%d,o=%d\n",t,w,o);
//        scanf("%d",&sto[o]);//具体的输入数据
//        return;
//    }
//    int mid=(t+w)>>1;//二分区间，使得二叉树尽可能的平衡化
//    printf("****t=%d,w=%d,mid=%d\n",t,w,mid);
//    int lso=o<<1;
//    printf("***lso=%d,o=%d\n",lso,o);
//    init(t,mid,lso);//分左子树
//    printf("**t=%d,mid=%d,lso=%d\n",t,mid,lso);
//    init(mid+1,w,lso|1);//分右子树
//    printf("*mid+1=%d,w=%d,lso|1=%d\n",mid+1,w,lso|1);
//    sto[o]=max(sto[lso],sto[lso|1]);//父节点保存子节点的最值
//    printf("sto[o]=%d,o=%d,lso=%d,lso|1=%d\n",sto[o],o,lso,lso|1);
//}
//int update(int t,int w,int o,int st,int en)
//{
//    if(st<=t&&w<=en)//查找的区间包含在当前节点的区间，直接返回当前节点的特征属性
//        return sto[o];
//    int mid=(t+w)>>1;
//    int lso=o<<1;
//    int ans=-1<<29;
//    if(st<=mid)
//        ans=max(ans,update(t,mid,lso,st,en));
//    if(mid<en)
//        ans=max(ans,update(mid+1,w,lso|1,st,en));
//    return ans;
//}
//int main()
//{
//    while(~scanf("%d",&n))//输入数据的个数
//    {
//        init(1,n,1);
//        scanf("%d",&q);//需要访问的次数
//        for(int i=1; i<=q; i++)
//        {
//            scanf("%d%d",&x,&y);//访问的区间范围
//            printf("%d\n",update(1,n,1,x,y));
//        }
//    }
//    return 0;
//}

//区间更新
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 100100<<2
using namespace std;
int sto[N],up[N];
char s[10];
int n,q,x,y,z;
void init(int t,int w,int o)
{
    up[o]=0;
    if(t==w)//分配到叶结点，具体的位置
    {
        scanf("%d",&sto[o]);//具体的输入数据
        return;
    }
    int mid=(t+w)>>1;//二分区间，使得二叉树尽可能的平衡化
    int lso=o<<1;
    init(t,mid,lso);//分左子树
    init(mid+1,w,lso|1);//分右子树
    sto[o]=sto[lso]+sto[lso|1];//父节点保存子节点的和
}
void updown(int sum,int o)
{
    if(up[o])
    {
        //printf("***%d\n",o);
        int lso=o<<1;
        up[lso]+=up[o];
        up[lso|1]+=up[o];
        sto[lso]+=(sum-(sum>>1))*up[o];
        sto[lso|1]+=(sum>>1)*up[o];
        up[o]=0;
    }
}
int update(int t,int w,int o,int st,int en,int num)
{
    if(st<=t&&w<=en)//查找的区间包含在当前节点的区间，直接返回当前节点的特征属性
    {
        if(num!=1<<29)
        {
            up[o]+=num;
            sto[o]+=(w-t+1)*num;
        }
        return sto[o];
    }
    //printf("%d %d %d\n",t,w,o);
    updown(w-t+1,o);
    int mid=(t+w)>>1;
    int lso=o<<1;
    int sum=0;
    if(st<=mid)
        sum+=update(t,mid,lso,st,en,num);
    if(mid<en)
        sum+=update(mid+1,w,lso|1,st,en,num);
    sto[o]=sto[lso]+sto[lso|1];
    return sum;
}
int main()
{
    while(~scanf("%d",&n))//输入数据的个数
    {
        init(1,n,1);
        scanf("%d",&q);//需要访问的次数
        for(int i=1; i<=q; i++)
        {
            scanf("%s",s);
            if(s[0]=='Q')
            {
                scanf("%d%d",&x,&y);//访问的区间范围
                printf("%d\n",update(1,n,1,x,y,1<<29));
            }
            else
            {
                scanf("%d%d%d",&x,&y,&z);
                update(1,n,1,x,y,z);
            }
        }
    }
    return 0;
}
