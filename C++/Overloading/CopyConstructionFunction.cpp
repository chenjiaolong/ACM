#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

class Point// Point 类的定义
{
public :
    Point(int xx = 0, int yy = 0) { x = xx; y = yy; }    //构造函数，内联
    Point(const Point& p) /*= delete*/;  //指示编译器不生成默认复制构造函数
    Point& operator = (const Point &p);
    bool operator == (const Point &p) const
    {
        return x == p.x && y == p.y;
    }
    int getX() { return x; }
private :// 私有数据
    int x, y;
};
// 成员函数的实现
Point :: Point(const Point& p)
{
    x = p.x;
    y = p.y;
    cout << "Calling the copy constructor" << endl;
}
Point& Point :: operator = (const Point& p)
{
    if(*this == p) return *this;
    cout << "Assignment Copying" << endl;
    x = p.x, y = p.y;
    return *this;
}

// 形参为Point 类对象的函数
void fun1(Point p)
{
    cout << p.getX() << endl;
}
// 返回值为Point类对象的函数
Point fun2()
{
    Point a(1, 1);
    return a;
}
int main()
{
    Point a; // 第一个对象a
    Point b(a); // 情况一， 用a初始化b。第一次调用拷贝构造函数
    cout << b.getX() << endl;

    fun1(b); // 情况二，对象b作为fun1的实参。第二次调用拷贝构造函数
    puts("OK1");
    b = fun2(); // 情况三，函数的返回值是类对象，函数返回时， 调用拷贝构造函数
    puts("OK2");
    cout << b.getX() << endl;

    // 赋值拷贝
    Point c(1, 2), d(3, 4);
    cout << c.getX() << endl;
    c = d;
    cout << c.getX() << endl;

    return 0;
}

//#include<string.h>
//#include<iostream>
//
//using namespace std;
//
//class Name
//{
//    char name[20];
//public:
//    Name(){ strcpy(name, ""); cout << '?'; }
//    Name(char *fname){ strcpy(name, fname); cout << '*'; }
//};
//
//int main()
//{
//    Name names[3] = {Name("张三"), Name("李四")};
//    return 0;
//}
