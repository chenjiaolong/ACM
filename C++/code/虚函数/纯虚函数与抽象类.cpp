#include <iostream>

class live // �����࣬�޷�����ʵ���������ڱ��̳�
{
public:
    virtual void life() = 0; // ���麯������Ϊ�ӿ�
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
    // һ���̳��ˣ�����ʵ�ִ��麯���Ľӿ�
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
