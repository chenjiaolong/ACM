// 胜利大逃亡：三维BFS
//#include<queue>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//int A, B, C, T;
//int map[55][55][55];
//int dir[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0 , 1}, {0, 0, -1}};
//struct node
//{
//    int x, y, z;
//    int step;
//};
//node s, e, h, t;
//int BFS()
//{
//    s.x = 0, s.y = 0, s.z = 0, s.step = 0;
//    e.x = A - 1, e.y = B - 1, e.z = C - 1;
//    queue<node>q;
//    q.push(s);
//    map[0][0][0] = 1;
//    while(!q.empty())
//    {
//        h = q.front();
//        q.pop();
//        if(h.x == e.x && h.y == e.y && h.z == e.z && h.step <= T) return h.step;
//        for(int i = 0; i < 6; i ++)
//        {
//            t.x = h.x + dir[i][0];
//            t.y = h.y + dir[i][1];
//            t.z = h.z + dir[i][2];
//            t.step = h.step + 1;
//            if(t.x >= 0 && t.x < A && t.y >= 0 && t.y < B && t.z >= 0 && t.z < C && !map[t.x][t.y][t.z])
//            {
//                map[t.x][t.y][t.z] = 1;
//                // 由于行走只能朝6个固定方向，这里是对剩下时间里能否走到出口进行预判，如果走最短路径依然不能再规定时间内到达出口，明显是不行的,当然不加这个判断也能AC，只是比较消耗时间
//                if(abs(t.x - (A - 1)) + abs(t.y - (B - 1)) + abs(t.z - (C - 1)) > T)
//                    continue;
//                q.push(t);
//            }
//        }
//    }
//    return -1;
//}
//int main()
//{
//    int K;
//    scanf("%d", &K);
//    while(K--)
//    {
//        scanf("%d%d%d%d", &A, &B, &C, &T);
//        for(int i = 0; i < A; i ++)
//            for(int j = 0; j < B; j ++)
//            for(int k = 0; k < C; k ++)
//            scanf("%d", &map[i][j][k]);
//        if(map[A - 1][B - 1][C - 1] == 1)
//        {
//            printf("-1\n");
//            continue;
//        }
//        int res = BFS();
//        printf("%d\n", res);
//    }
//    return 0;
//}

// 胜利大逃亡(续)：状态压缩（位运算） + BFS
//#include<queue>
//#include<iostream>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//int n, m, t;
//char map[25][25];
//int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
//bool vis[25][25][1 << 10];
//struct node
//{
//    int x, y;
//    int time;
//    int nKey;
//};
//node s, e;
//int BFS()
//{
//    node h, tmp;
//    s.time = 0;
//    s.nKey = 0;
//    memset(vis, false, sizeof(vis));
//    queue<node> q;
//    while(!q.empty()) q.pop();
//    q.push(s);
//    vis[s.x][s.y][s.nKey] = true;
//    while(!q.empty())
//    {
//        h = q.front();
//        q.pop();
//        if(h.x == e.x && h.y == e.y && h.time < t) return h.time;
//        for(int i = 0; i < 4; i ++)
//        {
//            tmp.x = h.x + dir[i][0];
//            tmp.y = h.y + dir[i][1];
//            tmp.nKey = h.nKey;
//            if(tmp.x >= 0 && tmp.x < n && tmp.y >= 0 && tmp.y < m && map[tmp.x][tmp.y] != '*')
//            {
//                tmp.time = h.time + 1;
//                if(tmp.time > t) continue;
//                if(map[tmp.x][tmp.y] >= 'a' && map[tmp.x][tmp.y] <= 'z')
//                {
//                    int key = (1 << (map[tmp.x][tmp.y] - 'a')); // 左移一位， 因为0000的意思应该是0001；
//                    tmp.nKey |= key; // 拾取钥匙
//                    if(!vis[tmp.x][tmp.y][tmp.nKey])
//                    {
//                        vis[tmp.x][tmp.y][tmp.nKey] = true;
//                        q.push(tmp);
//                    }
//                }
//                else if(map[tmp.x][tmp.y] >= 'A' && map[tmp.x][tmp.y] <= 'Z')
//                {
//                    int key = map[tmp.x][tmp.y] - 'A';
//                    if((tmp.nKey >> key) & 1 && !vis[tmp.x][tmp.y][tmp.nKey])//右移key位后与1，判断是不是存在打开当前门的钥匙
//                    {
//                        vis[tmp.x][tmp.y][tmp.nKey] = true;
//                        q.push(tmp);
//                    }
//                }
//                else if(!vis[tmp.x][tmp.y][tmp.nKey]) // 表示走过的点不能再重新走，除非拿或者用过了钥匙
//                {
//                    vis[tmp.x][tmp.y][tmp.nKey] = true;
//                    q.push(tmp);
//                }
//
//            }
//        }
//    }
//    return -1;
//}
//int main()
//{
//    while(scanf("%d%d%d", &n, &m, &t) != EOF)
//    {
//        for(int i = 0; i < n; i ++)
//        {
//            scanf("%s", map[i]);
//            for(int j = 0; j < m; j ++)
//            {
//                if(map[i][j] == '@')
//                {
//                    s.x = i;
//                    s.y = j;
//                }
//                if(map[i][j] == '^')
//                {
//                    e.x = i;
//                    e.y = j;
//                }
//            }
//        }
//        int res = BFS();
//        printf("%d\n", res);
//    }
//    return 0;
//}

