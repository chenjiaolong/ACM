// ��̬�滮��dp[i][j]��ʾԭ��source[0-i)��Ŀ��target[0-j)�ı༭����
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;
const int maxn = 1e3 + 100;
int dp[maxn][maxn];

int EditDistance(char *pSource, char *pTarget)
{
    int srcLength = strlen(pSource);
    int targetLength = strlen(pTarget);
    // �߽�dp[i][0] = i, dp[0][j] = j;
    for(int i = 1; i <= srcLength; i ++) dp[i][0] = i;
    for(int j = 1; j <= targetLength; j ++) dp[0][j] = j;
    for(int i = 1; i <= srcLength; i ++)
        for(int j = 1; j <= targetLength; j ++)
        {
            if(pSource[i - 1] == pTarget[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    return dp[srcLength][targetLength];
}

int main()
{
    char source[maxn] = "ALGORITHM";
    char target[maxn] = "ALTRUISTIC";
    puts(source);
    puts(target);
    memset(dp, 0, sizeof(dp));
    printf("%d\n",EditDistance(source, target));
    return 0;
}
