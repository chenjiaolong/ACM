// nsu 1131
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int K[10];
    while(N --)
    {
        for(int i = 1; i <= 9; i ++)
            scanf("%d", &K[i]);
        int x = K[1];
        for(int i = 2; i <= 9; i ++)
            if(x > K[i])
            {
                K[0] = K[i];
                for(int j = i; j >= 1; j --)
                    K[j] = K[j - 1];
            }
        for(int i = 1; i <= 9; i ++)
            printf("%d%c", K[i], i == 9 ? '\n' : ' ');
    }
    return 0;
}

