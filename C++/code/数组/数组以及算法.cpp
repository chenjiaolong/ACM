#include <iostream>

using namespace std;

int main()
{
    // 创建数组，指针数组，创建二维数组
    int *p = new int[10];
    int **pp = new int*[10];
    int (*px)[4] = (int(*)[4])new int[20];
    // 二维的指针数组
    int *(*py)[4] = (int *(*)[4])new int *[20];

    return 0;
}
