// 1073 Duplicate Numbers
// http://www.ifrog.cc/acm/problem/1073
#include<map>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 1e5 + 10;

map<int, int>mp;
int ans[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        int cur = 0;
        mp.clear();
        int temp;
        bool flag = false;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &temp);
            mp[temp]++;
            if(mp[temp] == 2)
            {
                ans[cur++] = temp;
                flag = true;
            }
        }
        if(!flag)
        {
            puts("none");
            continue;
        }
        sort(ans, ans + cur);
        for(int i = 0; i < cur; i ++)
            printf("%d%c", ans[i], i == cur - 1 ? '\n' : ' ');
    }
    return 0;
}

