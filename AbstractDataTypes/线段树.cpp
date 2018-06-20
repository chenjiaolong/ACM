// hdu 1166 敌兵布阵
// 线段树功能:update:单点增减 query:区间求和
//#include<map>
//#include<set>
//#include<stack>
//#include<queue>
//#include<vector>
//#include<unordered_map>
//#include<unordered_set>
//#include <ext/hash_map>
///***********************
// *以上是 C++ 常用容器 *
// **********************/
//#include<string>
//#include<sstream>
//#include<fstream>
//#include<istream>
//#include<ostream>
//#include<iostream>
//#include<strstream>
///***********************
// *以上是 C++ 流式文件 *
// **********************/
//#include<math.h>
//#include<ctype.h> // 字符文件
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
///***********************
// *以上是 C++ 基本文件 *
// **********************/
//#include<algorithm>// 算法模板文件
//#pragma comment(linker, "/STACK:102400000, 102400000")// 输入输出外挂
//
//using namespace std;
//
//// 常用的功能或常量宏定义
//#define maxnode 15
//#define sigma_size 26
//#define lson l, m, rt << 1
//#define rson m + 1, r, rt << 1 | 1
//#define lrt rt << 1
//#define rrt rt << 1 | 1
//#define middle int m = (l + r) >> 1
//#define LL long long
//#define ull unsigned long long
//#define mem(x, v) memset(x, v, sizeof(x))
//#define lowbit(x) (x & -x)
//#define pii pair<int, int>
//#define mk make_pair
//#define limit 10000
//#define N 1000100 << 2
//
//const int prime = 999983;
//const int INF = 0x3f3f3f3f;
//const LL INFF = 0x3f3f;
//const double pi = acos(-1.0);
//const double inf = 1e18;
//const double eps = 1e-4;
//const LL mod = 1e9 + 7;
//const ull mx = 133333331;
//
//int sto[N];
//void PushUp(int rt)
//{
//    sto[rt] = sto[rt << 1] + sto[rt << 1 |1];
//}
//void Build(int l, int r, int rt)
//{
//    if(l == r)
//    {
//        scanf("%d", &sto[rt]);
//        return;
//    }
//    int m = (l + r) >> 1;
//    Build(lson);
//    Build(rson);
//    PushUp(rt);
//}
//void update(int p, int add, int l, int r, int rt)
//{
//    if(l == r)
//    {
//        sto[rt] += add;
//        return;
//    }
//    int m = (l + r) >> 1;
//    if(p <= m) update(p, add, lson);
//    else update(p, add, rson);
//    PushUp(rt);
//}
//int query(int L, int R, int l, int r, int rt)
//{
//    if(L <= l && r <= R) return sto[rt];
//    int m = (l + r) >> 1;
//    int res = 0;
//    if(L <= m) res += query(L, R, lson);
//    if(m < R) res += query(L, R, rson);
//    return res;
//}
//int main()
//{
//    int T;
//    int n;
//    scanf("%d", &T);
//    for(int t = 1; t <= T; t ++)
//    {
//        scanf("%d", &n);
//        Build(1, n, 1);
//        char op[10];
//        printf("Case %d:\n", t);
//        while(scanf("%s", op), op[0] != 'E')
//        {
//            int a, b;
//            scanf("%d%d", &a, &b);
//            if(op[0] == 'Q') printf("%d\n", query(a, b, 1, n, 1));
//            else if(op[0] == 'S') update(a, -b, 1, n, 1);
//            else update(a, b, 1, n, 1);
//        }
//    }
//    return 0;
//}

// hdu 1754 I Hate It
// 线段树功能:update:单点替换 query:区间最值
//#include<map>
//#include<set>
//#include<stack>
//#include<queue>
//#include<vector>
//#include<unordered_map>
//#include<unordered_set>
//#include <ext/hash_map>
///***********************
// *以上是 C++ 常用容器 *
// **********************/
//#include<string>
//#include<sstream>
//#include<fstream>
//#include<istream>
//#include<ostream>
//#include<iostream>
//#include<strstream>
///***********************
// *以上是 C++ 流式文件 *
// **********************/
//#include<math.h>
//#include<ctype.h> // 字符文件
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
///***********************
// *以上是 C++ 基本文件 *
// **********************/
//#include<algorithm>// 算法模板文件
//#pragma comment(linker, "/STACK:102400000, 102400000")// 输入输出外挂
//
//using namespace std;
//
//// 常用的功能或常量宏定义
//#define maxnode 15
//#define sigma_size 26
//#define lson l, m, rt << 1
//#define rson m + 1, r, rt << 1 | 1
//#define lrt rt << 1
//#define rrt rt << 1 | 1
//#define middle int m = (l + r) >> 1
//#define LL long long
//#define ull unsigned long long
//#define mem(x, v) memset(x, v, sizeof(x))
//#define lowbit(x) (x & -x)
//#define pii pair<int, int>
//#define mk make_pair
//#define limit 10000
//#define N 1000100 << 2
//
//const int prime = 999983;
//const int INF = 0x3f3f3f3f;
//const LL INFF = 0x3f3f;
//const double pi = acos(-1.0);
//const double inf = 1e18;
//const double eps = 1e-4;
//const LL mod = 1e9 + 7;
//const ull mx = 133333331;
//
//int sto[N];
//void PushUp(int rt)
//{
//    sto[rt] = max(sto[rt << 1], sto[rt << 1 | 1]);
//}
//void Build(int l, int r, int rt)
//{
//    if(l == r)
//    {
//        scanf("%d", &sto[rt]);
//        return;
//    }
//    int m = (l + r) >> 1;
//    Build(lson);
//    Build(rson);
//    PushUp(rt);
//}
//void update(int p, int sc, int l, int r, int rt)
//{
//    if(l == r)
//    {
//        sto[rt] = sc;
//        return;
//    }
//    int m = (l + r) >> 1;
//    if(p <= m) update(p, sc, lson);
//    else update(p, sc, rson);
//    PushUp(rt);
//}
//int query(int L, int R, int l, int r, int rt)
//{
//    if(L <= l && r <= R) return sto[rt];
//    int m = (l + r) >> 1;
//    int res = -0x3f3f3f3f;
//    if(L <= m) res = max(res, query(L, R, lson));
//    if(m < R) res = max(res, query(L, R, rson));
//    return res;
//}
//int main()
//{
//    int n, m;
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        Build(1, n, 1);
//        while(m--)
//        {
//            char op[5];
//            int a, b;
//            scanf("%s%d%d", op, &a, &b);
//            if(op[0] == 'Q') printf("%d\n", query(a, b, 1, n, 1));
//            else update(a, b, 1, n, 1);
//        }
//    }
//    return 0;
//}

