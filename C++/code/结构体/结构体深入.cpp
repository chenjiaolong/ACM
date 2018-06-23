#include <iostream>

using namespace std;
struct node; // 结构体的声明，只能创建指针，引用

node *p;
//! node q;
void show (node &p)
{

}

struct node
{
    //! struct node q;
    struct node *p;
    struct node &rp; // 结构体内部可以创建指针和引用
};

//struct
//{
//    // 匿名结构体，不可以初始化
//    // int num = 10;
//};

struct A
{
    virtual void show()
    {
        cout << "AAA" << endl;
    }
};

struct B: public A
{
    void show()
    {
        cout << "BBB" << endl;
    }
};

int main()
{
    B b;
    b.show(); // 结构体继承
    A *p = new A; // 多态
    p -> show();
    p = new B;
    p -> show();
    return 0;
}
