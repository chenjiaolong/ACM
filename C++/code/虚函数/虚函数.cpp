#include <iostream>

// �麯�����أ��뷵��ֵ�޹أ���������������ͣ�˳���й�
// �麯�����̳��Ժ����麯��
// ���Ҫʹ�ñ��̳е��麯��������������麯�����أ�C++��������ʶ��
// ��̬���Կ��࣬үү����ָ�룬�洢���ӱ���ַ��������ָ��洢���ӱ��ĵ�ַ
class myclass
{
public:
    virtual void go1() { std :: cout << "myclassY" << std :: endl; }
    virtual void go(int a) { }
    virtual void go(int a, int b){ }
};
class myclassX: public myclass
{
public:
    virtual void go(int a, int b, int c) {  }
};
class myclassY: public myclassX
{
public:
    void go1() { std :: cout << "myclassY" << std :: endl; }
};
int main()
{
    myclassX *p = new myclassY;
    p -> go1();
    return 0;
}
