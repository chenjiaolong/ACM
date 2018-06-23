#include <iostream>

using namespace std;
// 类成员函数指针，包含this指针，必须明确谁来引用
// 类成员函数指针，空指针可以调用，没有类成员数据
// 调用方式: ->* .*
// 类成员函数指针数组
// int (A :: *ps[4])(int, int){&A :: Add, &A :: Sub, &A :: Mul, &A :: Div};

class A
{
public :
    int Add(int a, int b)
    {
        return a + b;
    }
    int Sub(int a, int b)
    {
        return a - b;
    }
    int Mul(int a, int b)
    {
        return a * b;
    }
    int Div(int a, int b)
    {
        try{
        if(b == 0) throw 1;
        return a / b;
        }catch(int code)
        {
            cout << "除数不能为0" << endl;
        }
    }
};

void change(int (A :: * &p)(int, int)) // int (A :: * &p)(int, int) 类成员函数指针的引用
{
    p = &A :: Sub;
}

// changeit 的参数是类成员函数指针的引用，返回值是类成员函数指针的引用
int (A :: * &changeit(int (A :: * &p)(int, int)))(int, int)
{

    p = &A :: Mul;
    return p;
}
// 类成员函数指针数组作为参数退化为二级类成员函数指针
void showit(int (A :: *p[4])(int, int))
{
    p += 3;
    cout << "showit " << sizeof(p) << endl;
}
void show(int (A :: **p)(int, int))
{
    A *pclass(nullptr);
    for(int (A :: **pp)(int, int) = p; pp < p + 4; pp ++) // 二级类成员函数指针数组遍历函数指针数组
        cout << (pclass ->** pp)(100, 10) << endl; // 指针循环
}
int main()
{
    // 类成员函数指针
    int (A :: *p)(int, int) = &A :: Add;
    A *pclass(nullptr);
    // 类成员函数指针，空指针可以调用，没有类成员数据
    cout << pclass -> Add(1, 2) << endl;
    cout << (pclass ->* p)(2, 3) << endl;
    cout << ((*pclass).*p)(2, 3) << endl;

    cout << "-----" << endl;
    // 类成员函数指针数组
    // 栈
    // int (A :: *ps[4])(int, int){&A :: Add, &A :: Sub, &A :: Mul, &A :: Div};
    // 堆
    int (A :: **ps)(int, int) = new( int(A :: *[4])(int, int) ) {&A :: Add, &A :: Sub, &A :: Mul, &A :: Div}; // 二级类成员函数开辟指针数组
    // 二级类成员函数指针
    cout << sizeof(ps) << endl;
    for(int i = 0; i < 4; i ++)
        cout << (pclass ->* ps[i])(100, 10) << endl; // 下标循环
    for(int (A :: **pp)(int, int) = ps; pp < ps + 4; pp ++) // 二级类成员函数指针数组遍历函数指针数组
        cout << (pclass ->** pp)(100, 10) << endl; // 指针循环

    cout << "----" << endl;
    cout << (pclass ->* p)(100, 10) << endl;
    change(p);
    cout << (pclass ->* p)(100, 10) << endl;
    p = changeit(p);
    cout << (pclass ->* p)(100, 10) << endl;

    cout << "----" << endl;
    cout << sizeof(ps) << endl;
    //! ps += 3;
    showit(ps);
    show(ps);

    return 0;
}
