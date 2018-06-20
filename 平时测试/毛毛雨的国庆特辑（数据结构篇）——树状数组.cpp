//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int lim = 4e4 + 10;
//const int maxn = 5e5;
//
//struct node
//{
//    int x, p;
//    int ans;
//} ask[lim + 5];
//
//int loc[maxn + 100];
//int ans[lim + 5];
//int ansx[lim + 5];
//int fa[maxn + 100];
//bool v[maxn + 100];
//
//int Find(int x)
//{
//    return fa[x] == x ? fa[x] : fa[x] = Find(fa[x]);
//}
//int main()
//{
//    int T;
//    int t = 1;
//    while(scanf("%d", &T), T)
//    {
//        if(t != 1) puts("");
//        int nt = sqrt(maxn);
//        memset(ask, 127 / 3, sizeof(ask));
//        memset(ans, 127 / 3, sizeof(ans));
//        memset(ansx, 127 / 3, sizeof(ansx));
//        memset(loc, 127 / 3, sizeof(loc));
//        for(int i = 0; i <= maxn; i ++) v[i] = fa[i] = 0;
//        int tot = 0;
//        for(int i = 1; i <= T; i ++)
//        {
//            char str[5];
//            scanf("%s%d", str, &ask[i].x);
//            if(str[0] == 'B')
//            {
//                tot ++;
//                ask[i].p = 1;
//                for(int j = 1; j <= nt; j ++)
//                    if(ask[i].x %j <= ans[j])
//                    {
//                        ans[j] = ask[i].x %j;
//                        ansx[j] = tot;
//                    }
//                v[ask[i].x] = true;
//                loc[ask[i].x] = tot;
//            }
//            else
//            {
//                ask[i].p = 2;
//                if(ask[i].x <= nt)
//                {
//                    if(ansx[ask[i].x] <= tot)
//                        ask[i].ans = ansx[ask[i].x];
//                    else ask[i].ans = -1;
//                }
//            }
//        }
//        for(int i = maxn; i >= 1; i --)
//        {
//            if(!v[i]) fa[i] = fa[i + 1];
//            else fa[i] = i;
//        }
//        for(int i = T; i >= 1; i --)
//        {
//            if(ask[i].p == 1)
//                fa[ask[i].x] = fa[ask[i].x + 1];
//            else if(ask[i].x > nt)
//            {
//                int minn = ask[i].ans;
//                for(int j = 0; j <= maxn; j += ask[i].x)
//                {
//                    int xt = Find(j);
//                    if(j == 0) xt = Find(1);
//                    if(xt != 0)
//                    {
//                        if(xt - j < minn)
//                        {
//                            minn = xt -j;
//                            ask[i].ans = loc[xt];
//                        }
//                        else if(xt - j <= minn && loc[xt] > ask[i].ans)
//                            ask[i].ans = loc[xt];
//                    }
//                }
//            }
//        }
//        printf("Case %d:\n", t++);
//        for(int i = 1; i <= T; i ++)
//        {
//            if(ask[i].p == 2)
//            {
//                if(ask[i].ans <= tot) printf("%d\n", ask[i].ans);
//                else puts("-1");
//            }
//        }
//    }
//    return 0;
//}

