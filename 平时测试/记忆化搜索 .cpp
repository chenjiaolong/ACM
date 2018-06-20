// hdu 1078 atMouse and Cheese
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

const int maxn = 105;

int map[maxn][maxn];
int dp[maxn][maxn];
int n, k;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int DFS(int x, int y)
{
    if(dp[x][y]) return dp[x][y];
    int MAX = 0;
    for(int i = 1; i <= k; i ++)
    {
        for(int j = 0; j < 4; j ++)
        {
            int xx = x + dir[j][0] * i;
            int yy = y + dir[j][1] * i;
            if(xx >= 0 && xx < n && yy >= 0 && yy < n && map[xx][yy] > map[x][y])
            {
                int ans = DFS(xx, yy);
                if(ans > MAX) MAX = ans;
            }
        }
    }
    return dp[x][y] = map[x][y] + MAX;
}
int main()
{
    while(scanf("%d%d", &n, &k), n != -1)
    {
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
            {
                scanf("%d", &map[i][j]);
                dp[i][j] = 0;
            }
        int ans = DFS(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
