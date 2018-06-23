#include <iostream>

using namespace std;
// 本质是地址，操作引用等价于操作原本

struct MyStruct
{
    int &rint;
    int *p;
}; // 引用的本质就是指针

int * getp()
{
    int a = 5;
    return &a; // 返回局部变量或临时变量的地址：a
}

int & getrp()
{
    int a = 5;
    return a; // 返回局部变量或临时变量的地址：a
}

int & getint(int &rint) // 参数，返回都是地址
{
    rint = 1;
    return rint;
}

int main()
{
    cout << __FILE__ << endl;
    cout << sizeof(MyStruct) << endl;
    cout << sizeof(int *) << endl;

    cout << "-------------" << endl;
    //! int *p(new int);
    //! p = getp();
    //! cout << *p << endl;
    //! int &ra = getrp();
    //! cout << ra << endl;

    cout << "-------------" << endl;
    int a(10);
    getint(a);
    cout << a << endl;

    cout << "-------------" << endl;
    int *p(new int(5));
    getint(*p);
    cout << *p << endl;

    int &ra(a); // 引用，栈上
    //! int & *pr; // 不允许使用指向引用的的指针，指向引用的指针非法

    return 0;
}
