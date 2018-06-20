// Fashion in Berland
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//const int maxn = 1100;
//
//int main()
//{
//    int n;
//    int array[maxn];
//    while(scanf("%d", &n) != EOF)
//    {
//        for(int i = 0; i < n; i ++)
//            scanf("%d", &array[i]);
//        if(n == 1 && array[0] == 1)
//        {
//            puts("YES");
//            continue;
//        }
//        else if(n == 1 && array[0] == 0)
//        {
//            puts("NO");
//            continue;
//        }
//        int cnt = 0;
//        for(int i = 0; i < n; i ++)
//            if(array[i] == 0)
//                cnt ++;
//        if(cnt == 1) puts("YES");
//        else puts("NO");
//    }
//    return 0;
//}

// s-palindrome
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//const int maxn = 1100;
//
//int main()
//{
//    char str[maxn];
//    while(scanf("%s",str) != EOF)
//    {
//        int len = strlen(str);
//        bool flag = false;
//        for(int i = 0; i < (len + 1) / 2; i ++)
//        {
//            if(str[i] == 'b' && str[len - 1 - i] == 'd')
//                continue;
//            if(str[i] == 'd' && str[len - 1 - i] == 'b')
//                continue;
//            if(str[i] == 'p' && str[len - 1 - i] == 'q')
//                continue;
//            if(str[i] == 'q' && str[len - 1 - i] == 'p')
//                continue;
//            if(str[i] == str[len - 1 - i])
//            {
//                if(str[i] == 'A' || str[i] == 'H' || str[i] == 'I' || str[i] == 'M' || str[i] == 'O' || str[i] == 'T' || str[i] == 'U' || str[i] == 'V' || str[i] == 'W' || str[i] == 'X' || str[i] == 'Y' || str[i] == 'o' || str[i] == 'v' || str[i] == 'w' || str[i] == 'x')
//                    continue;
//            }
//            flag = true;
//            break;
//        }
//        if(!flag) puts("TAK");
//        else puts("NIE");
//    }
//    return 0;
//}

// Pineapple Incident
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//int main()
//{
//    int t, s, x;
//    while(scanf("%d%d%d", &t, &s, &x) != EOF)
//    {
//        if(x >= t && (x - t) % s == 0)
//            puts("YES");
//        else if(x != t + 1 && (x - t - 1) % s == 0)
//            puts("YES");
//        else puts("NO");
//    }
//    return 0;
//}

// Pineapple Incident
//#include<math.h>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    char str[300];
//    while(scanf("%s", str) != EOF)
//    {
//        int len = strlen(str);
//        int a = str[0] - '0';
//        char d[100];
//        int cur = 0;
//        int cnt = 0;
//        for(int i = 2; i < len; i ++)
//        {
//            if(str[i] == 'e')
//            {
//                cur = i + 1;
//                break;
//            }
//            d[cnt ++] = str[i];
//        }
//        d[cnt ++] = '\0';
//        int b = 0;
//        for(int i = cur; i < len; i ++)
//            b = 10 * b + str[i] - '0';
//        printf("%d", a);
//        int cur1 = -1;
//        for(int i = 0; i < b; i ++)
//        {
//            cur1 = i;
//            if(i < cnt - 1) printf("%c", d[i]);
//            else printf("0");
//        }
//        if(cur1 + 1 >= cnt - 1 || (d[0] == '0' && cnt == 2))
//        {
//            puts("");
//            continue;
//        }
//        printf(".");
//        for(int i = cur1 + 1; i < cnt - 1; i ++)
//            printf("%c", d[i]);
//        puts("");
//    }
//    return 0;
//}

// Launch of Collider
//#include<limits.h>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//const int maxn = 2e5 + 100;
//char str[maxn];
//int a[maxn];
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        scanf("%s", str);
//        for(int i = 0; i < n; i ++)
//            scanf("%d", &a[i]);
//        int min = INT_MAX;
//        //printf("%d\n", min);
//        for(int i = 1; i < n; i ++)
//            {
//                if(str[i] == 'L' && str[i - 1] == 'R' && a[i] - a[i - 1] < min)
//                   min = a[i] - a[i - 1];
//            }
//        if(min == INT_MAX) printf("-1\n");
//        else printf("%d\n", min / 2);
//    }
//    return 0;
//}

// One Bomb
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//const int maxn = 1005;
//char map[maxn][maxn];
//int col[maxn];
//int row[maxn];
//
//int main()
//{
//    int n, m;
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        int num = 0;
//        for(int i = 0; i < n; i ++)
//        {
//            scanf("%s", map[i]);
//            for(int j = 0; j < m; j ++)
//                if(map[i][j] == '*')num++;
//        }
//        memset(row, 0, sizeof(row));
//        memset(col, 0, sizeof(col));
//        for(int i = 0; i < n; i ++)
//        {
//            int cnt = 0;
//            for(int j = 0; j < m; j ++)
//                if(map[i][j] == '*')
//                    cnt ++;
//            row[i] = cnt;
//        }
//        for(int i = 0; i < m; i ++)
//        {
//            int cnt= 0;
//            for(int j = 0; j < n; j ++)
//                if(map[j][i] == '*')
//                    cnt++;
//            col[i] = cnt;
//        }
//        int x = 1001,y = 1001;
//        for(int i = 0; i < n; i ++)
//            for(int j = 0; j < m; j ++)
//            {
//                if(row[i] + col[j] - 1 == num && map[i][j] == '*')
//                {
//                    x = i;
//                    y = j;
//                    goto A;
//                }
//                if(row[i] + col[j] >= num && map[i][j] == '.')
//                {
//                    x = i;
//                    y = j;
//                    goto A;
//                }
//            }
//A:
//        if(x != 1001 && y != 1001)
//        {
//            puts("YES");
//            printf("%d %d\n", x + 1, y + 1);
//        }
//        else puts("NO");
//    }
//    return 0;
//}


// King of Thieves
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    char str[105];
//    while(scanf("%d", &n) != EOF)
//    {
//        scanf("%s", str);
//        bool flag = false;
//        for(int i = 0; i < n; i ++)
//        {
//            if(str[i] == '*')
//            {
//                int cur = i;
//                for(int j = 1; cur + j < n; j ++)
//                    for(int k = 1, cnt = 1; k <= 4; k ++)
//                    {
//                        if(str[cur + k * j] == '*')
//                        {
//                            cnt ++;
//                            if(cnt >= 5)
//                            {
//                                flag = true;
//                                goto A;
//                            }
//                        }
//                        else break;
//                    }
//            }
//        }
//A :
//        if(flag) puts("yes");
//        else puts("no");
//    }
//    return 0;
//}

// Cards
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    int arr[105];
//    bool vis[105];
//    while(scanf("%d", &n) != EOF)
//    {
//        int sum = 0;
//        memset(vis, false, sizeof(vis));
//        for(int i = 1; i <= n; i ++)
//        {
//            scanf("%d", &arr[i]);
//            sum += arr[i];
//        }
//        int temp = sum / (n / 2);
//        for(int i = 1; i <= n; i ++)
//        {
//            for(int j = 1; j <= n; j ++)
//                if(arr[i] + arr[j] == temp && !vis[i] && !vis[j] && i != j)
//                {
//                    vis[i] = true;
//                    vis[j] = true;
//                    printf("%d %d\n", i, j);
//                }
//
//        }
//    }
//    return 0;
//}

