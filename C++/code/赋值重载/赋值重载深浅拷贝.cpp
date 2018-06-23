#include <cstring>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
// 默认拷贝构造，赋值重载，值传递
// 非指针，深浅拷贝一样，指针
// 浅拷贝，内存共享，指针一致，内容一致
// 深拷贝，指针不一致，内容一致，内存独享

// 赋值重载如果有返回自身类型对象，会调用拷贝构造
// 返回对象没有影响 返回对象地址或引用，触发故障
// 如果在栈上，也会触发异常
using namespace std;

class mystring
{
public:
    char *p;
    int n;
    mystring() : p(nullptr), n(0){  }
    mystring(char *str)
    {
        n = strlen(str) + 1;
        p = new char[n];
        strcpy(p, str);
    }
    ~mystring()
    {
        if(p) delete[] p, p = nullptr;
    }
    mystring(const mystring &str)
    {
        delete[] p;
        cout << "构造函数call" << endl;
        n = str.n;
        p = new char[n];
        strcpy(p, str.p);
    }
    void operator = (const mystring &str)
    {
        delete[] p;
        cout << "赋值重载call" << endl;
        n = str.n;
        p = new char[n];
        strcpy(p, str.p);
    }
};

int main()
{
    mystring my1{"12345"};
    mystring my2;
    my2 = my1;
    cout << (void *)my1.p << " " << my1.p << endl;
    cout << (void *)my2.p << " " << my2.p << endl;

    my1.~mystring();
    cout << (void *)my2.p << " " << my2.p << endl;
    return 0;
}
