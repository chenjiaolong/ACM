#include <stdio.h>
int main ()
{
    int a=0,b=0,c=0;
    char ch;
    ch=getchar();
    while(ch!='#')
    {
        if(ch==' '&&ch!='\n')
            a++;
        else if (ch!=' '&&ch=='\n')
            b++;
        else
            c++;
        ch=getchar();
    }
    printf("空格数为%d，换行符数目为%d，其他字符为%d",a,b,c);
    return 0;
}

