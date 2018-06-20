//圣诞节补平安夜苹果
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
    int t;
    while(scanf("%d",&t) == 1)
    {
        while(t--)
        {
            int n,k;
            scanf("%d%d",&n,&k);
            if(k == 13)
                k--;
            int ans = ceil(n * 1.0 / k);
            if(n % k == 13 && (n < k || k == 14))
                ans++;
            printf("%d\n",ans);
        }
    }
    return 0;
}
//I belive it is very easy for you
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int n,m,x,y,z,p;
//    while(~scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&z,&p))
//    {
//        x %= 4,y &= 1,z %= 4;
//        //printf("%d %d %d\n",x,y,z);
//        int a,b;
//        for(int i = 1; i <= p; i++)
//        {
//            scanf("%d%d",&a,&b);
//            int N = n,M = m;
//            for(int j = 1; j <= x; j++)
//            {
//                swap(a,b);
//                b = N - b + 1;
//                swap(N,M);
//            }
//            if(y)
//                b = M - b + 1;
//            for(int j = 1; j <= z; j++)
//            {
//                swap(a,b);
//                a = M - a + 1;
//                swap(N,M);
//            }
//            printf("%d %d\n",a,b);
//        }
//    }
//    return 0;
//}
