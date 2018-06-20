//#include<stdio.h>
//int main()
//{
//    int n,array[105];
//    while(~scanf("%d",&n))
//    {
//        for(int i=0; i<n; i++)
//            scanf("%d",&array[i]);
//        int flag=0;
//        for(int i=0; i<n; i++)
//            for(int j=0; j<n; j++)
//                for(int k=0; k<n; k++)
//                    if(i!=j&&j!=k&&i!=k&&((array[i]-array[j]==array[k])||array[j]-array[i]==array[k]))
//                    {
//                        flag=1;
//                        break;
//                    }
//        if(flag)
//            printf("YES\n");
//        else
//            printf("NO\n");
//    }
//    return 0;
//}

// 5776 sum
#include<map>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;
const int maxn = 1e5 + 100;
int x[maxn];
int pre[maxn];
map<int, bool>mp;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        mp.clear();
        pre[0] = 0;
        mp[0] = true;
        bool flag = false;
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &x[i]);
            pre[i] = pre[i - 1] + x[i];
            if(mp[pre[i] % m])
                flag = true;
            else mp[pre[i] % m] = true;
        }
        A:
        if(flag) puts("YES");
        else puts("NO");

    }
    return 0;
}
