#include <stdio.h>
#include <string.h>
const int INF = 1000000;
const int maxn = 100000 + 10;
int n,x,y;
int d[maxn],dig[4],que[maxn * 4];
int primes[maxn];

int isPrime(int g)
{
    for (int i = 2; i < g; i++)
        if (g % i == 0)
            return 0;
    return 1;
}

void initPrimes()
{
    memset(primes,0,sizeof(primes));
    for (int i = 1000; i < 9999; i++)
        if (isPrime(i))
            primes[i] = 1;
}

int bfs()
{
    for (int i = 0; i < maxn; i++)
        d[i] = INF;
    int head = 0,tail = 0;
    d[x] = 0;
    que[tail++] = x;

    while (head <= tail)
    {
        int t = que[head++];

        int ks = 1;
        for (int i = 0; i < 4; i++)
        {
            dig[i] = (t / ks) % 10;
            ks *= 10;
        }

        int tmp;
        for (int i = 0; i < 4; i++)
        {
            tmp = dig[i];
            for (int j = 0; j <= 9; j++)
            {
                dig[i] = j;
                int tt = dig[0] + dig[1] * 10 + dig[2] * 100 + dig[3] * 1000;
                if (d[tt] == INF && primes[tt])
                {
                    d[tt] = d[t] + 1;
                    que[tail++] = tt;
                }
                if (tt == y)
                    return d[tt];
            }
            dig[i] = tmp;
        }
    }

    return INF;
}

int main()
{
    initPrimes();
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d %d",&x,&y);
        int t = bfs();
        if (t == INF)
            printf("Impossible\n");
        else
            printf("%d\n",t);
    }
}
