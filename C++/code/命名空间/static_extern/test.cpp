#include <iostream>

using namespace std;

int x = 10;
static int x1 = 100; // static �����ڵ�ǰ�ļ������Ա��룬�޷�����
namespace
{
    int x = 999;
    static int x1 = 999;
}

void test()
{
    cout << :: x << endl; // ���ļ����õ���ȫ��
    cout << :: x1 << endl; // ͬһ���ļ������õĻ���static
}
