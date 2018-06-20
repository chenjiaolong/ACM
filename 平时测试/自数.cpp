#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
bool flag[10000000];
using namespace std;
int main()
{
    // freopen("test.out","w",stdout);
    memset(flag, false, sizeof(flag));
    for(int n = 1; n < 10000000; n ++)
    {
        int num = n, sum = n;
        while(num > 0)
        {
            sum += num % 10;
            num = num / 10;
        }
        flag[sum] = true;
    }
    for(int n = 1; n < 10000000; n ++)
        if(!flag[n])
            printf("%d\n", n);
    // fclose(stdout);
    return 0;
}
