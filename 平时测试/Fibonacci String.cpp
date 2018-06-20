// hdu 1708
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

int main()
{
    int N;
    int K;
    scanf("%d", &N);
    while(N --)
    {
        char pre[35], next[35];
        long long pre_seg[30] = {0};
        long long next_seg[30] = {0};
        long long temp[30] = {0};
        scanf("%s%s%d", pre, next, &K);
        int len1 = strlen(pre);
        int len2 = strlen(next);
        for(int i = 0; i < len1; i ++)
            pre_seg[pre[i] - 'a']++;
        for(int i = 0; i < len2; i ++)
            next_seg[next[i] - 'a']++;
        if(K == 0)
        {
            for(char ch = 'a'; ch <= 'z'; ch ++)
                printf("%c:%lld\n", ch, pre_seg[ch - 'a']);
            continue;
        }
        for(int i = 2; i <= K; i ++)
        {
            for(int ch = 0; ch < 26; ch ++) temp[ch] = next_seg[ch];
            for(int ch = 0; ch < 26; ch ++) next_seg[ch] = pre_seg[ch] + next_seg[ch];
            for(int ch = 0; ch < 26; ch ++) pre_seg[ch] = temp[ch];
        }
        for(char ch = 'a'; ch <= 'z'; ch ++)
            printf("%c:%lld\n", ch, next_seg[ch - 'a']);
        puts("");
    }
    return 0;
}
