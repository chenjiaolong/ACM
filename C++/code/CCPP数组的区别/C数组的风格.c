#include <stdio.h>

int main()
{
    // C99 的写法
    // C语言的数组放在栈
    int *p = (int [5]){[2] = 1, [3] = 2}; // 赋值
    // int *p = (int[]){1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i ++)
        printf("%d\n", p[i]);
    return 0;
}
