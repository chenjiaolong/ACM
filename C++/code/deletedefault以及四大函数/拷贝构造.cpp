#include <iostream>

using namespace std;

class A
{
public :
    // ��Ĭ�������ĸ��������������죬���죬 ��������ֵ����
    // A(const A &a) = delete; // ������ִ�п������캯��
    // A() = delete;
    // ~A() = delete;
    // A operator = (const A & a) = delete;

    A() = default; // default���ڣ�����һ��
    // void operator = (const A & a) = default;
};

int main()
{
    // A *p = new A;
    // A a;
    // A b(a); // ��������
    A c;
    A d;
    d = c; // ��ֵ����

    return 0;
}
