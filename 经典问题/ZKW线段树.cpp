/**
  *zkw线段树的核心思想：用1表示根节点，那么每一个节点的值就表示以该节点编号为后缀的所有节点的和。
  *Warning:理论上能放 [0,2^N) 的树 其实只能查询 [1,2^N - 2] 的范围
  */

// 记录线段树有k层，则叶子节点编号为2^(n-1)+t     O（1）


// hdu 1166-敌兵布阵(单点更新,区间求和)
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//#define N 50005
//int M;
//int T[N << 2];
//using namespace std;
//
//void build_tree(int n)
//{
//    for(M = 1; M <= n + 1; M <<= 1);// 计算
//    for(int i = M + 1; i <= M + n; i ++) scanf("%d", &T[i]);
//    for(int i = M - 1; i >= 1; i --) T[i] = T[i << 1] + T[i << 1 | 1];
//    // printf("%d\n", M);
//}
//int query(int s, int t)
//{
//    int res = 0;
//    s = s - 1, t = t + 1; // 变为开区间
//    s += M, t += M; // 找到叶子位置 M = 2 ^ (层数 - 1)
//    for(; s^t^1; s >>= 1, t >>= 1) // (s ^ t) != 1 若s 与 t 不想邻； t >>= 1, s >= 1 上移一层
//    {
//        // 在X<>2^n-1（偶数）时，X+1即是其兄弟右节点，X<>2^n（奇数）时，X-1即是其兄弟左节点。
//        // 找第I个叶子节点(0 <= i < n)：
//        // if((s & 1) == 0) res += T[s + 1];// 若s 是左子树， 加上右兄弟 s ^ 1 < == > s + 1
//        if(~s & 1) res += T[s ^ 1];//如果是左子树的左孩子,则处理左子树右孩子
//        // if((t & 1) == 1) res += T[t - 1];// 若t 是右子树， 加上左兄弟 t ^ 1 < == > t - 1
//        if(t & 1) res += T[t ^ 1];//如果是右子树的左孩子,则处理右子树左孩子
//    }
//    return res;
//}
//void Add(int n, int v)
//{
//    // n += M 找到叶子节点
//    for(T[n += M] += v, n >>= 1; n; n >>= 1)
//        T[n] = T[n << 1] + T[n << 1 | 1];
//}
//void Sub(int n, int v)
//{
//    for(T[n += M] -= v, n >>= 1; n; n >>= 1)
//        T[n] = T[n << 1] + T[n << 1 | 1];
//}
//int main()
//{
//    int tt;
//    scanf("%d", &tt);
//    for(int t = 1; t <= tt; t ++)
//    {
//        printf("Case %d:\n", t);
//        int n;
//        scanf("%d", &n);
//        build_tree(n);
//        char str[10];
//        while(scanf("%s", str), str[0] != 'E')
//        {
//            int x, y;
//            scanf("%d%d", &x, &y);
//            if(str[0] == 'Q') printf("%d\n", query(x, y));
//            else if(str[0] == 'A') Add(x, y);
//            else Sub(x, y);
//        }
//    }
//    return 0;
//}

