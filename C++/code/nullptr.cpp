#include <iostream>
#include <typeinfo>
using namespace std;

void show(int num)
{
    cout << "int " << endl;
}
void show(int *p)
{
    cout << "int *" << endl;
}
int main()
{
    //! show(NULL); �����޷�ͨ��C����ָ�룬�ᱻ����Ϊ����
    show(nullptr); // C++ ���Ŀ�ָ��
    cout << typeid(NULL).name() << endl; // int
    cout << typeid(nullptr).name() << endl; // std :: nullptr_t
    // �ϸ�����ƥ��

    int *p1 = NULL;
    int *p2 = nullptr;
    show(p1);
    show(p2);

    return 0;
}
