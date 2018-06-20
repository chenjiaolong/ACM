#include<stdio.h>
int main()
{
    char ch;
    int i=0;
    while(ch=getchar())
        if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
        {
            i++;
            printf("%d",i);
        }
    return 0;
}
