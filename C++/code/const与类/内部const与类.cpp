#include <iostream>

using namespace std;
// 创建对象的时候，const常量对象，无法没改变数据，只能引用尾部带const方法
// 类成员如果是const，第一种默认初始化，第二必须构造的初始化，不可以在构造函数内部初始化
// 类中的const成员，无法直接修改，可以间接修改
// 类的成员函数，返回值const，返回常量，参数const，可读不可写，尾部const，常量对象仅可以引用方法，常量有没有都可以访问
// const 不能用于构造与析构 常量对象可以引用
class A
{
public :
    int x, y;
    const int z = 3; // 常量数据原则，必须初始化
    A() : z(3){ /* z = 1; 常量数据对象初始化，必须构造函数之后，不允许构造函数内部初始化*/ }
    A(int a, int b) : x(a), y(b), z(a + b){  }
    ~A(){  }
    void show() const // const 对象可以引用
    {
        //! x = 1; // 只能读，不能修改
        cout << x << " " << y << endl;
    }
    void change(const int a, const int b) // 保护参数不被修改
    {
        x = a;
        y = b;
    }
    const int getx() const // 返回一个常量， 函数保护状态
    {
        return x;
    }
};

int main()
{
    // 对象，常量对象 ，只能调用自带const的方法，无法修改数据
    // const A a(10, 10);
    //! a.x = 20;
    A a(10, 10);
    a.show();
    //! a.z = 2;
    cout << a.z << endl;
    int *p = const_cast<int *>(&a.z);
    *p = 3; // 可以间接修改类中的const 成员
    cout << a.z << endl;

    a.change(1, 2);

    return 0;
}