// Cells Not Under Attack
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//const int maxn = 1e5 + 1000;
//bool row[maxn], col[maxn];
//
//int main()
//{
//    long long n, m;
//    while(scanf("%I64d%I64d", &n, &m) != EOF)
//    {
//        for(int i = 1; i <= n; i ++)
//            row[i] = col[i] = false;
//        long long ans = n * n;
//        int xi, yi;
//        long long p = 0, q = 0;
//        long long cnt = 0;
//        for(int i = 1; i <= m; i ++)
//        {
//            scanf("%d%d", &xi, &yi);
//            if(!row[xi])
//            {
//                cnt += n;
//                p ++;
//                row[xi] = true;
//            }
//            if(!col[yi])
//            {
//                col[yi] = true;
//                q ++;
//            }
//            printf("%I64d ", ans - (n - p) * q - cnt);
//            printf("\n");
//        }
//    }
//    return 0;
//}

// They Are Everywhere
//#include<map>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<algorithm>
//
//using namespace std;
//const int maxn = 1e5 + 100;
//char str[maxn];
//int dp[maxn];
//map<char, bool>mp;
//map<char, int>record;
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        mp.clear();
//        scanf("%s", str);
//        for(int i = 0; i < n; i ++)
//            mp[str[i]] = true;
//        int kind = 0;
//        for(char ch = 'a'; ch <= 'z'; ch ++)
//            if(mp[ch]) kind++;
//        for(char ch = 'A'; ch <= 'Z'; ch ++)
//            if(mp[ch]) kind++;
//        if(kind == 1)
//        {
//            printf("1\n");
//            continue;
//        }
//        record.clear();
//        int MIN = maxn;
//        int cnt = 0;
//        for(int l = 0, r = 0; l < n; l ++)
//        {
//            for(; r < n && cnt < kind; r ++)
//            {
//                if(record[str[r]] == 0) cnt ++;
//                record[str[r]] ++;
//            }
//            if(cnt == kind) MIN = MIN > r - l ? r - l : MIN;
//            record[str[l]] --;
//            if(record[str[l]] == 0) cnt--;
//            // printf("%d\n", MIN);
//        }
//        printf("%d\n", MIN);
//    }
//    return 0;
//}

// Olesya and Rodion
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//int main()
//{
//    int n, t;
//    while(scanf("%d%d", &n, &t) != EOF)
//    {
//        if(n == 1 && t == 10) printf("-1\n");
//        else if(n >= 2 && t == 10)
//        {
//            printf("1");
//            for(int i = 1; i < n; i ++)
//                printf("0");
//            puts("");
//        }
//        else
//        {
//            for(int i = 0; i < n; i ++)
//                printf("%d", t);
//            puts("");
//        }
//    }
//    return 0;
//}

// Kolya and Tanya
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//const long long mod = 1e9 + 7;
//
//long long Mod(long long m, long long e)
//{
//    long long res = 1;
//    while(e)
//    {
//        if(e&1)
//        {
//            e = e - 1 ;
//            res = (res * m) % mod ;
//        }
//        else
//        {
//            e = e / 2 ;
//            m = (m * m) % mod ;
//        }
//    }
//    return res;
//}
//
//int main()
//{
//    long long n;
//    while(scanf("%I64d", &n) != EOF)
//    {
//        printf("%I64d\n", (Mod(27, n) % mod - Mod(7, n) % mod + mod) % mod);
//    }
//    return 0;
//}


// Mike and Cellphone
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    char str[12];
//    while(scanf("%d", &n) != EOF)
//    {
//        scanf("%s", str);
//        int up = 0, below = 0, left = 0, right = 0;
//        for(int i = 0; i < n; i ++)
//        {
//            if(str[i] >= '1' && str[i] <= '3')
//                up = 1;
//            if(str[i] == '7' || str[i] == '9' || str[i] == '0')
//                below = 1;
//            if(str[i] == '1' || str[i] == '4' || str[i] == '7' || str[i] == '0')
//                left = 1;
//            if(str[i] == '3' || str[i] == '6' || str[i] == '9' || str[i] == '0')
//                right = 1;
//        }
//        if(up && right && left && below)puts("YES");
//        else puts("NO");
//    }
//    return 0;
//}


// Mike and Shortcuts : BFS
//#include<queue>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//const int maxn = 2e5 + 100;
//int arr[maxn];
//int ans[maxn];
//
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        for(int i = 1; i <= n; i ++)
//        {
//            scanf("%d", &arr[i]);
//            ans[i] = -1;
//        }
//        ans[1] = 0;
//        queue<int >q;
//        q.push(1);
//        while(!q.empty())
//        {
//            int s = q.front();
//            q.pop();
//            for(int i = -1; i <= 1; i ++)
//            {
//                if(i == 0) continue;
//                int d = s + i;
//                if(d >= 1 && d <= n && ans[d] == -1)
//                {
//                    ans[d] = ans[s] + 1;
//                    q.push(d);
//                }
//            }
//            int d = arr[s];
//            if(ans[d] == -1)
//            {
//                ans[d] = ans[s] + 1;
//                q.push(d);
//            }
//        }
//        for(int i = 1; i <= n; i ++)
//            printf("%d%c", ans[i], i == n ? '\n' : ' ');
//
//    }
//    return 0;
//}

// Mike and Shortcuts : SPFA
//#include<queue>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//const int maxn = 2e5 + 100;
//
//struct edge
//{
//    int cost;
//    int v, next;
//}edge[maxn << 2];
//int n;
//struct node
//{
//    int id, dis;
//    friend bool operator<(node a, node b)
//    {
//        return a.dis > b.dis;
//    }
//};
//int head[maxn], dist[maxn];
//int cur;
//void AddEdge(int u, int v, int cost)
//{
//    edge[cur].v = v;
//    edge[cur].cost = cost;
//    edge[cur].next = head[u];
//    head[u] = cur ++;
//}
//void SPFA()
//{
//    node s;
//    s.id = 1;
//    s.dis = 0;
//    dist[1] = 0;
//    bool vis[maxn] = {0};
//    priority_queue<node>q;
//    q.push(s);
//    int num = 0;
//    while(!q.empty())
//    {
//        s = q.top();
//        q.pop();
//        if(vis[s.id]) continue;
//        num++;
//        if(num == n) break;
//        vis[s.id] = true;
//        for(int i = head[s.id]; ~i; i = edge[i].next)
//        {
//            int v = edge[i].v;
//            if(vis[v]) continue;
//            if(dist[v] == 0 || dist[s.id] + edge[i].cost < dist[v])
//            {
//                dist[v] = dist[s.id] + edge[i].cost;
//                node e;
//                e.id = v;
//                e.dis = dist[v];
//                q.push(e);
//            }
//        }
//    }
//}
//int main()
//{
//    while(scanf("%d", &n) != EOF)
//    {
//        cur = 0;
//        memset(head, -1, sizeof(head));
//        memset(dist, 0, sizeof(dist));
//        for(int u = 1; u <= n; u ++)
//        {
//            int v;
//            scanf("%d", &v);
//            if(u != v) AddEdge(u, v, 1);
//            if(u != n)
//            {
//                AddEdge(u, u + 1, 1);
//                AddEdge(u + 1, u, 1);
//            }
//        }
//        SPFA();
//        for(int i = 1; i <= n; i ++)
//        printf("%d%c", dist[i], i == n ? '\n' : ' ');
//    }
//
//    return 0;
//}

