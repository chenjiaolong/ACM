//#include<stdio.h>
//#include<math.h>
//int main()
//{
//    int T, X;
//    while(~scanf("%d",&T))
//    {
//        while(T--)
//        {
//            int cnt = 0;
//            scanf("%d", &X);
//            for(int i = 1; i <= (int )(sqrt(X)); i ++)
//                if(X % i == 0)
//                    cnt ++;
//            printf("%d\n", cnt);
//        }
//
//    }
//    return 0;
//}


#include<stdio.h>
#include<string.h>
char key[10][10] = {"if", "then", "else", "end", "repeat", "until", "read", "write"};
char sys[11][5] = {":=", "=", "<", "+", "-", "*", "/", "(", ")", ";"};
int main()
{
    char str[2005];
    while(gets(str) != NULL)
    {
        int len = strlen(str);
        int cur = 0;
        int cnt = 0;
        char ss[2005][30] = {'\0'};
        for(int i = 0; i < len; i ++)
        {
            if(str[i] != ' ')
                ss[cur][cnt++] = str[i];
            else
            {
                if(cnt != 0)
                {
                    ss[cur][cnt] = '\0';
                    cur ++;
                    cnt = 0;
                }
            }
        }
        for(int i = 0; i <= cur; i ++)
        {
            bool flag = false;
            if(strlen(ss[i]) == 0) continue;
            for(int j = 0; j < 8; j ++)
                if(strcmp(ss[i], key[j]) == 0)
                {
                    printf("Keywords : %s\n", key[j]);
                    flag = true;
                }
            if(flag) continue;
            for(int j = 0; j < 10; j ++)
                if(strcmp(ss[i], sys[j]) == 0)
                {
                    printf(" Symbols : %s\n", sys[j]);
                    flag = true;
                }
            if(flag) continue;
            bool isnum = true;
            for(int j = 0; j < strlen(ss[i]); j ++)
                if(ss[i][j] >= '0' && ss[i][j] <= '9' )
                    continue;
                else
                {
                    isnum = false;
                    break;
                }
            if(isnum)
            {
                printf("     NUM : %s\n", ss[i]);
                flag = true;
            }
            if(flag) continue;
            bool marked = true;
            for(int j = 0; j < strlen(ss[i]); j ++)
                if(ss[i][j] >= 'a' && ss[i][j] <= 'z' || ss[i][j] >= 'A' && ss[i][j] <= 'Z')
                    continue;
                else
                {
                    marked = false;
                    break;
                }
            if(marked)
            {
                printf("      ID : %s\n",ss[i]);
                flag = true;
            }
            if(flag) continue;
            printf(" Unknown : %s\n", ss[i]);
        }
        puts("");
    }
    return 0;
}