// hdu1394 Minimum Inversion Number
// 题意:求Inversion后的最小逆序数
// 思路:用O(nlogn)复杂度求出最初逆序数后,就可以用O(1)的复杂度分别递推出其他解
// 线段树功能:update:单点增减 query:区间求和
//#include<map>
//#include<set>
//#include<stack>
//#include<queue>
//#include<vector>
//#include<unordered_map>
//#include<unordered_set>
//#include <ext/hash_map>
///***********************
// *以上是 C++ 常用容器 *
// **********************/
//#include<string>
//#include<sstream>
//#include<fstream>
//#include<istream>
//#include<ostream>
//#include<iostream>
//#include<strstream>
///***********************
// *以上是 C++ 流式文件 *
// **********************/
//#include<math.h>
//#include<ctype.h> // 字符文件
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
///***********************
// *以上是 C++ 基本文件 *
// **********************/
//#include<algorithm>// 算法模板文件
//#pragma comment(linker, "/STACK:102400000, 102400000")// 输入输出外挂
//
//using namespace std;
//
//// 常用的功能或常量宏定义
//#define maxnode 15
//#define sigma_size 26
//#define lson l, m, rt << 1
//#define rson m + 1, r, rt << 1 | 1
//#define lrt rt << 1
//#define rrt rt << 1 | 1
//#define middle int m = (l + r) >> 1
//#define LL long long
//#define ull unsigned long long
//#define mem(x, v) memset(x, v, sizeof(x))
//#define lowbit(x) (x & -x)
//#define pii pair<int, int>
//#define mk make_pair
//#define limit 10000
//#define N 1000100 << 2
//
//const int prime = 999983;
//const int INF = 0x3f3f3f3f;
//const LL INFF = 0x3f3f;
//const double pi = acos(-1.0);
//const double inf = 1e18;
//const double eps = 1e-4;
//const LL mod = 1e9 + 7;
//const ull mx = 133333331;
//
//int sto[N];
//void PushUp(int rt)
//{
//    sto[rt] = sto[rt << 1] + sto[rt << 1 | 1];
//}
//void Build(int l, int r, int rt)
//{
//    sto[rt] = 0;
//    if(l == r) return;
//    int m = (l + r) >> 1;
//    Build(lson);
//    Build(rson);
//}
//void update(int p, int l, int r, int rt)
//{
//    if(l == r)
//    {
//        sto[rt]++;
//        return;
//    }
//    int m = (l + r) >> 1;
//    if(p <= m) update(p, lson);
//    else update(p, rson);
//    PushUp(rt);
//}
//int query(int L, int R, int l, int r, int rt)
//{
//    if(L <= l && r <= R) return sto[rt];
//    int m = (l + r) >> 1;
//    int res = 0;
//    if(L <= m) res += query(L, R, lson);
//    if(m < R) res += query(L, R, rson);
//    return res;
//}
//int x[MAXN];
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        Build(0, n - 1, 1);
//        int sum = 0;
//        for(int i = 0; i < n; i ++)
//        {
//            scanf("%d", &x[i]);
//            sum += query(x[i], n - 1, 0, n - 1, 1);
//            update(x[i], 0, n - 1, 1);
//        }
//        int res = sum;
//        for(int i = 0; i < n; i ++)
//        {
//            sum += n - x[i] - x[i] -1;
//            if(res > sum)
//                res = sum;
//        }
//        printf("%d\n", res);
//    }
//    return 0;
//}

// hdu2795 Billboard
// 题意:h*w的木板,放进一些1*L的物品,求每次放空间能容纳且最上边的位置
// 思路:每次找到最大值的位子,然后减去L
// 线段树功能:query:区间求最大值的位置(直接把update的操作在query里做了)
//#include<map>
//#include<set>
//#include<stack>
//#include<queue>
//#include<vector>
//#include<unordered_map>
//#include<unordered_set>
//#include <ext/hash_map>
///***********************
// *以上是 C++ 常用容器 *
// **********************/
//#include<string>
//#include<sstream>
//#include<fstream>
//#include<istream>
//#include<ostream>
//#include<iostream>
//#include<strstream>
///***********************
// *以上是 C++ 流式文件 *
// **********************/
//#include<math.h>
//#include<ctype.h> // 字符文件
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
///***********************
// *以上是 C++ 基本文件 *
// **********************/
//#include<algorithm>// 算法模板文件
//#pragma comment(linker, "/STACK:102400000, 102400000")// 输入输出外挂
//
//using namespace std;
//
//// 常用的功能或常量宏定义
//#define maxnode 15
//#define sigma_size 26
//#define lson l, m, rt << 1
//#define rson m + 1, r, rt << 1 | 1
//#define lrt rt << 1
//#define rrt rt << 1 | 1
//#define middle int m = (l + r) >> 1
//#define LL long long
//#define ull unsigned long long
//#define mem(x, v) memset(x, v, sizeof(x))
//#define lowbit(x) (x & -x)
//#define pii pair<int, int>
//#define mk make_pair
//#define limit 10000
//#define N 1000100 << 2
//
//const int prime = 999983;
//const int INF = 0x3f3f3f3f;
//const LL INFF = 0x3f3f;
//const double pi = acos(-1.0);
//const double inf = 1e18;
//const double eps = 1e-4;
//const LL mod = 1e9 + 7;
//const ull mx = 133333331;
//
//int sto[N];
//int h, w, n;
//void PushUp(int rt)
//{
//    sto[rt] = max(sto[rt << 1], sto[rt << 1 | 1]);
//}
//void Build(int l, int r, int rt)
//{
//    sto[rt] = w;
//    if(l == r) return;
//    int m = (l + r) >> 1;
//    Build(lson);
//    Build(rson);
//}
//int query(int x, int l, int r, int rt)
//{
//    if(l == r)
//    {
//        sto[rt] -= x;
//        return l;
//    }
//    int m = (l + r) >> 1;
//    int res = (sto[rt << 1] >= x) ? query(x, lson) : query(x, rson);
//    PushUp(rt);
//    return res;
//}
//int main()
//{
//    while(scanf("%d%d%d", &h, &w, &n) != EOF)
//    {
//        if(h > n) h = n;
//        Build(1, h, 1);
//        while(n --)
//        {
//            int x;
//            scanf("%d", &x);
//            if(sto[1] < x) puts("-1");
//            else printf("%d\n", query(x, 1, h, 1));
//        }
//    }
//    return 0;
//}

