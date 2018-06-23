#include <stdio.h>

int main()
{
    const int num = 100;
    // int a[num]; // 伪常量 只能避免直接，无法避免间接
    *(int *)&num = 4;
    printf("%d\n", num);
    return 0;
}