// 518 A Vitaly and Strings
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//int main()
//{
//    char s[105], t[105];
//    while(scanf("%s%s", s, t) != EOF)
//    {
//        int len = strlen(s);
//        char ans[105] = {'\0'};
//        int digit = 1;
//        for(int i = len - 1; i >= 0; i --)
//        {
//            char temp = s[i] + digit;
//            if(temp > 'z')
//            {
//                digit = 1;
//                ans[i] = 'a';
//            }
//            else
//            {
//                digit = 0;
//                ans[i] = temp;
//            }
//        }
//        if(strcmp(ans, t) < 0) puts(ans);
//        else puts("No such string");
//    }
//    return 0;
//}

// 518B Tanya and Postcard
//#include<map>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<algorithm>
//
//using namespace std;
//
//const int maxn = 2e5 + 100;
//
//char s[maxn], t[maxn];
//map<char, int>mp1,mp2;
//int main()
//{
//    while(scanf("%s%s", s, t) != EOF)
//    {
//        int len_s = strlen(s);
//        int len_t = strlen(t);
//        mp1.clear();mp2.clear();
//        for(int i = 0; i < len_t; i ++) mp1[t[i]]++;
//        for(int i = 0; i < len_s; i ++) mp2[s[i]]++;
//        int YAY = 0, WHOOPS = 0;
//        int MIN;
//        for(int i = 0; i < 26; i ++)
//        {
//            MIN = min(mp1[i + 'a'], mp2[i + 'a']);
//            YAY += MIN;
//            mp1[i + 'a'] -= MIN;
//            mp2[i + 'a'] -= MIN;
//        }
//        for(int i = 0; i < 26; i ++)
//        {
//            MIN = min(mp1[i + 'A'], mp2[i + 'A']);
//            YAY += MIN;
//            mp1[i + 'A'] -= MIN;
//            mp2[i + 'A'] -= MIN;
//        }
//        for(int i = 0; i < 26; i++)
//        {
//            if(mp1[i + 'a']) WHOOPS += min(mp1[i + 'a'], mp2[i + 'A']);
//            if(mp1[i + 'A']) WHOOPS += min(mp1[i + 'A'], mp2[i + 'a']);
//        }
//        printf("%d %d\n", YAY, WHOOPS);
//    }
//    return 0;
//}
//

// 510B Fox And Two Dots :DFS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//int n, m;
//char map[52][52];
//bool vis[52][52];
//int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//bool flag;
//void DFS(int x,int y, int prex, int prey)
//{
//    for(int i = 0; i < 4; i ++)
//    {
//        int xx = x + dir[i][0];
//        int yy = y + dir[i][1];
//        if(x >= 0 && x < n && y >= 0 && y < m && map[xx][yy] == map[x][y])
//        {
//            if(xx == prex && yy == prey) continue;
//            if(vis[xx][yy])
//            {
//                flag = true;
//                return;
//            }
//            vis[xx][yy] = true;
//            DFS(xx, yy, x, y);
//        }
//        if(flag) return;
//    }
//}
//
//int main()
//{
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        flag = false;
//        for(int i = 0; i < n; i ++) scanf("%s", map[i]);
//        memset(vis, false, sizeof(vis));
//        for(int i = 0; i < n; i ++)
//            for(int j = 0; j < m; j ++)
//            {
//                if(vis[i][j]) continue;
//                vis[i][j] = true;
//                DFS(i, j, -1, -1);
//                if(flag) goto A;
//            }
//        A: if(flag) puts("Yes");
//        else puts("No");
//    }
//    return 0;
//}

// 510B Fox And Two Dots :BFS
//#include<queue>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//const int maxn = 1e5 + 100;
//
//struct node
//{
//    int x, y;
//}pre[maxn];
//int n, m;
//char map[52][52];
//bool vis[52][52];
//int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//bool flag;
//
//void BFS(int x, int y)
//{
//    int front = 0, rear = 0;
//    queue<node>q;
//    node s, e;
//    s.x = x, s.y = y;
//    q.push(s);
//    memset(pre, -1, sizeof(pre));
//    while(!q.empty())
//    {
//        s = q.front();
//        q.pop();
//        front++;
//        vis[s.x][s.y] = true;
//        for(int i = 0; i < 4; i ++)
//        {
//            e.x = s.x + dir[i][0];
//            e.y = s.y + dir[i][1];
//            if(e.x >= 0 && e.x < n && e.y >= 0 && e.y < m && map[e.x][e.y] == map[s.x][s.y])
//            {
//                if(pre[front - 1].x == e.x && pre[front - 1].y == e.y) continue;
//                if(vis[e.x][e.y])
//                {
//                    flag = true;
//                    return;
//                }
//                rear ++;
//                q.push(e);
//                pre[rear].x = s.x;
//                pre[rear].y = s.y;
//            }
//        }
//    }
//}
//int main()
//{
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        flag = false;
//        for(int i = 0; i < n; i ++) scanf("%s", map[i]);
//        memset(vis, false, sizeof(vis));
//        for(int i = 0; i < n; i ++)
//            for(int j = 0; j < m; j ++)
//            {
//                if(vis[i][j]) continue;
//                vis[i][j] = true;
//                BFS(i, j);
//                if(flag) goto A;
//            }
//A:
//        if(flag) puts("Yes");
//        else puts("No");
//    }
//    return 0;
//}

// 513C Drazil and Factorial
/**
 *解题思路:找规律
    从2！~9！开始分解，分出尽可能多的位数
        2! 2!
        3! 3!
        4! 3!*(2*2!)
        5! 5!（因为有5就无法分解了）
        6! 5!*(3!)
        7! 7!
        8! 7!*(3*2!)
        9! 7!*(2*3! * 1*2!)
        这样分解出尽可能多的位数后就可以从大到小的输出最大的数了
 */
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//int main()
//{
//    char num[18];
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        int ans[8] = {0};
//        scanf("%s", num);
//        for(int i = 0; i < n; i ++)
//        {
//            int index = num[i] - '0';
//            if(index == 2 || index == 3 || index == 5 || index == 7)
//                ans[index]++;
//            else if(index == 4)
//                ans[2]+=2, ans[3]++;
//            else if(index == 6)
//                 ans[3]++, ans[5]++;
//            else if(index == 8)
//                ans[2] += 3, ans[7]++;
//            else if(index == 9)
//                ans[2]++, ans[3]+= 2, ans[7]++;
//        }
//        for(int digit = 7; digit >= 2; digit --)
//            for(int cnt = 1; cnt <= ans[digit]; cnt ++)
//            printf("%d", digit);
//        puts("");
//    }
//    return 0;
//}

