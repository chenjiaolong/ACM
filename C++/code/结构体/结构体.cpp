#include <iostream>
#include <functional>

using namespace std;
// C++结构体可以为空，C不可以
// C++结构体可以有默认值，C不可以
// C++结构体定义变量，无需关键字struct
// C++结构体可以有函数
// 变量函数指针，变量，lambda函数快，不计入体积
// 结构体默认是私有，也可以设置为私有
// 没有私有变量的初始化
// 私有，需要构造函数
// 结构体的声明，只能创建指针，引用:拓展结构体声明
// 结构体内部可以创建指针和引用
// 匿名结构体，不可以初始化
struct node
{
    int num = 3;
    function<void(void)> fun = [](){  };
    //! auto fu; // 结构体无法保存auto
    void go()
    {

    }
};

struct nodex
{
    void (*p)() = []() {};

    /** function<void (void )>fun = [](){};
    function<void (int )>fun1 = [](int a){};
    function<void (char *)>fun2 = [](char *str){ cout << "1111111111111111111111111111111111111111" << endl;};
    */
};
struct point
{
// private :
    int x, y;
};
struct size
{
private :
    int x, y;
public :
    size() {   }
    size(int a, int b) : x(a), y(b){  }
    void show()
    {
        cout << x << " " << y << endl;
    }
};
int main()
{
    node p;
    cout << p.num << endl;

    // fun包装器一个占40（32）个字节
    // 函数指针4（8）个字节
    cout << sizeof(nodex) << endl;

    point p1 {1, 2};
    //! point p1(1, 2);
    point *ptr = new point{1, 2};
    point px[2]{{1, 2}, {3, 4}};
    point *pp = new point[2]{{1, 2}, {3, 4}};

    // p1.x = p1.y = 20; // 外部访问
    cout << p1.x << " " << p1.y << endl;

    size s1{1, 2};
    s1.show();
    size *p3 = new size(3, 4);
    p3 -> show();
    size ss[3] {size(13, 4), size(23, 4), size(33, 4)};
    size *ps = new size[3]{size(13, 4), size(23, 4), size(33, 4)};
    return 0;
}
