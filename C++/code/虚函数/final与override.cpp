#include <iostream>

class myclass
{
public:
    virtual void run() final { } // final�ؼ��֣���ֹ�麯������д�������Ӧ�麯��
    virtual void go() { }
};
class mynewclass: public myclass
{
public:
    // override���Զ�����麯���Ƿ���ڣ������ڻ����
    void go() override { }  // override����һ�£���д���麯���ӿڣ�������̹淶

};
int main()
{

    return 0;
}
