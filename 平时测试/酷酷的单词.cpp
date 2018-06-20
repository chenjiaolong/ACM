#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    int n;
    int Case = 1;
    while(scanf("%d", &n) != EOF)
    {
        char str[35];
        int ans = 0;
        while(n --)
        {
            scanf("%s", str);
            int len = strlen(str);
            int cnt[30] = {0};
            bool vis[30] = {0};
            if(len == 1) continue;
            for(int i = 0; i < len; i ++)
            {
                cnt[str[i]-'a'] ++;
                vis[str[i] - 'a'] = true;
            }
            bool flag = false;
            bool mark[35] = {0};
            for(int i = 0; i < 26; i ++)
                if(vis[i])
                {
                    if(mark[cnt[i]])
                    {
                        flag = true;
                        break;
                    }
                    mark[cnt[i]] = true;
                }
            if(!flag) ans ++;

        }
        printf("Case %d: %d\n", Case++, ans);
    }
    return 0;
}
