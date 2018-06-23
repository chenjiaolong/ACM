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
    // cout << typeid(a.Add).name() << endl; // int_cdecl<int, int>  通过对象调用函数
    cout << typeid(&A :: Add).name()<< endl; // int<__thiscall A::*><int, int> 无法直接访问
    int ( A :: *pf)(int, int) = &A :: Add; // 创建一个函数指针指向类成员函数
    A *pmy = &a;
    cout << (a.*pf)(1, 2) << endl;
    cout << (pmy ->* pf)(11, 2) << endl;
    // 访问类成员函数指针的时候，指针调用 ->* 对象.*
    return 0;
}
