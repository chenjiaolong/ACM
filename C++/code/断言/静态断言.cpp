#include <cassert>
#include <iostream>

using namespace std;
// static_assert(sizeof(void*) != 8, "IDE is not 64 bits, baby");
// 区别用指针的大小
int main()
{
    cout << sizeof(void *) << endl;
    const int a = 0;
    // assert(a > 0); // 运行时断言
    static_assert(a > 0, "> 0, baby");// 变量不可以，必须常量
    return 0;
}