// 702A Maximum Inrease
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//const int maxn = 1e5 + 100;
//
//int a[maxn];
//
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        for(int i = 0; i < n; i ++)
//            scanf("%d", &a[i]);
//        int maxlen = 1;
//        int cnt = 1;
//        for(int i = 0; i < n - 1; i ++)
//        {
//            if(a[i] < a[i + 1])
//                cnt ++;
//            else
//            {
//                if(maxlen < cnt)
//                    maxlen = cnt;
//                cnt = 1;
//            }
//        }
//        if(maxlen < cnt)
//            maxlen = cnt;
//        printf("%d\n", maxlen);
//    }
//    return 0;
//}

// 702B Powers of Two
//#include<map>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//using namespace std;
//const int maxn = 1e5 + 100;
//int a[maxn];
//map<int, int>mp;
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        mp.clear();
//        for(int i = 0; i < n; i ++)
//        {
//            scanf("%d", &a[i]);
//            mp[a[i]]++;
//        }
//        long long cnt = 0;
//        for(int i = 0; i < n - 1; i ++)
//        {
//            mp[a[i]] --;
//            long long num = 1;
//            for(int j = 1; j <= 31; j ++)
//            {
//                num *= 2;
//                int index = (int)(num - a[i]);
//                if(mp[index] >= 1) cnt+= mp[index];
//            }
//        }
//        printf("%I64d\n", cnt);
//
//    }
//    return 0;
//}

// 703A Mishka and Game
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//    std :: ios::sync_with_stdio(false);
//    int n;
//    while(cin >> n)
//    {
//        int Mishka = 0, Chris = 0;
//        int mi, ci;
//        while(n --)
//        {
//            cin >> mi >> ci;
//            if(mi > ci)
//                Mishka ++;
//            else if(mi < ci)
//                Chris ++;
//        }
//        if(Mishka > Chris) cout << "Mishka" << endl;
//        else if(Mishka == Chris) cout << "Friendship is magic!^^" << endl;
//        else cout << "Chris" << endl;
//    }
//    return 0;
//}

// 703B Mishka and trip
//#include<bits/stdc++.h>
//
//#define FIO ios :: sync_with_stdio(false)
//
//using namespace std;
//
//const int maxn = 1e5 + 100;
//
//typedef long long LL;
//LL c[maxn];
//
//int main()
//{
//    FIO;
//    int n, k;
//    while(cin >> n >> k)
//    {
//        LL sum = 0, ans = 0;
//        for(int i = 1; i <= n; i ++)
//        {
//            cin >> c[i];
//            sum += c[i];
//        }
//        LL capital;
//        for(int i = 1; i <= k; i ++)
//        {
//            cin >> capital;
//            sum -= c[capital];
//            ans += (sum * c[capital]);
//            c[capital] = 0;
//        }
//        c[n + 1] = c[1];
//        for(int i = 1; i <= n; i ++)
//            ans += (c[i] *c[i + 1]);
//        cout << ans << endl;
//    }
//    return 0;
//}

// 704 A Thor
// 数据
//5 6
//1 2
//1 3
//1 2
//2 2
//1 2
//3 4(3 1)/(3 3)
//#include<bits/stdc++.h>
//
//using namespace std;
//
//const int maxn = 3e5 + 100;
//int num[maxn];
//int tail[maxn];
//int connect[maxn];
//
//inline int read()
//{
//    int x = 0, f = 1;
//    char ch = getchar();
//    while(ch <'0' || ch > '9')
//    {
//        if(ch == '-') f = -1;
//        ch = getchar();
//    }
//    while(ch >= '0' && ch <= '9')
//    {
//        x = 10 * x + ch - '0';
//        ch = getchar();
//    }
//    return x * f;
//}
//int main()
//{
//    int n = read();
//    int q = read();
//    memset(num, 0, sizeof(num));
//    memset(tail, 0, sizeof(tail));
//    memset(connect, 0, sizeof(connect));
//    int l = 0, r = 0;
//    int cnt = 0;
//    for(int i = 1; i <= q; i ++)
//    {
//        int type = read();
//        int xi = read();
//        if(type == 1)
//        {
//            num[xi] ++;
//            tail[r++] = xi;
//            cnt ++;
//        }
//        else if(type == 2)
//        {
//            cnt -= num[xi];
//            connect[xi] += num[xi];
//            num[xi] = 0;
//        }
//        else if(type == 3)
//        {
//            for(; l < r && l < xi; l ++)
//                if(connect[tail[l]]) connect[tail[l]]--;
//                else
//                {
//                    cnt--;
//                    num[tail[l]] --;
//                }
//        }
//        printf("%d\n", cnt);
//    }
//    return 0;
//}

// 705 A Hulk
//#include<bits/stdc++.h>
//
//#define FIO ios :: sync_with_stdio(flase)
//
//using namespace std;
//
//int main()
//{
//    FIO;
//    int n;
//    while(cin >> n)
//    {
//        for(int i = 1; i <= n; i ++)
//        {
//            if(i & 1) cout << "I hate";
//            else cout << "I love";
//            if(i != n) cout << " that ";
//        }
//        puts(" it");
//    }
//    return 0;
//}

// 705 B Spider Man
//#include<bits/stdc++.h>
//
//#define FIO ios :: sync_with_stdio(false)
//
//using namespace std;
//
//int main()
//{
//    FIO;
//    int n;
//    while(cin >> n)
//    {
//        int sum = 0;
//        int temp;
//        int cnt = 0;
//        for(int i = 1; i <= n; i ++)
//        {
//            cin >> temp;
//            sum = (sum + temp) % 2;
//            if((sum - i) & 1) puts("1");
//            else puts("2");
//        }
//    }
//    return 0;
//}

// 519 B A and B and Compilation Errors
//#include<bits/stdc++.h>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        int a = 0, b = 0, c = 0;
//        int data;
//        for(int i = 1; i <= n; i ++)
//        {
//            scanf("%d", &data);
//            a += data;
//        }
//        for(int i = 1; i <= n - 1; i ++)
//        {
//            scanf("%d", &data);
//            b += data;
//        }
//        for(int i = 1; i <= n - 2; i ++)
//        {
//            scanf("%d", &data);
//            c += data;
//        }
//        printf("%d\n%d\n", a - b, b - c);
//    }
//    return 0;
//}

// 706A Beru-taxi
//#include<bits/stdc++.h>
//
//using namespace std;
//
//int main()
//{
//    double a, b;
//    cin >> a >> b;
//    int n;
//    scanf("%d", &n);
//    double mini = 1 << 29;
//    for(int i = 1; i <= n; i ++)
//    {
//        double x, y, v;
//        cin >> x >> y >> v;
//        double dist = sqrt((x - a) * (x - a) + (y - b) * (y - b));
//        double t = dist / v;
//        if(mini > t) mini = t;
//    }
//    printf("%.15f\n", mini);
//    return 0;
//}

// 706B Interesting drink
//#include<bits/stdc++.h>
//
//using namespace std;
//const int maxn = 1e5 + 100;
//int data[maxn];
//
//int main()
//{
//    int n;
//    while(scanf("%d", &n)!= EOF)
//    {
//        for(int i = 1; i <= n; i ++)
//            scanf("%d", &data[i]);
//        sort(data + 1, data + 1 + n);
//        int q;
//        scanf("%d", &q);
//        while(q--)
//        {
//            int mi;
//            scanf("%d", &mi);
//            if(data[1] > mi)
//            {
//                puts("0");
//                continue;
//            }
//            if(data[n] <= mi)
//            {
//                printf("%d\n", n);
//                continue;
//            }
//            int index = upper_bound(data + 1, data + 1 + n, mi) - data;
//            printf("%d\n", index - 1);
//        }
//    }
//    return 0;
//}

