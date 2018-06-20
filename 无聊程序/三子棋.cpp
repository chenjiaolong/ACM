#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char board[4][4]; // global variable - be careful!!!!
void initialise()
{
    for(int r=0; r<3; r++)
        for(int c=0; c<3; c++)
            board[r][c]='-';
}

void showBoard()
{
    for(int r=0; r<3; r++)
        for(int c=0; c<3; c++)
            printf("%c%c",board[r][c],c == 2?'\n':' ');
}

int checkWinner(char m)
{
    // check all rows
    for(int r=0; r<3; r++)
        if(board[r][0]==m && board[r][1]==m && board[r][2]==m)
            return 1;
    // check all columns
    for(int c=0; c<3; c++)
        if(board[0][c]==m && board[1][c]==m && board[2][c]==m)
            return 1;
    if(board[0][0]==m && board[1][1]==m && board[2][2]==m)
        return 1;
    if(board[0][2]==m && board[1][1]==m && board[2][0]==m)
        return 1;
    return 0;
}
int main()
{
    initialise();
    char r,c;
    while(1)
    {
        showBoard();
        // user's turn X
        // get input
        printf("USER enter row:");
        r = getchar();
        getchar();
        //fflush(stdin);
        printf("enter column:");
        c = getchar();
        //fflush(stdin);
        getchar();
        printf("**%d***%d**\n",r,c);
        board[atoi(&r)-1][atoi(&c)-1]='X';
        // check winner
        if(checkWinner('X')==1)
        {
            printf("USER WON!");
            break;
        }
        // computer's turn O
        // get move
        int row, col;
        int found=0;
        for(r=0; r<3; r++)
        {
            if(found==1) break;
            for(c=0; c<3; c++)
            {
                if(board[r][c]=='-')
                {
                    found=1;
                    row = r;
                    col = c;
                    break;
                }
            }
        }
        board[row][col]='O';

        // check winner
        if(checkWinner('O')==1)
        {
            printf("PC WON!");
            break;
        }
    }
    getchar();
}
