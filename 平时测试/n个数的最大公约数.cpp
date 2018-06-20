#include<bits/stdc++.h>
using namespace std;
long long GCD(long long a,long long b)
{
    return !b ? a : GCD(b, a % b);
}
int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        long long a,b;
        scanf("%lld",&a);
        long long gcd = a;
        n--;
        while(n--)
        {
            scanf("%lld",&b);
            gcd = GCD(gcd,b);
        }
        printf("%lld\n",gcd);
    }
    return 0;
}
