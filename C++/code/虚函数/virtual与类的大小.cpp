#include <iostream>

class my // 虚基类
{

};
class myfu: virtual public my // 虚继承，虚基类指针，存储虚基类地址，4个字节
{

};
class myfupo: virtual public myfu // 12个字节
{
    virtual void go() = 0; // 纯虚函数，虚函数，存储了虚函数表的地址，4个字节
};
int main()
{
    std :: cout << sizeof(myfu) << std :: endl;
    std :: cout << sizeof(myfupo) << std :: endl;
    return 0;
}
