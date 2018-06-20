#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 100;
vector<int>E[maxn];
int dfn[maxn], low[maxn], tot, n, ans, vis[maxn];
stack<int>s;

void Tarjan(int x)
{
   low[x] = dfn[x] = ++ tot;
   s.push(x), vis[x] = 1;
   for(int i = 0; i < E[x].size(); i ++)
   {
       int v = E[x][i];
       if(!dfn[v])
       {
           Tarjan(v);
           low[x] = min(low[x], low[v]);
       }
       else if(vis[v]) low[x] = min(low[x], dfn[v]);
   }
   if(low[x] == dfn[x])
   {
       int cnt = 0;
       while(1)
       {
           int now = s.top();
           s.pop();
           vis[x] = 0;
           cnt ++;
           if(now == x) break;
       }
       if(cnt > 1) ans = min(ans, cnt);
   }
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; i ++)
            vis[i] = low[i] = dfn[i] = 0, E[i].clear();
		while(!s.empty()) s.pop();
        ans = maxn;
        tot = 0;
        for(int i = 1; i <= n; i ++)
        {
            int x;
            scanf("%d", &x);
            E[i].push_back(x);
        }
        for(int u = 1; u <= n; u ++)
            if(!dfn[u]) Tarjan(u);
        printf("%d\n", ans);
    }
    return 0;
}
