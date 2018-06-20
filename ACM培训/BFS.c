//ACM 2325 �Թ����⣺һ����ά�����ʾ�Թ���int maze[5][5]={{0,1,0,0,0},{0,1,0,1,0},{0,0,0,0,0},{0,1,1,1,0},{0,0,0,1,0}};���е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·��ֻ�ܺ����߻������ߣ�����б���ߣ�Ҫ�������ҳ������Ͻǵ����½ǵ����·�ߡ�
//���룺һ��5 �� 5�Ķ�ά���飬��ʾһ���Թ������ݱ�֤��Ψһ�⡣
//��������Ͻǵ����½ǵ����·������ͨ��·���������ʾ��
#include<stdio.h>
#include<string.h>
int map[10][10];//��ͼ
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};//�ƶ����ĸ�����
int vis[10][10];//��ǵ�ͼ
typedef struct
{
    int x,y,step,pre;//step�ǲ�����pre��ǰ��
}node;
node queue[100000],s,g;//s����ʼ�㣬g���յ�

void Print(int i)//�ݹ�,i��ǰ��
{
    if(queue[i].pre!=-1)//��ʼ���ǰ����-1
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
    queue[f++]=s;//���
    node t,h;
    while(e<f)
    {
        t=queue[e++];//���ӣ�e++
        if(t.x==g.x&&t.y==g.y)//�յ�ļ��
        {
            printf("(0, 0)\n");
            Print(t.pre);//�����¼�ĵ�
            printf("(4, 4)\n");
            return t.step;//���������
        }
        for(i=0;i<4;i++)//�ĸ��������
        {
            h.x=t.x+dir[i][0];
            h.y=t.y+dir[i][1];
            h.step=t.step+1;
            if(h.x>=0&&h.y>=0&&h.x<5&&h.y<5&&map[h.x][h.y]==0&&vis[h.x][h.y]==0)//����Ƿ�Խ�磬�Ƿ��ǵ�ͼ0���Ƿ��߹���
            {
                h.pre=e-1;//ָ������ǰ��
                vis[h.x][h.y]=1;//��ǣ���ʾ�߹���
                queue[f++]=h;//���
            }
        }
    }
    return -1;//���أ�-1��ʾ�����ߵ��յ�
}
int main()
{
    int i,j;
    memset(vis,0,sizeof(vis));//vis�����Ϊ0
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            scanf("%d",&map[i][j]);
    int res=bfs();
    printf("%d\n",res);//��������
    return 0;
}