//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int maxn = 2e4 + 100;
//typedef long long LL;
//
//struct point
//{
//    int v;
//    int x;
//    bool operator <(const point &s) const
//    {
//        return v < s.v;
//    }
//}pt[maxn + 5];
//
//LL c[2][maxn + 10];
//int Max;
//
//LL ABS(LL v)
//{
//    return v < 0 ? -v : v;
//}
//inline int lowbit(int x)
//{
//    return x & (-x);
//}
//void Add(int op, int i, int v)
//{
//    while(i <= Max)
//    {
//        c[op][i] += v;
//        i += lowbit(i);
//    }
//}
//LL Sum(int op, int x)
//{
//    LL sum = 0ll;
//    while(x)
//    {
//        sum += c[op][x];
//        x -= lowbit(x);
//    }
//    return sum;
//}
//int main()
//{
//    int N;
//    while(scanf("%d", &N) != EOF)
//    {
//        Max = 0;
//        for(int i = 0; i < N; i ++)
//        {
//            scanf("%d%d", &pt[i].v, &pt[i].x);
//            if(pt[i].x > Max) Max = pt[i].x;
//        }
//        for(int i = 1; i <= Max; i ++)
//            c[0][i] = c[1][i] = 0;
//        sort(pt, pt + N);
//        LL ans = 0ll;
//        for(int i = 0; i < N; i ++)
//        {
//            ans += ABS((Sum(0, Max) - Sum(0, pt[i].x) - (Sum(1, Max) - Sum(1, pt[i].x)) * pt[i].x)) * pt[i].v;
//            ans += ABS((Sum(0, pt[i].x)) - Sum(1, pt[i].x) * pt[i].x) * pt[i].v;
//            Add(0, pt[i].x, pt[i].x);
//            Add(1, pt[i].x, 1);
//        }
//        printf("%I64d\n", ans);
//    }
//    return 0;
//}

//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int maxn = 2e5 + 10;
//int ans[maxn + 5];
//struct node
//{
//    int id;
//    int val;
//}T[maxn + 5];
//
//int c[maxn + 5];
//int n;
//
//inline int lowbit(int x)
//{
//    return x & (-x);
//}
//void Add(int i, int x)
//{
//    while(i <= n)
//    {
//        c[i] += x;
//        i += lowbit(i);
//    }
//}
//int Sum(int x)
//{
//    int sum = 0;
//    while(x)
//    {
//        sum += c[x];
//        x -= lowbit(x);
//    }
//    return sum;
//}
//int main()
//{
//    while(scanf("%d", &n) != EOF)
//    {
//        for(int i = 0; i <= maxn; i ++) c[i] = 0;
//        for(int i = 1; i <= n; i ++)
//        {
//            scanf("%d%d", &T[i].id, &T[i].val);
//            T[i].id ++;
//        }
//        for(int i = n; i >= 1; i --)
//        {
//            int l = 1;
//            int r = n;
//            int cur = 1;
//            while(l <= r)
//            {
//                int mid = (l + r) >> 1;
//                if(mid - Sum(mid) >= T[i].id)
//                {
//                    r = mid - 1;
//                    cur = mid;
//                }
//                else l = mid + 1;
//            }
//            ans[cur] = T[i].val;
//            Add(cur, 1);
//        }
//        for(int i = 1; i <= n; i ++)
//            printf("%d%c", ans[i], i == n ? '\n' : ' ');
//    }
//    return 0;
//}

//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long LL;
//
//const int maxn = 1000;
//const int maxm = 1e6 + 100;
//LL c[maxn + 10];
//int n, m, k;
//
//struct node
//{
//    int l, r;
//    bool operator <(const node &s) const
//    {
//        if(l == s.l) return r < s.r;
//        return l < s.l;
//    }
//}highways[maxm + 10];
//
//inline int lowbit(int x)
//{
//    return x & (-x);
//}
//void Add(int i)
//{
//    while(i <= m)
//    {
//        c[i] ++;
//        i += lowbit(i);
//    }
//}
//LL Sum(int x)
//{
//    LL sum = 0ll;
//    while(x)
//    {
//        sum += c[x];
//        x -= lowbit(x);
//    }
//    return sum;
//}
//
//int main()
//{
//    int T;
//    scanf("%d", &T);
//    for(int t = 1; t <= T; t ++)
//    {
//        scanf("%d%d%d", &n, &m, &k);
//        memset(c, 0ll, sizeof(c));
//        for(int i = 1; i <= k; i ++)
//            scanf("%d%d", &highways[i].l, &highways[i].r);
//        sort(highways + 1, highways + k + 1);
//        LL ans = 0;
//        for(int i = 1; i <= k; i ++)
//        {
//            ans += Sum(m) - Sum(highways[i].r);
//            Add(highways[i].r);
//        }
//        printf("Test case %d: %lld\n", t, ans);
//    }
//    return 0;
//}

