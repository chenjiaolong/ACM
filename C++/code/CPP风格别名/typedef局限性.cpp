#include <iostream>

// typedef 只能处理C语言
// C++独有命名空间，函数模板， 类模板

using namespace std;

typedef int a[5]; // 别名

namespace run
{
    int num = 10;
}
//! typedef run NS; // C风格.不能处理C++独有的命名空间

namespace NS = run; // 单独处理别名命名空间

template<typename T> // typedef T tx
void runit(T t)
{
    typedef T tx;
    tx t1 = t; // 内部可以
    cout << t << endl;
}

int main()
{
    a a1;
    cout << sizeof(a1) << endl;

    run :: num = 19;
    cout << run :: num << endl;

    NS :: num = 9;
    cout << NS :: num << endl;

    runit(10);
    return 0;
}
