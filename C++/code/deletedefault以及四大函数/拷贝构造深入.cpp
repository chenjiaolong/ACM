#include <iostream>

using namespace std;

class A
{
public :
    int x, y;
    A(){ cout << "构造" << endl; }
    ~A(){ cout << "析构" << endl; }
    A(const A &a) { cout << "拷贝构造" << endl; x = a.x; y = a.y; }
    // A operator = (const A & a) = delete;
    void operator = (const A &a) { cout << "赋值重载" << endl; x = a.x; y = a.y; }
    void show() { cout << x << " " << y << endl; }
};

int main()
{
    A a;
    a.x = 10;
    a.y = 20;
    a.show();

    A b(a);
    b.show();

    A c;
    c.x = 10;
    c.y = 20;
    A d;
    d = c;
    d.show();

    cin.get();
    return 0;
}
