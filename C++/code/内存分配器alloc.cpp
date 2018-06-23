#include <memory>
#include <cstdlib>
#include <iostream>
// #include <allocators>

using namespace std;

class A
{
public :
    A() { cout << "A()" << endl; }
    ~A() { cout << "~A()" << endl; }
    A(const A &a)
    {
        cout << "copying" << endl;
    }
};

int main()
{
    A *p = new A;
    delete p;

    allocator<A>a; // �������� �����Զ����ƹ�������ʱ��
    A *ptr = a.allocate(3); // ����һ��Ԫ��

    a.construct(p, A()); // ���ù��죬A()��һ��������������
    a.construct(p + 1, A());
    a.construct(p + 2, A());

    a.destroy(p); // ������ݣ���������
    a.destroy(p + 1);
    a.destroy(p + 2);
    a.deallocate(p, 1); // �ͷ��ڴ�

    // ��������Ĵ����뻺����
    // A(); // �������󣬹������ˣ���������������

    // �����ڶ��ϣ���������
    // A *q = new A(); // ��

    puts("-----");
    A f1 = A();
    A f2;

    return 0;
}
