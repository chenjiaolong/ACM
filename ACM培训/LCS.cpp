#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1000][1000];
int main()
{
    char str[1000],str2[1000];
    while(~scanf("%s%s",str,str2))
    {
        for(int i=0; i<1000; i++)
            dp[i][0]=0;
        for(int j=0; j<1000; j++)
            dp[0][j]=0;
        for(int i=1; i<=strlen(str); i++)
            for(int j=1; j<=strlen(str2); j++)
            {
                if(str[i-1]==str2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        printf("%d\n",dp[strlen(str)][strlen(str2)]);
    }
    return 0;
}

