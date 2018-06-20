#include<stdio.h>
#include<string.h>
#define MAX 10000
int main()
{
    char input[MAX],*p;
    while(fgets(input,MAX,stdin)!=NULL)
    {
        if(!strcmp(input,"END"))
            break;
        p=input;
        while(*p!='\0')
        {
            if(*p=='A'||*p=='W'||*p=='F')
                printf("I");
            else if(*p=='C')
                printf("L");
            else if(*p=='M')
                printf("o");
            else if(*p=='S')
                printf("v");
            else if(*p=='D'||*p=='P'||*p=='G'||*p=='B')
                printf("e");
            else if(*p=='L')
                printf("Y");
            else if(*p=='X')
                printf("u");
            else
                printf("%c",*p);
            p++;
        }
        printf("\n");
    }
    return 0;
}
