#include <typeinfo>
#include <iostream>
#include <functional>

using namespace std;
using namespace std :: placeholders;

struct node
{
    void add1(int a)
    {
        cout << a << endl;
    }
    void add2(int a, int b)
    {
        cout << a << " " << b << endl;
    }
    void add3(int a, int b, int c)
    {
        cout << a << " " << b << " " << c << endl;
    }
};

int main()
{
    node pnode;
    pnode.add1(10);

    // cout << typeid(pnode.add1).name() << endl; // void _cdel<int>
    cout << typeid(&node :: add1).name() << endl; // void <__thiscall node :: *><int>

    void (node :: *p)(int a) = &node :: add1;
    // void (node :: *p)(int ) add1����������

    //! node :: p(10); // p���ѵ���

    // �󶨰�װ������װ���Ա����������ʹ��
    cout << "-----------" << endl;
                    // ������ �����ַ ����
    auto fun1 = bind(&node :: add1, & pnode, _1); // ��һ������
    fun1(1000);
    auto fun2 = bind(&node :: add2, & pnode, _1, _2); // ��������
    fun2(100, 900);
    auto fun3 = bind(&node :: add3, & pnode, _1, _2, _3);
    fun3(100, 900, 200);
    return 0;
}
