#include<stdio.h>
#include<string.h>
#include<ctype.h>
const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[] = {"not a palindrome","a regular palindrome","a mirrored string","a mirrored palindrome"};
char r(char ch)
{
    if(isalpha(ch))
        return rev[ch - 'A'];
    return rev[ch - '0' + 25];
}
int main()
{
    char str[30];
    while(scanf("%s",str) == 1)
    {
        int len = strlen(str);
        int p = 1,m = 1;
        for(int i = 0; i <(len + 1)/ 2; i++)
        {
            if(str[i] != str[len - 1 - i])
                p = 0;//不是回文串
            if(r(str[i]) != str[len - 1 - i])
                m = 0;//不是镜像串
        }
        //printf("%d %d\n",m,p);
        printf("%s-- is %s.\n",str,msg[m * 2 + p]);
    }
    return 0;
}

//样例输入：
//NOTAPALINROME
//ISAPALINILAPASI
//2A3MEAS
//ATOYOTA

//样例输出：
//NOTAPALINROME -- is not a palindrome.
//ISAPALINILAPASI -- is regular palindrome.
//2A3MEAS -- is a mirrored string.
//ATOYOTA -- is a mirrored palindrome.

