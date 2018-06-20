// hdu 5301 Buildings
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
    int n, m, x, y;
    while(scanf("%d%d%d%d", &n, &m, &x, &y) != EOF)
    {
        if(n > m) swap(n, m), swap(x, y);
        int maxi = max(x - 1, n - x);
        int minj = min(y, m - y + 1);
        int minn = min(maxi, minj);
        int maxm;
        if(n & 1)maxm = n / 2 + 1;
        else maxm = n / 2;
        int ans = max(minn, maxm);
        if(n == m && (n & 1) && x == y && x == maxm)
            printf("%d\n", x - 1);
        else
        printf("%d\n", ans);
    }
    return 0;
}

