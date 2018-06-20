//#include<iostream>
//#include<cstdio>
//#include<memory.h>
//using namespace std;
//bool dp[10001][101];//每次存放余数 余数的情况一共有101种
//int a[10001]; //dp方程:dp[i-1][j]到dp[i][]是如何变化的，这个题目好好的利用了100这个数，去看起余数，这样的就刚好是记录路径的dp了把中见过程都保存下来了。
//   //余数为j的时候有两种情况，可以加上括号减去当前的数，然后如果为附属直接转化为正数
//   //原来也做了不少这样的题目。老是不太懂，以后还是要继续多做练习。
//   //最后只要看dp[n][0]处是否存在这种情况，若存在，表示余数为0的情况出现即除尽
//int main()
//{
//    int i, j, n, k, t, r, temp;
//    while (scanf("%d%d", &n, &k) != EOF)
//    {
//        for (i = 1; i <= n; i++)
//        {
//            scanf("%d", &a[i]);
//            while (a[i] < 0)//如果是负数变成正数
//                a[i] += k;
//            a[i] = a[i] % k;
//        }
//        memset(dp, 0, sizeof(dp));
//        dp[1][a[1]] = 1;//表示对于输入的第一个数对于k来说余数r这种情况存在如果是0处，那么代表正好相除
//        for (i = 2; i <= n; i++)
//            for (j = 0; j <= k; j++)
//                if (dp[i - 1][j])//转移方程
//                {
//                    dp[i][(j + a[i]) % k] = 1;
//                    temp = j - a[i];
//                    while (temp < 0) temp += k;
//                    dp[i][temp] = 1;
//                }
//        if (dp[n][0])
//            printf("Divisible\n");
//        else
//            printf("Not divisible\n");
//    }
//    return 0;
//}

//#include <iostream>
//#include <cstring>
//#include <cstdio>
//#include <cmath>
//#include <algorithm>
//using namespace:: std;
//#define maxn 108
//int n, K;
//int  a[maxn*maxn];
//bool dp[2][maxn<<1];
//int main()
//{
//    while( ~scanf ("%d%d", &n, &K) )
//    {
//        for ( int i(0); i<n; ++i )
//            scanf ("%d", a+i);
//        memset(dp,0, sizeof(dp));
//        int cnt = 1;
//        dp[1][ a[0]%K+ 100 ] = true;
//        for ( int i=1; i<n; ++i )
//        {
//            cnt ^= 1;
//            memset(dp[cnt], 0, sizeof dp[cnt]);
//            for ( int j=0; j<K+100; ++j )
//                if(dp[cnt^1][j])
//                {
//                    dp[cnt][(j-100+a[i])%K+100] = true;
//                    dp[cnt][(j-100-a[i])%K+100] = true;
//                }
//        }
//        puts(dp[n&1][100]? "Divisible": "Not divisible");
//    }
//};

#include<iostream>
using namespace std;
int dp[10010][110];
int x[10010];
int n,k;
int solve()
{
    dp[1][(x[1]%k+k)%k]=1;  // 注意防止负数的处理方式
    for(int i=2; i<=n; i++)
        for(int j=0; j<k; j++)
            dp[i][j]=dp[i-1][((j-x[i])%k+k)%k]||dp[i-1][((j+x[i])%k+k)%k];  // 注意防止负数的处理方式
    return dp[n][0];
}
int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++)
        cin>>x[i];
    if(solve())
        cout<<"Divisible"<<endl;
    else
        cout<<"Not divisible"<<endl;
    return 0;
}
