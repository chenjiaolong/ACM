#include <cstdlib>
#include <typeinfo>
#include <iostream>

using namespace std;

class myclass
{
public :
    int num;
    void go()
    {
        cout << (void *)this << endl; // this 当前对象的首地址
    }
    void show()
    {
        cout << (void *)this << endl;
        cout << "show AAA" << endl;
    }
    void run()
    {
        cout << "show CCC" << endl;
    }
    static void showit(int data)
    {
        // 无法访问内部变量，无法访问类成员函数
        //! num = 1;
        //! show();
        //! run();
        // 静态函数无法使用this指针
        //! cout << (void *)this << endl;
        cout << "show BBB " << data << endl;
    }
};

class tools
{
public :
    static void runcmd(const char *cmd)
    {
        system(cmd);
    }
    static int add(int, int)
    {
        return 1;
    }
};

int main()
{
    myclass my1;
    cout << (void *)&my1 << endl;
    my1.go();
    myclass my2;
    cout << (void *)&my2 << endl;
    my2.go();

    cout << typeid(&myclass :: show).name() << endl; // void<__thiscall myclass :: *><void>
    cout << typeid(&myclass :: showit).name() << endl; // void<__cdecl*><int>
    void (*p)(int ) = &myclass :: showit; // C风格函数指针
    void(myclass :: *px)() = &myclass :: show; // 类成员函数的风格

    puts("---");
    myclass :: showit(10); // 类中静态函数无需对象名就可以直接访问，没有this 指针

    // 访问静态函数，也可以借助对象名访问
    my1.showit(11);
    my2.showit(12);

    puts("---");
    tools :: runcmd("notepad"); // 可以对C语言实现功能函数，分类包装到类
    tools ts1;
    ts1.runcmd("calc");

    return 0;
}