//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int maxn = 5e4 + 100;
//int c[maxn + 10];
//int N;
//
//inline int lowbit(int x)
//{
//    return x &(-x);
//}
//void Add(int i, int x)
//{
//    while(i <= N)
//    {
//        c[i] += x;
//        i += lowbit(i);
//    }
//}
//int Sum(int x)
//{
//    int sum = 0;
//    while(x)
//    {
//        sum += c[x];
//        x -= lowbit(x);
//    }
//    return sum;
//}
//int main()
//{
//    int T;
//    scanf("%d", &T);
//    for(int t = 1; t <= T; t ++)
//    {
//        scanf("%d", &N);
//        memset(c, 0, sizeof(c));
//        int value;
//        for(int i = 1; i <= N; i ++)
//        {
//            scanf("%d", &value);
//            Add(i, value);
//        }
//        char str[10];
//        printf("Case %d:\n", t);
//        while(scanf("%s", str), str[0] != 'E')
//        {
//            if(str[0] == 'Q')
//            {
//                int u, v;
//                scanf("%d%d", &u, &v);
//                printf("%d\n", Sum(v) - Sum(u - 1));
//            }
//            else if(str[0] == 'A')
//            {
//                int id, val;
//                scanf("%d%d", &id, &val);
//                Add(id, val);
//            }
//            else
//            {
//                int id, val;
//                scanf("%d%d", &id, &val);
//                Add(id, -val);
//            }
//        }
//    }
//    return 0;
//}

//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <iostream>
//
//using namespace std;
//const int maxn = 1010;
//int c[maxn + 5][maxn + 5];
//int n;
//inline int lowbit(int x)
//{
//    return x & (-x);
//}
//void Add(int x, int y)
//{
//    while(x <= n)
//    {
//        int ty = y;
//        while(ty <= n)
//        {
//            c[x][ty] ^= 1;
//            ty += lowbit(ty);
//        }
//        x += lowbit(x);
//    }
//}
//int GetVal(int x, int y)
//{
//    int res = 0;
//    if(x > n) x = n;
//    if(y > n) y = n;
//    while(x)
//    {
//        int ty = y;
//        while(ty)
//        {
//            res ^= c[x][ty];
//            ty -= lowbit(ty);
//        }
//        x -= lowbit(x);
//    }
//    return res;
//}
//int main()
//{
//    int x;
//    int T;
//    scanf("%d", &x);
//    while(x --)
//    {
//        scanf("%d%d", &n, &T);
//        memset(c, 0, sizeof(c));
//        while(T --)
//        {
//            char str[5];
//            int x1, y1, x2, y2;
//            scanf("%s", str);
//            if(str[0] == 'C')
//            {
//                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
//                Add(x1, y1);
//                Add(x2 + 1, y2 + 1);
//                Add(x1, y2 + 1);
//                Add(x2 + 1, y1);
//            }
//            else
//            {
//                scanf("%d%d", &x1, &y1);
//                printf("%d\n", GetVal(x1, y1));
//            }
//        }
//        if(x) puts("");
//    }
//    return 0;
//}

