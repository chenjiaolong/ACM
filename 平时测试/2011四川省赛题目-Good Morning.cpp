#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    while(~scanf("%d",&T))
    {
        char buffer[10];
        gets(buffer);
        for(int t = 1; t <= T; t++)
        {
            char str[1010];
            gets(str);
            int cnt[10] = {0};
            int len = strlen(str);
            for(int i = 0; i < len; i++)
            {
                if(str[i] == 'g')
                    cnt[0]++;
                else if(str[i] == 'o')
                    cnt[1]++;
                else if(str[i] == 'd')
                    cnt[2]++;
                else if(str[i] == ' ')
                    cnt[3]++;
                else if(str[i] == 'm')
                    cnt[4]++;
                else if(str[i] == 'r')
                    cnt[5]++;
                else if(str[i] == 'n')
                    cnt[6]++;
                else if(str[i] == 'i')
                    cnt[7]++;
            }
            if(cnt[0]>0)
                cnt[0]--;
            cnt[1] /= 3,cnt[6]/=2;
//            for(int i = 0; i < 8; i++)
//                printf("%d%c",cnt[i],i == 7? '\n':' ');
            int Min = 1 << 29;
            for(int j = 0; j < 8; j++)
                if(j != 3)
                    Min = min(Min,cnt[j]);
            printf("Case #%d: %d\n",t,Min);
        }
    }
    return 0;
}
