#include <iostream>

// 虚函数重载，与返回值无关，与参数个数，类型，顺序有关
// 虚函数被继承以后还是虚函数
// 如果要使用被继承的虚函数，不允许出现虚函数重载，C++编译器不识别
// 多态可以跨类，爷爷辈的指针，存储孙子辈地址，父辈的指针存储孙子辈的地址
class myclass
{
public:
    virtual void go1() { std :: cout << "myclassY" << std :: endl; }
    virtual void go(int a) { }
    virtual void go(int a, int b){ }
};
class myclassX: public myclass
{
public:
    virtual void go(int a, int b, int c) {  }
};
class myclassY: public myclassX
{
public:
    void go1() { std :: cout << "myclassY" << std :: endl; }
};
int main()
{
    myclassX *p = new myclassY;
    p -> go1();
    return 0;
}
