#include <stdio.h>

int main()
{
    // C99 ��д��
    // C���Ե��������ջ
    int *p = (int [5]){[2] = 1, [3] = 2}; // ��ֵ
    // int *p = (int[]){1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i ++)
        printf("%d\n", p[i]);
    return 0;
}