// 707A Brain's Photos
//#include<bits/stdc++.h>
//
//using namespace std;
//
//int main()
//{
//    int n, m;
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        char str[5];
//        bool flag = false;
//        for(int i = 0; i < n; i ++)
//        {
//            for(int j = 0; j < m; j ++)
//            {
//                scanf("%s", str);
//                if(str[0] == 'C' || str[0] == 'M' || str[0] == 'Y') flag = true;
//            }
//        }
//        if(flag) puts("#Color");
//        else puts("#Black&White");
//    }
//    return 0;
//}

// 707B Bakery
//#include<bits/stdc++.h>
//
//using namespace std;
//
//const int maxn = 1e5 + 10;
//const int inf = 0x3f3f3f3f;
//
//struct node
//{
//    int u, v;
//    int w;
//    bool operator<(const node &S)const
//    {
//        if(w == S.w) return u < S.u;
//        return w<S.w;
//    }
//}edge[maxn];
//bool vis[maxn];
//int main()
//{
//    int n, m, k;
//    while(scanf("%d%d%d", &n, &m, &k) != EOF)
//    {
//        memset(vis, false, sizeof(vis));
//        for(int i = 0; i < m; i++)
//            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
//        sort(edge, edge + m);
//        int temp;
//        for(int i = 0; i < k; i ++)
//        {
//            scanf("%d", &temp);
//            vis[temp] = true;
//        }
//        int ans = inf;
//        for(int i = 0; i < m; i ++)
//        {
//            if((vis[edge[i].u] && !vis[edge[i].v]) || (!vis[edge[i].u] && vis[edge[i].v]))
//            {
//                ans = edge[i].w;
//                break;
//            }
//        }
//        if(ans == inf) puts("-1");
//        else printf("%d\n", ans);
//    }
//    return 0;
//}

// 707C Pythagorean Triples
//#include<bits/stdc++.h>
//
//using namespace std;
//
//typedef long long LL;
//
//int main()
//{
//    LL n;
//    while(scanf("%I64d", &n) != EOF)
//    {
//        if(n < 3)
//            puts("-1");
//        else
//        {
//            LL m = n * n;
//            if(n & 1) printf("%I64d %I64d\n", (m - 1ll) / 2, m / 2 + 1ll);
//            else
//            {
//                m /= 4;
//                printf("%I64d %I64d\n", m - 1ll, m + 1ll);
//            }
//        }
//    }
//    return 0;
//}


/*
         _...---.._
       ,'          ~~"--..
      /                   ~"-._
     /                         ~-.
    /              .              `-.
    \             -.\                `-.
     \              ~-.                 `-.
  ,-~~\                ~.
 /     \                 `.
.       \                  `.
|        \                   .
|         \                   \
 .         `.                  \
             \                  \
  `           `.                 \
   `           \.                 \
    `           \`.                \
     .           \ -.               \
     `               -.              \
      .           `    -              \  .
      `            \    ~-             \
       `            .     ~.            \
        .            \      -_           \
        `                     -           \
         .            |        ~.          \
         `            |          \          \
          .           |           \          \
          `           |            `.         \
           `          `              \         \
            .          .              `.        `.
            `          :                \         `.
             \         `                 \          `.
              \         .                 `.         `~~-.
               \        :                   `         \   \
                .        .                   \         : `.\
                `        :                    \        |  | .
                 \        .                    \       |  |
                  \       :                     \      `  |  `
                   .                             .      | |_  .
                   `       `.                    `      ` | ~.;
                    \       `.                    .      . .
                     .       `.                   `      ` `
                     `.       `._.                 \      `.\
                      `        <  \                 `.     | .
                       `       `   :                 `     | |
                        `       \                     `    | |
                         `.     |   \                  :  .' |
"Are you crying? "        `     |    \                 `_-'  |
  "It's only the rain."  :    | |   |                   :    ;
"The rain already stopped."`    ; |~-.|                 :    '
  "Devils never cry."       :   \ |                     `   ,
                            `    \`                      :  '
                             :    \`                     `_/
                             `     .\       "For we have none. Our enemy shall fall."
                              `    ` \      "As we apprise. To claim our fate."
                               \    | :     "Now and forever. "
                                \  .'  :    "We'll be together."
                                 :    :    "In love and in hate"
                                 |    .'
                                 |    :     "They will see. We'll fight until eternity. "
                                 |    '     "Come with me.We'll stand and fight together."
                                 |   /      "Through our strength We'll make a better day. "
                                 `_.'       "Tomorrow we shall never surrender."
*//** @xigua */

// 710A King Moves
//#include<bits/stdc++.h>
//
//using namespace std;
//
//int main()
//{
//    char str[5];
//    while(scanf("%s", str) != EOF)
//    {
//        int x = str[0] - 'a' + 1;
//        int y = str[1] - '0';
//        int cnt = 0;
//        if(x - 1 >= 1 && y + 1 <= 8) cnt ++;
//        if(x - 1 >= 1) cnt ++;
//        if(x - 1 >= 1 && y - 1 >= 1) cnt++;
//        if(y + 1 <= 8) cnt ++;
//        if(y - 1 >= 1) cnt ++;
//        if(x + 1 <= 8 && y + 1 <= 8) cnt ++;
//        if(x + 1 <= 8) cnt ++;
//        if(x + 1 <= 8 && y - 1 >= 1) cnt++;
//        printf("%d\n", cnt);
//    }
//    return 0;
//}

// 710B Optimal Point on a Line
//#include<bits/stdc++.h>
//
//using namespace std;
//
//const int maxn = 3e5 + 100;
//
//int x[maxn];
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        for(int i = 1; i <= n; i ++) scanf("%d", &x[i]);
//        sort(x + 1, x + n + 1);
//        if(n & 1) printf("%d\n", x[n / 2 + 1]);
//        else printf("%d\n", x[n / 2]);
//    }
//    return 0;
//}

// 709A Juicer
//#include<bits/stdc++.h>
//
//using namespace std;
//
//const int maxn = 1e5 + 100;
//
//int a[maxn];
//
//int main()
//{
//    int n, b, d;
//    while(scanf("%d%d%d", &n, &b, &d) != EOF)
//    {
//        int sum = 0, cnt = 0;
//        for(int i = 1; i <= n; i ++)
//        {
//            scanf("%d", &a[i]);
//            if(a[i] <= b) sum += a[i];
//            if(sum > d)
//            {
//                sum = 0;
//                cnt++;
//            }
//        }
//        printf("%d\n", cnt);
//
//    }
//    return 0;
//}