// Key Task:状态压缩（位运算） + BFS
//#include<map>
//#include<queue>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//int R, C;
//char maze[105][105];
//bool vis[105][105][1 << 4];
//map<char, int>key;
//struct node
//{
//    int x,y;
//    int step;
//    int key;
//};
//node s;
//int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//void BFS()
//{
//    memset(vis, false, sizeof(vis));
//    queue<node>q;
//    q.push((node){s.x, s.y, 0, 0});
//    vis[s.x][s.y][0] = true;
//    while(!q.empty())
//    {
//        s = q.front();
//        q.pop();
//        if(maze[s.x][s.y] == 'X')
//        {
//            printf("Escape possible in %d steps.\n", s.step);
//            return;
//        }
//        for(int i = 0; i < 4; i ++)
//        {
//            node e;
//            e.x = s.x + dir[i][0];
//            e.y = s.y + dir[i][1];
//            e.key = s.key;
//            if(maze[e.x][e.y] == '#') continue;
//            if(e.x >= 0 && e.x < R && e.y >= 0 && e.y < C)
//            {
//                e.step = s.step + 1;
//                //printf("SSSSSSS  %d %d %d\n", e.x, e.y, s.key);
//                if(maze[e.x][e.y] >= 'a' && maze[e.x][e.y] <= 'z')
//                {
//                    int Key = key[maze[e.x][e.y]];
//                    e.key |= (1 << Key);
//                    if(!vis[e.x][e.y][e.key])
//                    {
//                        vis[e.x][e.y][e.key] = true;
//                        q.push((node){e.x, e.y, e.step, e.key});
//                    }
//                }
//                else if(maze[e.x][e.y] >= 'A' && maze[e.x][e.y] <= 'Z' && maze[e.x][e.y] != 'X')
//                {
//                    int Key = key[maze[e.x][e.y]];
//                    if(((e.key >> Key) & 1)  && !vis[e.x][e.y][e.key])//if((1 << Key) & s.key)
//                    {
//                        vis[e.x][e.y][s.key] = true;
//                        q.push((node){e.x, e.y, e.step, s.key});
//                    }
//
//                }
//                else if(!vis[e.x][e.y][e.key])
//                {
//                    vis[e.x][e.y][e.key] = true;
//                    q.push((node){e.x, e.y, e.step, e.key});
//                }
//
//            }
//        }
//    }
//    puts("The poor student is trapped!");
//}
//int main()
//{
//    key['B'] = 0;
//    key['Y'] = 1;
//    key['R'] = 2;
//    key['G'] = 3;
//    key['b'] = 0;
//    key['y'] = 1;
//    key['r'] = 2;
//    key['g'] = 3;
//
//    while(scanf("%d%d", &R, &C), R&&C)
//    {
//        for(int i = 0; i < R; i ++)
//        {
//            scanf("%s", maze[i]);
//            for(int j = 0; j < C; j ++)
//            {
//                if(maze[i][j] == '*')
//                {
//                    s.x = i;
//                    s.y = j;
//                }
//            }
//        }
//        BFS();
//    }
//    return 0;
//}

