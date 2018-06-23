#include <iostream>

using namespace std;

class A
{
public :
    int x, y, z;
    A(int a = 10, int b = 10, int c = 10) : x(a), y(b), z(c){  }
    void show() const
    {
        cout << x << " " << y << " " << z << endl;
    }
    void set(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
};

int main()
{
    const A a(1, 2, 3); // 栈区
    a.show();
    //! a.set(2, 3, 4);
    const A *p = new A(4, 5, 6); // 堆区
    p -> show();
    //! p -> set(6, 7, 8); // 无法改变数据
    p = nullptr; // 指向常对象的指针，指针可以改变指向，不可以改变数据，无论指向一个对象，数组，都不能改变

    // 不可以改变指向，指向的不是常量，是变量可以修改
    A *const ptr = new A(1, 2, 3);
    ptr -> show();
    ptr -> set(2, 3, 4);
    //! p = nullptr;

    // 指向常对象常指针
    A const *const pp = new A(1, 2, 0);
    //! pp = nullptr;
    //! pp -> set(1, 2, 4);
    pp -> show();

    return 0;
}
