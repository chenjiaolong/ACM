#include <iostream>

using namespace std;

class A
{
public :
    int x, y, z;
    A() = default; // д�˹��캯�����Ḳ��ԭ������
    // A() {  }
    A(int a, int b, int c) : x(a), y(b), z(c) {  }

};

int main()
{
    A a;
    return 0;
}