// 超级密码: 余数判重 + BFS
//#include<queue>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//int N, C, M;
//bool num[20];
//struct node
//{
//    char ans[505];//将每一位的字符压入此数组
//    int len;
//};
//int judge(node s)
//{
//    int mod = 0;
//    for(int i = 0; i < s.len; i ++)
//    {
//        if(s.ans[i] >= 'A') mod = (C * mod + s.ans[i] - 'A' + 10) % N;// 由于是N进制，mod在前面的基础上乘以进制数C在加上下一位，如果能整除N，那必定是N的倍数，则成立
//        else mod = (C * mod + s.ans[i] - '0') % N;
//    }
//    return mod;
//}
//void BFS()
//{
//    bool vis[5005] = {0};
//    queue<node> q;
//    node s;
//    for(int i = 1; i < 16; i ++)//由于第一位不能为0，所以从1开始
//    {
//        if(num[i])
//        {
//            if(i >= 10) s.ans[0] = i - 10 + 'A';
//            else s.ans[0] = i + '0';
//            s.len = 1;
//            int r = judge(s);
//            if(!r)// 余数不能与之前出现过的余数相同，因为前面出现过的序列，肯定包含同样余数却在后面出现的序列
//            {
//                s.ans[1] = '\0';
//                puts(s.ans);
//                return;
//            }
//            else if(!vis[r])
//            {
//                vis[r] = true;
//                q.push(s);
//            }
//        }
//    }
//    while(!q.empty())
//    {
//        s = q.front();
//        q.pop();
//        for(int i = 0; i < 16; i ++)//由于第一位不能为0，所以从1开始
//        {
//            if(num[i])
//            {
//                if(i >= 10) s.ans[s.len++] = i - 10 + 'A';
//                else s.ans[s.len++] = i + '0';
//                int r = judge(s);
//                if(!r)
//                {
//                    s.ans[s.len ++] = '\0';
//                    puts(s.ans);
//                    return;
//                }
//                else if(!vis[r] && s.len < 499)
//                {
//                    vis[r] = true;
//                    q.push(s);
//                }
//                s.len --;// 是不是觉得这里与s.len++这句话会无限重复，导致s.len一直为1？错了！要注意，在r与之前出现过的余数相同是，这次的s是没有压入队列的，也就是这次的s.len减少了，但是在队列中的s.len却没有减少！
//            }
//        }
//    }
//    puts("give me the bomb please");
//}
//int main()
//{
//    int T;
//    char str[2];
//    scanf("%d", &T);
//    while(T--)
//    {
//        scanf("%d%d", &N, &C);
//        scanf("%d", &M);
//        memset(num, false, sizeof(num));
//        for(int i = 0; i < M; i ++)
//        {
//            scanf("%s", str);
//            if(str[0] >= '0' && str[0] <= '9') num[str[0] - '0'] = true;
//            else num[str[0] - 'A' + 10] = true;
//        }
//        if(N == 0)
//        {
//            if(num[0]) puts("0");
//            else puts("give me the bomb please");
//            continue;
//        }
//        BFS();
//    }
//    return 0;
//}

// A计划：双层BFS
//#include<queue>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//int N, M, T;
//char map[3][12][12];
//int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//struct node
//{
//    int x, y;
//    int floor;
//    int time;
//};
//void BFS()
//{
//    node s;
//    queue<node> q;
//    q.push((node){0, 0, 0, 0});
//    map[0][0][0] = '*';
//    while(!q.empty())
//    {
//        s = q.front();
//        q.pop();
//        if(map[s.floor][s.x][s.y] == 'P')
//        {
//            if(s.time <= T) puts("YES");
//            else puts("NO");
//            return;
//        }
//        for(int i = 0; i < 4; i++)
//        {
//            node e;
//            e.x = s.x + dir[i][0];
//            e.y = s.y + dir[i][1];
//            e.floor = s.floor;
//            if(e.x >=0 && e.x < N && e.y >= 0 && e.y < M && map[e.floor][e.x][e.y] != '*')
//            {
//                if(map[e.floor][e.x][e.y] == '#')
//                {
//                    e.floor = (s.floor + 1) % 2;
//                    if(map[e.floor][e.x][e.y] == '#' || map[e.floor][e.x][e.y] == '*') continue;
//                }
//                q.push((node){e.x, e.y, e.floor, s.time + 1});
//                if(map[e.floor][e.x][e.y] != 'P')
//                map[e.floor][e.x][e.y] = '*';
//            }
//        }
//    }
//    puts("NO");
//}
//int main()
//{
//    int C;
//    scanf("%d", &C);
//    while(C--)
//    {
//        scanf("%d%d%d", &N, &M, &T);
//        for(int i = 0; i < N; i ++)
//            scanf("%s", map[0][i]);
//        for(int i = 0; i < N; i ++)
//            scanf("%s", map[1][i]);
//        BFS();
//    }
//    return 0;
//}

