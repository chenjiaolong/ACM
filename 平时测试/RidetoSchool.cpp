#include<stdio.h>
int main()
{
    int N;
    while(scanf("%d",&N) == 1 && N)
    {
        double min = 1 << 29;
        while(N--)
        {
            double V,T;
            scanf("%lf%lf",&V,&T);
            if(T < 0)
                continue;
            double time = T + (4.5 / V) * 3600;
            if(time < min)
                min = time;
        }
        printf("%.0f\n",min);
    }
    return 0;
}
