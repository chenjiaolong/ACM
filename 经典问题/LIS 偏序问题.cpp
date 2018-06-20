// poj 1361 Bridging signals(一维偏序)
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//
//#define INF 0x3f3f3f3f
//
//using namespace std;
//
//const int maxn = 4e4 + 100;
//int dp[maxn], num[maxn];
//int main()
//{
//    int n, p;
//    scanf("%d", &n);
//    while(n--)
//    {
//        scanf("%d", &p);
//        for(int i = 1; i <= p; i ++)
//            scanf("%d", num + i);
//        memset(dp, INF, sizeof(dp));
//        for(int i = 1; i  <= p; i ++)
//            *lower_bound(dp, dp + p, num[i]) = num[i];
//        printf("%d\n", lower_bound(dp, dp + p, INF) - dp);
//    }
//    return 0;
//}

// poj 1065 Wooden Sticks(二维偏序)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<functional>

#define l first
#define w second

using namespace std;

const int maxn = 5005;

int dp[maxn];// 实质是一个栈
pair<int, int>sticks[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%d%d", &sticks[i].l, &sticks[i].w);
        sort(sticks + 1, sticks + n + 1);
        memset(dp, -1, sizeof(dp));// 可以将其赋值为-1然后利用lower_bound实现查找操作，第一个-1的位置便是栈顶
        for(int i = 1; i <= n; i ++)
            *lower_bound(dp, dp + n, sticks[i].w, greater<int>()) = sticks[i].w;//找到第一个<=w[i]的位置并改变其值
        printf("%d\n", lower_bound(dp, dp + n, -1, greater<int>()) - dp);// 第一个<=-1的位置便是栈的top
    }
    return 0;
}
