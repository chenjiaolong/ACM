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
    printf("�ո���Ϊ%d�����з���ĿΪ%d�������ַ�Ϊ%d",a,b,c);
    return 0;
}

