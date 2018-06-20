#include<stdio.h>
int main()
{
    int row,column;
    for(row=1; row<=9; row++)
        for(column=1; column<=row; column++)
            printf("%d*%d=%2d%c",column, row,column*row, column == row ? '\n' : '\t');
    return 0;
}
