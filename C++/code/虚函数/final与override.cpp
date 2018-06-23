#include <iostream>

class myclass
{
public:
    virtual void run() final { } // final关键字，禁止虚函数被重写，必须对应虚函数
    virtual void go() { }
};
class mynewclass: public myclass
{
public:
    // override会自动检测虚函数是否存在，不存在会出错
    void go() override { }  // override声明一下，重写了虚函数接口，软件工程规范

};
int main()
{

    return 0;
}
