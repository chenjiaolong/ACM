#include <typeinfo>
#include <iostream>

using namespace std;

template<typename T1, typename T2>
auto add(T1 t1, T2 t2) // �Զ�������������
{
    return t1 + t2;
}
int main()
{
    // ����Ӧ�������ͣ��Զ�����
    // auto num = 10;
    // auto num = 10.1;
    // auto num = 'A';
    // auto num = L"bobo"; // wchar_t const *
    //! auto double num = 3 + 1.2; // auto �������κ���������˵�������
    auto num = 3 / 5;
    cout << typeid(num).name() << endl;

    int a[5] = {1, 2, 3, 4, 5};
    // auto i ���� auto &i ԭ��
    for(auto &i : a)
    {
        i += 1;
        cout << i << endl;
    }
    for(auto i : a) cout << i << endl;

    cout << add(10, 11.2) << endl;
    cout << add(10.1, 11) << endl;

    return 0;
}
