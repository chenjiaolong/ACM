#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T>
void show(T *p) // ����
{
    // decltype(*p) num(*p); // �ڴ汸��
    // cout << num << endl;

    int a = *p; // ��ȡһ������
    decltype(a) num[5]{a, a, a, a, a};
    for(auto i : num)
        cout << i << endl;

    cout << *p << endl;
}

int main()
{
    auto str("hello world");
    cout << typeid(str).name() << endl;// const char *

    cout << "----------" << endl;
    auto flag(1 && 0 && 3 || -1);
    //! flag(0); ()�����ڳ�ʼ��
    cout << typeid(flag).name() << " " << flag << endl;

    cout << "----------" << endl;
    auto flag1(flag);
    cout << typeid(flag1).name() << " " << flag1 << endl;

    // ��������
    cout << "----------" << endl;
    // decltype(flag) ����һ��������ȡ���ͣ��������飬����ָ��
    decltype(flag)flag2[5]{0}; // {0}��ʼ��
    for(auto i : flag2)
        cout << typeid(i).name() << " " << i << endl;

    cout << "----------" << endl;
    int a = 10;
    show(&a);

    return 0;
}
