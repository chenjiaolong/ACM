// hiho 一下 第九十五周
#include<stdio.h>
#include<string.h>
typedef long long LL;
LL gcd(LL a, LL b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}
LL extend_gcd(LL a, LL b, LL &x, LL &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL r = extend_gcd(b, a % b, y, x);
    y -= x * (a / b);
    return r;
}
LL solve(LL s1, LL s2, LL v1, LL v2, LL m)
{
    LL A, B, C;
    A = v1 - v2;
    B = m;
    C = s2 - s1;

    if(A < 0)
        A += m; // 相对距离变化
    LL D = gcd(A, B);
    if(C % D)
        return -1;
    A = A / D;
    B = B / D;
    C = C / D;
    LL x,y;
    LL r = extend_gcd(A, B,x,y);
    x = (x * C) % B;
    while(x < 0)
        x += B;
    return x;
}
int main()
{
    LL s1, s2, v1, v2, m;
    while(~scanf("%lld%lld%lld%lld%lld", &s1, &s2, &v1, &v2, &m))
    printf("%lld\n", solve(s1, s2, v1, v2, m));
    return 0;
}
