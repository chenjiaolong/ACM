#include<stdio.h>
#include<windows.h>
int main()
{
    int i,j;
    system("title ������");
    for(i=1; i<=15; i++)
    {
        system("cls");
        printf("��============================��\n");
        printf(" ");
        for(j=1; j<=i; j++)
            printf("��");
        printf("\n��============================��\n");
        printf("��ǰ����Ϊ%.2f%%,",(float)(j-1)/15*100);
        Sleep(100);
    }
    return 0;
}