// hdu 1698 Just a hook
// 线段树功能:update:成段替换 (由于只query一次总区间,所以可以直接输出1结点的信息)
//#include<map>
//#include<set>
//#include<stack>
//#include<queue>
//#include<vector>
//#include<unordered_map>
//#include<unordered_set>
//#include <ext/hash_map>// (hdu C++编译器不支持)
///***********************
// *以上是 C++ 常用容器 *
// **********************/
//#include<string>
//#include<sstream>
//#include<fstream>
//#include<istream>
//#include<ostream>
//#include<iostream>
//#include<strstream>
///***********************
// *以上是 C++ 流式文件 *
// **********************/
//#include<math.h>
//#include<ctype.h> // 字符文件
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
///***********************
// *以上是 C++ 基本文件 *
// **********************/
//#include<algorithm>// 算法模板文件
//#pragma comment(linker, "/STACK:102400000, 102400000")// 输入加速外挂(hdu C++编译器不支持)
//
//using namespace std;
//
//// 常用的功能或常量宏定义
//#define MAX 100005
//#define MAXN 1000005
//#define maxnode 15
//#define sigma_size 26
//#define lson l, m, rt << 1
//#define rson m + 1, r, rt << 1 | 1
//#define lrt rt << 1
//#define rrt rt << 1 | 1
//#define middle int m = (l + r) >> 1
//#define LL long long
//#define ull unsigned long long
//#define mem(x, v) memset(x, v, sizeof(x))
//#define lowbit(x) (x & -x)
//#define pii pair<int, int>
//#define mk make_pair
//#define limit 10000
//#define N 1000100 << 2
//
//const int prime = 999983;
//const int INF = 0x3f3f3f3f;
//const LL INFF = 0x3f3f;
//const double pi = acos(-1.0);
//const double inf = 1e18;
//const double eps = 1e-4;
//const LL mod = 1e9 + 7;
//const ull mx = 133333331;
//
//int sto[N];
//int up[N];
//
//void PushUp(int rt)
//{
//    sto[rt] = sto[rt << 1] + sto[rt << 1 | 1];
//}
//void PushDown(int rt, int m)
//{
//    if(up[rt])
//    {
//        int lso = rt << 1;
//        up[lso] = up[lso | 1] = up[rt];
//        sto[lso] = (m - (m >> 1)) * up[rt];
//        sto[lso | 1] = (m >> 1) * up[rt];
//        up[rt] = 0;
//    }
//}
//void Build(int l, int r, int rt)
//{
//    up[rt] = 0;
//    sto[rt] = 1;
//    if(l == r) return;
//    int m = (l + r) >> 1;
//    Build(lson);
//    Build(rson);
//    PushUp(rt);
//}
//void update(int L, int R, int c, int l, int r, int rt)
//{
//    if(L <= l && r <= R)
//    {
//        up[rt] = c;
//        sto[rt] = c * (r - l + 1);
//        return ;
//    }
//    PushDown(rt, r - l + 1);
//    int m = (l + r) >> 1;
//    if(L <= m) update(L, R, c, lson);
//    if(R > m) update(L, R, c, rson);
//    PushUp(rt);
//}
//int main()
//{
//    int T;
//    scanf("%d", &T);
//    int n, m;
//    for(int t = 1; t <= T; t ++)
//    {
//        scanf("%d%d", &n, &m);
//        Build(1, n, 1);
//        while(m--)
//        {
//            int a, b, c;
//            scanf("%d%d%d", &a, &b, &c);
//            update(a, b, c, 1, n, 1);
//        }
//        printf("Case %d: The total value of the hook is %d.\n", t, sto[1]);
//    }
//    return 0;
//}

// poj 3468 A Simple Problem with Integers
// 线段树功能:update:成段增减 query:区间求和
//#include<map>
//#include<set>
//#include<stack>
//#include<queue>
//#include<vector>
//#include<unordered_map>// (pku C++, G++编译器不支持)
//#include<unordered_set>// (pku C++, G++编译器不支持)
//#include <ext/hash_map>// (hdu C++编译器不支持)  (pku C++, G++编译器不支持)
///***********************
// *以上是 C++ 常用容器 *
// **********************/
//#include<string>
//#include<sstream>
//#include<fstream>
//#include<istream>
//#include<ostream>
//#include<iostream>
//#include<strstream>// (pku G++编译器不支持)
///***********************
// *以上是 C++ 流式文件 *
// **********************/
//#include<math.h>
//#include<time.h>
//#include<ctype.h> // 字符文件
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
///***********************
// *以上是 C++ 基本文件 *
// **********************/
//#include<algorithm>// 算法模板文件
//#pragma comment(linker, "/STACK:102400000, 102400000")// 输入加速外挂(hdu C++编译器不支持) (pku C++编译器不支持)
//
//using namespace std;
//
//// 常用的功能或常量宏定义
//#define maxnode 15
//#define sigma_size 26
//#define lson l, m, rt << 1
//#define rson m + 1, r, rt << 1 | 1
//#define lrt rt << 1
//#define rrt rt << 1 | 1
//#define middle int m = (l + r) >> 1
//#define LL long long
//#define ull unsigned long long
//#define mem(x, v) memset(x, v, sizeof(x))
//#define lowbit(x) (x & -x)
//#define pii pair<int, int>
//#define mk make_pair
//#define limit 10000
//#define N 100100 << 2
//
//const int prime = 999983;
//const int INF = 0x3f3f3f3f;
//const LL INFF = 0x3f3f;
//const double pi = acos(-1.0);
//const double inf = 1e18;
//const double eps = 1e-4;
//const LL mod = 1e9 + 7;
//const ull mx = 133333331;
//
//LL sto[N];
//LL up[N];
//
//void PushUp(int rt)
//{
//    sto[rt] = sto[rt << 1] + sto[rt << 1 | 1];
//}
//void PushDown(int rt, int m)
//{
//    if(up[rt])
//    {
//        up[lrt] += up[rt];
//        up[rrt] += up[rt];
//        sto[lrt] += (m - (m >> 1)) * up[rt];
//        sto[rrt] += (m >> 1) * up[rt];
//        up[rt] = 0;
//    }
//}
//void Build(int l, int r, int rt)
//{
//    up[rt] = 0;
//    if(l == r)
//    {
//        scanf("%lld", &sto[rt]);
//        return;
//    }
//    int m = (l + r) >> 1;
//    Build(lson);
//    Build(rson);
//    PushUp(rt);
//}
//void update(int L, int R, int c, int l, int r, int rt)
//{
//    if(L <= l && r <= R)
//    {
//        up[rt] += c;
//        sto[rt] += (LL)c * (r - l + 1);
//        return ;
//    }
//    PushDown(rt, r - l + 1);
//    int m = (l + r) >> 1;
//    if(L <= m) update(L, R, c, lson);
//    if(m < R) update(L, R, c, rson);
//    PushUp(rt);
//}
//LL query(int L, int R, int l, int r, int rt)
//{
//    if(L <= l && r <= R) return sto[rt];
//    PushDown(rt, r - l + 1);
//    int m = (l + r) >> 1;
//    LL res = 0;
//    if(L <= m) res += query(L, R, lson);
//    if(m < R) res += query(L, R, rson);
//    return res;
//}
//int main()
//{
//    int n, m;
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        Build(1, n, 1);
//        char op[3];
//        while(m--)
//        {
//            scanf("%s", op);
//            if(op[0] == 'Q')
//            {
//                int a, b;
//                scanf("%d%d", &a, &b);
//                printf("%lld\n", query(a, b, 1, n, 1));
//            }
//            else
//            {
//                int a, b, c;
//                scanf("%d%d%d", &a, &b, &c);
//                update(a, b, c, 1, n, 1);
//            }
//        }
//    }
//    return 0;
//}

