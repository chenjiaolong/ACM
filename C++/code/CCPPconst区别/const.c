#include <stdio.h>

int main()
{
    const int num = 100;
    // int a[num]; // α���� ֻ�ܱ���ֱ�ӣ��޷�������
    *(int *)&num = 4;
    printf("%d\n", num);
    return 0;
}
