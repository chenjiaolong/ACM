// 淘宝流量分配
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 1e4 + 5;
//int main()
//{
//    int array[maxn];
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        for(int i = 1; i <= n; i++)
//            scanf("%d", &array[i]);
//        int dp[maxn];
//        dp[0] = 0;
//        dp[1] = array[1];
//        int i;
//        for(i = 2; i <= n; i++)
//            dp[i] = max(dp[i - 1], dp[i - 2] + array[i]);
//        printf("%d\n", max(dp[n], dp[n-1]));
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const long long mod = 1 << 32;
//int main()
//{
//    int n,m;
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        if(n == 1) printf("%d\n", m);
//        else if(n == 2) printf("%d\n", m * m);
//        else if(n == 3) printf("%d\n", m * m * m);
//        else if(n == 4) printf("%d\n", m * m * m * m - m * m + m);
//        else printf("%d\n", m * m * m * m * m - m * m * m + m);
//    }
//
//    return 0;
//}

// 腾讯的一笔画游戏
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<math.h>
//const double PI = acos(-1.0);
//using namespace std;
//int main()
//{
//    int n,k;
//    double L;
//    while(scanf("%d%d%lf", &n, &k, &L) != EOF)
//    {
//        double alpha = ((n - 2) * 180) / n * (PI / 180);
//        double ans = (n - 1) * L;
//        for(int i = 1; i <= k; i ++)
//        {
//            ans += L /2;
//            L = sqrt(2 * (L / 2) * (L / 2) - 2 * (L / 2) * (L / 2) * cos(alpha));
//            ans += (n - 1) * L;
//        }
//        printf("%.7f\n", ans);
//    }
//    return 0;
//}