// poj 2528 Mayor’s posters
/**
    1
    6
    1 10
    1 4
    5 10
    1 10
    1 4
    6 10
  */
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//#define lson l, m, rt << 1
//#define rson m + 1, r, rt << 1 | 1
//
//using namespace std;
//
//const int maxn = 1e5 + 100;
//bool hash[maxn];
//int l[maxn], r[maxn];
//
//int X[maxn * 3];
//int col[maxn << 4];
//int cnt;
//
//void PushDown(int rt)
//{
//    if(col[rt] != -1)
//    {
//        col[rt << 1] = col[rt << 1 | 1] = col[rt];
//        col[rt] = -1;
//    }
//}
//void update(int L, int R, int c, int l, int r, int rt)
//{
//    if(L <= l && r <= R)
//    {
//        col[rt] = c;
//        return ;
//    }
//    PushDown(rt);
//    int m = (l + r) >> 1;
//    if(L <= m) update(L, R, c, lson);
//    if(m < R) update(L, R, c, rson);
//}
//
//void query(int l, int r, int rt)
//{
//    if (col[rt] != -1)
//    {
//        if(!hash[col[rt]]) cnt++;
//        hash[col[rt]] = true;
//        return ;
//    }
//    if(l == r) return ;
//    int m = (l + r) >> 1;
//    query(lson);
//    query(rson);
//}
//int Binary(int key, int n, int X[])
//{
//    int l = 0, r = n - 1;
//    while(l <= r)
//    {
//        int m = (l + r) >> 1;
//        if(X[m] == key) return m;
//        if(X[m] < key) l = m + 1;
//        else r = m - 1;
//    }
//    return -1;
//}
//int main()
//{
//    int T;
//    int n;
//    scanf("%d", &T);
//    while(T--)
//    {
//        scanf("%d", &n);
//        int cur = 0;
//        for(int i = 0; i < n; i ++)
//        {
//            scanf("%d%d", &l[i], &r[i]);
//            X[cur ++] = l[i];
//            X[cur ++] = r[i];
//        }
//        sort(X, X + cur);
//        int m = 1;
//        for(int i = 1; i < cur; i ++)
//            if(X[i] != X[i - 1]) X[m ++] = X[i];
//        for(int i = m - 1; i > 0; i --)
//            if(X[i] != X[i - 1] + 1) X[m ++] = X[i - 1] + 1;
//        sort(X, X + m);
//        memset(col, -1, sizeof(col));
//        for(int i = 0; i < n; i ++)
//        {
//            int s = Binary(l[i], m, X);
//            int e = Binary(r[i], m, X);
//            update(s, e, i, 0, m, 1);
//        }
//        cnt = 0;
//        memset(hash, false, sizeof(hash));
//        query(0, m, 1);
//        printf("%d\n", cnt);
//    }
//    return 0;
//}

// poj 2155 Matrix (二维线段树)
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//#define xlson xl, mid, xrt << 1
//#define xrson mid + 1, xr, xrt << 1 | 1
//#define ylson yl, mid, yrt << 1
//#define yrson mid + 1, yr, yrt << 1 | 1
//
//#define N 1010 << 2
//using namespace std;
//
//bool tree[N][N];
//int num, n;
//
//void update_y(int xrt, int y1, int y2, int yl, int yr, int yrt)
//{
//    if(y1 <= yl && yr <= y2)
//    {
//        tree[xrt][yrt] = !tree[xrt][yrt];
//        return ;
//    }
//    int mid = (yl + yr) >> 1;
//    if(y1 <= mid) update_y(xrt, y1, y2, ylson);
//    if(y2 > mid) update_y(xrt, y1, y2, yrson);
//}
//void update(int x1, int y1, int x2, int y2, int xl, int xr, int xrt)
//{
//    if(x1 <= xl && xr <= x2)
//    {
//        update_y(xrt, y1, y2, 1, n, 1);
//        return ;
//    }
//    int mid = (xl + xr) >> 1;
//    if(x1 <= mid) update(x1, y1, x2, y2, xlson);
//    if(x2 > mid) update(x1, y1, x2, y2, xrson);
//}
//void query_y(int xrt, int y, int yl, int yr, int yrt)
//{
//    if(tree[xrt][yrt]) num ++;
//    if(yl == yr) return ;
//    int mid = (yl + yr) >> 1;
//    if(y <= mid) query_y(xrt, y, ylson);
//    else query_y(xrt, y, yrson);
//}
//void query(int x, int y, int xl, int xr, int xrt)
//{
//    query_y(xrt, y, 1, n, 1);
//    if(xl == xr) return;
//    int mid = (xl + xr) >> 1;
//    if(x <= mid) query(x, y, xlson);
//    else query(x, y, xrson);
//}
//int main()
//{
//    int T;
//    scanf("%d", &T);
//    for(int t = 0; t < T; t ++)
//    {
//        if(t) puts("");
//        memset(tree, false, sizeof(tree));
//        int m;
//        int a, b, c, d;
//        scanf("%d%d", &n, &m);
//        for(int i = 1; i <= m; i ++)
//        {
//            char str[10];
//            scanf("%s", str);
//            if(str[0] == 'C')
//            {
//                scanf("%d%d%d%d", &a, &b, &c, &d);
//                update(a, b, c, d, 1, n, 1);
//            }
//            else
//            {
//                scanf("%d%d", &a, &b);
//                num = 0;
//                query(a, b, 1, n, 1);
//                if(num & 1) puts("1");
//                else puts("0");
//            }
//        }
//    }
//    return 0;
//}

