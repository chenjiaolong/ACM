#include <iostream>

using namespace std;
struct node; // �ṹ���������ֻ�ܴ���ָ�룬����

node *p;
//! node q;
void show (node &p)
{

}

struct node
{
    //! struct node q;
    struct node *p;
    struct node &rp; // �ṹ���ڲ����Դ���ָ�������
};

//struct
//{
//    // �����ṹ�壬�����Գ�ʼ��
//    // int num = 10;
//};

struct A
{
    virtual void show()
    {
        cout << "AAA" << endl;
    }
};

struct B: public A
{
    void show()
    {
        cout << "BBB" << endl;
    }
};

int main()
{
    B b;
    b.show(); // �ṹ��̳�
    A *p = new A; // ��̬
    p -> show();
    p = new B;
    p -> show();
    return 0;
}
