#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

const double EPS = 1e-7;

int main()
{
    double CF[12];
    int T;
    while(scanf("%d", &T), T)
    {
        for(int i = 0; i <= T; i ++)
            scanf("%lf", &CF[i]);
        double l, r, mid, ans = 0, tmp;
        CF[0] *= -1.0;
        l = -1.0;
        r = 1e6;
        while(fabs(CF[0] - ans) > EPS)
        {
            ans = 0.0;
            tmp = 1.0;
            mid =(l + r) / 2;
            for(int i = 1; i <= T; i ++)
            {
                tmp = tmp / (1 + mid);
                ans += CF[i] * tmp;
            }
            if(ans > CF[0]) l = mid;
            else r = mid;
        }
        printf("%.2f\n", mid);

    }
    return 0;
}
