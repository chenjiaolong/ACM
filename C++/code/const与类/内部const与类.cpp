#include <iostream>

using namespace std;
// ���������ʱ��const���������޷�û�ı����ݣ�ֻ������β����const����
// ���Ա�����const����һ��Ĭ�ϳ�ʼ�����ڶ����빹��ĳ�ʼ�����������ڹ��캯���ڲ���ʼ��
// ���е�const��Ա���޷�ֱ���޸ģ����Լ���޸�
// ��ĳ�Ա����������ֵconst�����س���������const���ɶ�����д��β��const������������������÷�����������û�ж����Է���
// const �������ڹ��������� ���������������
class A
{
public :
    int x, y;
    const int z = 3; // ��������ԭ�򣬱����ʼ��
    A() : z(3){ /* z = 1; �������ݶ����ʼ�������빹�캯��֮�󣬲������캯���ڲ���ʼ��*/ }
    A(int a, int b) : x(a), y(b), z(a + b){  }
    ~A(){  }
    void show() const // const �����������
    {
        //! x = 1; // ֻ�ܶ��������޸�
        cout << x << " " << y << endl;
    }
    void change(const int a, const int b) // �������������޸�
    {
        x = a;
        y = b;
    }
    const int getx() const // ����һ�������� ��������״̬
    {
        return x;
    }
};

int main()
{
    // ���󣬳������� ��ֻ�ܵ����Դ�const�ķ������޷��޸�����
    // const A a(10, 10);
    //! a.x = 20;
    A a(10, 10);
    a.show();
    //! a.z = 2;
    cout << a.z << endl;
    int *p = const_cast<int *>(&a.z);
    *p = 3; // ���Լ���޸����е�const ��Ա
    cout << a.z << endl;

    a.change(1, 2);

    return 0;
}