// hdu 1754-I Hate It(单点更新,区间最值)
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//#define N 200005
//
//int T[N << 2];
//int M;// 底层的节点数
//
//using namespace std;
//
//void build_tree(int n)
//{
//    for(M = 1; M <= n + 1; M <<= 1);
//    for(int i = M + 1; i <= M + n; i ++) scanf("%d", &T[i]);
//    for(int i = M - 1; i >= 1; i --) T[i] = max(T[i << 1], T[i << 1 | 1]);
//}
//int query(int s, int t)
//{
//    int maxi = -1 << 29;
//    s = s - 1, t = t + 1;// 变为开区间
//    s += M, t += M; // 找到叶子位置 M = 2 ^ (层数 - 1)
//    for(; s ^ t ^ 1; t >>= 1, s >>= 1) // (s ^ t) != 1 若s 与 t 不想邻； t >>= 1, s >= 1 上移一层
//    {
//        // 在X<>2^n-1（偶数）时，X+1即是其兄弟右节点，X<>2^n（奇数）时，X-1即是其兄弟左节点。
//        // 找第I个叶子节点(0 <= i < n)：
//        if((s & 1) == 0) maxi = max(maxi, T[s^1]); // s ^ 1 < == > s + 1
//        if((t & 1) == 1) maxi = max(maxi, T[t^1]); // t ^ 1 < == > t - 1
//    }
//    return maxi;
//}
//void update(int n, int v)
//{
//    for(T[n += M] = v, n >>= 1; n; n >>= 1)
//        T[n] = max(T[n << 1], T[n << 1 | 1]);
//}
//int main()
//{
//    int n, m;
//    char str[5];
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        memset(T, 0, sizeof(T));
//        build_tree(n);
//        while(m--)
//        {
//            int a, b;
//            scanf("%s%d%d", str, &a, &b);
//            if(str[0] == 'U') update(a, b);
//            else printf("%d\n", query(a, b));
//        }
//    }
//    return 0;
//}

// poj 3468 A Simple Problem with Integers(区间更新， 区间求和)
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#define N ((131072 << 1) + 10) //表示节点个数->不小于区间长度+2的最小2的正整数次幂*2+10
//typedef long long LL;
//inline int getc()
//{
//    static const int L = 1 << 15;
//    static char buf[L] , *S = buf , *T = buf;
//    if (S == T)
//    {
//        T = (S = buf) + fread(buf , 1 , L , stdin);
//        if (S == T)
//            return EOF;
//    }
//    return *S++;
//}
//inline int getint()
//{
//    static char c;
//    while(!isdigit(c = getc()) && c != '-');
//    bool sign = (c == '-');
//    int tmp = sign ? 0 : c - '0';
//    while(isdigit(c = getc()))
//        tmp = (tmp << 1) + (tmp << 3) + c - '0';
//    return sign ? -tmp : tmp;
//}
//inline char getch()
//{
//    char c;
//    while((c = getc()) != 'Q' && c != 'C');
//    return c;
//}
//int M; //底层的节点数
//int dl[N] , dr[N]; //节点的左右端点
//LL sum[N]; //节点的区间和
//LL add[N]; //节点的区间加上一个数的标记
//#define l(x) (x<<1) //x的左儿子，利用堆的性质
//#define r(x) ((x<<1)|1) //x的右儿子，利用堆的性质
//void pushdown(int x)   //下传标记
//{
//    if (add[x]&&x<M)  //如果是叶子节点，显然不用下传标记（别忘了）
//    {
//        add[l(x)] += add[x];
//        sum[l(x)] += add[x] * (dr[l(x)] - dl[l(x)] + 1);
//        add[r(x)] += add[x];
//        sum[r(x)] += add[x] * (dr[r(x)] - dl[r(x)] + 1);
//        add[x] = 0;
//    }
//}
//int stack[20] , top;//栈
//void upd(int x)   //下传x至根节点路径上节点的标记（自上而下，用栈实现）
//{
//    top = 0;
//    int tmp = x;
//    for(; tmp ; tmp >>= 1)
//        stack[++top] = tmp;
//    while(top--)
//        pushdown(stack[top]);
//}
//LL query(int tl , int tr)   //求和
//{
//    LL res=0;
//    int insl = 0, insr = 0; //两侧第一个有用节点
//    for(tl=tl+M-1,tr=tr+M+1; tl^tr^1; tl>>=1,tr>>=1)
//    {
//        if (~tl&1)
//        {
//            if (!insl) upd(insl=tl^1);
//            res+=sum[tl^1];
//        }
//        if (tr&1)
//        {
//            if(!insr) upd(insr=tr^1);
//            res+=sum[tr^1];
//        }
//    }
//    return res;
//}
//void modify(int tl , int tr , int val)   //修改
//{
//    int insl = 0, insr = 0;
//    for(tl=tl+M-1,tr=tr+M+1; tl^tr^1; tl>>=1,tr>>=1)
//    {
//        if (~tl&1)
//        {
//            if (!insl) upd(insl=tl^1);
//            add[tl^1]+=val;
//            sum[tl^1]+=(LL)val*(dr[tl^1]-dl[tl^1]+1);
//        }
//        if (tr&1)
//        {
//            if (!insr) upd(insr=tr^1);
//            add[tr^1]+=val;
//            sum[tr^1]+=(LL)val*(dr[tr^1]-dl[tr^1]+1);
//        }
//    }
//    for(insl=insl>>1; insl; insl>>=1) //一路update
//        sum[insl]=sum[l(insl)]+sum[r(insl)];
//    for(insr=insr>>1; insr; insr>>=1)
//        sum[insr]=sum[l(insr)]+sum[r(insr)];
//}
//inline void swap(int &a , int &b)
//{
//    int tmp = a;
//    a = b;
//    b = tmp;
//}
//int main()
//{
//    freopen("tt.in" , "r" , stdin);
//    int n , ask;
//    n = getint();
//    ask = getint();
//    int i;
//    for(M = 1 ; M < (n + 2) ; M <<= 1);
//    for(i = 1 ; i <= n ; ++i)
//        sum[M + i] = getint() , dl[M + i] = dr[M + i] = i; //建树
//    for(i = M - 1; i >= 1 ; --i)   //预处理节点左右端点
//    {
//        sum[i] = sum[l(i)] + sum[r(i)];
//        dl[i] = dl[l(i)];
//        dr[i] = dr[r(i)];
//    }
//    char s;
//    int a , b , x;
//    while(ask--)
//    {
//        s = getch();
//        if (s == 'Q')
//        {
//            a = getint();
//            b = getint();
//            if (a > b)
//                swap(a , b);
//            printf("%lld\n" , query(a , b));
//        }
//        else
//        {
//            a = getint();
//            b = getint();
//            x = getint();
//            if (a > b)
//                swap(a , b);
//            modify(a , b , x);
//        }
//    }
//    return 0;
//}

