#include<stdio.h>
#define MAX(x, y) (x > y ? x : y)
int main()
{
    int a = MAX(1, 2) + 3;
    int b = MAX(2, 1) + 3;
    printf("%d %d\n", a, b);
    return 0;
}
