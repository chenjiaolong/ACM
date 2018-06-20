// csu 1785
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t ++)
    {
        char str[5];
        scanf("%s", str);
        int a = str[0] - '0';
        int b = str[1] - '0';
        int c = str[2] - '0';
        int d = str[3] - '0';
        int cnt = 0;
        for(int i = 1; i <= 9; i ++)
        {
            if(a == i) continue;
            for(int j = 30; j <= 100; j ++)
                if(j * j == 1000 * i + 100 * b + 10 * c + d)
                {
                    cnt ++;
                    break;
                }
        }
        for(int i = 0; i <= 9; i ++)
        {
            if(b == i) continue;
            for(int j = 30; j <= 100; j ++)
                if(j * j == 1000 * a + 100 * i + 10 * c + d)
                {
                    cnt ++;
                    break;
                }
        }
        for(int i = 0; i <= 9; i ++)
        {
            if(c == i) continue;
            for(int j = 30; j <= 100; j ++)
                if(j * j == 1000 * a + 100 * b + 10 * i + d)
                {
                    cnt ++;
                    break;
                }
        }
        for(int i = 0; i <= 9; i ++)
        {
            if(d == i) continue;
            for(int j = 30; j <= 100; j ++)
                if(j * j == 1000 * a + 100 * b + 10 * c + i)
                {
                    cnt ++;
                    break;
                }
        }
        printf("Case %d: %d\n", t, cnt);

    }
    return 0;
}
