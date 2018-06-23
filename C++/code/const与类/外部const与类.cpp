#include <iostream>

using namespace std;

class A
{
public :
    int x, y, z;
    A(int a = 10, int b = 10, int c = 10) : x(a), y(b), z(c){  }
    void show() const
    {
        cout << x << " " << y << " " << z << endl;
    }
    void set(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
};

int main()
{
    const A a(1, 2, 3); // ջ��
    a.show();
    //! a.set(2, 3, 4);
    const A *p = new A(4, 5, 6); // ����
    p -> show();
    //! p -> set(6, 7, 8); // �޷��ı�����
    p = nullptr; // ָ�򳣶����ָ�룬ָ����Ըı�ָ�򣬲����Ըı����ݣ�����ָ��һ���������飬�����ܸı�

    // �����Ըı�ָ��ָ��Ĳ��ǳ������Ǳ��������޸�
    A *const ptr = new A(1, 2, 3);
    ptr -> show();
    ptr -> set(2, 3, 4);
    //! p = nullptr;

    // ָ�򳣶���ָ��
    A const *const pp = new A(1, 2, 0);
    //! pp = nullptr;
    //! pp -> set(1, 2, 4);
    pp -> show();

    return 0;
}
