#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int F(int n, int m)
{
    if(n < m)
        return pow(2, n);
    if(n == m)
        return pow(2, n) - 1;
    return 2 * F(n-1, m) - F(n - 1 - m, m);
}
int main()
{
    int L;
    while(~scanf("%d",&L))
    {
        while(L--)
        {
            int N,M;
            scanf("%d%d",&N,&M);
            printf("%d\n",F(N,M));
        }
    }
    return 0;
}