// poj 3225 Help with Intervals
//#include<stdio.h>
//#include<ctype.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//#define lson l, mid, rt << 1
//#define rson mid + 1, r, rt << 1 | 1
//
//#define N 131072
//
//using namespace std;
//
//bool mark[N];
//int cover[N << 2];
//int XOR[N << 2];
//
//void Replace(int rt)
//{
//    if(cover[rt] != -1) cover[rt] ^= 1;
//    else XOR[rt] ^= 1;
//}
//void PushDown(int rt)
//{
//    if(cover[rt] != -1)
//    {
//        cover[rt << 1] = cover[rt << 1 | 1] = cover[rt];
//        XOR[rt << 1] = XOR[rt << 1 | 1] = 0;
//        cover[rt] = -1;
//    }
//    if(XOR[rt])
//    {
//        Replace(rt << 1);
//        Replace(rt << 1 | 1);
//        XOR[rt] = 0;
//    }
//}
//void update(char op, int L, int R, int l, int r, int rt)
//{
//    if(L <= l && r <= R)
//    {
//        if(op == 'U')
//        {
//            cover[rt] = 1;
//            XOR[rt] = 0;
//        }
//        else if(op == 'D')
//        {
//            cover[rt] = 0;
//            XOR[rt] = 0;
//        }
//        else if(op == 'C' || op == 'S') Replace(rt);
//        return ;
//    }
//    PushDown(rt);
//    int mid = (l + r) >> 1;
//    if(L <= mid) update(op, L, R, lson);
//    else if(op == 'I' || op == 'C') cover[rt << 1] = XOR[rt << 1] = 0;
//    if(mid < R) update(op, L, R, rson);
//    else if(op == 'I' || op == 'C') cover[rt << 1 | 1] = XOR[rt << 1 | 1] = 0;
//}
//void query(int l, int r, int rt)
//{
//    if(cover[rt] == 1)
//    {
//        for(int it = l; it <= r; it ++)
//            mark[it] = true;
//        return ;
//    }
//    else if(cover[rt] == 0) return ;
//    if(l == r) return ;
//    PushDown(rt);
//    int mid = (l + r) >> 1;
//    query(lson);
//    query(rson);
//}
//int main()
//{
//    for(int i = 0; i <= N; i ++)
//    {
//        cover[i] = XOR[i] = 0;
//        mark[i] = false;
//    }
//    char op, l, r;
//    int a, b;
//    while(scanf("%c %c%d,%d%c",&op, &l, &a, &b, &r) != EOF)
//    {
//        a <<= 1, b <<= 1;
//        if(l == '(') a ++;
//        if(r == ')') b --;
//        update(op, a, b, 0, N, 1);
//        getchar();
//    }
//    query(0, N, 1);
//    bool flag = false;
//    int s = -1, e;
//    for(int i = 0; i <= N; i ++)
//    {
//        if(mark[i])
//        {
//            if(s == -1) s = i;
//            e = i;
//        }
//        else
//        {
//            if(s != -1)
//            {
//                if(flag) printf(" ");
//                flag = true;
//                printf("%c%d,%d%c", s & 1 ? '(' : '[', s >> 1, (e + 1) >> 1, e & 1 ? ')' : ']');
//            }
//            s = -1;
//        }
//    }
//    if(!flag) printf("empty set");
//    puts("");
//    return 0;
//}

//POJ 2828 Buy Tickets
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//#define lson l, mid, rt << 1
//#define rson mid + 1, r, rt << 1 | 1
//
//using namespace std;
//const int maxn = 2e5 + 100;
//int sto[maxn << 2];
//struct node
//{
//    int pos;
//    int val;
//} data[maxn];
//int ans[maxn];
//void PushUp(int rt)
//{
//    sto[rt] = sto[rt << 1] + sto[rt << 1 | 1];
//}
//void Init(int l, int r, int rt)
//{
//    if(l == r)
//    {
//        sto[rt] = 1;
//        return ;
//    }
//    int mid = (l + r) >> 1;
//    Init(lson);
//    Init(rson);
//    PushUp(rt);
//}
//void Update(int p, int v, int l, int r, int rt)
//{
//    if(l == r)
//    {
//        sto[rt] = 0;
//        ans[l] = v;
//        return;
//    }
//    int mid = (l + r) >> 1;
//    if(p <= sto[rt << 1]) Update(p, v, lson);
//    else Update(p - sto[rt << 1], v, rson);
//    PushUp(rt);
//}
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        Init(1, n, 1);
//        for(int i = 1; i <= n; i ++)
//            scanf("%d%d", &data[i].pos, &data[i].val);
//        for(int i = n; i >= 1; i --)
//            Update(data[i].pos + 1, data[i].val, 1, n, 1);
//        for(int i = 1; i <= n; i ++)
//            printf("%d%c", ans[i], i == n ? '\n' : ' ');
//    }
//    return 0;
//}

