// People Counting
#include<stdio.h>
#include<string.h>
char photo[105][105];
int H, W;
void BFS(int x, int y)
{
    if(x + 1 < H && photo[x + 1][y] == '|')
        photo[x + 1][y] = '.';
    if(x + 1 < H && y - 1 >= 0 && photo[x + 1][y - 1] == '/')
        photo[x + 1][y - 1] = '.';
    if(x + 1 < H && y + 1 < W && photo[x + 1][ y + 1] == '\\')
        photo[x + 1][y + 1] = '.';
    if(x + 2 < H && y - 1 >= 0 && photo[x + 2][y - 1] == '(')
        photo[x + 2][y - 1] = '.';
    if(x + 2 < H && y + 1 < W && photo[x + 2][y + 1] == ')')
        photo[x + 2][y + 1] = '.';
}
int main()
{
    int T;
    while(~scanf("%d", &T))
    {
        while(T--)
        {
            scanf("%d%d", &H, &W);
            for(int i = 0; i < H; i ++)
                scanf("%s",photo[i]);
            int cnt = 0;
            for(int i = 0; i < H; i ++)
                for(int j = 0; j < W; j ++)
                {
                    if(photo[i][j] == 'O')
                    {
                        cnt ++;
                        photo[i][j] = '.';
                        BFS(i, j);
                    }
                    else if(photo[i][j] == '/')
                    {
                        photo[i][j] = '.';
                        cnt ++;
                        if(photo[i][j + 1] == '|' && j + 1 >= 0)
                            photo[i][j + 1] = '.';
                        if(photo[i][j + 2] == '\\' && j + 2 < W)
                            photo[i][j + 2] = '.';
                        if(photo[i + 1][j] == '(' && i + 1 < H)
                            photo[i + 1][j] = '.';
                        if(photo[i + 1][j + 2] == ')' && i + 1 < H && j + 2 < W)
                            photo[i + 1][j + 2] = '.';
                    }
                    else if(photo[i][j] == '|')
                    {
                        photo[i][j] = '.';
                        cnt ++;
                        if(photo[i][j + 1] == '\\' && j + 1 < W)
                            photo[i][j + 1] = '.';
                        if(photo[i + 1][j - 1] == '(' && i + 1 < H && j - 1 >= 0)
                            photo[i + 1][j - 1] = '.';
                        if(photo[i + 1][j + 1] == ')' && i + 1 < H && j + 1 < W)
                            photo[i + 1][j + 1] = '.';
                    }
                    else if(photo[i][j] == '\\')
                    {
                        photo[i][j] = '.';
                        cnt ++;
                        if(photo[i + 1][j - 2] == '(' && i + 1 < H && j - 2 >= 0)
                            photo[i + 1][j - 2] = '.';
                        if(photo[i + 1][j] == ')' && i + 1 < H)
                            photo[i + 1][j] = '.';
                    }
                    else if(photo[i][j] == '(')
                    {
                        photo[i][j] = '.';
                        cnt ++;
                        if(photo[i][j + 2] == ')' && j + 2 < W)
                            photo[i][j + 2] = '.';
                    }
                    else if(photo[i][j] == ')')
                    {
                        photo[i][j] = '.';
                        cnt ++;
                    }
                }
            printf("%d\n",cnt);
        }
    }
    return 0;
}

