#include <iostream>

using namespace std;
// Ƕ���࣬���ж���һ���࣬public ���� :: ���������Դ�������private���޷�����

class A
{
public :
    class B
    {
    public :
        int x, y;
        B(int a, int b) : x(a), y(b) {  }
    };
    B *px1, *px2;
    A(int a1, int b1, int a2, int b2) : px1(new B(a1, b1)), px2(new B(a2, b2)){  }

};


int main()
{
    A a(1, 2, 3, 4);
    // B b(1, 2);
    A :: B b(1, 2);
    return 0;
}
