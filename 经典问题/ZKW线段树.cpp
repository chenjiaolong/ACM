/**
  *zkw�߶����ĺ���˼�룺��1��ʾ���ڵ㣬��ôÿһ���ڵ��ֵ�ͱ�ʾ�Ըýڵ���Ϊ��׺�����нڵ�ĺ͡�
  *Warning:�������ܷ� [0,2^N) ���� ��ʵֻ�ܲ�ѯ [1,2^N - 2] �ķ�Χ
  */

// ��¼�߶�����k�㣬��Ҷ�ӽڵ���Ϊ2^(n-1)+t     O��1��


// hdu 1166-�б�����(�������,�������)
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
//    for(M = 1; M <= n + 1; M <<= 1);// ����
//    for(int i = M + 1; i <= M + n; i ++) scanf("%d", &T[i]);
//    for(int i = M - 1; i >= 1; i --) T[i] = T[i << 1] + T[i << 1 | 1];
//    // printf("%d\n", M);
//}
//int query(int s, int t)
//{
//    int res = 0;
//    s = s - 1, t = t + 1; // ��Ϊ������
//    s += M, t += M; // �ҵ�Ҷ��λ�� M = 2 ^ (���� - 1)
//    for(; s^t^1; s >>= 1, t >>= 1) // (s ^ t) != 1 ��s �� t �����ڣ� t >>= 1, s >= 1 ����һ��
//    {
//        // ��X<>2^n-1��ż����ʱ��X+1�������ֵ��ҽڵ㣬X<>2^n��������ʱ��X-1�������ֵ���ڵ㡣
//        // �ҵ�I��Ҷ�ӽڵ�(0 <= i < n)��
//        // if((s & 1) == 0) res += T[s + 1];// ��s ���������� �������ֵ� s ^ 1 < == > s + 1
//        if(~s & 1) res += T[s ^ 1];//�����������������,�����������Һ���
//        // if((t & 1) == 1) res += T[t - 1];// ��t ���������� �������ֵ� t ^ 1 < == > t - 1
//        if(t & 1) res += T[t ^ 1];//�����������������,��������������
//    }
//    return res;
//}
//void Add(int n, int v)
//{
//    // n += M �ҵ�Ҷ�ӽڵ�
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

// hdu 1754-I Hate It(�������,������ֵ)
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//#define N 200005
//
//int T[N << 2];
//int M;// �ײ�Ľڵ���
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
//    s = s - 1, t = t + 1;// ��Ϊ������
//    s += M, t += M; // �ҵ�Ҷ��λ�� M = 2 ^ (���� - 1)
//    for(; s ^ t ^ 1; t >>= 1, s >>= 1) // (s ^ t) != 1 ��s �� t �����ڣ� t >>= 1, s >= 1 ����һ��
//    {
//        // ��X<>2^n-1��ż����ʱ��X+1�������ֵ��ҽڵ㣬X<>2^n��������ʱ��X-1�������ֵ���ڵ㡣
//        // �ҵ�I��Ҷ�ӽڵ�(0 <= i < n)��
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

// poj 3468 A Simple Problem with Integers(������£� �������)
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#define N ((131072 << 1) + 10) //��ʾ�ڵ����->��С�����䳤��+2����С2������������*2+10
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
//int M; //�ײ�Ľڵ���
//int dl[N] , dr[N]; //�ڵ�����Ҷ˵�
//LL sum[N]; //�ڵ�������
//LL add[N]; //�ڵ���������һ�����ı��
//#define l(x) (x<<1) //x������ӣ����öѵ�����
//#define r(x) ((x<<1)|1) //x���Ҷ��ӣ����öѵ�����
//void pushdown(int x)   //�´����
//{
//    if (add[x]&&x<M)  //�����Ҷ�ӽڵ㣬��Ȼ�����´���ǣ������ˣ�
//    {
//        add[l(x)] += add[x];
//        sum[l(x)] += add[x] * (dr[l(x)] - dl[l(x)] + 1);
//        add[r(x)] += add[x];
//        sum[r(x)] += add[x] * (dr[r(x)] - dl[r(x)] + 1);
//        add[x] = 0;
//    }
//}
//int stack[20] , top;//ջ
//void upd(int x)   //�´�x�����ڵ�·���Ͻڵ�ı�ǣ����϶��£���ջʵ�֣�
//{
//    top = 0;
//    int tmp = x;
//    for(; tmp ; tmp >>= 1)
//        stack[++top] = tmp;
//    while(top--)
//        pushdown(stack[top]);
//}
//LL query(int tl , int tr)   //���
//{
//    LL res=0;
//    int insl = 0, insr = 0; //�����һ�����ýڵ�
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
//void modify(int tl , int tr , int val)   //�޸�
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
//    for(insl=insl>>1; insl; insl>>=1) //һ·update
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
//        sum[M + i] = getint() , dl[M + i] = dr[M + i] = i; //����
//    for(i = M - 1; i >= 1 ; --i)   //Ԥ����ڵ����Ҷ˵�
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

// poj 2155 Matrix ����ά�߶�����
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