// poj 2155 Matrix （二维线段树）
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

bool tree[5010][5010];

int M;
void update_y(int x, int y1, int y2)
{
    y1 += M - 1;
    y2 += M + 1;
    while(y1 ^ y2 ^ 1)
    {
        if(~y1 & 1)
            tree[x][y1 ^ 1] = !tree[x][y1 ^ 1];
        if(y2 & 1)
            tree[x][y2 ^ 1] = !tree[x][y2 ^ 1];
        y1 >>= 1;
        y2 >>= 1;
    }
}

void update(int x1, int y1, int x2, int y2)
{
    x1 += M - 1;
    x2 += M + 1;
    while(x1 ^ x2 ^ 1)
    {
        if(~x1 & 1)
            update_y(x1 ^ 1, y1, y2);
        if(x2 & 1)
            update_y(x2 ^ 1, y1, y2);
        x1 >>= 1;
        x2 >>= 1;
    }
}
bool query_y(int x, int y)
{
    y += M;
    bool res = false;
    while(y)
    {
        if(tree[x][y]) res = !res;
        y >>= 1;
    }
    return res;
}
bool query(int x, int y)
{
    x += M;

    bool res = false;
    while(x)
    {
        res = res ^ query_y(x, y);
        x >>= 1;
    }
    return res;
}
int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; t ++)
    {
        if(t) puts("");
        memset(tree, false, sizeof(tree));
        int n , m;
        int a, b, c, d;
        scanf("%d%d", &n, &m);
        for(M = 1; M <= n + 1; M <<= 1);
        for(int i = 1; i <= m; i ++)
        {
            char str[10];
            scanf("%s", str);
            if(str[0] == 'C')
            {
                scanf("%d%d%d%d", &a, &b, &c, &d);
                update(a, b, c, d);
            }
            else
            {
                scanf("%d%d", &a, &b);
                if(query(a, b)) puts("1");
                else puts("0");
            }
        }
    }
    return 0;
}
