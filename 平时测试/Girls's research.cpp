// hdu 3824 Girls' research
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

const int maxn = 2e5 + 100;
char str[maxn], ss[maxn << 1];
int dp[maxn << 1];
int Min(int a, int b)
{
    return a < b ? a : b;
}
int main()
{
    char ch[5];
    while(scanf("%s%s", ch, str) != EOF)
    {
        ss[0] = '!';
        ss[1] = '#';
        int len = strlen(str);
        for(int i = 0; i < len; i ++)
        {
            ss[(i << 1) + 2] = str[i];
            ss[(i << 1) + 3] = '#';
        }
        for(int i = 0; i < len; i ++)
        {
            if(str[i] >= ch[0]) str[i] = str[i] - ch[0] + 'a';
            else str[i] = 'z' - (ch[0] - str[i] - 1);
        }
        //puts(str);
        len = (len << 1) + 2;
        ss[len] = '\0';
        int MaxL = 0, MaxId = 0, id = 0;
        int fir = -1, sec = -1;
        //puts(ss);
        bool flag = false;
        for(int i = 1; i < len; i ++)
        {
            if(MaxId > i) dp[i] = Min(dp[(id << 1) - i], MaxId - i);
            else dp[i] = 1;
            while(ss[i + dp[i]] == ss[i - dp[i]]) dp[i]++;
            if(dp[i] + i > MaxId)
            {
                MaxId = dp[i] + i;
                id = i;
            }
            if(MaxL < dp[i] && dp[i] > 2)
            {
                MaxL = dp[i];
                fir = (i - MaxL + 1) / 2;
                sec = (i + MaxL - 3) / 2;
            }

        }
        if(fir != -1)
        {
            printf("%d %d\n", fir, sec);
            for(int i = fir; i <= sec; i ++)
                printf("%c", str[i]);
            puts("");
        }
        else puts("No solution!");
    }
    return 0;
}