// poj 3667 Hotel: 区间合并
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//#define lson l, mid, rt << 1
//#define rson mid + 1, r, rt << 1 | 1
//
//using namespace std;
//const int maxn = 55555;
//
//struct node
//{
//    int lsum, msum, rsum;
//}sto[maxn << 2];
//int cover[maxn << 2];
//
//void PushUp(int rt, int cnt)
//{
//    sto[rt].lsum = sto[rt << 1].lsum;
//    sto[rt].rsum = sto[rt << 1 | 1].rsum;
//
//    if(sto[rt].lsum == cnt - (cnt >> 1)) sto[rt].lsum += sto[rt << 1 | 1].lsum;
//    if(sto[rt].rsum == (cnt >> 1)) sto[rt].rsum += sto[rt << 1].rsum;
//    sto[rt].msum = max(sto[rt << 1 | 1].lsum + sto[rt << 1].rsum, max(sto[rt << 1].msum, sto[rt << 1 | 1].msum));
//}
//void PushDown(int rt, int cnt)
//{
//    if(cover[rt] != -1)
//    {
//        cover[rt << 1] = cover[rt << 1 | 1] = cover[rt];
//        sto[rt << 1].lsum = sto[rt << 1].msum = sto[rt << 1].rsum = cover[rt] ? 0 : cnt - (cnt >> 1);
//        sto[rt << 1 | 1].lsum = sto[rt << 1 | 1].msum = sto[rt << 1 | 1].rsum = cover[rt] ? 0 : (cnt >> 1);
//        cover[rt] = -1;
//    }
//}
//void BuildTree(int l, int r, int rt)
//{
//    sto[rt].lsum = sto[rt].msum = sto[rt].rsum = r - l + 1;
//    cover[rt] = -1;
//    if(l == r) return;
//    int mid = (l + r) >> 1;
//    BuildTree(lson);
//    BuildTree(rson);
//}
//void update(int L, int R, int c, int l, int r, int rt)
//{
//    if(L <= l && r <= R)
//    {
//        sto[rt].lsum = sto[rt].msum = sto[rt].rsum = c ? 0 : r - l + 1;
//        cover[rt] = c;
//        return ;
//    }
//    PushDown(rt, r - l + 1);
//    int mid = (l + r) >> 1;
//    if(L <= mid) update(L, R, c, lson);
//    if(mid < R) update(L, R, c, rson);
//    PushUp(rt, r - l + 1);
//}
//int query(int w, int l, int r, int rt)
//{
//    if(l == r) return l;
//    PushDown(rt, r - l + 1);
//    int mid = (l + r) >> 1;
//    if(sto[rt << 1].msum >= w) return query(w, lson);
//    else if(sto[rt << 1].rsum + sto[rt << 1 | 1].lsum >= w) return mid - sto[rt << 1].rsum + 1;
//    return query(w, rson);
//}
//int main()
//{
//    int n, m;
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        BuildTree(1, n, 1);
//        while(m --)
//        {
//            int op, a, b;
//            scanf("%d", &op);
//            if(op == 1)
//            {
//                scanf("%d", &a);
//                if(sto[1].msum < a) puts("0");
//                else
//                {
//                    int p = query(a, 1, n, 1);
//                    printf("%d\n", p);
//                    update(p, p + a - 1, 1, 1, n, 1);
//                }
//            }
//            else
//            {
//                scanf("%d%d", &a, &b);
//                update(a, a + b - 1, 0, 1, n, 1);
//            }
//        }
//    }
//    return 0;
//}

// hdu 1542 ： Atlantis 点建树与段建树
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//#define lson l, mid, rt << 1
//#define rson mid + 1, r, rt << 1 | 1
//
//using namespace std;
//
//const int maxn = 800;
//
//struct node
//{
//    double l, r, y;// 左右端点，纵坐标
//    int f; // 增量的意思是扫到上边的时候总区间减去这条边，扫到下边的时候总区间加上这条边，用1,-1表示
//    bool operator<(const node &S)const
//    {
//        return y < S.y;
//    }
//} s[maxn];
//double pos[maxn];// 记录所有线段的横坐标
//
//int m;
//// 线段树
//struct edge
//{
//    int l, r, cnt;// 维护每条线段的左右端点， 该线段被重复覆盖了几次
//    double len;// 该区间被覆盖区间的实际总长度， 对应是真实坐标值
//} sto[maxn];
//int Binary(double x)
//{
//    int l = 1, r = m;
//    while(l <= r)
//    {
//        int mid = (l + r) >> 1;
//        if(pos[mid] > x) r = mid - 1;
//        else if(pos[mid] < x) l = mid + 1;
//        else return mid;
//    }
//    if(pos[l] == x) return l;
//    return r;
//}
//void BuildTree(int l, int r, int rt)
//{
//    sto[rt].l = l, sto[rt].r = r, sto[rt].cnt = 0, sto[rt].len = 0.0;
//    if(l == r) return ;
//    int mid = (l + r) >> 1;
//    BuildTree(lson);
//    BuildTree(rson);
//}
//void getline(int rt)
//{
//    if(sto[rt].cnt) sto[rt].len = pos[sto[rt].r + 1] - pos[sto[rt].l];
//    else if(sto[rt].l == sto[rt].r) sto[rt].len = 0; // 这里是叶子节点， 已经不是一条线段，所以是0
//    else sto[rt].len = sto[rt << 1].len + sto[rt << 1 | 1].len;
//}
//void update(int l, int r, int rt, int add)
//{
//    if(sto[rt].l == l && sto[rt].r == r)
//    {
//        sto[rt].cnt += add;
//        getline(rt);
//        return ;
//    }
//    int mid = (sto[rt].l + sto[rt].r) >> 1;
//    if(r <= mid) update(l, r, rt << 1, add);
//    else if(l > mid) update(l, r, rt << 1 | 1, add);
//    else
//    {
//        update(lson, add);
//        update(rson, add);
//    }
//    getline(rt);
//}
//int main()
//{
//    int n;
//    int k = 1;
//    while(scanf("%d", &n), n)
//    {
//        int num = 0;
//        double x1, y1,x2,y2;
//        for(int i = 1; i <= n; i ++)
//        {
//            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
//            num ++;
//            s[num].l = x1, s[num].r = x2;
//            s[num].y = y1;
//            s[num].f = 1, pos[num] = x1;
//
//            num ++;
//            s[num].l = x1, s[num].r = x2;
//            s[num].y = y2;
//            s[num].f = -1, pos[num] = x2;
//        }
//        sort(s + 1, s + num + 1);
//        sort(pos + 1, pos + num + 1);
//        m = 1;
//        for(int i = 2; i <= num; i ++)
//            if(pos[i] != pos[i - 1])
//            {
//                m++;
//                pos[m] = pos[i];
//            }
//        // BuildTree(1, m, 1); // 点建树: 即叶子节点表示一个点的左边
//        BuildTree(1, m - 1, 1);// 段建树: 即叶子节点表示该点到右边一点的线段，左闭右开
//        s[0].y = 0;
//        double sum = 0.0;
//        for(int i = 1; i <= num; i ++)
//        {
//            sum += sto[1].len *(s[i].y - s[i - 1].y);
//            int l = Binary(s[i].l);
//            int r = Binary(s[i].r) - 1;
//            update(l, r, 1, s[i].f);
//        }
//        printf("Test case #%d\n", k ++);
//        printf("Total explored area: %.2f\n\n", sum);
//    }
//    return 0;
//}