//#include <stack>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int maxn = 5e4 + 100;
//int n;
//int c[maxn + 10];
//inline int lowbit(int x)
//{
//    return x & (-x);
//}
//void Add(int i, int x)
//{
//    while(i <= n)
//    {
//        c[i] += x;
//        i += lowbit(i);
//    }
//}
//int Sum(int x)
//{
//    int res = 0;
//    while(x)
//    {
//        res += c[x];
//        x -= lowbit(x);
//    }
//    return res;
//}
//int main()
//{
//    int m;
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        stack <int> s;
//        memset(c, 0, sizeof(c));
//        for(int i = 1; i <= n; i ++) Add(i, 1);
//        char str[5];
//        while(m --)
//        {
//            scanf("%s", str);
//            if(str[0] == 'D')
//            {
//                int x;
//                scanf("%d", &x);
//                Add(x, -1);
//                s.push(x);
//            }
//            else if(str[0] == 'R')
//            {
//                int id = s.top();
//                s.pop();
//                while(Sum(id) - Sum(id - 1) != 1)
//                Add(id, 1);
//            }
//            else
//            {
//                int x;
//                scanf("%d", &x);
//                if(Sum(x) - Sum(x - 1) == 0)
//                {
//                    puts("0");
//                    continue;
//                }
//                int l = x, r = n;
//                int ans;
//                while(l <= r)
//                {
//                    int mid = (l + r) >> 1;
//                    if(Sum(mid) - Sum(x - 1) == mid - x + 1)\
//                    {
//                        ans = mid;
//                        l = mid + 1;
//                    }
//                    else r = mid - 1;
//                }
//                int re = ans;
//                l = 1, r = x;
//                while(l <= r)
//                {
//                    int mid = (l + r) >> 1;
//                    if(Sum(x) - Sum(mid - 1) == x - mid + 1)
//                    {
//                        ans = mid;
//                        r = mid - 1;
//                    }
//                    else l = mid + 1;
//                }
//                int rs = ans;
//                printf("%d\n", re - rs + 1);
//            }
//        }
//    }
//    return 0;
//}

//#include <set>
//#include <stack>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//set<int >s;
//set<int > :: iterator it;
//stack <int >st;
//
//int main()
//{
//    int n, m;
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        while(!st.empty()) st.pop();
//        s.clear();
//        char op[2];
//        int x;
//        while(m --)
//        {
//            scanf("%s", op);
//            if(op[0] == 'D')
//            {
//                scanf("%d", &x);
//                s.insert(x);
//                st.push(x);
//            }
//            else if(op[0] == 'Q')
//            {
//               scanf("%d", &x);
//               if(s.find(x) != s.end())
//                   puts("0");
//                else
//                {
//                    int l = 1, r = n;
//                    it = s.upper_bound(x);
//                    if(it != s.end())
//                        r = (*it) - 1;
//                    if(it != s.begin())
//                    {
//                        it --;
//                        l = (*it) + 1;
//                    }
//                    printf("%d\n", r - l + 1);
//                }
//            }
//            else
//            {
//                if(st.empty()) continue;
//                int tmp = st.top();
//                st.pop();
//                s.erase(tmp);
//            }
//        }
//    }
//    return 0;
//}

