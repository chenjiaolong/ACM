#include <iostream>

using namespace std;

int main()
{
    // �������飬ָ�����飬������ά����
    int *p = new int[10];
    int **pp = new int*[10];
    int (*px)[4] = (int(*)[4])new int[20];
    // ��ά��ָ������
    int *(*py)[4] = (int *(*)[4])new int *[20];

    return 0;
}