// hdu 1542 ： Atlantis 扫描线（用于增减线段）
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//#define MAXN 250
//#define lson l, mid, rt << 1
//#define rson mid + 1, r, rt << 1 | 1
//
//using namespace std;
//
//struct node
//{
//    double l, r, y;
//    int f;
//} s[MAXN];
//double num, pos[MAXN];
//int n, m;
//bool cmp(node a, node b)
//{
//    return a.y < b.y;
//}
//struct egde
//{
//    int l, r, cnt;
//    double len;
//} sto[MAXN << 2];
//int Binary(int l, int r, double x)
//{
//    while(l <= r)
//    {
//        int mid = (l + r) >> 1;
//        if(pos[mid] == x)return mid;
//        else if(pos[mid] > x) r = mid - 1;
//        else l = mid + 1;
//    }
//    if(pos[l] == x) return l;
//    return r;
//}
//void BuildTree(int l, int r, int rt)
//{
//    sto[rt].l = l;
//    sto[rt].r = r;
//    sto[rt].cnt = 0;
//    sto[rt].len = 0.0;
//    if(l == r) return;
//    int mid = (l + r) >> 1;
//    BuildTree(lson);
//    BuildTree(rson);
//}
//void update(int l, int r, int rt, int add)
//{
//    if(sto[rt].cnt != -1 && sto[rt].l == l && sto[rt].r == r)
//    {
//        sto[rt].cnt += add;
//        return;
//    }
//    if(sto[rt].cnt != -1)
//    {
//        sto[rt << 1].cnt = sto[rt << 1 | 1].cnt = sto[rt].cnt;
//        sto[rt].cnt = -1;
//    }
//    int mid = (sto[rt].l + sto[rt].r) >> 1;
//    if(r <= mid) update(l, r, rt << 1, add);
//    else if(l > mid) update(l, r, rt << 1 | 1, add);
//    else
//    {
//        update(lson, add);
//        update(rson, add);
//    }
//}
//void question(int l, int r, int rt)
//{
//    if(sto[rt].l == l && sto[rt].r == r && sto[rt].cnt > 0)
//    {
//        num += pos[sto[rt].r + 1] - pos[sto[rt].l];
//        return ;
//    }
//    if(sto[rt].cnt == 0) return ;
//    int mid = (sto[rt].l + sto[rt].r) >> 1;
//    if(r <= mid) question(l, r, rt << 1);
//    else if(l > mid) question(l, r, rt << 1 | 1);
//    else
//    {
//        question(lson);
//        question(rson);
//    }
//}
//
//int main()
//{
//    int tt = 1;
//    double sum = 0.0;
//    while(scanf("%d", &n), n)
//    {
//        int t = 0;
//        double x, y, xx, yy;
//        for(int i = 1; i <= n; i ++)
//        {
//            scanf("%lf%lf%lf%lf", &x, &y, &xx, &yy);
//            pos[i] = x,pos[i + n] = xx;
//            t++;
//            s[t].y = y, s[t].l = x, s[t].r = xx, s[t].f = 1;
//            t++;
//            s[t].y = yy, s[t].l = x, s[t].r = xx, s[t].f = -1;
//        }
//        sort(pos + 1, pos + 2 * n + 1);
//        m = 1;
//        for(int i = 2; i <= 2 * n; i ++)
//            if(pos[m] != pos[i])
//            m++, pos[m] = pos[i];
//        BuildTree(1, m, 1);
//        sum = 0.0;
//        sort(s + 1, s + 2 * n + 1, cmp);
//        s[0].y = 0;
//        for(int i = 1; i <= 2 * n; i ++)
//        {
//            num = 0;
//            question(1, m - 1, 1);
//            sum += num * (s[i].y - s[i - 1].y);
//            int l = Binary(1, m, s[i].l);
//            int r = Binary(1, m, s[i].r);
//            update(l, r - 1, 1, s[i].f);
//        }
//        printf("Test case #%d\n", tt++);
//        printf("Total explored area: %.2f\n\n", sum);
//    }
//    return 0;
//}

