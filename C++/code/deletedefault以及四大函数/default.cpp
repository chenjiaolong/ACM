#include <iostream>

using namespace std;

class A
{
public :
    int x, y, z;
    A() = default; // 写了构造函数，会覆盖原生构造
    // A() {  }
    A(int a, int b, int c) : x(a), y(b), z(c) {  }

};

int main()
{
    A a;
    return 0;
}
