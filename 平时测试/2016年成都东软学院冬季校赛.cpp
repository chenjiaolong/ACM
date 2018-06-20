//#include<stdio.h>
//
//using namespace std;
//
//int main()
//{
//    int a, b;
//    while(scanf("%d%d", &a, &b) != EOF)
//    {
//        int ans = a;
//        while(a >= b)
//        {
//            ans += a / b;
//            a = a / b + a % b;
//            //printf("%d\n", a);
//        }
//        printf("%d\n", ans);
//    }
//    return 0;
//}


//#include<math.h>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//using namespace std;
//
//int main()
//{
//    int T;
//    scanf("%d", &T);
//    while(T--)
//    {
//        int n;
//        scanf("%d", &n);
//        int m = (int )sqrt(n);
//        bool flag = true;
//        for(int i = 2; i <= m; i ++)
//            if(n % i == 0) flag = false;
//        if(flag) puts("Yes");
//        else puts("No");
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        char stone[55];
//        scanf("%s", stone);
//        int len = strlen(stone);
//        int ans = 0;
//        for(int i = 0; i < len - 1; i ++)
//            if(stone[i] == stone[i + 1])
//                ans ++;
//        printf("%d\n", ans);
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//using namespace std;
//
//int main()
//{
//    // freopen("test4.in", "r", stdin);
//    // freopen("test4.out", "w", stdout);
//    int matrix[205][205];
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        memset(matrix, 0, sizeof(matrix));
//        matrix[0][n / 2] = 1;
//        int x = 0, y = n / 2;
//        int xx, yy;
//        for(int i = 2; i <= n * n; i ++)
//        {
//            xx = x - 1;
//            yy = y + 1;
//            if(xx < 0) xx = n - 1;
//            if(yy > n - 1) yy = 0;
//            if(matrix[xx][yy])
//            {
//                xx = x + 1;
//                yy = y;
//            }
//            matrix[xx][yy] = i;
//            x = xx, y = yy;
//            // printf("SSs %d %d %d\n", xx, yy, i);
//        }
//        for(int i = 0; i < n; i ++)
//            for(int j = 0; j < n; j ++)
//                printf("%d%c", matrix[i][j], j == n - 1? '\n' : ' ');
//        puts("");
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//using namespace std;
//
//int main()
//{
//    int a, b;
//    while(scanf("%d%d", &a, &b) != EOF)
//    {
//        if(b == 0)
//        {
//            puts("-1");
//            continue;
//        }
//        int ans = a / b;
//        if(a % b) ans ++;
//        printf("%d\n", ans);
//    }
//    return 0;
//}

#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

int n, k;
char myMap[105][105];
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

struct node
{
    int x, y;
    int time;
    int num;
};
node s, e;
int BFS()
{
    queue<node>q;
    bool vis[105][105][(1 << 5) + 5] = {0};
    q.push(s);
    vis[s.x][s.y][s.num] = true;
    while(q.size())
    {
        node h = q.front();
        q.pop();
        if(h.num == ((1 << k) - 1)) return h.time;
        for(int i = 0; i < 4; i ++)
        {
            e.x = h.x + dir[i][0];
            e.y = h.y + dir[i][1];
            e.time = h.time + 1;
            e.num = h.num;
            if(e.x >= 0 && e.x < n && e.y >= 0 && e.y < n && myMap[e.x][e.y] != '#')
            {
                if(myMap[e.x][e.y] >= '0' && myMap[e.x][e.y] <= '5')
                {
                    int key = 1 << (myMap[e.x][e.y] - '0');
                    e.num |= key;
                }
                if(vis[e.x][e.y][e.num]) continue;
                vis[e.x][e.y][e.num] = true;
                q.push(e);
            }
        }
    }
    return -1;
}
int main()
{
    while(scanf("%d%d", &n, &k) != EOF)
    {
        int cnt = 0;
        for(int i = 0; i < n; i ++)
        {
            scanf("%s", myMap[i]);
            for(int j = 0; j < n; j ++)
            {
                if(myMap[i][j] == '@')
                {
                    s.x = i;
                    s.y = j;
                    s.time = 0;
                    s.num = 0;
                }
                if(myMap[i][j] == '1')
                {
                    myMap[i][j] = cnt + '0';
                    cnt ++;
                }
            }
        }
        printf("%d\n", BFS());
    }
    return 0;
}
