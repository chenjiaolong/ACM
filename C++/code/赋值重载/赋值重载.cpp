#include <cstdlib>
#include <iostream>

using namespace std;

class point
{
public :
    int a, b;
};


class myclass
{
    int x, y;
public :
    myclass() : x(10), y(20){  }
    myclass(int num)
    {
        cout << "拷贝构造num" << endl;
        x = num;
        y = num;
    }
    myclass(const point &pt)
    {
        cout << "拷贝构造point" << endl;
        x = pt.a;
        y = pt.b;
    }
    // myclass operator = (const myclass &my) = delete;
    void operator = (const myclass &my)
    {
        cout << "赋值重载" << endl;
        x = my.x;
        y = my.y;
    }
    void operator = (const point &pt)
    {
        cout << "赋值重载point" << endl;
        x = pt.a;
        y = pt.b;
    }
    void operator = (int num) // 类型转换
    {
        cout << "赋值重载num" << endl;
        x = num;
        y = num;
    }
    void show()
    {
        cout << x << " " << y << endl;
    }
};
int main()
{
    myclass my1;
    myclass my2(my1); // 拷贝构造
    myclass my3;
    my3 = my2; // 赋值重载
    myclass my4 = my2; // 拷贝构造

    puts("---");
    my1 = 8;
    my1.show();
    myclass my5 = 3; // 拷贝构造
    my5.show();

    point p1{1, 2};
    myclass my6 = p1;
    my6.show();

    myclass my7;
    my7 = p1;
    my7.show();

    return 0;
}
