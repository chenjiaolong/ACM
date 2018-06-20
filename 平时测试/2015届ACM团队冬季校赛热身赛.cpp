//就是算一个距离
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int d1,d2,d3;
//    while(~scanf("%d%d%d",&d1,&d2,&d3))
//    {
//        int min1 = d1 + d2 + d3;
//        int min2 = 2 * (d1 + d2);
//        int min3 = 2 * (d1 + d3);
//        int min4 = 2 * (d2 + d3);
//        printf("%d\n",min(min1,min2) < min(min3,min4)? min(min1,min2) : min(min3,min4));
//    }
//    return 0;
//}

//养猪好赚啊
//#include<stdio.h>
//int main()
//{
//    int n;
//    int array[120];
//    array[1] = 1;
//    array[2] = 1;
//    array[3] = 1;
//    for(int i = 4; i <=110; i++)
//        array[i] = array[i - 3] + array[i - 1];
//    while(~scanf("%d",&n))
//    printf("%d\n",array[n]);
//    return 0;
//}

//简单的求和
//#include<stdio.h>
//int main()
//{
//    int n;
//    while(~scanf("%d",&n))
//    {
//        long long sum = 0;
//        while(n--)
//        {
//            long long temp;
//            scanf("%lld",&temp);
//            temp %= 7777;
//            sum = (sum + temp)%7777;
//        }
//        printf("%lld\n",sum);
//    }
//    return 0;
//}

//有没有人想打我
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long l,r;
    while(~scanf("%lld%lld",&l,&r))
    {
        long long a,b,c;
        bool flag = false;
        for( a = l ; a <= r - 2; a++)
            for(b = a + 1; b <= r - 1; b++)
                for(c = b + 1; c <= r;  c++)
                    if(__gcd(a,b) == 1&&__gcd(b,c) == 1 && __gcd(a,c) != 1)
                    {
                        flag = true;
                        printf("%lld %lld %lld\n",a,b,c);
                        goto A;
                    }
A :
        if(!flag)
            printf("-1\n");
    }
    return 0;
}
