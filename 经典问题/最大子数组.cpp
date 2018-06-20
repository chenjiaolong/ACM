#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
// ���η���T(O) = nlogn
int MaxAddSub(int *array, int from, int to)
{
    if(from == to)
        return array[from];
    int middle = (from + to) >> 1;
    // ���߲��������������
    int m1 = MaxAddSub(array, from, middle);
    // �Ұ�߲��������������
    int m2 = MaxAddSub(array, middle + 1, to);
    // �����ڷֽ��: �����������׺������������ǰ׺�ĺ�
    // �ӷֽ����ǰɨ�����ɨ
    int left = array[middle], now = array[middle];
    for(int i = middle - 1; i >= from; i--)
    {
        now += array[i];
        left = max(now, left);
    }
    int right = array[middle + 1];
    now = array[middle + 1];
    for(int i = middle + 2; i <= to; i++)
    {
        now += array[i];
        right = max(now, right);
    }
    int m3 = left + right;
    return max(max(m1, m2), m3);
}
int main()
{
    int array[9]= {1, -2, 3, 10, -4, 7, 2, -5};
    int ans = MaxAddSub(array, 0, 7);
    printf("%d\n", ans);
    return 0;
}

// hdu 1003 Max Sum
// ��̬�滮��˼·:dp[i]��array[i]��β�������к�����������
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    int T;
//    while(~scanf("%d", &T))
//    {
//        for(int t = 1; t <= T; t ++)
//        {
//            int N;
//            scanf("%d", &N);
//            int array[100005];
//            int dp[100005];
//            for(int i = 0; i < N; i ++)
//                scanf("%d",&array[i]);
//            dp[0] = array[0];
//            int st = 0, en = 0;
//            int fir = 0, sec = 0;
//            int max = -1 << 29;
//            for(int i = 0; i < N; i ++)
//            {
//                if(dp[i - 1] >= 0)
//                {
//                    dp[i] = dp[i - 1] + array[i];
//                    en = i;
//                }
//                else
//                {
//                    dp[i] = array[i];
//                    st = en = i;
//                }
//                if(max <= dp[i])
//                {
//                    max = dp[i];
//                    fir = st;
//                    sec = en;
//                }
//            }
//            printf("Case %d:\n%d %d %d\n", t, max, fir + 1, sec + 1);
//            if(t != T)
//                puts("");
//        }
//    }
//    return 0;
//}
