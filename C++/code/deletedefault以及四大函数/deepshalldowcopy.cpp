// 处理安全问题
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>

using namespace std;

// 默认拷贝构造，只是值传递，对于数据，对于指针，同一个指向 -> 浅拷贝
// 类的内部有指针分配内存，需要深拷贝，否则浅拷贝
class mystring
{
public :
    char *pstr;
    int length;
    mystring(const char *str)
    {
        length = strlen(str);
        pstr = new char[length]{0};
        strcpy(pstr, str); // 初始化
    }
    ~mystring()
    {
        if(pstr) delete[] pstr, pstr = nullptr;
    }
    mystring(const mystring &p)
    {
        length = p.length;
        pstr = new char[length];
        strcpy(pstr, p.pstr);
    }
    void show()
    {
        cout << length << "  " << (void *)pstr << "  " << pstr << endl;
    }
};

int main()
{
    mystring str1("gogogo");
    str1.show();
    mystring str2(str1);
    str2.show();
    str1.~mystring();
    str2.show();

    return 0;
}