//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int maxn = 5e5 + 10;
//int C[maxn];
//int N;
//
//bool flag[maxn];
//int prime[maxn], ans[maxn], Size;
//int MaxAns[maxn], id[maxn];
//
//struct node
//{
//    char name[20];
//    int value;
//}p[maxn];
//
//inline int lowbit(int x)
//{
//    return x & (-x);
//}
//void Add(int i, int x)
//{
//    while(i <= N)
//    {
//        C[i] += x;
//        i += lowbit(i);
//    }
//}
//int Sum(int x)
//{
//    int sum = 0;
//    while(x > 0)
//    {
//        sum += C[x];
//        x -= lowbit(x);
//    }
//    return sum;
//}
//// 从x到y中找到第k个存在的元素
//int Binary(int l, int r, int k)
//{
//    int ans;
//    if(l <= r)
//    {
//        int pre = Sum(l - 1);
//        while(l <= r)
//        {
//            int mid = (l + r) >> 1;
//            if(Sum(mid) - pre >= k)
//            {
//                r = mid - 1;
//                ans = mid;
//            }
//            else l = mid + 1;
//        }
//        return ans;
//    }
//    swap(l, r);
//    int pre = Sum(r);
//    while(l <= r)
//    {
//        int mid = (l + r) >> 1;
//        if(pre - Sum(mid - 1) >= k)
//        {
//            l = mid + 1;
//            ans = mid;
//        }
//        else r = mid - 1;
//    }
//    return ans;
//}
//void Prime()
//{
//    memset(flag, 0, sizeof(flag));
//    for(int i = 2; i < maxn; i ++)
//    {
//        if(!flag[i])
//        {
//            prime[Size ++] = i;
//            ans[i] = 2;
//            for(int j = i + i; j < maxn; j += i)
//            {
//                int val = j;
//                if(!ans[j]) ans[j] = 1;
//                int x = 1;
//                while(val % i == 0)
//                {
//                    val /= i;
//                    x ++;
//                }
//                ans[j] *= x;
//                flag[j] = 1;
//            }
//        }
//    }
//    MaxAns[1] = 1;
//    id[1] = 1;
//    for(int i = 2; i < maxn; i ++)
//    {
//        MaxAns[i] = MaxAns[i - 1];
//        id[i] = id[i - 1];
//
//        if(ans[i] > MaxAns[i])
//        {
//            MaxAns[i] = ans[i];
//            id[i] = i;
//        }
//    }
//}
//int main()
//{
//    Prime();
//    int K;
//    while(scanf("%d%d", &N, &K) != EOF)
//    {
//        int pos = id[N];
//        for(int i = 1; i <= N; i ++)
//        {
//            char str[20];
//            int v;
//            scanf("%s%d", str, &v);
//            strcpy(p[i].name, str);
//            p[i].value = v;
//        }
//        if(MaxAns[pos] == 1)
//        {
//            printf("%s 1\n", p[K].name);
//            continue;
//        }
//
//        for(int i = 1; i <= N; i ++) C[i] = 0;
//        for(int i = 1; i <= N; i ++) Add(i, 1);
//        int cur = K;
//        int cnt = 1;
//        Add(K, -1);
//        while(cnt < pos)
//        {
//            int A = p[cur].value;
//            if(A > 0)
//            {
//                A %= (N - cnt);
//                if(A == 0) A = N - cnt;
//                int more = Sum(N) - Sum(cur);
//                if(A <= more) cur = Binary(cur + 1, N, A);
//                else
//                {
//                    A -= more;
//                    cur = Binary(1, cur - 1, A);
//                }
//            }
//            else
//            {
//                A = -A;
//                A %= (N - cnt);
//                if(A == 0) A = N - cnt;
//                int less = Sum(cur - 1);
//                if(A <= less) cur = Binary(cur - 1, 1, A);
//                else
//                {
//                    A -= less;
//                    cur = Binary(N, cur + 1, A);
//                }
//            }
//
//            Add(cur, -1);
//            cnt ++;
//        }
//        printf("%s %d\n", p[cur].name, MaxAns[pos]);
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//int n;
//int a[1000006];
//priority_queue<int>q;
//int main()
//{
//    while(~scanf("%d",&n))
//    {
//        while(!q.empty())
//            q.pop();
//        for(int i=1;i<=n;i++)
//            scanf("%d",&a[i]);
//        ll sum=0;
//        for(int i=n;i>=1;i--)
//        {
//            q.push(a[i]);
//            int data=q.top();
//            sum+=data-a[i];
//        }
//        printf("%lld\n",sum);
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const ll mod=1e9+7;
//ll n;
//struct Matrix
//{
//    ll ma[2][2];
//    void init()
//    {
//        for(int i=0; i<2; i++)
//            for(int j=0; j<2; j++)
//                ma[i][j]=(i==j);
//    }
//};
//Matrix operator *(Matrix A,Matrix B)
//{
//    Matrix temp;
//    for(int i=0; i<2; i++)
//    {
//        for(int j=0; j<2; j++)
//        {
//            temp.ma[i][j]=0;
//            for(int k=0; k<2; k++)
//            {
//                temp.ma[i][j]=(temp.ma[i][j]+(A.ma[i][k]*B.ma[k][j]%mod+mod)%mod)%mod;
//            }
//        }
//    }
//    return temp;
//}
//Matrix mul(Matrix A,ll B)
//{
//    Matrix res;
//    res.init();
//    while(B)
//    {
//        if(B&1)
//            res=res*A;
//        B>>=1;
//        A=A*A;
//    }
//    return res;
//}
//int main()
//{
//    while(~scanf("%lld",&n))
//    {
//        if(n==1) puts("1");
//        else if(n==2) puts("3");
//        else
//        {
//            Matrix A;
//            A.ma[0][0]=3;
//            A.ma[0][1]=-1;
//            A.ma[1][0]=1;
//            A.ma[1][1]=0;
//            Matrix tep=mul(A,n-1);
//            printf("%lld\n",tep.ma[0][0]%mod);
//        }
//    }
//    return 0;
//}

