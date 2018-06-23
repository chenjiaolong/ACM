#include <thread>
#include <iostream>
#include <windows.h>

using namespace std;

struct fun
{
    int i;
    void run()
    {
        // i = 3;
        MessageBoxA(0, "content", "title", 0);
        cout << "hello china hello cpp" << endl;
    }
    void runit(const char *str)
    {
        // i = 3;
        MessageBoxA(0, str, str, 0);
        cout << "hello china hello cpp" << endl;
    }

};

int main()
{
    // fun *p(nullptr);
    // p -> run(); // 空类指针可以引用没有调用内部变量的成员函数

    fun fun1;
    // & fun1 :: run 引用成员函数
    thread th1(& fun :: run, fun1);
    thread th2(& fun :: run, fun1);
    thread th3(& fun :: runit, fun1, "maomaoyu");
    thread th4(& fun :: runit, fun1, "liufangjun"); // 传递参数模式
    system("pause");

    return 0;
}
