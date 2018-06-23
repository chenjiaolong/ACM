#include <iostream>

using namespace std;

int main()
{
    // register 对于CPP建议
    register int num = 10;
    cout << &num << endl; // 编译器优化，检测到取地址，就会优化内存变量
    return 0;
}
