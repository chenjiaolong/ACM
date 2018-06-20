#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

int ans[1000],m,n,d,len;//len为sequence的长度，就是m-n+1
bool flag,vis[1001],composite[10000]= {1,1}; //flag用于判断是否生成anti-prime sequence

//筛选素数,composite[i]=1当且仅当i不是素数
void InitComposite()
{
    for(int i=2; i<1001; i++)
        if(!composite[i])
            for(int j=2; j*i<10000; j++)
                composite[i*j]=1;
    //for(int i=0; i<100; i++)cout<<i<<":"<<composite[i]<<" "<<endl;
}

//检查sum是否是composite number
bool CheckSum(int idx)
{
    int sum=ans[idx];
    for(int i=idx-1; i>-1&&i>idx-d; i--)
    {
        sum+=ans[i];
        if(!composite[sum])
            return 0;
    }
    return 1;
}

//depth记录当前有多少个数成功加入sequence
void DFS(int depth)
{
    //当depth大于len时，代表找到anti-prime sequence
    if(depth==len)
    {
        flag=1;
        return ;
    }
    for(int i=n; i<=m; i++)
        if(!vis[i])
        {
            ans[depth]=i;
            if(CheckSum(depth))
            {
                vis[i]=1;
                //ans中第depth个数已经确定，往depth+1处搜索
                DFS(depth+1);
                vis[i]=0;//不要漏了这个！！！
                if(flag)
                    return ;
            }
        }
    return ;
}

int main()
{
    InitComposite();
    while(scanf("%d%d%d",&n,&m,&d) && m)
    {
        memset(vis,0,sizeof(vis));
        len=m-n+1;
        flag=0;
        DFS(0);
        if(flag)
        {
            for(int i=0; i<len-1; i++)
                printf("%d,",ans[i]);
            printf("%d\n",ans[len-1]);
        }
        else puts("No anti-prime sequence exists.");
    }
    return 0;
}