// Different Digits：BFS + 余数判重 + 数论（鸽笼原理）
//#include<string>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<iostream>
//
//using namespace std;
//
//const int maxn = (1 << 16) + 5;
//int n, MinLen, a[5];
//string ans, curans;
//struct node
//{
//    char ch;
//    int mod, len,  pre;// 余数， 当前长度，前驱指针
//} u, v, q[maxn];
//void GetStr(int k)// 用递归来得到字符串信息，注意这里的写法
//{
//    if(k == -1) return;
//    GetStr(q[k].pre);
//    curans += q[k].ch;
//}
//bool cmp(string a, string b)// 比较两个串表示的十进制的大小
//{
//    if(a.size() > b.size()) return true;
//    if(a.size() == b.size() && a > b) return true;
//    return false;
//}
//bool BFS(int k)
//{
//    bool vis[maxn] = {0};
//    int head = 0, tail = -1;// 队列的首尾指针
//    for(int i = 1; i <= k; i ++)
//    {
//        if(a[i] != 0)
//        {
//            u.pre = -1;
//            u.ch = a[i] + '0';
//            u.mod = a[i] % n;
//            u.len = 1;
//            vis[u.mod] = true;
//            q[++tail] = u;
//        }
//    }
//    while(head <= tail)
//    {
//        u = q[head];
//        if(u.len > MinLen) break;// 这里有一个剪枝
//        for(int i = 1; i <= k; i ++)
//        {
//            v.mod = (u.mod * 10 + a[i]) % n;
//            v.ch = a[i] + '0';
//            v.len = u.len + 1;
//            v.pre = head;
//            if(!vis[v.mod])// 同余判重
//            {
//                q[++tail] = v;
//                vis[v.mod] = true;
//                if(v.mod == 0)// 搜到了结果
//                {
//                    curans = "";
//                    GetStr(tail);// 获得字符串
//                    return true;
//                }
//            }
//        }
//        head ++;
//    }
//    return false;
//}
//int main()
//{
//    //freopen("Test.out", "w", stdout);
//    while(scanf("%d", &n), n)
//    {
//        if(n <= 11)
//        {
//            printf("%d\n", n);
//            continue;
//        }
//        bool flag = false;
//        ans = "";
//        MinLen = maxn;
//        for(int i = 1; i <= 9; i ++)
//        {
//            a[1] = i;
//            if(BFS(1))
//            {
//                if(!flag || cmp(ans, curans))
//                {
//                    flag = true;
//                    ans = curans;
//                    MinLen = ans.size();
//                }
//            }
//        }
//        if(flag)
//        {
//            cout << ans << endl;
//            continue;
//        }
//        for(int i = 0; i <= 9; i ++)
//        {
//            for(int j = i + 1; j <= 9; j ++)
//            {
//                a[1] = i, a[2] = j;
//                if(BFS(2))
//                {
//                    if(!flag || cmp(ans, curans))
//                    {
//                        flag = true;
//                        ans = curans;
//                        MinLen = ans.size();
//                    }
//                }
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// Pusher：DFS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//using namespace std;
//
//char map[30][30];
//int R, C;
//int blocks;
//bool flag;
//char ans[1005];
//int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//char turn[10] = "DURL";
//
//bool judge(int x, int y)
//{
//    if(x < 0 || x >= R || y < 0 || y >= C) return false;
//    return true;
//}
//
//void DFS(int x, int y, int cnt) // 表示出发位置为(x,y),已经消灭了num个箱子
//{
//    if(cnt >= blocks)// 所有的block清除了
//    {
//        flag = true;
//        ans[cnt] = '\0';
//        return;
//    }
//    for(int k = 0; k < 4; k ++)
//    {
//        int xx = x + dir[k][0];
//        int yy = y + dir[k][1];
//        if(!judge(xx, yy) || map[xx][yy]) continue;// 下一步就走出界外，或者与箱子之间没有空格
//        while(judge(xx, yy) && !map[xx][yy])
//        {
//            xx += dir[k][0];
//            yy += dir[k][1];
//        }
//        if(!judge(xx + dir[k][0], yy + dir[k][1])) continue;// 到达棋盘的边缘也是不能push的
//        int temp = map[xx][yy];
//        map[xx + dir[k][0]][yy + dir[k][1]] += temp - 1;
//        map[xx][yy] = 0;// 原先的位置清空
//        ans[cnt] = turn[k];// 保存路径
//        DFS(xx, yy, cnt + 1);
//        if(flag) return;
//        map[xx + dir[k][0]][yy + dir[k][1]] -= temp - 1;// 回溯时要还原
//        map[xx][yy] = temp;
//    }
//}
//
//int main()
//{
//    while(scanf("%d%d", &C, &R) != EOF)
//    {
//        blocks = 0;
//        flag = false;
//        for(int i = 0; i < R; i ++)
//        {
//            scanf("%s", map[i]);
//            for(int j = 0; j < C; j ++)
//            {
//                if(map[i][j] == '.') map[i][j] = 0;
//                else map[i][j] = map[i][j] - 'a' + 1;
//                blocks += map[i][j];
//            }
//        }
//        for(int i = 0; i < R; i ++)
//        {
//            for(int j = 0; j < C; j ++)
//            {
//                if(map[i][j]) continue;
//                DFS(i, j, 0);
//                if(flag)
//                {
//                    printf("%d\n%d\n",i, j);
//                    puts(ans);
//                    goto END;
//                }
//            }
//        }
//        END:;
//    }
//    return 0;
//}

