//N皇后问题
//#include<stdio.h>
//#include<string.h>
//
//int N,tmp;
//int map[11];
//int cnt[11];
//void DFS(int cur)
//{
//    int i,j,flag;
//    if(cur==N+1)
//    {
//        tmp++;
//        return;
//    }
//    else
//    {
//        for(i=1; i<=N; ++i)
//        {
//            map[cur]=i;
//            flag=1;
//            for(j=1; j<cur; ++j)
//                if(map[j]==i||i-cur==map[j]-j||i+cur==map[j]+j)   // 注：1、i=map[j]  2、不在同一条斜线的两点的含义是行标到对角线的的距离不相等
//                {
//                    flag=0;
//                    break;
//                }
//            if(flag)
//                DFS(cur+1);
//        }
//    }
//}
//int main()
//{
//    memset(cnt,-1,sizeof(cnt));
//    while(~scanf("%d",&N)&&N)
//    {
//        memset(map,0,sizeof(map));
//        if(cnt[N]==-1)
//        {
//            tmp=0;
//            DFS(1);
//            printf("%d\n",cnt[N]=tmp);
//            continue;
//        }
//        else
//            printf("%d\n",cnt[N]);
//    }
//    return 0;
//}

//Knight Moves
//#include<stdio.h>
//#include<string.h>
//#define MAX 100000
//int dir[8][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
//int n,l;、
//int map[320][320];
//int x0,y0,x1,y1;
//typedef struct
//{
//    int x;
//    int y;
//    int step;
//}node;
//node queue[8*MAX],s,d;
//int BFS()
//{
//    int e=0,f=0;
//    s.x=x0,s.y=y0,s.step=0;
//    d.x=x1,d.y=y1;
//    queue[f++]=s;
//    node t,h;
//    while(e<=f)
//    {
//        t=queue[e++];
//        if(t.x==d.x&&t.y==d.y)
//            return t.step;
//        int i;
//        for(i=0;i<8;i++)
//        {
//            h.x=t.x+dir[i][0];
//            h.y=t.y+dir[i][1];
//            h.step=t.step+1;
//            if(h.x>=0&&h.x<l&&h.y>=0&&h.y<l&&map[h.x][h.y]==0)
//            {
//                map[h.x][h.y]=1;
//                queue[f++]=h;
//            }
//        }
//    }
//    return 0;
//}
//int main()
//{
//    int i;
//    while(~scanf("%d",&n))
//    {
//        for(i=1;i<=n;i++)
//        {
//            memset(map,0,sizeof(map));
//            scanf("%d",&l);
//            scanf("%d%d",&x0,&y0);
//            scanf("%d%d",&x1,&y1);
//            printf("%d\n",BFS());
//        }
//    }
//}

//Bovine Math Geniuses
//#include<stdio.h>
//#include<string.h>
//int flag[1000000];
//int main()
//{
//    int i,cnt,num,temp;
//    while(~scanf("%d",&num))
//    {
//        memset(flag,-1,sizeof(flag));
//        cnt=0;
//        for(i=9999; i>=0; i--)
//        {
//            temp=(num/10)%10000;
//            num=(temp*temp)%1000000;
//            if(flag[num]==-1)
//            {
//                flag[num]=cnt;
//                cnt++;
//            }
//            else
//            {
//                printf("%d %d %d\n",num,cnt-flag[num],cnt+1);
//                break;
//            }
//        }
//    }
//    return 0;
//}

//Tempter of the Bone
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<math.h>
//#define MAX 10
//char map[MAX][MAX];
//int dir[4][2]= {{-1,0},{0,1},{1,0},{0,-1}};
//int N,M,T,flag=0;
//int sx,sy,dx,dy;
//void DFS(int x,int y,int step)
//{
//    if(step==T)
//    {
//        if(x==dx&&y==dy)
//        {
//            flag=1;
//            return;
//        }
//        return;
//    }
//    int i,X,Y;
//    for(i=0; i<4; i++)
//    {
//        X=x+dir[i][0];
//        Y=y+dir[i][1];
//        if(X>=0&&X<M&&Y>=0&&Y<N&&map[Y][X]!='X')
//        {
//            map[Y][X]='X';
//            DFS(X,Y,step+1);
//            if(flag)
//                return;
//            map[Y][X]='.';
//        }
//
//    }
//
//}
//int main()
//{
//    int i,j;
//    while(~scanf("%d%d%d",&N,&M,&T)&&(N+M+T))
//    {
//        flag=0;
//        for(i=0; i<N; i++)
//        {
//            scanf("%s",map[i]);
//            for(j=0; j<M; j++)
//            {
//                if(map[i][j]=='S')
//                {
//                    sy=i;
//                    sx=j;
//                    map[i][j]='X';
//                }
//                if(map[i][j]=='D')
//                {
//                    dy=i;
//                    dx=j;
//                }
//            }
//        }
//        if(T-abs(dx-sx)-abs(dy-sy)&1)
//        {
//            printf("NO\n");
//            continue;
//        }
//        DFS(sx,sy,0);
//        if(flag)
//            printf("YES\n");
//        else
//            printf("NO\n");
//    }
//    return 0;
//}

//放苹果
//#include<stdio.h>
//#include<string.h>
//int num[10][10]={0};
//int Digui(int m,int n)
//{
//    if(m==1||n==1)
//        return num[m][n]=1;
//    if(m<n)
//        return Digui(m,m);
//    if(m==n)
//        return 1+Digui(m,n-1);
//    if(m>n)
//        return Digui(m-n,n)+Digui(m,n-1);
//}
//int main()
//{
//    int t,M,N;
//    while(~scanf("%d",&t))
//    {
//        int i,j;
//        for(i=1; i<=t; i++)
//        {
//            scanf("%d%d",&M,&N);
//            printf("%d ",num[M][N]);
//            if(num[M][N])
//            {
//                printf("%d\n",num[M][N]);
//                continue;
//            }
//            printf("%d\n",num[M][N]=Digui(M,N));
//
//        }
//    }
//    return 0;
//}

//Red and Black
#include<stdio.h>
#include<string.h>
int H,W;
int sy,sx;
int cnt;
char map[30][30];
int dir[4][2]= {{-1,0},{0,1},{1,0},{0,-1}};
int DFS(int x,int y)
{
    int i,X,Y;
    for(i=0; i<4; i++)
    {
        X=x+dir[i][0];
        Y=y+dir[i][1];
        if(X>=0&&X<H&&Y>=0&&Y<W&&map[X][Y]!='#')
        {
            map[X][Y]='#';
            cnt++;
            DFS(X,Y);
        }
    }
    return cnt;
}
int main()
{
    int i,j;
    while(~scanf("%d%d",&W,&H)&&(W+H))
    {
        for(i=0; i<H; i++)
        {
            scanf("%s",map[i]);
            for(j=0; j<W; j++)
            {
                if(map[i][j]=='@')
                {
                    sx=i;
                    sy=j;
                    map[i][j]='#';
                }
            }
        }
        cnt=1;
        printf("%d\n",DFS(sx,sy));
    }
    return 0;
}
