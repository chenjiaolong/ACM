#include <iostream>

using namespace std;

class A
{
public :
    // 类默认生成四个函数：拷贝构造，构造， 析构，赋值重载
    // A(const A &a) = delete; // 不允许执行拷贝构造函数
    // A() = delete;
    // ~A() = delete;
    // A operator = (const A & a) = delete;

    A() = default; // default存在，声明一下
    // void operator = (const A & a) = default;
};

int main()
{
    // A *p = new A;
    // A a;
    // A b(a); // 拷贝构造
    A c;
    A d;
    d = c; // 赋值重载

    return 0;
}
