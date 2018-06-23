#include <cstdlib>
#include <iostream>

using namespace std;
// 函数指针引用作为参数，改变指针
// 函数指针引用作为返回值，实现调用getitrp(p)("dir");
// int (* (&p) )(const char * cmd)((int (* (&) )(const char * cmd))showcmd);

int gocmd(const char * cmd)
{
    system(cmd);
    return 0;
}
int showcmd(const char * cmd)
{
    cout << cmd << endl;
    return 0;
}
void change(int (* (&p) )(const char *cmd)) // 引用作为参数
{
    p = showcmd;
}
// 返回一个函数指针
int (* getp() )(const char *cmd)
{
    int (* p )(const char * cmd)(gocmd); // 函数指针
    return p;
}
// 参数是一个引用， 利用指针
int (* getitp(int (* (&p) )(const char * cmd)))(const char *cmd)
{
    p = showcmd;
    return p;
}
// 参数是一个引用， 返回值也是一个引用
int (* (&getitrp(int (* (&p) )(const char * cmd))))(const char *cmd)
{
    p = gocmd;
    return p;
}
int (* (&getitrp2()))(const char *cmd)
{
    //! int (*p)(const char * cmd)(showcmd); // 栈上
    // 强类型，注意类型转换
    // int (* (&p) )(const char * cmd) = (int (* (&) )(const char * cmd))showcmd;
    int (* (&p) )(const char * cmd)((int (* (&) )(const char * cmd))showcmd);
    return p;
}
int main()
{
    int (*p)(const char * cmd)(gocmd);// 定义函数指针并初始化
    p("calc");
    change(p);
    p("echo maomaoyu");

    p = getp();
    p("mspaint");
    getitp(p);
    p ("echo hehe");
    p = getitrp(p);
    p ("notepad");
    getitrp(p)("dir");
    //! p = getitrp2();
    //! p("cls");
    return 0;
}