// Beat
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//int T[20][20];
//bool vis[20];
//int ans;
//int n;
//void DFS(int x, int time, int cur)
//{
//    for(int i = 0; i < n; i ++)
//    {
//        if(!vis[i] && T[x][i] >= time)
//        {
//            vis[i] = true;
//            DFS(i, T[x][i], cur + 1);
//            vis[i] = false;
//        }
//    }
//    if(cur > ans) ans = cur;
//}
//int main()
//{
//    while(scanf("%d", &n) != EOF)
//    {
//        for(int i = 0; i < n; i ++)
//            for(int j = 0; j < n; j ++)
//            scanf("%d", &T[i][j]);
//        memset(vis, false, sizeof(vis));
//        vis[0] = true;
//        ans = 1;
//        DFS(0, 0, 1);// 现在正要解决的题号（从0到n-1），也就是T数组的横坐标；上一次题所花的时间；已经解决的题
//        printf("%d\n", ans);
//    }
//    return 0;
//}

// Open the Lock：BFS暴力
//#include<queue>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//struct node
//{
//    int num;
//    int step;
//};
//int BFS(int N, int M)
//{
//    bool vis[10005] = {0};
//    queue<node>q;
//    q.push((node){N, 0});
//    vis[N] = 1;
//    while(!q.empty())
//    {
//        node s = q.front();
//        q.pop();
//        if(s.num == M) return s.step;
//        node e = s;
//        e.step++;
//        // s.num % 100 得到最后两位数即十位和个位；s.num / 1000 得到千位 再将其 * 100 变成百位 (s.num % 1000) / 100 得到百位 再将 * 1000 变成千位
//        e.num = s.num % 100 + (s.num / 1000) * 100 + (s.num % 1000) / 100 * 1000;
//        if(!vis[e.num])
//        {
//            vis[e.num] = true;
//            q.push(e);
//        }
//        e.num = s.num / 1000 * 1000 + (s.num % 1000) / 100 * 10 + (s.num % 100) / 10 * 100 + s.num % 10;
//        if(!vis[e.num])
//        {
//            vis[e.num] = true;
//            q.push(e);
//        }
//        e.num = s.num / 100 * 100 + (s.num  % 10) * 10 + (s.num % 100) / 10;
//        if(!vis[e.num])
//        {
//            vis[e.num] = true;
//            q.push(e);
//        }
//        for(int i = 1; i < 1001; i *= 10)
//        {
//            int temp = (s.num % (i * 10)) / i; // 获取密码的每一位
//            if(temp == 9) e.num = s.num - 8 * i;
//            else e.num = s.num + i;
//            if(!vis[e.num])
//            {
//                vis[e.num] = true;
//                q.push(e);
//            }
//            if(temp == 1) e.num = s.num + 8 * i;
//            else e.num = s.num - i;
//            if(!vis[e.num])
//            {
//                vis[e.num] = true;
//                q.push(e);
//            }
//        }
//        // if(s.num < 1000) return 0;
//    }
//    return 0;
//}
//int main()
//{
//    int T;
//    scanf("%d", &T);
//    int N, M;
//    while(T--)
//    {
//        scanf("%d%d", &N, &M);
//        if(N == M)
//        {
//            printf("0\n");
//            continue;
//        }
//        printf("%d\n", BFS(N, M));
//    }
//    return 0;
//}

