#include <stdio.h>

int main()
{
    void *p1 = NULL;
    char *p2 = p1;
    int a[3][4];
    int *p3 = a; // C语言 类型检测不严格，弱类型
    return 0;
}
