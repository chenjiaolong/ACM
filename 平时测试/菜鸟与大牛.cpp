// csu 1022
// http://acm.csu.edu.cn/OnlineJudge/problem.php?id=1022
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int N;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d", &N);
        int dp[120][1010] = {0};
        for(int i=1; i<=N; i++)
            for(int j= N - i + 1; j< N + i; j++)
                scanf("%d",&dp[i][j]);
        for(int i=N-1; i>=1; i--)
            for(int j=N - i + 1; j< N + i; j++)
                dp[i][j]=max(max(dp[i+1][j],dp[i+1][j+1]), dp[i + 1][j - 1])+dp[i][j];
        printf("%d\n",dp[1][N]);
    }
    return 0;
}

