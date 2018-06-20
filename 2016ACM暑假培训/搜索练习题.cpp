// Anti-prime Sequences
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//#define N 1005
//
//using namespace std;
//bool vis[N], flag, prime[10005] = {0};
//int ans[N];
//int n, m, d, len;
//void Prime()
//{
//    prime[0] = true;
//    prime[1] = true;
//    for(int i = 2; i < N; i++)
//        if(!prime[i])
//            for(int j = 2; i * j < 10010; j++)
//                prime[i * j] = true;
//}
//bool Check(int cur)
//{
//    int sum = ans[cur];
//    for(int i = cur - 1; i >= 0 && i > cur - d; i--)
//    {
//        sum += ans[i];
//        if(!prime[sum]) return false;
//    }
//    return true;
//}
//void DFS(int depth)
//{
//    if(depth == len)
//    {
//        flag = true;
//        return;
//    }
//    for(int i = n; i <= m; i++)
//        if(!vis[i])
//        {
//            ans[depth] = i;
//            if(Check(depth))
//            {
//                vis[i] = true;
//                DFS(depth + 1);
//                vis[i] = false;
//                if(flag) return;
//            }
//        }
//    return;
//}
//int main()
//{
//    Prime();
//    while(scanf("%d%d%d", &n, &m, &d) != EOF && n && m && d)
//    {
//        len = m - n + 1;
//        flag = false;
//        memset(vis, false, sizeof(vis));
//        DFS(0);
//        if(flag)
//        {
//            for(int i = 0; i < len; i ++)
//                printf("%d%c", ans[i], i == len - 1 ? '\n' : ',');
//        }
//        else puts("No anti-prime sequence exists.");
//
//    }
//    return 0;
//}

// 棋盘问题
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//char chessBoard[10][10];
//bool vis[10];
//int n, k;
//int num, ans;
//void DFS(int cur)
//{
//    if(num == k)
//    {
//        ans ++;
//        return;
//    }
//    if(cur >= n) return;
//    for(int j = 0; j < n; j++)
//        if(chessBoard[cur][j] == '#' && !vis[j])
//        {
//            vis[j] = true;
//            num ++;
//            DFS(cur + 1);
//            num --;
//            vis[j] = false;
//        }
//    DFS(cur + 1);
//}
//int main()
//{
//    while(scanf("%d%d", &n, &k) != EOF)
//    {
//        if(n == -1 && k == -1) break;
//        for(int i = 0; i < n; i ++)
//            scanf("%s", chessBoard[i]);
//        ans = 0, num = 0;
//        memset(vis, false, sizeof(vis));
//        DFS(0);
//        printf("%d\n", ans);
//    }
//
//    return 0;
//}

// Dessert
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//using namespace std;
//
//int N, cnt;
//char symbol[30];
//void DFS(int sum, int pre, int cur)
//{
//    if(cur == N + 1)
//    {
//        if(sum == 0)
//        {
//            cnt ++;
//            if(cnt > 20)
//                return;
//            for(int i = 1; i < N; i ++)
//                printf("%d %c ", i, symbol[i]);
//            printf("%d\n", N);
//        }
//        return;
//    }
//    symbol[cur - 1] = '+';
//    DFS(sum + cur, cur, cur + 1);
//    symbol[cur - 1] = '-';
//    DFS(sum - cur, -cur, cur + 1);
//    symbol[cur - 1] = '.';
//    int x = pre < 0 ? - cur : cur;
//    if(cur <= 9) DFS(sum - pre + 10 * pre + x, 10 * pre + x, cur + 1);
//    else DFS(sum - pre + 100 * pre + x, 100 * pre + x, cur + 1);
//}
//int main()
//{
//    while(scanf("%d", &N) != EOF)
//    {
//        cnt = 0;
//        DFS(1, 1, 2);// 当前的和，前驱元素， 当前元素
//        printf("%d\n", cnt);
//    }
//}

// 	Sudoku
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//using namespace std;
//
//char Sudoku[10][10];
//bool flag;
//bool judge(int data, int r, int c)
//{
//    char used = data + '0';
//    for(int i = 0; i < 9; i ++)
//    {
//        if(Sudoku[r][i] == used) return false;
//        if(Sudoku[i][c] == used) return false;
//    }
//    int x = r / 3 * 3;
//    int y = c / 3 * 3;
//    for(int i = x; i < x + 3; i ++)
//        for(int j = y; j < y + 3; j ++)
//            if(Sudoku[i][j] == used) return false;
//    return true;
//}
//void DFS(int r, int c)
//{
//    if(r == 9)
//    {
//        flag = true;
//        return ;
//    }
//    if(Sudoku[r][c] != '0')
//    {
//        if(c + 1 == 9) DFS(r + 1, 0);
//        else DFS(r, c + 1);
//        return ;
//    }
//    for(int num = 1; num <= 9; num ++)
//        if(judge(num, r, c))
//        {
//            Sudoku[r][c] = num + '0';
//            if(c + 1 == 9) DFS(r + 1, 0);
//            else DFS(r, c + 1);
//            if(flag) return ;
//            Sudoku[r][c] = '0';
//        }
//}
//int main()
//{
//    int t;
//    scanf("%d", &t);
//    while(t--)
//    {
//        for(int i = 0; i < 9; i ++)
//            scanf("%s", Sudoku[i]);
//        flag = false;
//        DFS(0, 0);
//        for(int i = 0; i < 9; i ++)
//            puts(Sudoku[i]);
//    }
//    return 0;
//}


// 	Rescue
#include<queue>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

int N, M;
struct node
{
    int x, y, step;
    bool operator <(const node &S) const
    {
        return S.step < step;
    }
};
node s, e, h, t;
char map[205][205];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int BFS()
{
    priority_queue<node>q;
    while(!q.empty())
        q.pop();
    s.step = 0;
    q.push(s);
    while(!q.empty())
    {
        h = q.top();
        q.pop();
        if(h.x == e.x && h.y == e.y) return h.step;
        for(int i = 0; i < 4; i ++)
        {
            t.x = h.x + dir[i][0];
            t.y = h.y + dir[i][1];
            t.step = h.step + 1;
            if(t.x >= 0 && t.x < N && t.y >= 0 && t.y < M && map[t.x][t.y] != '#' )
            {
                if(map[t.x][t.y] == 'x')
                    t.step = t.step + 1;
                map[t.x][t.y] = '#';
                q.push(t);
            }
        }
    }
    return -1;
}
int main()
{
    while(scanf("%d%d", &N, &M) != EOF)
    {
        for(int i = 0; i < N; i ++)
        {
            scanf("%s", map[i]);
            for(int j = 0; j < M; j ++)
            {
                if(map[i][j] == 'r')
                {
                    s.x = i;
                    s.y = j;
                    map[i][j] = '#';
                }
                if(map[i][j] == 'a')
                {
                    e.x = i;
                    e.y = j;
                }
            }
        }
        int res = BFS();
        if(res == -1)puts("Poor ANGEL has to stay in the prison all his life.");
        else printf("%d\n", res);
    }
    return 0;
}

