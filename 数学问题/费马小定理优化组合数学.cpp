#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LL long long

using namespace std;

const LL mod = 1e9 + 7;
const int maxn = 1000005;

LL fact[maxn];

LL Pow(LL a, LL b)
{
    LL c = 1;
    while(b)
    {
        if(b&1) c = (c * a) %mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return c;
}
LL Work(LL n, LL m)
{
    return ((fact[n]% mod) * Pow((fact[m] * fact[n - m]) % mod, mod - 2) % mod)% mod;// 费马小定理 + 乘法逆元
}
int main()
{
    fact[0] = 1;
    for(int i = 1; i < maxn; i ++)
        fact[i] = (fact[i - 1] * i) % mod;
    printf("%lld\n", Work(5, 2));
    return 0;
}
