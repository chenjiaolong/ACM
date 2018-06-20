// hdu 5422 Rikka with Graph
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

int main()
{
    int n, m;
    int map[105][105];
    while(scanf("%d%d", &n,&m) != EOF)
    {
        memset(map, 0, sizeof(map));
        int u,v;
        bool flag = false;
        for(int i = 0; i < m; i ++)
        {
            scanf("%d%d", &u,&v);
            if((u == 1 && v == n)|| (u == n && v == 1)) flag = true;
            if(u != v && map[u][v] == 0)
            map[u][v] = map[v][u] = 1;
        }
        if(!flag) printf("1 1\n");
        else printf("1 %d\n", n * (n - 1)/ 2);
    }
    return 0;
}
