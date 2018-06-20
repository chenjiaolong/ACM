//#include<stdio.h>
//int main()
//{
//    int X,N,P,Y;
//    while(scanf("%d%d",&X,&N)!=EOF)
//    {
//        int i;
//        for(i=1;i<=N;i++)
//        {
//            scanf("%d%d",&P,&Y);
//            if(P==1)
//                X+=Y;
//            else if(P==2)
//                X-=Y;
//            else if(P==3)
//                X*=Y;
//            else if(P==4)
//                X/=Y;
//            X%=10007;
//        }
//        printf("%d",X%10007);
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int M,N;
//int map[1001][1001];//地图
//int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}}; //移动的四个方向
//typedef struct
//{
//    int x,y,step;//step是步数
//} node;
//node queue[1000010],s,g;//s是起始点，g是终点
//
//int bfs()
//{
//    int i;
//    s.x=M/2,s.y=N/2,s.step=0;
//    g.x=M-1,g.y=N-1;
//    int e=0,f=0;
//    queue[f++]=s;//入队
//    node t,h;
//    while(e<f)
//    {
//        t=queue[e++];//出队，e++
//        if(t.x==g.x&&t.y==g.y)
//            return t.step;
//        for(i=0; i<4; i++) //四个方向遍历
//        {
//            h.x=t.x+dir[i][0];
//            h.y=t.y+dir[i][1];
//            h.step=t.step+1;
//            if(h.x>=0&&h.y>=0&&h.x<M&&h.y<N&&map[h.x][h.y]==0)//检测是否越界，是否是地图0，是否走过了
//            {
//                map[h.x][h.y]=1;
//                queue[f++]=h;//入队
//            }
//        }
//    }
//    return -1;//返回，-1表示不能走到终点
//}
//int main()
//{
//    int i,j;
//
//    while(scanf("%d%d",&N,&M)!=EOF)
//    {
//        if(M==0&&N==0)
//            break;
//        for(i=0; i<M; i++)
//            for(j=0; j<N; j++)
//                scanf("%d",&map[i][j]);
//        int res=bfs();
//        printf("%d\n",res);//输出最大步数
//    }
//    return 0;
//}

#include<cstdio>
#include<cstring>
#include<iostream>
#define maxn 1001
using namespace std;
int xx[4]= {-1,1,0,0};
int yy[4]= {0,0,-1,1};
int n,m,map[maxn][maxn];
int sx,sy;
bool flag;
struct node
{
    int x,y,temp;
} q[maxn*maxn];
void bfs()
{
    struct node now,pre;
    int h=0,e=1;
    q[0].temp=0;
    q[0].x=sx;
    q[0].y=sy;
    while(h<e)
    {
        pre=q[h];
        //printf("%d %d\n",pre.x,pre.y);
        if(pre.x==n-1&&pre.y==m-1)
        {
            printf("%d\n",pre.temp);
            flag=true;
            return ;
        }
        for(int i=0; i<4; i++)
        {
            now.x=pre.x+xx[i];
            now.y=pre.y+yy[i];
            now.temp=pre.temp+1;
            if(now.x>=0&&now.x<n&&now.y>=0&&now.y<m&&map[now.x][now.y]==0)
            {
                map[now.x][now.y]=1;
                q[e++]=now;
            }
        }
        h++;
    }
}
int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        //memset(map,0,sizeof(map));这道题注意之处，用memset初始化就要超时，memset初始化比for循环初始化的更耗时，这题的数据非常强，不能用memset初始化；请大家注意
        if(n==0&&m==0)
            break;
        flag=false;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                scanf("%d",&map[i][j]);
        sx=n/2;
        sy=m/2;
        map[sx][sy]=1;
        if(sx==n-1&&sy==m-1)
        {
            printf("0\n");
            continue;
        }
        if(map[n-1][m-1]==1)
        {
            printf("-1\n");
            continue;
        }
        bfs();
        if(!flag)
            printf("-1\n");
    }
    return 0;
}
