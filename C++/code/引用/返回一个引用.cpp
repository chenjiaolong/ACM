#include <iostream>

using namespace std;

// 函数返回值有副本机制，返回变量
// 栈区，自动回收，释放，返回值为指针，不能指向栈区，返回引用，不可引用栈区
// 指针，指针在栈区，指针指向内存在其它区域
int getdata()
{
    int num = 10; // 栈区
    return num;
}

int &getdata1()
{
    int num = 10; // 销毁了，在内存，
    return num;
}
// 堆区
int &getdata2()
{
    int *p(new int(5));
    return *p; // *p == int num;
}
// 全局变量不会自动的释放
int g_num = 20;
int &getdata3()
{
    return g_num;
}
char * &getcode()
{
    // p 在栈上，指向的内容在代码区
    char *p("maomaoyu");
    return p;
}
int main()
{
    cout << getdata() << endl;

    // 栈区
    cout << "-----------" << endl;
    //! int & rnum = getdata1(); // 引用原来内存
    cout << "hello" << endl;
    //! cout << rnum << endl;
    // int rnum = getdata1(); // 拷贝到新的内存
    // cout << rnum << endl;

    // 堆区
    cout << "-----------" << endl;
    int &rnum = getdata2();
    cout << "xixi" << endl;
    cout << rnum << endl;

    // 全局变量
    cout << "-----------" << endl;
    int &gnum = getdata3();
    cout << "hehe" << endl;
    cout << gnum << endl;

    // 字符串
    // cout << "-----------" << endl;
    // char * &rp = getcode();
    // char *newp = rp; // 保存rp存储的代码区地址
    // cout << "heihei" << endl;
    // cout << newp << endl;
    //! cout << rp << endl;

    return 0;
}
