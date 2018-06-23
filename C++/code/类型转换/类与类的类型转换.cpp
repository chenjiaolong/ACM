#include <iostream>

using namespace std;

class point1;
// CPP编译的时候，从上往下，遇到不匹配
// class point1; 类的生命拓展作用域
// 只能创建指针或引用，不能创建对象
// 完成类型转换的时候，一般两个类的转换，两个转换接口放在一个类
class point2
{
public :
    int a, b;
    point2() : a(0), b(0){  }
    point2(int x, int y) : a(x), b(y) {  }
    // point1 *p1;
    // point1 &p1;
    //! point1 p1;
};
class point1
{
public :
    int x, y, z;
    point1(): x(10), y(20), z(25) {  }
    point1(const point2 &p2) : x(p2.a), y(p2.b), z(0) { cout << "拷贝构造" << endl; } // point2 -> point1

    void operator = (const point2 &p2)
    {
        cout << "赋值重载" << endl;
        x = p2.a;
        y = p2.b;
        z = 0;
    }

    operator point2() // point1 -> point2
    {
        point2 temp(x, y);
        return temp;
    }
};



int main()
{
    point2 p2(88, 66);
    point2 pp2(888, 666);

    point1 p1(p2);
    point1 pp1 = p2;
    pp1 = pp2; // 赋值重载

    point2 ppp3 = pp1;
    ppp3 = p1;


    return 0;
}
