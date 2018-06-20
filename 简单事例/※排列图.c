#include<stdio.h>
void main()
{
    int row,column;
    for(row=1; row<=5; row++)
    {
        for(column=1; column<=9; column++)
            printf("%d",column);
        printf("\n");
    }
    for(row=1; row<=5; row++)
    {
        for(column=1; column<=row; column++)
            printf("%d",column);
        printf("\n");
    }
    for(row=1; row<=5; row++)
    {
        for(column=1; column<=row; column++)
            printf("*");
        printf("\n");
    }
    for(row=1; row<=5; row++)
    {
        for(column=1; column<=5-row; column++)
            printf(" ");
        for(column=1; column<=row; column++)
            printf("*");
        printf("\n");
    }
    for(row=1; row<=5; row++)
    {
        for(column=1; column<=5-row; column++)
            printf(" ");
        for(column=1; column<=2*row-1; column++)
            printf("*");
        printf("\n");
    }
    for(row=1; row<=5; row++)
    {
        for(column=6-row; column>=1; column--)
            printf("*");
        printf("\n");
    }
    for(row=1; row<=5; row++)
    {
        for(column=row-1; column>= 1; column--)
            printf(" ");
        for(column=1; column<=6-row; column++)
            printf("*");
        printf("\n");
    }
    for(row=1; row<=5; row++)
    {
        for(column=row; column>=1; column--)
            printf(" ");
        for(column=1; column<=2*(6-row)-1; column++)
            printf("*");
        printf("\n");
    }
    int i=0;
    for(row=1; row<=7; row++)
    {
        if(row<=4)
        {
            for(column=1; column<=4-row; column++)
                printf(" ");
            for(column=1; column<=2*row-1; column++)
                printf("*");
            printf("\n");
        }
        else
        {
            for(column=1; column<=row-1; column++)
                printf(" ");
            i++;
            for(column=1; column<=2*(row-2*i)-1; column++)
                printf("*");
            printf("\n");
        }
    }
}
