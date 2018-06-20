#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=110010;
char s[maxn],ss[maxn<<1];
int dp[maxn<<1];
int main()
{
    // bababaaba
    while(~scanf("%s",s+1))
    {
        int len=strlen(s+1);
        for(int i=1; i<=len; i++)
        {
            ss[i<<1]=s[i];
            ss[i<<1|1]='#';// ss[2*i+1]='#';
        }
        ss[0]='!';
        ss[1]='#';
        int n=(len+1)<<1;
        ss[n]='\0';
        printf("%s\n",ss);
        int MaxId=0,id=0,MaxL=0;
        for(int i=1; i<n; i++)
        {
            if(MaxId>i)
                dp[i]=min(dp[(id<<1)-i],MaxId-i);// 从之前保存dp[i]值的角度，节省时间复杂度
            else
                dp[i]=1;
            while(ss[i-dp[i]]==ss[i+dp[i]])
                dp[i]++;
            if(dp[i]+i>MaxId)
            {
                MaxId=dp[i]+i;
                id=i;
            }
            if(MaxL<dp[i])
                MaxL=dp[i];
            printf("MaxId=%2d id=%2d MaxL=%2d\n",MaxId,id,MaxL-1);
        }
        printf("%s\n",ss);
        printf(" ");
        for(int i=1; i<n; i++)
            printf("%d",dp[i]);
        printf("\n");
        printf("%d\n",MaxL-1);
    }
    return 0;
}
