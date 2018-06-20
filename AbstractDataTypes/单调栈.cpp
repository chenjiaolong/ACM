// scu 4488 king's trouble II
#include<queue>
#include<stack>
#include<vector>
#include<math.h>
#include<cstdio>
#include<numeric>//STL数值算法头文件
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<functional>//模板类头文件
using namespace std;

const int INF=1e9+7;
const int maxn=1010;
typedef long long ll;


//单调栈
//先做 poj 2559后再看单调栈可能会好理解一点
int a[1010][1010];
struct node
{
    int idx,num;//下标和延伸值
};
int main()
{
    int t;
    while(~scanf("%d",&t))
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j])
                    a[i][j]+=a[i-1][j];
            }
            a[i][m+1]=-1;
        }
        int ans=-1;
        for(int i=1; i<=n; i++)
        {
            int top=0;
            node vis[100010];
            for(int j=1; j<=m+1; j++)
            {
                if(top==0)
                    vis[top].idx=j,vis[top++].num=1;
                else
                {
                    // printf("top=%d\n",top);
                    int v=vis[top-1].idx,cont=0;
                    while(top>0&&a[i][v]>=a[i][j])
                    {
                        cont+=vis[top-1].num;
                        if(cont>=a[i][v])
                            ans=max(ans,a[i][v]);
                        top--;
                        v=vis[top-1].idx;
                    }
                    vis[top].idx=j,vis[top++].num=cont+1;
                   // printf("vis[top].idx=%d vis[top].num=%d\n",vis[top-1].idx,vis[top-1].num);
                }
            }
        }
        printf("%d\n",ans);
    }
}
