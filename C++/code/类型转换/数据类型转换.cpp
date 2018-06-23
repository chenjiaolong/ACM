#include <iostream>

using namespace std;

// static_cast<type>(X)  static_cast静态转换，<>要转换的类型 () 要转换的数据, 不适用于指针
// reinterpret_cast<type *>(Y)用于指针转换，C语言，指针直接赋值


// 父类
class A
{
public :
    int a;
    // 有了虚函数可以实现多态
    virtual void run()
    {
        cout << "A is running!" << endl;
    }
};
// 子类
class B: public A
{
public :
    int b;
    void run()
    {
        cout << "B is playing!" << endl;
    }
};

int main()
{
    printf("%d\n", 10.2); // printf不会自动处理数据类型
    printf("%f\n", 1);

    cout << "---------" << endl;
    printf("%d\n", static_cast<int>(10.2)); // 默认转换
    printf("%f\n", static_cast<float>(1));

    cout << "---------" << endl;
    int *pint(new int(1));
    char *pch = reinterpret_cast<char *>(pint); // 指针类型的转换
    for(int i = 0; i < 4; i ++)
        cout << static_cast<int>(*(pch + i)) << " " << reinterpret_cast<void *>(pch + i) << endl;

    cout << "---------" << endl;
    int num[5]{1, 2, 3, 4, 5};
    const int *p(num);
    //! pint = reinterpret_cast<int *>p; // reinterpret_cast不适用于const
    // 涉及const,必须用const_cast
    pint = const_cast<int *>(p);
    for(int i = 0; i < 5; i ++)
        cout << pint[i] << " " << reinterpret_cast<void *>(pint + i) << endl;

    cout << "-----------" << endl;
    // 多态
    A a;
    B b;
    A *px = &a;
    px -> run();
    px = &b;
    px -> run();

    cout << "-----------" << endl;
    A *pfa(new A);
    B *pson(new B); // 创建一个父类对象以及子类
    cout << reinterpret_cast<void *>(pfa) << endl;
    cout << reinterpret_cast<void *>(pson) << endl;
    pfa -> run();
    pson -> run();

    // dynamic_cast用于安全的类型转换父类对象与子类对象，如果不匹配转换失败为nullptr
    // 只能用于转换多态，依赖于虚函数，非多态不能
    A *pY = dynamic_cast<A *>(pson); // 子类对象转换为父类指针
    cout << reinterpret_cast<void *>(pY) << endl;
    pY -> run();

    /* B *py = dynamic_cast<B *>(pfa); // 可以把子类对象的地址传递给父类指针，不能把父类对象传递给子类指针
    cout << reinterpret_cast<void *>(py) << endl;
    if(py != nullptr) py -> run();*/

    //! 不推荐
    B *py = reinterpret_cast<B *>(pfa);
    cout << reinterpret_cast<void *>(py) << endl;
    if(py != nullptr)
    {
        py -> a = 10; // 访问子类继承父类对象的变量
        py -> b = 10;

        py -> run();

        (*py).A :: run(); // 子类中间父类的方法
        (*py).B :: run();
    }

    return 0;
}
