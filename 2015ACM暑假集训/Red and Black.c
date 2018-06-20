//Red and Black （该方法运用搜索+dp）
#include <stdio.h>
#include <string.h>
#include<stdbool.h>
#define N 21
int w,h,sx,sy;
char map[N][N];
bool used[N][N];
int dir[][2]= {{-1,0},{0,1},{1,0},{0,-1}};
int dp[N][N];
int dfs(int x,int y)
{
    int i,xx,yy,sum=0;
    if(used[x][y])return 0;
    if(dp[x][y]!=0)return dp[x][y];
    used[x][y]=true;
    for(i=0; i<4; i++)
    {
        xx=x+dir[i][0];
        yy=y+dir[i][1];
        if(!used[xx][yy]&&xx>=0&&xx<h&&yy>=0&&yy<w&&map[xx][yy]=='.')
        {
            sum+=dfs(xx,yy);
        }
    }
    dp[x][y]=sum+1;
    return sum+1;
}
int main()
{
    int i,j;
    while(scanf("%d%d",&w,&h)!=EOF)
    {
        if(w==0&&h==0)break;        //getchar();
        memset(used,false,sizeof(used));
        memset(dp,0,sizeof(dp));
        for(i=0; i<h; i++)
            scanf("%s",map[i]);
        for(i=0; i<h; i++)
            for(j=0; j<w; j++)
            {
                if(map[i][j]=='@')
                {
                    sx=i;
                    sy=j;
                }          // getchar();
            }
        /*for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
                printf("%c",map[i][j]);
            printf("\n");
        }*/
        printf("%d\n",dfs(sx,sy));
    }
}
