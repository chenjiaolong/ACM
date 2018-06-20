//ACM 2323 天牢问题：N*N维的矩阵，从天牢第一层走到最后一层，竖着或者斜着都不能落脚
/*#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int Map[20][20],n;//Map[20][20]代表地图
int flag[20];//用来标记列，如flag[0]=1代表第1个放下标为1的那列，
//flag[2]=3代表第3个放在第下标为3那列
void dfs(int num)//搜索行
{
    //printf("num1=%d\n",num);
    if(num==n)
    {
        //打印答案
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                printf("%d%c",Map[i][j],j==n-1?'\n':' ');//每行最后没有空格
        printf("\n");
    }
    else
    {
        for(int i=0; i<n; i++)//代表将要填的列
        {
            int flag1=0;
            for(int j=0; j<num; j++)
                //判断条件，flag[j]-j表示填好的列-填好的第几个“1”(即行)，i-num代表1将要填的列-将要填的行
                //flag[j]+j==i+num同理
                //flag[j]=i表示下标为j的那行的“1”已经填在第i列，第i列就不能填“1”；
                if(flag[j]==i||flag[j]-j==i-num||flag[j]+j==i+num)
                {
                    flag1=1;
                    break;
                }
            if(flag1==1)//如果flag1==1代表满足上面的条件，就不能填“1”,因此就继续找下一列。
                continue;
            flag[num]=i;//标记下标为num的行的“1”填在第i列；
            Map[num][i]=1;//把该位置标记为“1”；
            dfs(num+1);//行数加1
            flag[num]=0;
            Map[num][i]=0;
        }
        //printf("num2=%d\n",num);
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(Map,0,sizeof(Map));
        dfs(0);
    }
    return 0;
}*/
/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
int vis[100][100];
void dfs(int cur)
{
    if(cur==n)
    {
        int i,j;
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                printf("%d%c",vis[i][j]<0?0:vis[i][j],j==n-1?'\n':' ');
        printf("\n");
    }
   else
    {
        int i,j,k;
        if(cur==0)
            memset(vis,0,sizeof(vis));
        for(j=0; j<n; j++)
        {
            if(vis[cur][j]==0)
            {
                vis[cur][j]=1;
                for(i=cur+1; i<n; i++)
                    if(vis[i][j]==0)
                        vis[i][j]=-(cur+1);
                for(i=cur+1,k=j+1; i<n&&k<n; i++,k++)
                    if(vis[i][k]==0)
                        vis[i][k]=-(cur+1);
                for(i=cur+1,k=j-1; i<n&&k>=0; i++,k--)
                    if(vis[i][k]==0)
                        vis[i][k]=-(cur+1);
                dfs(cur+1);
                vis[cur][j]=0;
                for(i=0; i<n; i++)
                    for(k=0; k<n; k++)
                        if(vis[i][k]==-(cur+1))
                            vis[i][k]=0;
            }
        }
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        memset(vis,0,sizeof(vis));
        dfs(0);
    }
    return 0;
}*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,a[200];
void show()
{
    int i,j;
    for(i = 1; i <= n; i ++)
        for(j = 1; j <= n; j ++)
            printf("%d%c",a[i] == j ? 1 : 0, j == n ? '\n' : ' ');//等价于printf("%d%c",a[i] == j, j == n ? '\n' : ' ');
    printf("\n");
}
int check(int num)
{
    int i;
    for(i = 1; i < num; i ++)
        if(a[i] == a[num] || abs(a[i] - a[num]) == num - i)
            return 1;
    return 0;
}
void dfs(int cnt)
{
    int i;
    for(i = 1; i <= n; i ++)
    {
        a[cnt] = i;
        if(!check(cnt))
        {
            if(cnt >= n)
                show();
            else
                dfs(cnt + 1);
        }
    }
}
// 等价于
//void dfs(int cnt)
//{
//    if(cnt >= n + 1)
//    {
//        show();
//        return ;
//    }
//    int i;
//    for(i = 1; i <= n; i ++)
//    {
//        a[cnt] = i;
//        if(!check(cnt))
//            dfs(cnt + 1);
//    }
//}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        dfs(1);
    }
    return 0;
}
//ACM 2325 迷宫问题：一个二维数组表示迷宫：int maze[5][5]={{0,1,0,0,0},{0,1,0,1,0},{0,0,0,0,0},{0,1,1,1,0},{0,0,0,1,0}};其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。
//输入：一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。
//输出：左上角到右下角的最短路径（用通过路径的坐标表示）
/*#include<cstdio>
#include<cstring>

int vis[25][25];
int xx[4]= {1,-1,0,0};
int yy[4]= {0,0,-1,1};
struct node
{
    int x,y;
};
node point[25];
node ans[25];
int map[5][5];
int ste=25;
void dfs(int x,int y,int cur)
{
    if(x==4&&y==4)
    {
        if(ste>cur)
        {
            ste=cur;
            for(int i=0; i<=cur; i++)
                ans[i].x=point[i].x,ans[i].y=point[i].y;
        }
        return;
    }
    for(int i=0; i<4; i++)
    {
        int X=x+xx[i],Y=y+yy[i];
        if(X>=0&&X<5&&Y>=0&&Y<5)
        {
            if(!vis[X][Y]&&map[X][Y]!=1)
            {
                point[cur].x=X;
                point[cur].y=Y;
                vis[X][Y]=1;
                dfs(X,Y,cur+1);
                vis[X][Y]=0;
            }
        }
    }
}
int main()
{
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            scanf("%d",&map[i][j]);
    dfs(0,0,0);
    printf("(0, 0)\n");
    for(int i=0; i<ste; i++)
        printf("(%d, %d)\n",ans[i].x,ans[i].y);
}*/
//输出：既不在同一行，也不再同一列棋子的排列情况（1表示已放置的棋子）
/*#include<cstdio>
#include<cstring>

int ans,n,num;;
int vis[30];
int Ans[30][30];
void dfs(int cur)
{
    if(cur==n)
    {
        ans++;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                printf("%d",Ans[i][j]);
            printf("\n");
        }
        printf("\n");
        return ;
    }
    if(cur>=n)return;
    for(int j=0; j<n; j++)
        if(!vis[j])
        {
            vis[j]=1;
            Ans[cur][j]=1;
            dfs(cur+1);
            vis[j]=0;
            Ans[cur][j]=0;
        }
    return ;
}
int main()
{
    ans=0;
    n=5;
    dfs(0);
    printf("%d\n",ans);
}*/
//统计油田问题
/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 120
char Map[M][M];
int n = 0, m = 0;
int count = 0;
int dfs(int x,int y)
{
    if (Map[x][y]=='@')
    {
        Map[x][y] = '#';
        if(x > 0)
        {
            dfs(x-1,y); //up
            if(y < m-1)
                dfs(x-1,y+1); //right-up
            if(y > 0) //left-up
                dfs(x-1,y-1);
        }
        /////////////////////////////////////////
        if(x < n-1) //bottom
        {
            dfs(x+1,y);//bottom
            if(y < m-1)//right-bottom
                dfs(x+1,y+1);
            if(y > 0)//left-bottom
                dfs(x+1,y-1);
        }
/////////////////////////////////
        if(y > 0)//right
            dfs(x,y-1);
        if(y < m-1)//left
            dfs(x,y+1);

    }
    return 1;
}
int main()
{
    n = 0, m =0;
    while(~scanf("%d%d",&n,&m)&&m||n)
    {
        memset(Map,0,sizeof(Map));
        count = 0;
        for(int i = 0; i < n; i ++)
            scanf("%s",Map[i]);
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                if(Map[i][j] == '@' )
                {
                    dfs(i,j);
                    count ++;
                }
        printf("%d\n",count);
    }
    return 0;
}*/
