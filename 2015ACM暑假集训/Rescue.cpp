#include <stdio.h>

const int INF = 10000000; // const 修饰符  INF 表示一个很大的值
const int maxn = 200 + 10; // 数据大小 题目中 0 <= N,M <= 100

int d[maxn][maxn];   //用于储存步数，如，起点为（0,0），那么d[0][0] = 0,表示
                     //从（0,0）到（0,0）的步数，d[1][3]表示从（0,0）到（1,3）的步数
char map[maxn][maxn];  //储存迷宫的地图
int dx[4] = {0,0,-1,1},dy[4] = {-1,1,0,0};// 移动的四个方向
int n,m;

typedef struct //表示一个点
{
    int x,y;
} P;

P queue[maxn * 4],s,e,tp,t;  //如同 int a,b,c[1000]一样,只不过这里是P ，是自己定义的类型，一样的用法

int bfs()
{
    int i,j;
    int head = 0,tail = 0;
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            d[i][j] = INF;
    d[s.x][s.y] = 0;
    queue[tail++] = s;
    while (head <=tail)
    {
        t = queue[head++];
        for (i = 0; i < 4; i++)
        {
            tp.x = t.x + dx[i];
            tp.y = t.y + dy[i];
            if (0 <= tp.x && tp.x < n &&0 <= tp.y && tp.y < m && map[tp.x][tp.y] != '#')
            {
                d[tp.x][tp.y] = d[t.x][t.y] + 1;
                if(map[tp.x][tp.y]=='x')
                    d[tp.x][tp.y]++;
                queue[tail++] = tp;
            }
        }
    }

    return d[e.x][e.y];
}

int main()
{
    int i,j;
    while(~scanf("%d%d",&n,&m))
    {
        for (i = 0; i < n; i++)
            scanf("%s",map[i]);
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
            {
                d[i][j] = INF;
                if (map[i][j] == 'r')
                {
                    s.x = i;
                    s.y = j;
                }
                else if (map[i][j] == 'a')
                {
                    e.x = i;
                    e.y = j;
                }
            }
        if(bfs()<INF)
            printf("%d\n",bfs());
        else
            printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
}

//#include<stdio.h>
//#include<string.h>
//int n,m;
//char map[300][300];
//int vis[300][300];
//int dir[4][2]= {{-1,0},{0,1},{1,0},{0,-1}};
//struct node
//{
//    int x,y,step;
//};
//node queue[1000000],s,g;
//int bfs()
//{
//    int e=0,f=0;
//    s.step=0;
//    queue[f++]=s;
//    node t,h;
//    while(e<f)
//    {
//        t=queue[e++];
//        if(t.x==g.x&&t.y==g.y)
//            return t.step;
//        for(int i=0; i<4; i++)
//        {
//            h.x=t.x+dir[i][0];
//            h.y=t.y+dir[i][1];
//            h.step=t.step+1;
//            if(h.x>=0&&h.y>=0&&h.x<n&&h.y<m&&map[h.x][h.y]!='#'&&vis[h.x][h.y]==0)
//            {
//                if(map[h.x][h.y]=='x')
//                    h.step=h.step+1;
//                vis[h.x][h.y]=1;
//                queue[f++]=h;
//            }
//        }
//    }
//    return -1;
//}
//int main()
//{
//    while(~scanf("%d%d",&n,&m))
//    {
//        memset(map,'\0',sizeof(map));
//        memset(vis,0,sizeof(vis));
//        for(int i=0; i<n; i++)
//        {
//            getchar();
//            for(int j=0; j<m; j++)
//                scanf("%c",&map[i][j]);
//        }
//        for(int i=0; i<n; i++)
//            for(int j=0; j<m; j++)
//                if(map[i][j]=='r')
//                {
//                    s.x=i;
//                    s.y=j;
//                }
//                else if(map[i][j]=='a')
//                {
//                    g.x=i;
//                    g.y=j;
//                }
//        int s=bfs();
//        if(s!=-1)
//            printf("%d\n",s);
//        else
//            printf("Poor ANGEL has to stay in the prison all his life.\n");
//    }
//}
