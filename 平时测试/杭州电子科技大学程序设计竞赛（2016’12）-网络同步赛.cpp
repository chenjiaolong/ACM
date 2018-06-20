// 1001 BigZhuGod的粉丝
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//using namespace std;
//
//const int maxn = 1e3 + 10;
//char str[maxn];
//
//int main()
//{
//    int T;
//    scanf("%d", &T);
//    gets(str);
//    while(T--)
//    {
//        gets(str);
//        int len = strlen(str);
//        if(str[len - 1] == '?')
//        {
//            puts("-_-");
//            continue;
//        }
//        if(str[len - 1] == '.')
//        {
//            puts("Orz");
//            continue;
//        }
//        int cnt = 0;
//        for(int i = len - 1; i >= 0; i --)
//        {
//            if(str[i] == '!') cnt++;
//            else break;
//        }
//        printf("W");
//        for(int i = 0; i < cnt; i ++)
//            putchar('o');
//        puts("w!");
//    }
//    return 0;
//}

// 1007 反差萌
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//using namespace std;
//
//const int maxn = 2e3 + 100;
//int M[maxn];
//
//int main()
//{
//    int T, N;
//    scanf("%d", &T);
//    while(T--)
//    {
//        scanf("%d", &N);
//        int n = N * 2;
//        for(int i = 0; i < n; i ++)
//            scanf("%d", &M[i]);
//        sort(M, M + n);
//        int ans = 0;
//        for(int i = 0; i < (n + 1) / 2; i ++)
//            ans += abs(M[i] - M[n - 1 - i]);
//        printf("%d\n", ans);
//    }
//    return 0;
//}

// 1004 我要拿走你的蜡烛
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        char str[15] = {'\0'};
        int Fire = 0, Ice = 0, Dog = 0, Evolved = 0;
        for(int i = 0; i < n; i ++)
        {
            scanf("%s", str);
            if(str[0] == 'F') Fire ++;
            else if(str[0] == 'I') Ice ++;
            else if(str[0] == 'D') Dog ++;
            else Evolved ++;
        }
        bool flag = false;
        for(int i = 0; i <= Fire; i ++)
            for(int j = 0; j <= Ice; j ++)
                for(int k = 0; k <= Dog; k ++)
                    for(int l = 0; l <= Evolved; l ++)
                        if(4 * i + 2 * j + 2 * k + 4 * l <= 10 && 6 * i + 3 * j  + k * (i + j) + 2 * l * (i + j)>= m)
                        {
                            flag = true;
                            break;
                        }
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}