// 709B Checkpoints
//#include<bits/stdc++.h>
//
//using namespace std;
//const int maxn = 1e5 + 100;
//
//typedef long long LL;
//
//LL x[maxn];
//
//int main()
//{
//    int n;
//    LL a;
//    while(scanf("%d%I64d", &n, &a) != EOF)
//    {
//        int start = 0;
//        for(int i = 1; i <= n; i ++) scanf("%I64d", &x[i]);
//        if(n == 1)
//        {
//            puts("0");
//            continue;
//        }
//        sort(x + 1, x + n + 1);
//        LL l = abs(x[n - 1] - a) + x[n - 1] - x[1];
//        LL r = abs(x[1] - a) + x[n - 1] - x[1];
//        LL b = l < r ? l : r;
//        l = abs(x[n] - a) + x[n] - x[2];
//        r = abs(x[2] - a) + x[n] - x[2];
//        LL c = l < r ? l : r;
//        LL ans = b < c ? b : c;
//        printf("%I64d\n", ans);
//    }
//    return 0;
//}

// 708A Letters Cyclic Shift
//#include<bits/stdc++.h>
//
//using namespace std;
//const int maxn = 1e5 + 100;
//char s[maxn];
//
//int main()
//{
//    while(scanf("%s", s) != EOF)
//    {
//        int len = strlen(s);
//        bool flag = false;
//        for(int i = 0; i < len; i ++)
//        {
//            if(!flag)
//            {
//                if(s[i] == 'a') continue;
//                else
//                {
//                    s[i] = s[i] - 1;
//                    flag = true;
//                }
//            }
//            else
//            {
//                if(s[i] == 'a')
//                    break;
//                else s[i] = s[i] - 1;
//            }
//        }
//        if(!flag)
//            s[len - 1] = 'z';
//        puts(s);
//    }
//    return 0;
//}

// 711A Bus to Udayland
//#include<bits/stdc++.h>
//
//using namespace std;
//
//const int maxn = 1000;
//
//char str[maxn][10];
//
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        bool flag = false;
//        for(int i = 0; i < n; i ++)
//        {
//            scanf("%s", str[i]);
//            for(int j = 1; j < 6; j ++)
//                if(str[i][j - 1] == 'O' && str[i][j] == 'O' && !flag )
//                {
//                    str[i][j - 1] = '+';
//                    str[i][j] = '+';
//                    flag = true;
//                }
//
//        }
//        if(flag)
//        {
//            puts("YES");
//            for(int i = 0; i < n; i ++)
//                puts(str[i]);
//        }
//        else puts("NO");
//    }
//    return 0;
//}

// 711B Chris and Magic Square
//#include<bits/stdc++.h>
//
//using namespace std;
//
//typedef long long LL;
//
//const int maxn = 510;
//const LL inf = 1e18;
//LL a[maxn][maxn];
//
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        int h, k;
//        for(int i = 0; i < n; i ++)
//            for(int j = 0; j < n; j ++)
//            {
//                scanf("%I64d", &a[i][j]);
//                if(a[i][j] == 0ll)
//                    h = i, k = j;
//            }
//        if(n == 1)
//        {
//            puts("1");
//            continue;
//        }
//        LL sum = 0ll;
//        for(int i = 0; i < n; i ++)
//        {
//            if(i == h) continue;
//            else
//            {
//                for(int j = 0; j < n; j ++)
//                    sum += a[i][j];
//                break;
//            }
//        }
//        LL temp = 0ll;
//        bool flag = true;
//        for(int i = 0; i < n; i ++)
//            temp += a[h][i];
//        LL ans = sum - temp;
//        if(ans <= 0) flag = false;
//        a[h][k] = ans;
//        for(int i = 0; i < n; i ++)
//        {
//            LL check = 0ll;
//            for(int j = 0; j < n; j ++)
//                check += a[i][j];
//            if(check != sum)
//            {
//                flag = false;
//                break;
//            }
//            check = 0ll;
//            for(int j = 0; j < n; j ++)
//                check += a[j][i];
//            if(check != sum)
//            {
//                flag = false;
//                break;
//            }
//        }
//        LL one = 0ll, two = 0ll;
//        for(int i = 0; i < n; i ++)
//            for(int j = 0; j < n; j ++)
//            {
//                if(i == j) one += a[i][j];
//                if(i + j == n - 1) two += a[i][j];
//            }
//        if(one != sum) flag = false;
//        if(two != sum) flag = false;
//        if(flag) printf("%I64d\n", ans);
//        else puts("-1");
//
//    }
//    return 0;
//}

// 234A Lefthanders and Righthanders
//#include<bits/stdc++.h>
//
//#define ONLINE_JUDGE
//using namespace std;
//
//int main()
//{
//#ifdef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif // ONLINE_JUDGE
//    char str[105];
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        scanf("%s", str + 1);
//        for(int i = 1; i <= n / 2; i ++)
//        {
//            if(str[i] == 'L' ) printf("%d %d\n", i, i + n / 2);
//            else
//            {
//                if(str[i + n / 2] == 'L')
//                    printf("%d %d\n", i + n / 2, i);
//                else
//                    printf("%d %d\n", i, i + n / 2);
//            }
//        }
//
//    }
//    return 0;
//}

// 712A Memory and Crow
//#include<bits/stdc++.h>
//
//using namespace std;
//
//const int maxn = 1e5 + 100;
//const int inf = 0x3f3f3f3f;
//int a[maxn];
//
//
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        for(int i = 1; i <= n; i ++)
//            scanf("%d", &a[i]);
//        a[n + 1] = 0;
//        for(int i = 1; i <= n; i ++)
//            printf("%d%c", a[i] + a[i + 1], i == n ? '\n' : ' ');
//    }
//    return 0;
//}


// 712B Memory ans Trident
//#include<bits/stdc++.h>
//
//using namespace std;
//const int maxn = 1e6 + 100;
//const int inf = ~0u >> 1;
//char str[maxn];
//
//int main()
//{
//    while(scanf("%s", str) != EOF)
//    {
//        int len = strlen(str);
//        if(len & 1)
//        {
//            puts("-1");
//            continue;
//        }
//        int l = 0, r = 0, u = 0, d = 0;
//        for(int i = 0; i < len; i ++)
//        {
//            if(str[i] == 'L') l ++;
//            else if(str[i] == 'R') r ++;
//            else if(str[i] == 'U') u ++;
//            else if(str[i] == 'D') d ++;
//        }
//        int ans = (abs(l - r) + abs(u - d)) / 2;
//        printf("%d\n", ans);
//    }
//    return 0;
//}

// 717C Potions Homework
//#include<bits/stdc++.h>
//
//using namespace std;
//const int maxn = 1e5 + 100;
//const int inf = ~0u >> 1;
//const long long mod = 1e4 + 7;
//long long a[maxn];
//
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        for(int i = 0; i < n; i ++)
//            scanf("%lld", &a[i]);
//        sort(a, a + n);
//        long long ans = 0ll;
//        for(int i = 0; i < n; i ++)
//        {
//            long long x = (long long)a[i] * a[n - i - 1];
//            ans += x;
//            ans %= mod;
//        }
//        printf("%I64d\n", ans);
//    }
//    return 0;
//}



