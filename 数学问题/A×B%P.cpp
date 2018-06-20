#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    long long a, b, p;
    while(scanf("%lld%lld%lld",&a, &b, &p) != EOF)
    {
        long long r = 0;
        while(b)
        {
            if(b&1) r = (r + a) % p;
            a = (a << 1) %p;
            b >>= 1;
        }
        printf("%lld\n", r);
    }
    return 0;
}
