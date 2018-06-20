// nsu 1084
// hdu 1466
/**
 *n��ֱ��ʱ������������浽arr[n]�С�
 *�ֳ����飬ѡ����һ��A��Ϊ������Aƽ�еĶ���A�飬�����ķŵ�B�飬
 *�򽻵���Ϊa * b + arr[b];
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    bool dp[25][210] = {0};// ��Ƿ�ĳ�̶ֳ��Ͼ߱����������
    for(int i = 0; i <= 20; i ++)
    {
        dp[i][0] = true;// 0һ���У�������
        for(int j = 1; j < i; j ++)
        {
            int p = i - j;
            int maxn = p * (p - 1) / 2;
            for(int k = 0; k <= maxn; k ++)
                if(dp[p][k]) dp[i][p * j + k] = true;
        }
    }
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int maxn = n * (n - 1) / 2;
        printf("0");
        for(int i = 1; i <= maxn; i ++)
            if(dp[n][i]) printf(" %d", i);
        puts("");
    }
    return 0;
}