//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int maxn = 2e5 + 100;
//
//int c[maxn + 10];
//int fa[maxn + 10];
//int r[maxn + 10];
//int n;
//
//inline int lowbit(int x)
//{
//    return x & (-x);
//}
//void Add(int i, int x)
//{
//    while(i <= n)
//    {
//        c[i] += x;
//        i += lowbit(i);
//    }
//}
//int Sum(int x)
//{
//    int sum = 0;
//    while(x)
//    {
//        sum += c[x];
//        x -= lowbit(x);
//    }
//    return sum;
//}
//
//int Find(int x)
//{
//    return fa[x] == x ? fa[x] : fa[x] = Find(fa[x]);
//}
//void Union(int x, int y)
//{
//    int xx = Find(x);
//    int yy = Find(y);
//    if(xx != yy)
//    {
//        if(r[xx] == r[yy]) Add(r[xx], -2);
//        else
//        {
//            Add(r[xx], -1);
//            Add(r[yy], -1);
//        }
//        Add(r[xx] + r[yy], 1);
//        if(r[xx] < r[yy])
//        {
//            fa[xx] = yy;
//            r[yy] += r[xx];
//        }
//        else
//        {
//            fa[yy] = xx;
//            r[xx] += r[yy];
//        }
//    }
//}
//
//int Binary(int k)
//{
//    int l = 1, r = n;
//    int ans = 0;
//    int all = Sum(n);
//    while(l <= r)
//    {
//        int mid = (l + r) >> 1;
//        if(k <= all - Sum(mid - 1))
//        {
//            l = mid + 1;
//            ans = mid;
//        }
//        else r = mid - 1;
//    }
//    return ans;
//}
//int main()
//{
//    int m;
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        for(int i = 1; i <= n; i ++)
//        {
//            c[i] = 0;
//            fa[i] = i;
//            r[i] = 1;
//        }
//        Add(1, n);
//        int op;
//        int x, y;
//        while(m --)
//        {
//            scanf("%d", &op);
//            if(op == 0)
//            {
//                scanf("%d%d", &x, &y);
//                Union(x, y);
//            }
//            else
//            {
//                scanf("%d", &x);
//                printf("%d\n", Binary(x));
//            }
//        }
//    }
//    return 0;
//}

