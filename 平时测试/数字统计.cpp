#include<stdio.h>
#include<time.h>
long long cnt[15] = {0};
void Census(int n)
{
    for(int i= 1; i <= n; i++)
    {
        int temp = i;
        while(temp)
        {
            cnt[temp%10]++;
            temp/=10;
        }
    }
}
int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int n;
    while(~scanf("%d",&n))
    {
        for(int i = 0; i < 10; i++)
            cnt[i] = 0;
        Census(n);
        for(int i = 0; i < 10; i++)
            printf("%lld\n",cnt[i]);
        printf("耗时：%d\n",clock()/CLOCKS_PER_SEC);//cmd配套使用时间会更精确 @echo off\r echo 数据|程序名.exe
    }
}
