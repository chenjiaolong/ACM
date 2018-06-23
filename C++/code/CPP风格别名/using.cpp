#include <iostream>
#include <functional>

using namespace std;
using std :: function; // 使用命名空间的一部分
using fun = std :: ios :: fmtflags; // 命名空间的类变量或者函数别名

// 一般情况，原则都用using取代typedef
// typedef处理不了模板，处理不了命名空间
// double DB;
// typedef doule DB;
// DB 就是double

// int num; // 定义变量
// using INT = int num;增加using INT =
// using INT = int; // 去掉变量名

typedef double DB;
using DBCPP = double; // CPP风格的别名

typedef int a[10];
using intarray = int[10];

typedef int(*p)(int a, int b); // 函数指针类型，p
using pf = int(*)(int a, int b); // CPP风格的别名

typedef int(*pa[10])(int a, int b); // 函数指针数组类型，pa
using ppf = int(*[10])(int a, int b);


namespace china
{
    template<typename T> using tp = T; // 别名
    // template<typename T> typedef T tp;
    template<typename T>
    T add(T a, T b)
    {
        T c = a + b;
        return c;
    }
}


int main()
{
    cout << sizeof(DBCPP) << endl;
    cout << sizeof(DB) << endl;
    intarray int_array;
    cout << sizeof(int_array) << endl;

    cout << china :: add<int >(1, 2) << endl;

    return 0;
}
