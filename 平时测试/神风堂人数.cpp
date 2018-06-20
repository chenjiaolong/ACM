#include<stdio.h>
#define EPS 1e-6
int main(int argc,char *argv [])
{
    double P,Q;
    while(scanf("%lf%lf",&P,&Q) == 2)
    {
        P /= 100,Q /= 100;
        int num = 1;
        while(num)
        {
            if((int )(num * Q - EPS)-(int )(num * P + EPS) >= 1)
            {
                printf("%d\n",num);
                break;
            }
            num ++;
        }
    }
    return 0;
}
