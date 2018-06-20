//将大写化为小写，如果是非大写字母则原样输出,直到遇到'\0'就结束！
#include<stdio.h>
#define MAX 100
int main()
{
    char ch[MAX];
    int i=0;
    scanf("%s",ch);
    for(i=0;ch[i]!='\0';i++)
        if(ch[i]>='A'&&ch[i]<='Z')
        {
            ch[i]=ch[i]+32;
            printf("%c",ch[i]);
        }
        else
            printf("%c",ch[i]);
    return 0;
}
