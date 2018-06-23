#include <iostream>

class live // 抽象类，无法创建实例对象，用于被继承
{
public:
    virtual void life() = 0; // 纯虚函数，作为接口
    virtual void sleep() = 0;
};
class people: public live
{
public:
    virtual void think() = 0;
    virtual void run() = 0;
};
class bird: public live
{
    virtual void fly() = 0;
};
class birdpeople: public bird, public people
{
public:
    // 一旦继承了，必须实现纯虚函数的接口
    void life() { std :: cout << "life" << std :: endl; }
    void sleep() { std :: cout << "sleep" << std :: endl; }
    void think() { std :: cout << "think" << std :: endl; }
    void run() { std :: cout << "run" << std :: endl; }
    void fly() { std :: cout << "fly" << std :: endl; }
};

int main()
{
    birdpeople bp;

    return 0;
}