// 714A Meeting of Old Friends
//#include<bits/stdc++.h>
//
//using namespace std;
//
//typedef long long LL;
//
//
//int main()
//{
//    LL l1, r1, l2, r2, k;
//    while(scanf("%I64d%I64d%I64d%I64d%I64d", &l1, &r1, &l2, &r2, &k) != EOF)
//    {
//        LL l = max(l1, l2);
//        LL r = min(r1, r2);
//
//        LL ans = r - l + 1;
//        if(ans < 0)
//        {
//            puts("0");
//            continue;
//        }
//        if(k <= r && k >= l) ans --;
//        printf("%I64d\n", ans);
//    }
//    return 0;
//}


// 714B Filya and Homework
//#include<bits/stdc++.h>
//
//using namespace std;
//
//const int maxn = 1e5 + 100;
//typedef long long LL;
//LL a[maxn];
//
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        for(int i = 1; i <= n; i ++)
//            scanf("%I64d", &a[i]);
//        sort(a + 1, a + 1 + n);
//        int m = unique(a + 1, a + 1 + n) - a - 1;
//        if(m <= 2 || (m == 3 && a[1] + a[3] == 2 * a[2])) puts("YES");
//        else puts("NO");
//    }
//    return 0;
//}


// 716A Crazy Computer
//#include<bits/stdc++.h>
//
//using namespace std;
//const int maxn = 1e5 + 100;
//int t[maxn];
//
//int main()
//{
//    int n, c;
//    while(scanf("%d%d", &n, &c) != EOF)
//    {
//        for(int i = 1; i <= n; i ++)
//            scanf("%d", &t[i]);
//        int cnt = 1;
//        for(int i = n; i >= 2; i --)
//        {
//            if(t[i] - t[i - 1] <= c)
//                cnt ++;
//            else break;
//        }
//        printf("%d\n", cnt);
//    }
//    return 0;
//}

// 716B Complete the Word
//#include<bits/stdc++.h>
//
//using namespace std;
//const int maxn = 5e4 + 100;
//char s[maxn];
//
//int main()
//{
//    while(scanf("%s", s + 1) != EOF)
//    {
//        int len = strlen(s + 1);
//        bool vis[30];
//        bool flag = false;
//        for(int i = 1; i <= len - 25; i ++)
//        {
//            memset(vis, false, sizeof(vis));
//            int cnt = 0;
//            for(int j = i; j <= i + 25; j ++)
//            {
//                if(s[j] >= 'A' && s[j] <= 'Z')
//                    vis[s[j] - 'A' + 1] = true;
//                if(s[j] == '?') cnt++;
//            }
//            int cur = 0;
//            for(int j = 1; j <= 26; j ++)
//                if(vis[j]) cur ++;
//            if(cur + cnt == 26)
//            {
//                flag = true;
//                for(int j = i; j <= i + 25; j ++)
//                    if(s[j] == '?')
//                    {
//                        for(int k = 1; k <= 26; k ++)
//                            if(!vis[k])
//                            {
//                                s[j] = k - 1 + 'A';
//                                vis[k] = true;
//                                break;
//                            }
//                    }
//
//                break;
//            }
//
//
//        }
//        if(flag)
//        {
//            for(int i = 1; i <= len; i ++)
//                if(s[i] != '?') printf("%c", s[i]);
//                else printf("A");
//            puts("");
//        }
//        else puts("-1");
//    }
//    return 0;
//}

// 659A Round House
//#include<bits/stdc++.h>
//
//using namespace std;
//
//int main()
//{
//    int n, a, b;
//    while(scanf("%d%d%d", &n, &a, &b) != EOF)
//    {
//        while(b < 0)
//        {
//            b += n;
//            b %= n;
//        }
//        int ans = (a + b) % n;
//        if(ans == 0) ans = n;
//        printf("%d\n", ans);
//    }
//    return 0;
//}

// 659B Qualifying Contest
//#include<bits/stdc++.h>
//
//using namespace std;
//
//const int maxn = 1e5 + 100;
//
//struct node
//{
//    string name;
//    int tid;
//    int score;
//} stu[maxn];
//bool cmp1(node a, node b)
//{
//    if(a.tid == b.tid)
//        return a.score > b.score;
//    return a.tid < b.tid;
//}
//bool cmp2(node a, node b)
//{
//    return a.score > b.score;
//}
//int main()
//{
//    int n, m;
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        for(int i = 0; i < n; i ++)
//        {
//            cin >> stu[i].name;
//            scanf("%d%d", &stu[i].tid, &stu[i].score);
//        }
//        stu[n].tid = 0;
//        sort(stu, stu + n, cmp1);
//        int cnt = 0;
//        int cur, pre = 0;
//        for(int i = 0; i < n; i ++)
//        {
//            if(stu[i].tid == stu[i + 1].tid)
//                continue;
//            cnt ++;
//            cur = i;
//            int ans = 0;
//            sort(stu + pre, stu + cur + 1, cmp2);
//            int cur1 = 1, cursor1 = pre;
//            for(int j = pre; j < cur; j ++)
//            {
//                if(stu[j].score == stu[j + 1].score)
//                    cur1 ++;
//                else break;
//            }
//            int temp = pre;
//            pre = cur + 1;
//            if(cur1 >= 3)
//            {
//                puts("?");
//                if(cnt == m) break;
//                continue;
//            }
//            int cur2 = 1, cursor2 = temp + 1;
//            for(int j = cursor2; j < cur; j ++)
//            {
//                if(stu[j].score == stu[j + 1].score)
//                    cur2 ++;
//                else break;
//
//            }
//            if(cur2 >= 2)
//            {
//                puts("?");
//                if(cnt == m) break;
//                continue;
//            }
//            cout << stu[cursor1].name << " " <<stu[cursor2].name << endl;
//            if(cnt == m) break;
//        }
//    }
//    return 0;
//}

