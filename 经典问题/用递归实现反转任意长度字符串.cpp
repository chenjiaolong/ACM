#include<stdio.h>
#include<string.h>
void Print()
{
    char ch;
    scanf("%c",&ch);
    if(ch != '#')
        Print();
    if(ch != '#')
        printf("%c",ch);
}
int main()
{
    printf("Please input a string ending for '#':\n");
    Print();
    printf("\n");
    return 0;
}
