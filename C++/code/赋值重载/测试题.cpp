#include <cstring>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
// 默认拷贝构造，赋值重载，值传递
// 非指针，深浅拷贝一样，指针
// 浅拷贝，内存共享，指针一致，内容一致
// 深拷贝，指针不一致，内容一致，内存独享

// 赋值重载如果有返回自身类型对象，会调用拷贝构造，注意深浅拷贝
// 返回对象没有影响 返回地址或引用，触发故障
using namespace std;

class mystring
{
public:
    char *p;
    int n;
    mystring() : p(nullptr), n(0){  }
    mystring(const char *str)
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
        cout << "构造函数call" << endl;
        n = str.n;
        p = new char[n];
        strcpy(p, str.p);
    }
    mystring * operator = (const mystring &str)
    {
        mystring tmp;
        cout << "赋值重载call" << endl;
        tmp.n = str.n;
        tmp.p = new char[tmp.n];
        strcpy(tmp.p, str.p);
        return &tmp;
    }
};

int main()
{
    mystring my1{"12345"};
    mystring my2;
    cout << (void *)my1.p << " " << my1.p << endl;
    cout << (void *) (my2 = my1) -> p << " " << (my2 = my1) -> p << endl;

    my1.~mystring();
    return 0;
}

