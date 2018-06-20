#include<stdio.h>
#include<string.h>
#define maxn 21
int array[maxn][maxn];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(array,0,sizeof(array));
        int tot = 0,x,y;
        tot = array[x = 0][y = n - 1] = 1;
        while(tot < n * n)
        {
            while(x + 1 < n && !array[x + 1][y])
                array[++x][y] = ++ tot;
            while(y - 1 >= 0 && !array[x][y-1])
                array[x][--y] = ++ tot;
            while(x - 1 >= 0 && !array[x - 1][y])
                array[--x][y] = ++tot;
            while(y + 1 < n && !array[x][y + 1])
                array[x][++y] = ++tot;
        }
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < n; j++)
                printf("%3d%c",array[i][j],j == n - 1 ?'\n':' ');
    }
    return 0;
}
