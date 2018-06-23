#include <thread>
#include <iostream>
#include <windows.h>

using namespace std;

// void operator()() 对象名当作函数名，重载()
// ()仅仅适用于当前结构体对象
// 不适合作为多线程参数， 销毁太快


struct MyStruct
{
    MyStruct() { cout << "create" << endl; }
    ~MyStruct() { cout << "end"  << endl; }
    void operator()()
    {
        MessageBoxA(0, "content", "title", 0);
    }
};

int main()
{
    MyStruct go1;
    thread t1(go1);

    MyStruct go2;
    thread t2(go2);

    thread t3(MyStruct()); // 不适合作为多线程参数， 销毁太快

    MyStruct *p(new MyStruct());

    // int a(5);
    // int*p = new int(5); // ()初始化，构造函数

    // MyStruct() 构造函数，创建一个临时对象，匿名对象
    MyStruct()();

    system("pause");
    return 0;
}
