#include <iostream>

using namespace std;

int main()
{
    int a = 1.2; // �Զ�ת��
    int b = static_cast<int > (2.3); // CPP��ת��
    int c = (int )2.5; // C����ת��
    int *p1 = nullptr;
    char *p2 = reinterpret_cast<char *>(p1); // CPP��ָ��ת������ַ���ƹ�������������

    return 0;
}
