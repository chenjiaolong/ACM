//#include<iostream>
//#include<cstdio>
//#include<memory.h>
//using namespace std;
//bool dp[10001][101];//ÿ�δ������ ���������һ����101��
//int a[10001]; //dp����:dp[i-1][j]��dp[i][]����α仯�ģ������Ŀ�úõ�������100�������ȥ���������������ľ͸պ��Ǽ�¼·����dp�˰��м����̶����������ˡ�
//   //����Ϊj��ʱ����������������Լ������ż�ȥ��ǰ������Ȼ�����Ϊ����ֱ��ת��Ϊ����
//   //ԭ��Ҳ���˲�����������Ŀ�����ǲ�̫�����Ժ���Ҫ����������ϰ��
//   //���ֻҪ��dp[n][0]���Ƿ������������������ڣ���ʾ����Ϊ0��������ּ�����
//int main()
//{
//    int i, j, n, k, t, r, temp;
//    while (scanf("%d%d", &n, &k) != EOF)
//    {
//        for (i = 1; i <= n; i++)
//        {
//            scanf("%d", &a[i]);
//            while (a[i] < 0)//����Ǹ����������
//                a[i] += k;
//            a[i] = a[i] % k;
//        }
//        memset(dp, 0, sizeof(dp));
//        dp[1][a[1]] = 1;//��ʾ��������ĵ�һ��������k��˵����r����������������0������ô�����������
//        for (i = 2; i <= n; i++)
//            for (j = 0; j <= k; j++)
//                if (dp[i - 1][j])//ת�Ʒ���
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
    dp[1][(x[1]%k+k)%k]=1;  // ע���ֹ�����Ĵ���ʽ
    for(int i=2; i<=n; i++)
        for(int j=0; j<k; j++)
            dp[i][j]=dp[i-1][((j-x[i])%k+k)%k]||dp[i-1][((j+x[i])%k+k)%k];  // ע���ֹ�����Ĵ���ʽ
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
