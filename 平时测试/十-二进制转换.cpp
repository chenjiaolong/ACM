//#include<stdio.h>
//#include<math.h>
//int main()
//{
//    long long b,p;
//    int a,n,q;
//    while(scanf("%d",&n)!=EOF)
//    {
//        b=0;
//        p=1;
//        q=n;
//        while(n)
//        {
//            a=n%2;
//            b=b+p*a;
//            p=p*10;
//            n=n/2;
//        }
//        printf("%d-->%lld\n",q,b);
//    }
//}

#include<stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n == 0)
        {
            printf("0-->0\n");
            continue;
        }
        int p = n;
        int array[18];
        int cur = 0;
        if(n < 0)
            n = -n;
        while(n)
        {
            array[cur++] = n % 2;
            n /= 2;
        }
        if(p < 0)
            printf("%d-->-",p);
        else
            printf("%d-->",p);
        for(int i = cur - 1; i>=0;i--)
            printf("%d",array[i]);
        printf("\n");
    }
    return 0;
}
