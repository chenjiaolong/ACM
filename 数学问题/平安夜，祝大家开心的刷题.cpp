//平安夜需要素数
//#include<stdio.h>
//int main()
//{
//    long long N;
//    while(scanf("%lld",&N) == 1)
//    {
//        printf("%d\n",N >= 7 ? 7 : -1);
//    }
//    return 0;
//}

//平安夜的选举
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int N;
//    while(~scanf("%d",&N) && N)
//    {
//        int array[105] = {0};
//        for(int i = 0; i < N; i++)
//            scanf("%d",&array[i]);
//        sort(array,array + N);
//        int cnt = 0;
//        for(int i = 0; i < N / 2 + 1; i++)
//            cnt += array[i] / 2 + 1;
//        printf("%d\n",cnt);
//    }
//    return 0;
//}

//平安夜的组合
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x,y;
    while(scanf("%lld%lld",&x,&y) == 2 && x + y)
    {
        long long gcd = __gcd(x,y);
        if(gcd == 1)
            printf("%lld\n",(y - 1) * x - y);
        else
            printf("Inf\n");
    }
    return 0;
}