//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int maxn = 1e5 + 100;
//const int mod = 9901;
//
//int n;
//int val[maxn], t[maxn], c[maxn];
//int tot;
//
//inline int lowbit(int x)
//{
//    return x & (-x);
//}
//void Add(int i, int x)
//{
//    while(i <= tot)
//    {
//        c[i] += x;
//        if(c[i] >= mod) c[i] %= mod;
//        i += lowbit(i);
//    }
//}
//int Sum(int x)
//{
//    int sum = 0;
//    while(x)
//    {
//        sum += c[x];
//        if(sum >= mod) sum %= mod;
//        x -= lowbit(x);
//    }
//    return sum;
//}
//int Binary(int v)
//{
//    int l = 1, r = tot;
//    while(l <= r)
//    {
//        int mid = (l + r) >> 1;
//        if(v == t[mid]) return mid;
//        if(v > t[mid]) l = mid + 1;
//        else r = mid - 1;
//    }
//}
//// 找到最小的大于等于它的数
//int BThan(int v)
//{
//    int l = 1, r = tot;
//    int ans = 1;
//    while(l <= r)
//    {
//        int mid = (l + r) >> 1;
//        if(t[mid] >= v)
//        {
//            r = mid - 1;
//            ans = mid;
//        }
//        else l = mid + 1;
//    }
//    return ans;
//}
//// 找到最大的小于等于它的数
//int LThan(int v)
//{
//    int l = 1;
//    int r = tot;
//    int ans = tot;
//    while(l <= r)
//    {
//        int mid = (l + r) >> 1;
//        if(t[mid] <= v)
//        {
//            l = mid + 1;
//            ans = mid;
//        }
//        else r = mid - 1;
//    }
//    return ans;
//}
//int main()
//{
//    int d;
//    while(scanf("%d%d", &n, &d) != EOF)
//    {
//        for(int i = 1; i <= n; i ++)
//        {
//            scanf("%d", &val[i]);
//            t[i] = val[i];
//        }
//        tot = 0;
//        sort(t + 1, t + n + 1);
//        for(int i = 1; i <= n; i ++)
//        {
//            if(i == 1 || t[i] != t[i - 1])
//            {
//                t[++tot] = t[i];
//                c[tot] = 0;
//            }
//        }
//        int ans = 0;
//        for(int i = 1; i <= n; i ++)
//        {
//            int nidx = Binary(val[i]);
//            int l = BThan(val[i] - d);
//            int r = LThan(val[i] + d);
//            int preVal = (Sum(r) - Sum(l - 1)) % mod;
//            if(preVal < 0) preVal += mod;
//            ans += preVal + 1;
//            if(ans >= mod) ans %= mod;
//            Add(nidx, preVal + 1);
//        }
//        printf("%d\n", ((ans - n) % mod + mod) % mod);
//    }
//    return 0;
//}

//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//typedef unsigned int UI;
//typedef long long LL;
//
//const int maxn = 1e5 + 100;
//const int mod = 1e9 + 7;
//
//int n;
//UI val[maxn], t[maxn];
//LL c[maxn];
//int tot;
//inline int lowbit(int x)
//{
//    return x & (-x);
//}
//void Add(int i, int x)
//{
//    while(i <= tot)
//    {
//        c[i] += x;
//        if(c[i] >= mod) c[i] %= mod;
//        i += lowbit(i);
//    }
//}
//
//LL Sum(int x)
//{
//    LL sum = 0;
//    while(x)
//    {
//        sum += c[x];
//        if(sum >= mod) sum %= mod;
//        x -= lowbit(x);
//    }
//    return sum;
//}
//
//int Binary(UI val)
//{
//    int l = 1, r = tot;
//    while(l <= r)
//    {
//        int mid = (l + r) >> 1;
//        if(val == t[mid])
//            return mid;
//        if(val > t[mid]) l = mid + 1;
//        else r = mid - 1;
//    }
//}
//int main()
//{
//    while(scanf("%d", &n) != EOF)
//    {
//        for(int i = 1; i <= n; i ++)
//        {
//            scanf("%u", &val[i]);
//            t[i] = val[i];
//        }
//        tot = 0;
//        sort(t + 1, t + n + 1);
//        for(int i = 1; i <= n; i ++)
//        {
//            if(i == 1 || t[i] != t[i - 1])
//            {
//                t[++tot] = t[i];
//                c[tot]  = 0;
//            }
//        }
//        for(int i = 1; i <= n; i ++)
//            val[i] = Binary(val[i]);
//        LL ans = 0;
//        Add(1, 1);
//        for(int i = 1; i <= n; i ++)
//        {
//            LL x = Sum(val[i]);
//            ans += x;
//            if(ans >= mod) ans %= mod;
//            Add(val[i], x);
//        }
//        printf("%d\n", (int )ans);
//    }
//    return 0;
//}

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 100;

struct node
{
    int val;
    int id;
    bool operator < (const node &s) const
    {
        return val < s.val;
    }
} v[maxn];

struct Interval
{
    int l, r, k;
    int id;
    bool operator <(const Interval &s) const
    {
        return l < s.l;
    }
} seg[maxn];
int id[maxn];

struct BIT
{
    int c[maxn];
    int n;

