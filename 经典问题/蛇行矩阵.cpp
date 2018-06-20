#include<bits/stdc++.h>
int main()
{
    int N;
    int array[105][105];
    while(~scanf("%d",&N))
    {
        array[0][0] = 1;
        for(int i = 1; i < N ; i++)
            array[i][0] = array[i-1][0] + i;
        for(int i =0; i < N; i+++)
            for(int j = 1; j < N - i; j++)
                array[i][j] = array[i][j-1] + (i + j + 1);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N - i; j++)
                printf("%d%c",array[i][j],j==N-i-1?'\n':' ');
    }
    return 0;
}
