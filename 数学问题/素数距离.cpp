//区间筛素数
//具体思路是先筛出1到sqrt(2147483647)之间的所有素数，然后再通过已经晒好素数筛出给定区间的素数
#include<iostream>
#include<stdio.h>
#include<limits.h>

using namespace std;

/**
 * prime[]:存储小范围的素数表
 * prime1[]:存储某一区间的素数表
 * pcount:小范围素数表中素数的个数
 * pcount1:某一区间的素数表中素数的个数
 * in[]、in1[]用来标记某一个数字是否为素数..
 */
long long prime[46500], prime1[1000010];
long long pcount, p1count;
long long in[46500], in1[1000010];

void getsprime()  //快速筛小范围素数
{
    for (int i = 2; i < 46500; ++i)
        in[i] = 1;
    for (int i = 2; i < 46500; ++i)
    {
        if (!in[i])
            continue;
        for (int j = i * 2; j < 46500; j += i)
            in[j] = 0;
    }
    pcount = 0;
    for (int i = 2; i < 46500; ++i)
        if (in[i])
            prime[pcount++] = i;
}
void getlprime(long L, long U)
{
    if (U < 46500)   //假如区间的最大值就小于46500的话，那么之际用我们刚才求完的就好了
    {
        p1count = 0;
        for (int i = L; i <= U; ++i)
            if (in[i])
                prime1[p1count++] = i;
    }
    else     //筛大数区间内的素数的核心部分
    {
        long long k, size = U - L;
        for (long i = 0; i <= size; ++i)
            in1[i] = 1;
        for (long i = 0; i <= pcount && prime[i] * prime[i] <= U; ++i)
        {
            k = L / prime[i];
            if (k * prime[i] < L)
                ++k;
            if (k <= 1)
                ++k;
            while (k * prime[i] <= U)
            {
                in1[k * prime[i] - L] = 0;
                ++k;
            }
        }
        p1count = 0;
        for (long i = 0; i <= size; ++i)
            if (in1[i])
                prime1[p1count++] = i + L;
    }
}

int main()
{

    getsprime();
    long long L, U;
    while (scanf("%lld%lld", &L, &U) != EOF)
    {
        getlprime(L, U);

        long long distance, xmin, ymin, xmax, ymax;
//		long long min=2147483647,max=-1;
        int max = INT_MIN;
        int min = INT_MAX;
        if (p1count < 2)
            printf("There are no adjacent primes.\n");
        else
        {
            long i;
            for (i = 0; i < p1count - 1; ++i)
            {
                distance = prime1[i + 1] - prime1[i];
                if (distance < min)
                {
                    min = distance;
                    xmin = i;
                    ymin = i + 1;
                }

                if (distance > max)
                {
                    max = distance;
                    xmax = i;
                    ymax = i + 1;
                }
            }

            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",prime1[xmin], prime1[ymin], prime1[xmax], prime1[ymax]);
        }

    }

    return 0;
}

//#include<math.h>
//#include<stdio.h>
//#include<limits.h>
//#include<string.h>
//#include<stdbool.h>
//
//const int MAX = INT_MAX;
//int prime[50000];
//bool array[1000005];
//int index;
//void IsPrime()
//{
//    prime[0] = 2;
//    index = 1;
//    int m = (int )sqrt(MAX) + 1;
//    for(int i = 3; i <= m; i += 2)
//    {
//        bool flag = true;
//        for(int j = 2; j * j <= i; j++)
//            if(i % j == 0)
//            {
//                flag = false;
//                break;
//            }
//        if(flag)
//            prime[index ++] = i;
//    }
//}
//int main(int argc, char *argv[])
//{
//    IsPrime();
//    int L,U;
//    while(~scanf("%d%d",&L,&U))
//    {
//        if(L == 1)
//            L ++;
//        memset(array,false,(U - L + 1) * sizeof(bool));
//        for(int i = 0; ( i < index ) && (prime[i]*prime[i] <= U); i++)
//        {
//            int t = L / prime[i];
//            if(t < prime[i])
//                t = prime[i];
//            while(1)
//            {
//                int in = t * prime[i];
//                if(in > U)
//                    break;
//                if(in >= L && in <= U)
//                    array[in - L] = true;
//                t ++;
//            }
//        }
//        bool flag = false;
//        int ind,i;
//        for(i = 0; i < U - L + 1; i++)
//            if(array[i] == false)
//            {
//                flag = true;
//                ind = i;
//                break;
//            }
//        if(!flag)
//        {
//            printf("No\n");
//            continue;
//        }
//        int ix = 0,iy = 0,jx = 0,jy = 0,min = 1 << 29,max = 0;
//        for(++i; i < U - L + 1; i++)
//            if(array[i] == false)
//            {
//                if(i - ind < min)
//                {
//                    ix = ind;
//                    iy = i;
//                    min = i - ind;
//                }
//                if(i - ind > max)
//                {
//                    jx = ind;
//                    jy = i;
//                    max = i - ind;
//                }
//                ind = i;
//            }
//        if(!ix&&!iy)
//            printf("No\n");
//        else
//            printf("(%d,%d),(%d,%d)\n",ix + L,iy + L,jx + L,jy + L);
//    }
//}

//#include<cstdio>
//#include<cstring>
//typedef long long LL;
//LL L,U;
//#define M 50000
//#define N 1000001
//bool a[M],is[N];
//int pri[10000],k,p[100000];
//void make()
//{
//    k=0;
//    for(int i=2; i<M; i++)
//        if(!a[i])
//        {
//            pri[k++]=i;
//            for(int j=i+i; j<M; j+=i)a[j]=1;
//        }
//}
//void solve()
//{
//    memset(is,0,sizeof(is));
//    for(int i=0; i<k; i++)
//    {
//        LL w=L/pri[i];
//        while(w*pri[i]<L||w<=1)
//            w++;
//        for(LL j=w*pri[i]; j<=U; j+=pri[i])
//            is[j-L]=1;
//    }
//    if(L==1)is[0]=1;
//}
//int main()
//{
//    make();
//    while(scanf("%lld%lld",&L,&U)!=EOF)
//    {
//        solve();
//        int s=(int)(U-L),cnt=0;
//        for(int i=0; i<=s; i++)
//            if(!is[i])
//                p[cnt++]=i;
//        if(cnt<=1)puts("There are no adjacent primes.");
//        else
//        {
//            int min1=N,max1=0,x1,x2,y1,y2;
//            for(int i=1; i<cnt; i++)
//            {
//                int t=p[i]-p[i-1];
//                if(t<min1)
//                {
//                    min1=t;
//                    x1=p[i-1],x2=p[i];
//                }
//                if(t>max1)
//                {
//                    max1=t;
//                    y1=p[i-1],y2=p[i];
//                }
//            }
//            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",L+(LL)x1,L+(LL)x2,L+(LL)y1,L+(LL)y2);
//        }
//    }
//    return 0;
//}
