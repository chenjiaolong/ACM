#include <iostream>
#include <typeinfo>

// 子类同名函数覆盖父类
// 父类指针存储子类地址，有虚函数情况，调用子类方法，否则调用父类方法
class base
{
public:
    virtual void show() { std :: cout << "base show" << std :: endl; }
};
class baseX: public base
{
public:
    void show() { std :: cout << "baseX show" << std :: endl; }
};

int main()
{
    base *p = new baseX;
    p -> show();
    std :: cout << typeid(p).name() << std :: endl; // class base *
    std :: cout << typeid(*p).name() << std :: endl; // 有虚函数 class baseX，否则 class base
    // typeid自动识类型，依赖于虚函数


    // dynamic_cast只能识别多态数据类型，转换失败，返回nulll
    baseX *px = dynamic_cast<baseX *>(p); // 必须要有虚函数，转换成功，否则失败
    px -> show();

    // 多态，父类子类指针可以根据多态转换为子类指针
    // 识别为父类对象，转换失败，返回null
    // 识别为子类对象，转换成功，返回正确的地址
    base *p1 = new base;
    base *p2 = new baseX;
    baseX *ptr = dynamic_cast<baseX *>(p1);
    std :: cout << (void *)ptr << std :: endl;

    // dynamic_cast只能转换指针或者引用，不能转换对象
    //! base b = dynamic_cast<baseX>(*p2);

    baseX *p3 = new baseX;
    base *p4 = p3; // CPP自动把子类指针转化为父类

    base & rbase(*p2);
    rbase.show();

    baseX &rx = dynamic_cast<baseX &>(rbase);

    return 0;
}
