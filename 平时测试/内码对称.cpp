#include<bits/stdc++.h>
int main()
{
    int T;
    while(scanf("%d",&T) == 1)
    {
        int cnt = 0;
        while(T--)
        {
            unsigned int N;
            scanf("%u",&N);
            if(N == 0)
            {
                cnt++;
                continue;
            }
            bool array[35] = {0};
            int cur = 0;
            while(N)
            {
                array[cur++] = N % 2;
                N /= 2;
            }
//            for(int i = 0; i <cur;i++)
//                printf("%d%c",array[i],i == cur - 1? '\n':' ');
            bool flag = true;
            for(int i = 0; i < cur / 2; i++)
                if(array[i] != array[cur - 1 - i])
                {
                    flag = false;
                    break;
                }
                if(flag)
                    cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
