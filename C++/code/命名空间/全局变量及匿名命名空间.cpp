#include <iostream>

using namespace std;

// int a; // CPP û�������Ͷ���Ĳ��
int a = 5;

// һ���ֹʹ�����������ռ�
namespace
{
    int a = 10;
}

int main()
{
    //! a = 3;
    cout << :: a << endl;// ����ȫ�֣�����������
    :: a = 3;
    return 0;
}
