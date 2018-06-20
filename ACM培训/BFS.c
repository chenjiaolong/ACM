//ACM 2325 迷宫问题：一个二维数组表示迷宫：int maze[5][5]={{0,1,0,0,0},{0,1,0,1,0},{0,0,0,0,0},{0,1,1,1,0},{0,0,0,1,0}};其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。
//输入：一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。
//输出：左上角到右下角的最短路径（用通过路径的坐标表示）
#include<stdio.h>
#include<string.h>
int map[10][10];//地图
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};//移动的四个方向
int vis[10][10];//标记地图
typedef struct
{
    int x,y,step,pre;//step是步数，pre是前驱
}node;
node queue[100000],s,g;//s是起始点，g是终点

void Print(int i)//递归,i是前驱
{
    if(queue[i].pre!=-1)//起始点的前驱是-1
    {
        Print(queue[i].pre);
        printf("(%d, %d)\n",queue[i].x,queue[i].y);
    }
}
int bfs()
{
    int i;
    s.x=0,s.y=0,s.step=0,s.pre=-1;
    g.x=4,g.y=4;
    int e=0,f=0;
    queue[f++]=s;//入队
    node t,h;
    while(e<f)
    {
        t=queue[e++];//出队，e++
        if(t.x==g.x&&t.y==g.y)//终点的检测
        {
            printf("(0, 0)\n");
            Print(t.pre);//输出记录的点
            printf("(4, 4)\n");
            return t.step;//返回最长步数
        }
        for(i=0;i<4;i++)//四个方向遍历
        {
            h.x=t.x+dir[i][0];
            h.y=t.y+dir[i][1];
            h.step=t.step+1;
            if(h.x>=0&&h.y>=0&&h.x<5&&h.y<5&&map[h.x][h.y]==0&&vis[h.x][h.y]==0)//检测是否越界，是否是地图0，是否走过了
            {
                h.pre=e-1;//指向他的前驱
                vis[h.x][h.y]=1;//标记，表示走过了
                queue[f++]=h;//入队
            }
        }
    }
    return -1;//返回，-1表示不能走到终点
}
int main()
{
    int i,j;
    memset(vis,0,sizeof(vis));//vis数组变为0
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            scanf("%d",&map[i][j]);
    int res=bfs();
    printf("%d\n",res);//输出最大步数
    return 0;
}
