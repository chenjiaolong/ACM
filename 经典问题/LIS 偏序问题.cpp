// poj 1361 Bridging signals(һάƫ��)
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

// poj 1065 Wooden Sticks(��άƫ��)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<functional>

#define l first
#define w second

using namespace std;

const int maxn = 5005;

int dp[maxn];// ʵ����һ��ջ
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
        memset(dp, -1, sizeof(dp));// ���Խ��丳ֵΪ-1Ȼ������lower_boundʵ�ֲ��Ҳ�������һ��-1��λ�ñ���ջ��
        for(int i = 1; i <= n; i ++)
            *lower_bound(dp, dp + n, sticks[i].w, greater<int>()) = sticks[i].w;//�ҵ���һ��<=w[i]��λ�ò��ı���ֵ
        printf("%d\n", lower_bound(dp, dp + n, -1, greater<int>()) - dp);// ��һ��<=-1��λ�ñ���ջ��top
    }
    return 0;
}
