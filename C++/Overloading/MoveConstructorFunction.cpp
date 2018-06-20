#include<iostream>
using namespace std;
class IntNum
{
public:
    IntNum(int x = 0) : xptr(new int(x))  //构造函数
    {
        cout << "Calling constructor..." << endl;
    }
    IntNum(const IntNum & n) : xptr(new int(*n.xptr)) //复制构造函数
    {
        cout << "Calling copy constructor..." << endl;
    }
    IntNum(IntNum && n): xptr( n.xptr)  //移动构造函数
    {
        n.xptr = nullptr;
        cout << "Calling move constructor..." << endl;
    }
    ~IntNum()  //析构函数
    {
        delete xptr;
        cout << "Destructing..." << endl;
    }
    int getInt() { return *xptr; }
private:
    int *xptr;
};
//返回值为IntNum类对象
IntNum getNum()
{
    IntNum a(3);
    return a;
}
int main()
{
    cout << getNum().getInt() << endl;
    return 0;
}

// 复制拷贝与移动拷贝
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<stdexcept>
//#include<iostream>
//
//using namespace std;
//
//class A
//{
//public :
//    A() : _n(0), _p(nullptr) { }
//    explicit A(int n) : _n(n), _p(new int[n + 1]) { }
//    A(int n, int *p) : _n(n), _p(p) { }
//    // 可以同时提供拷贝语义与移动语义版本，前者使用常左值引用
//    // 不能修改目标数据对象的值，后者则可以修改
//    A(const A & that);// 重载常量版本；深拷贝语义
//    A(A && that); // 重载非常量版本；移动构造语义
//    A & operator = (const A & that);// 重载常量版本；深拷贝赋值语义
//    A & operator = (A && that);//重载非常量版本；移动赋值语义
//    virtual ~A() { if(_p) { delete[] _p, _p = nullptr;} }
//public :
//    int &operator[](int i)/* throw(out_of_range)*/;
//    const int & operator[](int i)const/* throw(out_of_range)*/;
//private :
//    int _n;
//    int *_p;
//};
//A :: A(const A & that)
//{
//    this -> _n = that._n;
//    _p = new int[_n];
//    for(int i = 0; i < _n; i ++) _p[i] = that._p[i];
//}
//A :: A(A && that)
//{
//    // nullptr: C++11预定义的空指针类型的常对象
//    // 可隐式转换为任意指针类型和bool类型，但不能转换为整数类型，以取代NULL
//    _n = that._n, _p = that._p, that._n = 0, that._p = nullptr;
//    // *this = that;// 此代码不会调用下面重载的赋值操作符函数
//    // 具名右值引用that在函数内部被当作左值，不是右值
//    // 匿名右值引用才会被当作右值；理论上如此。。。
//    // *this = static_cast<A && >(that);// 等价于 *this = std :: move(that);
//    // 上一行代码可以调用下面的重载的移动赋值操作符，但是有可能导致程序崩溃
//    // 因this 指向的本对象可能刚刚分配内存，_p字段所指向的目标数据对象无定义
//}
//A & A :: operator = (const A & that)
//{
//    this -> _n = that._n;
//    if(_p) delete[] _p;// 删除此行代码可能会导致内存泄露
//    // 可以测试是否为同一对象， 以避免自身复制操作，但意义不太
//    _p = new int[_n];
//    for(int i = 0;i < _n; i ++) _p[i] = that._p[i];
//    return *this;
//}
//A & A :: operator = (A && that)
//{
//    if(_p) delete[] _p;// 删除此行代码可能会导致内存泄露
//    // 可以测试是否为同一对象， 以避免自身复制操作，但意义不太
//    _n = that._n, _p = that._p, that._n = 0, that._p = nullptr;
//    return *this;
//}
//int & A :: operator[](int index)
//{
//    if(index < 0 || index > 4)
//        throw out_of_range("Index is out of range!");
//    return _p[index];
//}
//const int & A :: operator[](int index) const
//{
//    if(index < 0 || index > 4)
//        throw out_of_range("Index is out of range!");
//    return _p[index];
//}
//int main()
//{
//    A a(4);
//    for(int i = 0; i < 4; i ++)
//        a[i] = i + 1;
//    A b(a); // 调用拷贝构造版本
//    b = a; // 调用普通赋值版本
//
//    // 把左值引用转换为右值引用，否则会调用左值版本
//    A c(static_cast< A && >(a));// 调用移动构造版本
//    c = static_cast< A && >(a);// 调用移动赋值版本
//
//    A a1; // 缺省构造
//    const A a2; // 缺省构造
//
//    A a3(a1);  // 调用A :: A(A & ), 移动构造
//    A a4(a2); // 调用A :: A(const A &), 深拷贝构造
//
//    // 对于非常量，必须转型为常量才能进行深拷贝
//    A a5(const_cast<const A & >(a1)); // 调用A :: A(const int &)
//
//    A a6, a7, a8; // 缺省构造
//    a6 = a1; // 调用A :: operator = (A &), 移动赋值
//    a7 = a2; // 调用A :: operator = (const A & ),深拷贝赋值
//    a8 = const_cast<const A & >(a1); // 调用A :: operator = (const A &)
//
//    return 0;
//}