// Jerboas：邻接表 + DFS + 余数剪枝
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//const int inf = 0x3f3f3f3f;
//const int maxn = 1000;
//
//struct node
//{
//    int v, w;
//    int next;
//} Edge[maxn * 21];
//
//char str[maxn + 5];
//int head[maxn + 5];
//int vis[maxn + 5][maxn + 5];
//
//int ans, dest;
//int e;
//
//int N, M, S, K;
//
//void AddEdge(int u, int v, int w)
//{
//    e++;
//    Edge[e].v = v;
//    Edge[e].w = w;
//    Edge[e].next = head[u];
//    head[u] = e;
//}
//void DFS(int u, int val)
//{
//    if(val > ans && ans != -1) return;
//    if(str[u] == 'P' && val % K == 0)
//    {
//        if(val < ans || ans == -1)
//        {
//            ans = val;
//            dest = u;
//            return;
//        }
//        else if(val == ans && u < dest)
//            dest = u;
//        return;
//    }
//    for(int i = head[u]; i != -1; i = Edge[i].next)
//    {
//        int v = Edge[i].v;
//        val += Edge[i].w;
//        if(!vis[v][val % K] || val < vis[v][val % K])// 到达某点时路径长度mod k的最短路径长度，如果余数相同，就更新最小值。
//        {
//            vis[v][val % K] = val;
//            DFS(v, val);
//            val -= Edge[i].w;
//        }
//    }
//}
//int main()
//{
//    int T;
//    scanf("%d", &T);
//    for(int t = 1; t <= T; t ++)
//    {
//        scanf("%d%d%d%d", &N, &M, &S, &K);
//        scanf("%s", str + 1);
//        memset(head, -1, sizeof(head));
//        memset(vis, 0, sizeof(vis));
//        e = 0;
//        int u, v, w;
//        for(int i = 1; i <= M; i ++)
//        {
//            scanf("%d%d%d", &u, &v, &w);
//            AddEdge(u, v, w);
//        }
//        ans = dest = -1;
//        DFS(S, 0);
//        printf("Case %d: %d %d\n", t, ans, dest);
//    }
//    return 0;
//}

// Jerboas：筑图 + bfs + 取余判重
//#include<queue>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//#define MAXN 1005
//#define INF 0x3f3f3f3f
//
//using namespace std;
//
//const int maxm = 21000;
//
//int N, M, S, K;
//char str[MAXN];
//int e;
//
//struct adjacencyList
//{
//    int v, next;
//    int cost;
//}edge[maxm];
//int head[MAXN];
//int ans, dest;
//struct node
//{
//    int pos, len;
//    bool operator <(const node &S) const
//    {
//        return S.len < len;
//    }
//};
//void AddEdge(int u, int v, int c)
//{
//    e++;
//    edge[e].v = v;
//    edge[e].cost = c;
//    edge[e].next = head[u];
//    head[u] = e;
//}
//void BFS()
//{
//    int temp = INF;
//    bool vis[MAXN][MAXN] = {0};
//    priority_queue<node>q;
//    q.push(node{S, 0});
//    vis[S][0] = true;
//    while(!q.empty())
//    {
//        node s = q.top();
//        q.pop();
//        if(s.len > temp) return;
//        if(str[s.pos] == 'P' && s.len % K == 0)
//        {
//            if(temp == INF) temp = s.len;
//            if(ans == -1 || ans > s.len || (ans == s.len && dest > s.pos))
//            {
//                ans = s.len;
//                dest = s.pos;
//            }
//        }
//        for(int i = head[s.pos]; i + 1; i = edge[i].next)
//        {
//            int v = edge[i].v;
//            int len = s.len + edge[i].cost;
//            int mod = len % K;
//            if(!vis[v][mod])
//            {
//                vis[v][mod] = true;
//                q.push(node{v, len});
//            }
//        }
//    }
//}
//int main()
//{
//    int T;
//    scanf("%d", &T);
//    for(int t = 1; t <= T; t ++)
//    {
//        scanf("%d%d%d%d", &N, &M, &S, &K);
//        scanf("%s", str + 1);
//        int u, v, c;
//        e = 0;
//        memset(head, -1, sizeof(head));
//        for(int i = 1; i <= M; i ++)
//        {
//            scanf("%d%d%d", &u, &v, &c);
//            AddEdge(u, v, c);
//        }
//        ans = dest = -1;
//        BFS();
//        printf("Case %d: %d %d\n", t, ans, dest);
//    }
//    return 0;
//}