// 718C Sasha and Array
//#include<bits/stdc++.h>
//
//using namespace std;
//const int maxn = 1e5 + 100;
//typedef long long LL;
//
//const LL mod=1e9+7;
//LL a[maxn];
//
//struct Matrix
//{
//    LL matrix[2][2];
//    Matrix()
//    {
//        matrix[0][0]=matrix[0][1]=matrix[1][0]=1;
//        matrix[1][1]=0;
//    }
//    void init()
//    {
//        for(int i=0; i<2; i++)
//            for(int j=0; j<2; j++)
//                matrix[i][j]=(i==j);
//    }
//};
//Matrix operator *(Matrix a,Matrix b)
//{
//    Matrix ans;
//    for(int i=0; i<2; i++)
//    {
//        for(int j=0; j<2; j++)
//        {
//            ans.matrix[i][j]=0;
//            for(int k=0; k<2; k++)
//            {
//                ans.matrix[i][j]=(ans.matrix[i][j]+a.matrix[i][k]*b.matrix[k][j]%mod)%mod;
//            }
//        }
//    }
//    return ans;
//}
//Matrix operator ^(Matrix a,LL b)
//{
//    Matrix ans;
//    ans.init();
//    while(b)
//    {
//        if(b&1)
//            ans=ans*a;
//        a=a*a;
//        b>>=1;
//    }
//    return ans;
//}
//Matrix operator +(Matrix a,Matrix b)
//{
//    Matrix ans;
//    for(int i=0; i<2; i++)
//        for(int j=0; j<2; j++)
//            ans.matrix[i][j]=0;
//    for(int i=0; i<2; i++)
//        for(int j=0; j<2; j++)
//            ans.matrix[i][j]=(a.matrix[i][j]+b.matrix[i][j])%mod;
//    return ans;
//}
//struct node
//{
//    int l,r;
//    Matrix lz;
//    Matrix data;
//} sto[maxn<<2];
//bool f(Matrix a)
//{
//    Matrix ans;
//    for(int i=0; i<2; i++)
//    {
//        for(int j=0; j<=2; j++)
//        {
//            if(ans.matrix[i][j]!=a.matrix[i][j])
//                return true;
//        }
//    }
//    return false;
//}
//void pushdown(int rt)
//{
//    if(f(sto[rt].lz))
//    {
//        sto[rt<<1].lz=sto[rt<<1].lz*sto[rt].lz;
//        sto[rt<<1|1].lz=sto[rt<<1|1].lz*sto[rt].lz;
//        sto[rt<<1].data=sto[rt<<1].data*sto[rt].lz;
//        sto[rt<<1|1].data=sto[rt<<1|1].data*sto[rt].lz;
//        sto[rt].lz.init();
//    }
//}
//void build(int l,int r,int rt)
//{
//    sto[rt].l=l;
//    sto[rt].r=r;
//    sto[rt].lz.init();
//    if(l==r)
//    {
//        scanf("%lld",a+l);
//        sto[rt].data=sto[rt].data^(a[l]-1);
//        return;
//    }
//    int mid=(l+r)>>1;
//    build(l,mid,rt<<1);
//    build(mid+1,r,rt<<1|1);
//    sto[rt].data=sto[rt<<1].data+sto[rt<<1|1].data;
//}
//void update(int rt,int l,int r,Matrix tmp)
//{
//    if(sto[rt].l==l&&sto[rt].r==r)
//    {
//        sto[rt].lz=sto[rt].lz*tmp;
//        sto[rt].data=sto[rt].data*tmp;
//        return;
//    }
//    pushdown(rt);
//    int mid=(sto[rt].l+sto[rt].r)>>1;
//    if(r <= mid)update(rt << 1, l, r, tmp);
//    else if(l > mid) update(rt << 1|1, l, r, tmp);
//    else
//    {
//        update(rt << 1, l, mid, tmp);
//        update(rt << 1 | 1, mid + 1, r, tmp);
//    }
//    sto[rt].data=sto[rt<<1].data+sto[rt<<1|1].data;
//}
//LL query(int rt,int l,int r)
//{
//    if(sto[rt].l==l&&sto[rt].r==r) return sto[rt].data.matrix[0][0];
//    pushdown(rt);
//    int mid=(sto[rt].l+sto[rt].r)>>1;
//    if(r <= mid) return query(rt << 1, l, r);
//    else if(l > mid) return query((rt << 1)|1, l, r);
//    else return (query(rt << 1, l, mid) + query(rt << 1|1, mid + 1, r)) % mod;
//}
//int main()
//{
//    int n,m;
//    scanf("%d%d",&n,&m);
//    build(1,n,1);
//    while(m--)
//    {
//        int num,L,R;
//        scanf("%d%d%d",&num,&L,&R);
//        if(num==1)
//        {
//            LL c;
//            scanf("%lld",&c);
//            Matrix tmp;
//            update(1,L,R,tmp^c);
//        }
//        else printf("%lld\n",query(1,L,R));
//    }
//    return 0;
//}

// 719A Vitya in the Countryside
//#include<bits/stdc++.h>
//
//using namespace std;
//
//const int maxn = 95;
//int stdard[35] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//int a[maxn];
//
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        for(int i = 0; i < n; i ++)
//            scanf("%d", &a[i]);
//        if(n == 1)
//        {
//            if(a[0] == 0) puts("UP");
//            if(a[0] == 15) puts("DOWN");
//            else puts("-1");
//            continue;
//        }
//        if(a[n - 1] > a[n - 2])
//        {
//            if(a[n - 1] == 15) puts("DOWN");
//            else if(a[n - 1] < 15) puts("UP");
//        }
//        else if(a[n - 1] < a[n - 2])
//        {
//            if(a[n - 1] == 0) puts("UP");
//            else if(a[n - 1] < 15) puts("DOWN");
//        }
//
//    }
//    return 0;
//}

// 719B Anatoly and Cockroaches
//#include<bits/stdc++.h>
//
//using namespace std;
//const int maxn = 1e5 + 100;
//char str[maxn];
//
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        scanf("%s", str);
//        int b = 0, r = 0;
//        int ans1, ans2, ans;
//        if(str[0] == 'b')
//        {
//            for(int i = 2; i < n; i += 2)
//                if(str[i] != 'b') b ++;
//            for(int i = 1; i < n; i += 2)
//                if(str[i] != 'r') r ++;
//            ans1 = max(b, r);
//            b = 0, r = 0;
//            r++;
//            for(int i = 2; i < n; i += 2)
//                if(str[i] != 'r') r ++;
//            for(int i = 1; i < n; i += 2)
//                if(str[i] != 'b') b ++;
//            ans2 = max(b, r);
//            ans = min(ans1, ans2);
//            printf("%d\n", ans);
//        }
//        else
//        {
//            for(int i = 2; i < n; i += 2)
//                if(str[i] != 'r') b ++;
//            for(int i = 1; i < n; i += 2)
//                if(str[i] != 'b') r ++;
//            ans1 = max(b, r);
//            r = 0, b = 0;
//            b++;
//            for(int i = 2; i < n; i += 2)
//                if(str[i] != 'b') b ++;
//            for(int i = 1; i < n; i += 2)
//                if(str[i] != 'r') r ++;
//            ans2 = max(b, r);
//            ans = min(ans1, ans2);
//            printf("%d\n", ans);
//        }
//
//    }
//    return 0;
//}

// 748B Santa Claus and Keyboard Check
#include<map>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

map<int, int>mp;

struct node
{
    char first;
    char second;
} q[1010];

int main()
{
    char s[1010], t[1010];
    while(scanf("%s%s", s, t) != EOF)
    {
        int len = strlen(s);
        int cur = 0;
        mp.clear();
        bool flag = true;
        for(int i = 0; i < len; i ++)
        {
            if(s[i] != t[i])
            {
                if(mp[s[i] - 'a'] == t[i] - 'a' + 1 && mp[t[i] - 'a'] == s[i] - 'a' + 1)
                    continue;
                if(mp[s[i] - 'a'] == 0 && mp[t[i] - 'a'] == 0)
                {
                    q[cur].first = s[i];
                    q[cur++].second = t[i];
                    mp[s[i] - 'a'] = t[i] - 'a' + 1;
                    mp[t[i] - 'a'] = s[i] - 'a' + 1;
                    continue;
                }
                flag = false;
            }
            else
            {
                if(mp[s[i] - 'a'] == 0 || mp[s[i] - 'a'] == t[i] - 'a' + 1)
                {
                    mp[s[i] - 'a'] = t[i] - 'a' + 1;
                    continue;
                }
                else flag = false;
            }
        }
        if(!flag) puts("-1");
        else
        {
            printf("%d\n", cur);
            for(int i = 0; i < cur; i ++)
                printf("%c %c\n", q[i].first, q[i].second);
        }
    }
    return 0;
}

