#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <typeinfo>
#include <iostream>

using namespace std;

class mystring
{
public :
    char *p;
    int n;
    mystring() : p(nullptr), n(0) { cout << "SSSS" << endl; }
    mystring(char *str)
    {
        p = new char[strlen(str) + 1];
        n = strlen(str) + 1;
        strcpy(p, str); // 拷贝
    }
//    mystring(mystring & mystr) // 拷贝构造基于引用的构造，浅拷贝
//    {
//        cout << "call 拷贝构造" << endl;
//        p = mystr.p;
//        n = mystr.n;
//    }
    mystring (mystring & mystr) // 拷贝构造基于引用的构造，浅拷贝
    {
        cout << "call 拷贝构造" << endl;
        p = mystr.p;
        n = mystr.n;
    }
    mystring operator + (mystring & mystrings)
    {
        cout << "赋值重载" << endl;
        mystring mys("ssss"); // 对象，自动消亡
        mys.n = n + mystrings.n;
        mys.p = new char[mys.n];
        strcpy(mys.p, p);
        strcat(mys.p, mystrings.p);
        return mys; // 副本机制
    }
    ~mystring(){ delete[] p; }
};

int main()
{
    mystring s1("hello,");
    mystring s2("world!");
    (s1 + s2); // 对象
    cout << (s1 + s2).p << endl;
    return 0;
}
