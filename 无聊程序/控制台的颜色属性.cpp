// 注意 Your choice is C ID
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char B[10];
    while(scanf("%s",B))
    {
        char C[25] = "color ";
        strcat(C,B);
        system(C);
        //system("pause");
    }
    return 0;
}
