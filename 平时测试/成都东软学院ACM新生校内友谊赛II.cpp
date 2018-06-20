// Infinite Sequence
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int main()
//{
//    long long a, b, c;
//    while(scanf("%lld%lld%lld",&a, &b, &c) != EOF)
//    {
//        if(c != 0)
//        {
//            if((b - a) % c == 0)
//            {
//                if((b - a) / c + 1 > 0) puts("YES");
//                else puts("NO");
//            }
//            else puts("NO");
//        }
//        else
//        {
//            if(a == b) puts("YES");
//            else puts("NO");
//        }
//
//    }
//    return 0;
//}

// Summer Camp
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int main()
//{
//    // freopen("Test.out", "w", stdout);
//    char str[1005];
//    int cur = 0;
//    for(int i = 1; i <= 370; i++)
//    {
//        int num = i;
//        int array[5] = {0}, digits = 0;
//        while(num)
//        {
//            array[digits++] = num % 10;
//            num /= 10;
//        }
//        for(int j = digits - 1; j >= 0; j--)
//            str[cur++] = array[j] + '0';
//    }
//    str[cur++] = '\0';
//    // puts(str);
//    int n;
//    while(scanf("%d", &n) != EOF)
//         printf("%c\n", str[n-1]);
//    return 0;
//}

// Restore Painting
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//    int n, a, b, c, d;
//    while(scanf("%d%d%d%d%d", &n, &a, &b, &c, &d) != EOF)
//    {
//        long long num = 0;
//        for(int i = 1; i <= n; i++)
//        {
//            int sum = a + b + i;
//            if(sum - (a + c) < 1 || sum - (a + c) > n) continue;
//            if(sum - (b + d) < 1 || sum - (b + d) > n) continue;
//            if(sum - (c + d) < 1 || sum - (c + d) > n) continue;
//            num ++;
//        }
//        printf("%lld\n", n * num);
//    }
//    return 0;
//}

// 哈密顿绕行世界问题
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int num[25][5];
//int tracert[25];
//bool vis[25];
//int m, count;
//void DFS(int cur, int cnt)
//{
//    if(cnt == 20)
//    {
//        if(tracert[20] == m)
//        {
//            printf("%d:  %d", count++, m);
//            for(int i = 1; i <= 20; i++)
//                printf(" %d", tracert[i]);
//            puts("");
//        }
//        return;
//    }
//    for(int i = 0; i < 3; i ++)
//        if(!vis[num[cur][i]])
//        {
//            vis[num[cur][i]] = true;
//            tracert[cnt + 1] = num[cur][i];
//            DFS(num[cur][i], cnt + 1);
//            vis[num[cur][i]] = false;
//        }
//}
//int main()
//{
//    for(int i = 1; i <= 20; i ++)
//        for(int j = 0; j < 3; j ++)
//            scanf("%d",&num[i][j]);
//    while(scanf("%d", &m) != EOF && m)
//    {
//        count = 1;
//        memset(tracert, 0, sizeof(tracert));
//        memset(vis, false, sizeof(vis));
//        tracert[0] = m;
//        DFS(m, 0);
//    }
//    return 0;
//}

// Little Artem and Dance
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int MAX_N = 1000010;
int n, q, one, two;
int ans[MAX_N];
inline int change(int x, int d)
{
    int res = ((x + d) % n + n) % n;
    if(res == 0) res = n;
    return res;
}
int main()
{
    while(scanf("%d%d", &n, &q) != EOF)
    {
        one = 1, two = 2;
        for(int i = 1; i <= q; i ++)
        {
            int t;
            scanf("%d", &t);
            if(t == 2)
            {
                if(one & 1)
                {
                    one = change(one, 1);
                    two = change(two, -1);
                }
                else
                {
                    one = change(one, -1);
                    two = change(two, 1);
                }
            }
            else
            {
                int a;
                scanf("%d", &a);
                one = change(one, a);
                two = change(two, a);
            }
        }
        for(int i = 1; i <= n - 1; i += 2)
        {
            // printf("one = %d, i = %d\n", one, i);
            ans[one] = i;
            one = change(one, 2);
        }
        for(int j = 2; j <= n; j += 2)
        {
            // printf("two = %d, j = %d\n", two, j);
            ans[two] = j;
            two = change(two, 2);
        }
        for(int i = 1; i <= n; i ++)
        printf("%d%c", ans[i], i == n? '\n' : ' ');
    }
    return 0;
}
