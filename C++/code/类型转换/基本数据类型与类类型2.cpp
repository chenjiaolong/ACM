#include <iostream>

using namespace std;

class myclass
{
public :
    int x, y;
    myclass() : x(0), y(0) {  }
    explicit myclass(int a) : x(a), y(a) { cout << "构造" << endl; }

    void operator = (int num)
    {
        cout << "赋值重载" << endl;
        x = y = num;
    }
    // 没有参数，没有返回类型，但一定要有返回值
    operator int() // 类类型转换为int
    {
        return (x + y) / 2;
    }
    operator double();
};
// operator重载类型，往往用于类型装换
// 只能是成员函数，必须有this
myclass :: operator double()
{
    return (x + y) / 2.0;
}

int main()
{
    // explicit 禁止隐式转换
    ///! myclass my1 = 5; ///! 不够明确
    myclass my1 = static_cast<myclass>(5);
    myclass my2(5);
    myclass my3 = myclass(5);
    myclass my4 = (myclass)5;

    myclass my5;
    my5 = 5; // 赋值重载的装换

    myclass my6;
    my6.x = 4;
    my6.y = 3;
    int a = my6;
    cout << a << endl;
    double b = my6;
    cout << b << endl;


    return 0;
}
