//ACM 2265 ����1~N(1<=N<=9)���ֵ���������е����������
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int n,ans[15];
bool vis[15];//ֻ�ܴ�false��0����true��1������״̬�����ݣ��ŵ㣺��ʡ�ռ�
void DFS(int cur)
{
    if(cur==n)
    {
        int i;
        for(i=0; i<n; i++)
            printf("%d%c",ans[i],i==n-1?'\n':' ');
    }
    else
    {
        int i;
        for(i=1; i<=n; i++)
            if(vis[i]==0)
            {
                vis[i]=1;
                // printf("Before cur=%d\n",cur);
                ans[cur]=i;
                DFS(cur+1);
                // printf("After i=%d,cur=%d\n",i,cur);
                vis[i]=0;
            }
    }
}
int main()
{
    // freopen("test.in", "w", stdout);
    while(~scanf("%d",&n))//while(scanf("%d",&n)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        DFS(0);
    }
    return 0;
}
/*#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int n,res[15];
int cnt=0;
bool vis[15];//ֻ�ܴ�false��0����true��1������״̬�����ݣ��ŵ㣺��ʡ�ռ�
void DFS()
{
    if(cnt==n)
    {
        int i;
        for(i=1; i<=n; i++)
            printf("%d%c",res[i],i==n?'\n':' ');
        return ;
    }
    else
    {
        int i;
        for(i=1; i<=n; i++)
            if(vis[i]==0)
            {
                vis[i]=1;
                printf("Before cnt=%d\n",cnt);
                res[++cnt]=i;
                DFS();
                printf("After i=%d,cnt=%d\n",i,cnt);
                cnt--;
                vis[i]=0;
            }
    }
}
int main()
{
    while(~scanf("%d",&n))//while(scanf("%d",&n)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        memset(res,0,sizeof(res));
        DFS();
    }
    return 0;
}*/
