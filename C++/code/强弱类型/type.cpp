#include <iostream>

using namespace std;

int main()
{
    int num = 100;
    int *p1 = &num;
    //! char *p2 = p1; // CPP���ͼ���ϸ񣬾�׼
    // int *p2 = p1; // C���Եĸ�ֵ
    int *p2(p1); // () ��ʼ��
    return 0;
}