// Ural 1890 Money out of Thin Air： DFS序 + 线段树
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//#define lson l, mid, rt << 1
//#define rson mid + 1, r, rt << 1 | 1
//
////4 3 1
////0 10
////0 10
////1 10
////employee 2 15 1
////employee 3 5 1
////department 0 10 1
//
//using namespace std;
//
//typedef long long LL;
//
//const int maxn = 5e4 + 100;
//
//struct edge
//{
//    int to, next;
//} edge[maxn * 2];
//
//struct node
//{
//    int l, r;
//    LL sum, val;
//} sto[maxn << 2];
//
//int head[maxn], s[maxn], e[maxn];
//int tot, Max, dfs[maxn];
//LL ans[maxn], w[maxn];
//
//void addEdge(int from, int to)
//{
//    edge[tot].to = to;
//    edge[tot].next = head[from];
//    head[from] = tot++;
//}
//void DFS(int u)
//{
//    s[u] = ++ Max;
//    dfs[Max] = u;
//    for(int i = head[u]; i != -1; i = edge[i].next)
//    {
//        int v = edge[i].to;
//        DFS(v);
//        e[v] = Max;
//    }
//}
//
//void PushUp(int rt)
//{
//    sto[rt].sum = sto[rt << 1].sum + sto[rt << 1 | 1].sum;
//}
//
//void PushDown(int rt, int cnt)
//{
//    if(sto[rt].val == 0 || cnt == 1) return;
//    sto[rt << 1].sum += (cnt - (cnt >> 1))* sto[rt].val;
//    sto[rt << 1 | 1].sum += (cnt >> 1) * sto[rt].val;
//    sto[rt << 1].val += sto[rt].val;
//    sto[rt << 1 | 1].val += sto[rt].val;
//    sto[rt].val = 0;
//}
//
//void Init(int l, int r, int rt)
//{
//    sto[rt].l = l, sto[rt].r = r, sto[rt].val = 0;
//    if(l == r)
//    {
//        sto[rt].sum = w[dfs[l]];
//        return ;
//    }
//    int mid = (l + r) >> 1;
//    Init(lson);
//    Init(rson);
//    PushUp(rt);
//}
//
//void update(int l, int r, int rt, LL x)
//{
//    if(sto[rt].l == l && sto[rt].r == r)
//    {
//        sto[rt].sum += (r - l + 1) * x;
//        sto[rt].val += x;
//        return;
//    }
//    PushDown(rt, sto[rt].r - sto[rt].l + 1);
//    int mid = (sto[rt].l + sto[rt].r) >> 1;
//    if(r <= mid) update(l, r, rt << 1, x);
//    else if(l > mid) update(l, r, rt << 1 | 1, x);
//    else
//    {
//        update(lson, x);
//        update(rson, x);
//    }
//    PushUp(rt);
//}
//
//LL query(int l, int r, int rt)
//{
//    if(sto[rt].l == l && sto[rt].r == r)
//        return sto[rt].sum;
//    PushDown(rt, sto[rt].r - sto[rt].l + 1);
//    int mid = (sto[rt].l + sto[rt].r) >> 1;
//    if(r <= mid) return query(l, r, rt << 1);
//    else if(l > mid) return query(l, r, rt << 1 | 1);
//    else
//    {
//        LL num = 0ll;
//        num += query(lson);
//        num += query(rson);
//        return num;
//    }
//}
//void display(int rt)
//{
//    if(sto[rt].l == sto[rt].r)
//    {
//        int num = sto[rt].l;
//        ans[dfs[num]] = sto[rt].sum;
//        return ;
//    }
//    PushDown(rt, sto[rt].r - sto[rt].l + 1);
//    display(rt << 1);
//    display(rt << 1 | 1);
//}
//int main()
//{
//    int n, q;
//    while(scanf("%d%d%I64d", &n, &q, &w[0]) != EOF)
//    {
//        for(int i = 0; i < maxn; i ++)
//        {
//            head[i] = -1;
//            dfs[i] = 0;
//            e[i] = 0;
//        }
//        tot = 0, Max = 0;
//        int u;
//        for(int i = 1; i < n; i ++)
//        {
//            scanf("%d%I64d", &u, &w[i]);
//            addEdge(u, i);
//        }
//        DFS(0);
////        printf("dfs：");
////        for(int i = 0; i < n; i ++)
////        printf("%d%c", dfs[i], i == n - 1 ? '\n' : ' ');
////        printf("s：");
////        for(int i = 0; i < n; i ++)
////        printf("%d%c", s[i], i == n - 1 ? '\n' : ' ');
////        printf("e：");
////        for(int i = 0; i < n; i ++)
////        printf("%d%c", e[i], i == n - 1 ? '\n' : ' ');
//        e[0] = Max;
//        Init(1, n, 1);
//        char str[20];
//        LL x, y, z;
//        while(q--)
//        {
//            scanf("%s%I64d%I64d%I64d", str, &x, &y, &z);
//            if(str[0] == 'e')
//            {
//                LL tmp = query(s[x], s[x], 1);
//                if(tmp < y) update(s[x], s[x], 1, z);
//            }
//            else
//            {
//                LL tmp = query(s[x], e[x], 1);
//                LL num = (e[x] - s[x] + 1) * y;
//                if(tmp < num) update(s[x], e[x], 1, z);
//            }
//        }
//        display(1);
//        for(int i = 0; i < n; i ++) printf("%I64d\n", ans[i]);
//
//    }
//    return 0;
//}

// POj 2777 Count Color
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<iostream>

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

using namespace std;

const int maxn = 1e6 + 100;

struct node
{
    int l, r;
    int color;
    bool v;
} sto[maxn << 2];

void PushDown(int rt)
{
    if(!sto[rt].v) return;
    sto[rt << 1].color = sto[rt << 1 | 1].color = sto[rt].color;
    sto[rt].v = false;
    sto[rt << 1].v = true;
    sto[rt << 1 | 1].v = true;
}
void Init(int l, int r, int rt)
{
    sto[rt].l = l, sto[rt].r = r, sto[rt].color = (1 << 1), sto[rt].v = true;
    if(l == r) return ;
    int mid = (l + r) >> 1;
    Init(lson);
    Init(rson);
}

void update(int l, int r, int rt, int v)
{
    if(sto[rt].l == l && sto[rt].r == r)
    {
        sto[rt].color = (1 << v);
        sto[rt].v = true;
        return ;
    }
    PushDown(rt);
    int mid = (sto[rt].l + sto[rt].r) >> 1;
    if(r <= mid) update(l, r, rt << 1, v);
    else if(l > mid) update(l, r, rt << 1 | 1, v);
    else
    {
        update(lson, v);
        update(rson, v);
    }
    sto[rt].color = sto[rt << 1].color | sto[rt << 1 | 1].color;
}

int query(int l, int r, int rt)
{
    if(sto[rt].l == l && sto[rt].r == r) return sto[rt].color;
    PushDown(rt);
    int mid = (sto[rt].l + sto[rt].r) >> 1;
    if(r <= mid) return query(l, r, rt << 1);
    else if(l > mid) return query(l, r, rt << 1 | 1);
    else return query(lson) | query(rson);
}

int getAns(int x)
{
    int ans = 0;
    while(x)
    {
        if(x&1) ans++;
        x /= 2;
    }
    return ans;
}

int main()
{
    int L, T, O;
    scanf("%d%d%d", &L, &T, &O);
    Init(1, L, 1);
    char str[5];
    int a, b, c;
    while(O --)
    {
        scanf("%s", str);
        if(str[0] == 'C')
        {
            scanf("%d%d%d", &a, &b, &c);
            if(a > b) swap(a, b);
            update(a, b, 1, c);
        }
        else
        {
            scanf("%d%d", &a, &b);
            if(a > b) swap(a, b);
            int sum = query(a, b, 1);
            int kind = getAns(sum);
            printf("%d\n", kind);
        }
    }
    return 0;
}


