#include <iostream>
#include <typeinfo>

using namespace std;

class op
{
    int a = 0, b = 0;
public :
    op(int x, int y) : a(x), b(y) {}
    ~op() {}
    int Add()
    {
        return a + b;
    }
    int Sub()
    {
        return a - b;
    }
};

class A
{
public :
    int Add(int a, int b)
    {
        cout << "Add call" << endl;
        return a + b;
    }
};

int main()
{
    op op1(1, 2);
    op1.Add();
    op *p = new op(1, 2);
    p -> Add();

    A a;
    a.Add(1, 2);
    cout << typeid(a).name() << endl; // class A
    // cout << typeid(a.Add).name() << endl; // int_cdecl<int, int>  ͨ��������ú���
    cout << typeid(&A :: Add).name()<< endl; // int<__thiscall A::*><int, int> �޷�ֱ�ӷ���
    int ( A :: *pf)(int, int) = &A :: Add; // ����һ������ָ��ָ�����Ա����
    A *pmy = &a;
    cout << (a.*pf)(1, 2) << endl;
    cout << (pmy ->* pf)(11, 2) << endl;
    // �������Ա����ָ���ʱ��ָ����� ->* ����.*
    return 0;
}
