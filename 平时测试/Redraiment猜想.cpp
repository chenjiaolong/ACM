// nsu 1833
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

const int maxn = 1e7 + 10;

bool prime[maxn];

void Init()
{
    for(int i = 0; i < maxn; i += 2) prime[i] = false;
    for(int i = 3; i < maxn; i += 2) prime[i] = true;
    prime[1] = false, prime[2] = true;
    for(int i = 3; i < maxn; i += 2)
    {
        if(prime[i])
        for(int j = 2; i * j < maxn; j ++)
            prime[i * j] = false;
    }
}

int main()
{
    Init();
    int n;
    while(scanf("%d", &n), n)
    {
        int cnt = 0;
        for(int i = 1; i <= n; i ++)
            cnt += prime[i];
        printf("%d\n", cnt);
    }
    return 0;
}