// Tempter of the Bone II: 优先队列 + BFS
//#include<queue>
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//char map[10][10];
//int N, M;
//int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//
//struct node
//{
//    int x, y;
//    int bomb;
//    int time;
//    char maze[10][10];
//    bool operator<(const node &S) const
//    {
//        return S.time < time;
//    }
//}s;
//int BFS()
//{
//    priority_queue<node>q;
//    int vis[8][8][8 * 8 * 9] = {0};
//    for(int i = 0; i < N; i ++)
//        for(int j = 0; j < M; j ++) s.maze[i][j] = map[i][j];
//    s.bomb = 0, s.time = 0;
//    q.push(s);
//    vis[s.x][s.y][0]++;
//    while(!q.empty())
//    {
//        s = q.top();
//        q.pop();
//        for(int i = 0; i < 4; i ++)
//        {
//            node e = s;
//            e.x = s.x + dir[i][0];
//            e.y = s.y + dir[i][1];
//            e.time = s.time + 1;
//            if(e.x >= 0 && e.x < N && e.y >= 0 && e.y < M && vis[e.x][e.y][e.bomb] < 20)
//            {
//                if(e.maze[e.x][e.y] == 'D') return e.time;
//                if(e.maze[e.x][e.y] == '.' || e.maze[e.x][e.y] == 'S')
//                {
//                    vis[e.x][e.y][e.bomb]++;
//                    q.push(e);
//                }
//                else if(e.maze[e.x][e.y] == 'X' && e.bomb > 0)
//                {
//                    vis[e.x][e.y][e.bomb] ++;
//                    e.bomb --;
//                    e.time ++;
//                    e.maze[e.x][e.y] = '.';
//                    vis[e.x][e.y][e.bomb] ++;
//                    q.push(e);
//                }
//                else if(e.maze[e.x][e.y] >= '1' && e.maze[e.x][e.y] <= '9')
//                {
//                    vis[e.x][e.y][e.bomb] ++;
//                    e.bomb += e.maze[e.x][e.y] - '0';
//                    e.maze[e.x][e.y] = '.';
//                    vis[e.x][e.y][e.bomb] ++;
//                    q.push(e);
//                }
//            }
//        }
//    }
//    return -1;
//}
//int main()
//{
//    while(scanf("%d%d", &N, &M), N + M)
//    {
//        for(int i = 0; i < N; i ++)
//        {
//            scanf("%s", map[i]);
//            for(int j = 0; j < M; j ++)
//            {
//                if(map[i][j] == 'S')
//                {
//                    s.x = i;
//                    s.y = j;
//                }
//            }
//        }
//        int res = BFS();
//        printf("%d\n", res);
//    }
//    return 0;
//}

