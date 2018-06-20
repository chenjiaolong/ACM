#include<bits/stdc++.h>
int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        int num = n;
        for(int i = 2; i <= num; i++)
        {
            while(n % i == 0)
            {
                printf("%d ",i);
                n /= i;
            }
        }
        printf("\n");
    }
    return 0;
}

