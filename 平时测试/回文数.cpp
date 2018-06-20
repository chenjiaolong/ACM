// nsu 1071
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

const int maxn = 2010;

char str[maxn];
int M[maxn];
int len;

bool Palindrome(int *p)
{
    for(int i = 1; i <= len / 2; i ++)
        if(p[i] != p[len - i + 1]) return false;
    return true;
}

int main()
{
    int N;
    while(scanf("%d", &N) != EOF)
    {
        scanf("%s", str);
        len = strlen(str);
        int step = 0;
        for(int i = 1; i <= len; i ++)
            if(str[i - 1] < 'A') M[i] = str[i - 1] - '0';
            else M[i] = str[i - 1] - 'A' + 10;
        do
        {
            int temp[maxn] = {0};
            for(int i = 1; i <= len; i ++) temp[i] = M[i] + M[len - i + 1];
            len *= 2;
            for(int i = 1; i <= len; i ++)
            {
                temp[i + 1] += temp[i] / N;
                temp[i] %= N;
            }
            while(temp[len] == 0) --len;
            for(int i = 1; i <= len; i ++) M[i] = temp[i];
            ++step;
        }
        while(!Palindrome(M) && step <= 30);
        if(step > 30) puts("Impossible");
        else printf("STEP=%d\n", step);
    }
    return 0;
}
