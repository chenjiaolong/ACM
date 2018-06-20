#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    puts("使用二维数组名作为指针：");
    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 4; j ++)
            printf("%2d%c", *(*(a + i) + j), j == 3 ? '\n' : ' ');
    puts("指向二维数组的指针：");// 处理相同长度的一维数组的集合
    int (*p)[4] = a;// p为指向一维数组的指针
    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 4; j ++)
            printf("%2d%c", *(*(p + i) + j), j == 3 ? '\n' : ' ');
    puts("指针数组："); // 处理不同长度的一维数组的集合
    int *ps[3] = {a[0], a[1], a[2]};
    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 4; j ++)
            printf("%2d%c", *(*(ps + i) + j), j == 3 ? '\n' : ' ');
    puts("指针的指针：");// 处理的对象是指针集合
    int **pp = ps;
    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 4; j ++)
            printf("%2d%c", *(*(pp + i) + j), j == 3 ? '\n' : ' ');
    return 0;
}
