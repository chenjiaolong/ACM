#include <memory>
#include <cstdlib>
#include <iostream>
// #include <allocators>

using namespace std;

class A
{
public :
    A() { cout << "A()" << endl; }
    ~A() { cout << "~A()" << endl; }
    A(const A &a)
    {
        cout << "copying" << endl;
    }
};

int main()
{
    A *p = new A;
    delete p;

    allocator<A>a; // 分配器， 可以自动控制构造析构时间
    A *ptr = a.allocate(3); // 分配一个元素

    a.construct(p, A()); // 调用构造，A()是一个匿名对象，销毁
    a.construct(p + 1, A());
    a.construct(p + 2, A());

    a.destroy(p); // 清空内容，调用析构
    a.destroy(p + 1);
    a.destroy(p + 2);
    a.deallocate(p, 1); // 释放内存

    // 匿名对象寄存器与缓存器
    // A(); // 匿名对象，构造完了，不保存马上析构

    // 保存在堆上，不再析构
    // A *q = new A(); // 堆

    puts("-----");
    A f1 = A();
    A f2;

    return 0;
}
