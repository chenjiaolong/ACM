#include <iostream>

// �̳У�Ĭ�����class˽�м̳У�struct���м̳�
// �麯�����Ե��ó�Ա
// ��̬������ָ��������õ���
// ������ã�����ÿ������죬����һ�����࣬�޷�ʵ�ֶ�̬
class myclass
{
public:
    myclass() { std :: cout << "myclass()" << std :: endl; }
    myclass(const myclass &my) { std :: cout << "myclass(const myclass &my)" << std :: endl; }
    virtual ~myclass() { std :: cout << "~myclass()" << std :: endl; }
    virtual void go() { show(); }
    void show() { std :: cout << "show" << std :: endl; }

};
struct mynewclass : myclass
{
public:
    void go()
    {
        std :: cout << "hello world!" << std :: endl;
    }
};
void test(myclass *p)
{
    p -> go();
}
void test1(myclass &my)
{
    my.go();
}
void test2(myclass my)
{
    my.go();
}
int main()
{
    myclass *p = new mynewclass;
    test(p);
    //! test1(p);
    test2(*p);
    p -> go(); // ��̬����
    p -> myclass :: go(); // ����ԭ��
    mynewclass my;
    my.go();

    return 0;
}
