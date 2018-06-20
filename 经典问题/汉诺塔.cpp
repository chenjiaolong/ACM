#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

void hanoi(int n, char src, char medium, char dest)
{
    if(n == 1)
        printf("%c --> %c\n", src, dest);
    else
    {
        hanoi(n - 1, src, dest, medium);
        printf("%c --> %c\n", src, dest);
        hanoi(n - 1, medium, src, dest);
    }
}

int main()
{
    freopen("test.out", "w", stdout);
    int n;
    while(scanf("%d", &n) != EOF)
        hanoi(n, 'A', 'B', 'C');
    return 0;
}