// Tempter of the Bone II: 普通队列 + BFS
//#include<queue>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//using namespace std;
//
//char map[10][10];
//int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//
//int N, M;
//struct node
//{
//    int x, y;
//    int bomb;
//    int time;
//    int pos[8][8]; // 保存每个位置的最小炸弹数
//} s;
//int ans;
//void BFS()
//{
//    ans = -1;
//    queue<node>q;
//    s.bomb = 0;
//    s.time = 0;
//    memset(s.pos, -1, sizeof(s.pos));
//    s.pos[s.x][s.y] = 0;
//    q.push(s);
//    while(!q.empty())
//    {
//        s = q.front();
//        q.pop();
//        if(ans != -1 && s.time + 1 >= ans) continue;
//        for(int i = 0; i < 4; i ++)
//        {
//            node e;
//            e.x = s.x + dir[i][0];
//            e.y = s.y + dir[i][1];
//            e.bomb = -1;
//            if(e.x >= 0 && e.x < N && e.y >= 0 && e.y < M)
//            {
//                if(map[e.x][e.y] == 'D')
//                {
//                    if(ans == -1 || ans > s.time + 1)
//                        ans = s.time + 1;
//                    continue;
//                }
//                if(map[e.x][e.y] == '.' || s.pos[e.x][e.y] > -1) // 已经走过的炸弹和WALL都没有了，相当于'.'
//                {
//                    e.time = s.time + 1;
//                    e.bomb = s.bomb;
//                }
//                else if(map[e.x][e.y] == 'X' && s.bomb > 0)
//                {
//                    e.time = s.time + 2;
//                    e.bomb = s.bomb - 1;
//                }
//                else if(map[e.x][e.y] >= '1' && map[e.x][e.y] <= '9')
//                {
//                    e.time = s.time + 1;
//                    e.bomb = s.bomb + map[e.x][e.y] - '0';
//                }
//                // 这个剪枝有问题
//                if (e.bomb > s.pos[e.x][e.y])
//                {
//                    memcpy(e.pos, s.pos, 64 * sizeof(int));
//                    e.pos[e.x][e.y] = e.bomb;
//                    q.push(e);
//                }
//            }
//        }
//    }
//    return;
//}
//int main()
//{
//    while(scanf("%d%d", &N, &M), N + M)
//    {
//        for(int i = 0; i < N; i ++)
//        {
//            scanf("%s", map[i]);
//            for(int j = 0; j < M; j ++)
//            {
//                if(map[i][j] == 'S')
//                {
//                    s.x = i;
//                    s.y = j;
//                    // map[i][j] = '.';
//                }
//            }
//        }
//        BFS();
//        printf("%d\n", ans);
//    }
//    return 0;
//}

// poj 2251 Dungeon Master
//#include<queue>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//
//const int maxn = 35;
//
//char map[maxn][maxn][maxn];
//int dir[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0 , 1}, {0, 0, -1}};
//int L, R, C;
//
//struct node
//{
//    int l, x, y;
//    int step;
//} s, e, t;
//
//int BFS()
//{
//    queue<node> q;
//    s.step = 0;
//    q.push(s);
//    while(q.size())
//    {
//        node h = q.front();
//        q.pop();
//        if(h.x == e.x && h.y == e.y && h.l == e.l)return h.step;
//        for(int i = 0; i < 6; i ++)
//        {
//            t.l = h.l + dir[i][0];
//            t.x = h.x + dir[i][1];
//            t.y = h.y + dir[i][2];
//            t.step = h.step + 1;
//            if(t.l >= 0 && t.l < L && t.x >= 0 && t.x < R && t.y >= 0 && t.y < C && map[t.l][t.x][t.y] != '#')
//            {
//                map[t.l][t.x][t.y] = '#';
//                q.push(t);
//            }
//        }
//    }
//    return -1;
//}
//
//int main()
//{
//    while(scanf("%d%d%d", &L, &R, &C), L && R && C)
//    {
//        for(int i = 0; i < L; i ++)
//        {
//            for(int j = 0; j < R; j ++)
//            {
//                scanf("%s", map[i][j]);
//                for(int k = 0; k < C; k ++)
//                {
//                    if(map[i][j][k] == 'S')
//                    {
//                        s.l = i;
//                        s.x = j;
//                        s.y = k;
//                    }
//                    if(map[i][j][k] == 'E')
//                    {
//                        e.l = i;
//                        e.x = j;
//                        e.y = k;
//                    }
//                }
//            }
//        }
//        int res = BFS();
//        if(res == -1) puts("Trapped!");
//        else printf("Escaped in %d minute(s).\n", res);
//
//    }
//    return 0;
//}


// poj 1426 Find The Multiple
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;
int n;

bool flag;

void DFS(int k, long long cur)
{
    if(k >= 19 || flag)
        return ;
    if(cur % n == 0)
    {
        printf("%I64d\n", cur);
        flag = true;
        return ;
    }
    DFS(k + 1, 10 * cur);
    DFS(k + 1, 10 * cur + 1);
}

int main()
{
    while(scanf("%d", &n), n)
    {
        flag = false;
        DFS(0, 1);
    }
    return 0;
}


