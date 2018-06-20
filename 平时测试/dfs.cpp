//POJ 1321 ÆåÅÌÎÊÌâ
#include<cstdio>
#include<cstring>

int n,m,ans,num;
char map[10][10];
int vis[10];
void dfs(int cur)
{
    if(num==m)
    {
        ans++;
        return;
    }
    if(cur>=n)return;
    for(int i=cur; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(map[i][j]=='#'&&!vis[j])
            {
                vis[j]=1;
                num++;
                dfs(i+1);
                vis[j]=0;
                num--;
            }
        }
    return ;
}
int main()
{
    while(~scanf("%d%d",&n,&m)&&n!=-1)
    {
        ans=0;
        memset(vis,0,sizeof(vis));
        num=0;
        for(int i=0; i<n; i++)
            scanf("%s",map[i]);
        dfs(0);
        printf("%d\n",ans);
    }
}
