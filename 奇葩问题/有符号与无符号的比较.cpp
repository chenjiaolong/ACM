#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    int a = -1;
    unsigned int b = 0u;
    unsigned int c = 2147483648u;
    int d = -2147483647 - 1;
    unsigned int e = (unsigned int)(-1);
    int f = -2;
    int g = 2147483647;
    int h = (int )2147483648u;
    printf("a = %d, b = %uu\n", a, b);
    printf("c = %uu, d(-2147483647 - 1) = %d\n", c, d);
    printf("e((unsigned int)(-1)) = %uu, f = %d\n", e, f);
    printf("g = %d, h = (int )%du\n", g, h);
    if(a > b) puts("-1 > 0u, SB!");
    if(c == d) puts("2147483648u == -2147483647 - 1, SB!!");
    if(e > f) puts("(unsigned int)(-1) > -2, SB!!!");
    if(g > h) puts("2147483647 > (int )2147483648u, SB!!!!");
    return 0;
}