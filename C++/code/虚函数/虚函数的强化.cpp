#include <iostream>

// 继承，默认情况class私有继承，struct公有继承
// 虚函数可以调用成员
// 多态依赖于指针或者引用调用
// 对象调用，会调用拷贝构造，拷贝一个父类，无法实现多态
class myclass
{
public:
    myclass() { std :: cout << "myclass()" << std :: endl; }
    myclass(const myclass &my) { std :: cout << "myclass(const myclass &my)" << std :: endl; }
    virtual ~myclass() { std :: cout << "~myclass()" << std :: endl; }
    virtual void go() { show(); }
    void show() { std :: cout << "show" << std :: endl; }

};
struct mynewclass : myclass
{
public:
    void go()
    {
        std :: cout << "hello world!" << std :: endl;
    }
};
void test(myclass *p)
{
    p -> go();
}
void test1(myclass &my)
{
    my.go();
}
void test2(myclass my)
{
    my.go();
}
int main()
{
    myclass *p = new mynewclass;
    test(p);
    //! test1(p);
    test2(*p);
    p -> go(); // 多态调用
    p -> myclass :: go(); // 调用原生
    mynewclass my;
    my.go();

    return 0;
}
