#include<stdio.h>
#include<string.h>
const int maxn = 1000;
int main()
{
    freopen("È¥µôË«Ð±¸Ü×¢ÊÍ.in","r",stdin);
    freopen("test.out","w",stdout);
    //freopen("È¥µôË«Ð±¸Ü×¢ÊÍ.out","w",stdout);
    char str[maxn];
    while(gets(str) != NULL)
    {
        char s[maxn];
        char *p = str;
        if(*p == '/' && *(p+1) == '/')
            continue;
        int cur = 0;
        while(*p != '\0')
        {
            if(*p == '/' && *(p+1) == '/')
                break;
            else
                s[cur++] = *p;
            p ++;
        }
        s[cur] ='\0';
        bool flag = true;
        for(int i = 0; i < cur; i++)
            if(s[i] != ' ')
            {
                flag = false;
                break;
            }
        if(flag)
            continue;
        for(int i = cur - 1; str[i] == ' '; i--)
            if(str[i] == ' ')
                cur --;
        s[cur] = '\0';
        puts(s);
    }
    return 0;
}