    void SetMaxVal(int v)
    {
        n = v;
    }
    void Clear()
    {
        n = maxn - 1;
        for(int i = 1; i < maxn; i ++) c[i] = 0;
    }
    inline int lowbit(int x)
    {
        return x & (-x);
    }
    void Add(int i, int x)
    {
        while(i && i <= n)
        {
            c[i] += x;
            i += lowbit(i);
        }
    }
    int Sum(int x)
    {
        int sum = 0;
        while(x)
        {
            sum += c[x];
            x -= lowbit(x);
        }
        return sum;
    }
    int Query(int k)
    {
        int l = 1, r = n;
        int ans = 0;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(Sum(mid - 1) < k)
            {
                l = mid + 1;
                if(mid > ans) ans = mid;
            }
            else r = mid - 1;
        }
        return ans;
    }
};
BIT Tree;
int ans[maxn];
int Min(int a, int b)
{
    return a < b ? a : b;
}
int Max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &v[i].val);
            v[i].id = i;
        }
        sort(v + 1, v + n + 1);
        for(int i = 1; i <= n; i ++) id[v[i].id] = i;
        for(int i = 1; i <= m; i ++)
        {
            scanf("%d%d%d", &seg[i].l, &seg[i].r, &seg[i].k);
            if(seg[i].l > seg[i].r)
                swap(seg[i].l, seg[i].r);
            seg[i].id = i;
        }
        sort(seg + 1, seg + m + 1);
        Tree.Clear();
        Tree.SetMaxVal(n);
        seg[0].l = seg[0].r = 0;
        for(int i = 1; i <= m; i ++)
        {
            int MinSub = Min(seg[i - 1].r, seg[i].l - 1);
            // 将上一个区间剩余的数去掉
            for(int j = seg[i - 1].l; j <= MinSub; j ++) Tree.Add(id[j], -1);
            for(int j = seg[i].r + 1; j <= seg[i - 1].r; j ++) Tree.Add(id[j], -1);
            // 加入这个区间新增加的数
            int MaxAdd = Max(seg[i - 1].r + 1, seg[i].l);
            for(int j = MaxAdd; j <= seg[i].r; j ++) Tree.Add(id[j], 1);
            ans[seg[i].id] = v[Tree.Query(seg[i].k)].val;
        }
        for(int i = 1; i <= m; i ++)
            printf("%d\n", ans[i]);
    }
    return 0;
}

//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int maxn = 1e5 + 10;
//int c[maxn], n;
//
//inline int lowbit(int x)
//{
//    return x & (-x);
//}
//void Add(int i, int x)
//{
//    while(i < maxn)
//    {
//        c[i] += x;
//        i += lowbit(i);
//    }
//}
//int Sum(int x)
//{
//    int sum = 0;
//    while(x)
//    {
//        sum += c[x];
//        x -= lowbit(x);
//    }
//    return sum;
//}
//int Query(int a, int k)
//{
//    int l = a + 1, r = maxn - 1;
//    int S = Sum(a);
//    int ans = maxn;
//    while(l <= r)
//    {
//        int mid = (l + r) >> 1;
//        int Q = Sum(mid);
//        if(Q - S >= k)
//        {
//            r = mid - 1;
//            if(mid < ans) ans = mid;
//        }
//        else l = mid + 1;
//    }
//    return ans;
//}
//
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        for(int i = 1; i < maxn; i ++) c[i] = 0;
//        while(n --)
//        {
//            int op, e, a, k;
//            scanf("%d", &op);
//            if(op == 0)
//            {
//                scanf("%d", &e);
//                Add(e, 1);
//            }
//            else if(op == 1)
//            {
//                scanf("%d", &e);
//                if(Sum(e) - Sum(e - 1) == 0) puts("No Elment!");
//                else Add(e, -1);
//            }
//            else
//            {
//                scanf("%d%d", &a, &k);
//                int res = Query(a, k);
//                if(res == maxn) puts("Not Find!");
//                else printf("%d\n", res);
//            }
//
//        }
//    }
//    return 0;
//}
