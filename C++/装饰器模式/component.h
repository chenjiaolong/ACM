#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include <iostream>

// 定义一个原始抽象类蛋糕，装饰器的功能是给蛋糕加上各种装饰，如奶油，巧克力，瓜子仁，水果等
class Cake
{
public :
    virtual void showCake() = 0;
    // 表示该函数没有函数题，函数体在派生类里定义

    virtual ~Cake() {};
    std :: string name;
};

class ConcreateCake : public Cake
{
public :
    ConcreateCake() { name = "原始蛋糕"; }

    void showCake() { std :: cout << name.c_str() << std :: endl; }
    virtual ~ConcreateCake() {}
};

#endif // COMPONENT_H_INCLUDED
