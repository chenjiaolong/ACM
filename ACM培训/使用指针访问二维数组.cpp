#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    puts("ʹ�ö�ά��������Ϊָ�룺");
    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 4; j ++)
            printf("%2d%c", *(*(a + i) + j), j == 3 ? '\n' : ' ');
    puts("ָ���ά�����ָ�룺");// ������ͬ���ȵ�һά����ļ���
    int (*p)[4] = a;// pΪָ��һά�����ָ��
    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 4; j ++)
            printf("%2d%c", *(*(p + i) + j), j == 3 ? '\n' : ' ');
    puts("ָ�����飺"); // ����ͬ���ȵ�һά����ļ���
    int *ps[3] = {a[0], a[1], a[2]};
    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 4; j ++)
            printf("%2d%c", *(*(ps + i) + j), j == 3 ? '\n' : ' ');
    puts("ָ���ָ�룺");// ����Ķ�����ָ�뼯��
    int **pp = ps;
    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 4; j ++)
            printf("%2d%c", *(*(pp + i) + j), j == 3 ? '\n' : ' ');
    return 0;
}
